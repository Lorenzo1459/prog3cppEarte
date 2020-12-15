#include "Leitor.h"

namespace br_ufes_inf_prog3_trab20152_io {

Leitor::Leitor(string nomeArquivoPeriodo, string nomeArquivoDocente, string nomeArquivoDisciplina, string nomeArquivoEstudante, string nomeArquivoMatriculas, string nomeArquivoAtividades, string nomeArquivoAvaliacoes) {
	lerPeriodos(nomeArquivoPeriodo);
	lerDocente(nomeArquivoDocente);
	lerDisciplina(nomeArquivoDisciplina);
	lerEstudantes(nomeArquivoEstudante);
	lerMatriculas(nomeArquivoMatriculas);
	lerAtividades(nomeArquivoAtividades);
	lerAvaliacoes(nomeArquivoAvaliacoes);
}

map<string, Periodo*> Leitor::getPeriodos() const {
	return periodos;
}

map<string, Docente*> Leitor::getDocentes() const {
	return docentes;
}

map<string, Disciplina*> Leitor::getDisciplinas() const {
	return disciplinas;
}

map<long, Estudante*> Leitor::getEstudantes() const {
	return estudantes;
}

vector<Matricula*> Leitor::getMatriculas() const {
	return matriculas;
}

vector<Atividade*> Leitor::getAtividades() const {
	return atividades;
}

vector<Avaliacao*> Leitor::getAvaliacoes() const {
	return avaliacoes;
}

void Leitor::lerPeriodos(string& nomeArquivoPeriodo) {
	vector<Periodo*> lista;
	ConversorCSVPeriodo conversor(this);
	conversor.lerArquivo(nomeArquivoPeriodo, lista);
	for (Periodo* p : lista)
		periodos.insert(pair<string, Periodo*>(p->getPeriodoString(),p));
}

void ConversorCSVPeriodo::criarObjetoDeLinhaCSV(vector<string>& dados, vector<Periodo*>& lista) const {
	int ano = stoi(dados[0]);
	char semestre = dados[1][0];
	Periodo* p = new Periodo(ano,semestre);
	lista.push_back(p);
}

void Leitor::lerDocente(string& nomeArquivoDocente) {
	vector<Docente*> lista;
	ConversorCSVDocente conversor(this);
	conversor.lerArquivo(nomeArquivoDocente, lista);
	for (Docente* d : lista)
		docentes.insert(pair<string, Docente*>(d->getLogin(), d));
}

void ConversorCSVDocente::criarObjetoDeLinhaCSV(vector<string>& dados, vector<Docente*>& lista) const {
	if (isNumber(dados.at(0)) || isNumber(dados.at(1)) || isNumber(dados.at(2))) throw FormatacaoException();
	Docente* docente = new Docente(dados[1], dados[0], dados[2]);
	lista.push_back(docente);
}

void Leitor::lerDisciplina(string& nomeArquivoDisciplina) {
	vector<Disciplina*> lista;
	ConversorCSVDisciplina conversor(this);
	conversor.lerArquivo(nomeArquivoDisciplina, lista);
	for (Disciplina* d : lista)
		disciplinas.insert(pair<string, Disciplina*>(d->getCodigo(), d));
}

void ConversorCSVDisciplina::criarObjetoDeLinhaCSV(vector<string>& dados, vector<Disciplina*>& lista) const {
	string per = dados[0];
	string codigo = dados[1] + "-" + per;
	string nome = dados[2];
	string login = dados[3];
	Periodo* p = leitor->periodos.at(per);
	Docente* d = leitor->docentes.at(login);
	leitor->docentes.at(login)->increasePeriodos(p);
	Disciplina* disc = new Disciplina(codigo,nome,p,d);
	leitor->docentes.at(login)->increaseNumDisc();
	lista.push_back(disc);
	//leitor->docentes.at(login)->setNumAtiv(leitor->getDisciplinas().at(disc->getCodigo())->getNumAtiv());
	//leitor->docentes.at(login)->increaseNumSinc(leitor->getDisciplinas().at(disc->getCodigo())->getNumSinc());
}

void Leitor::lerMatriculas(string& nomeArquivoMatriculas) {
	ConversorCSVMatriculas conversor(this);
	conversor.lerArquivo(nomeArquivoMatriculas, matriculas);
}

void ConversorCSVMatriculas::criarObjetoDeLinhaCSV(vector<string>& dados, vector<Matricula*>& lista) const{
	string codigoDisc = dados[0];
	Tokenizer tok(dados[0],'-');
	vector<string> cods = tok.remaining();
	long mat = stol(dados.at(1));
	if(leitor->disciplinas.count(codigoDisc) == 0) throw InconsistenciaException("Disciplina: " + dados[0]);
	Disciplina* disc = leitor->disciplinas.at(codigoDisc);
	if(leitor->estudantes.count(mat) == 0) throw InconsistenciaException("Estudante: " + dados[1]);
	Estudante* e = leitor->estudantes.at(mat);
	Matricula* matricula = new Matricula(disc,e);
	leitor->disciplinas.at(codigoDisc)->putEstudante(e);
	leitor->estudantes.at(mat)->increaseDisc();
	leitor->estudantes.at(mat)->increasePer(cods[1]);
	lista.push_back(matricula);
}

void Leitor::lerAtividades(string& nomeArquivoAtividade) {
	ConversorCSVAtividades conversor(this);
	conversor.lerArquivo(nomeArquivoAtividade, atividades);
}

void ConversorCSVAtividades::criarObjetoDeLinhaCSV(vector<string>& dados, vector<Atividade*>& lista) const{
	Atividade* atividade = nullptr;
	string codigoDisc = dados[0];
	if(leitor->disciplinas.count(codigoDisc) == 0) throw InconsistenciaException("Disciplina: " + dados[0]);
	Disciplina* d = leitor->disciplinas.at(codigoDisc);
	string nome = dados[1];
	char tipo = dados[2][0];
	switch(tipo){
		case 'A' : case 'a' : {
			if (! validDate(dados.at(3), DATE_FORMAT_PT_BR_SHORT)) throw FormatacaoException();
			time_t dataAula = parseDate(dados[2],DATE_FORMAT_PT_BR_SHORT);
			string horaAula = dados[4];
			Aula* aula = new Aula(tipo, 1, nome, dataAula, horaAula);
			atividade = aula;
			leitor->disciplinas.at(codigoDisc)->increaseNumSin();
			leitor->getDocentes().at(d->getDocente()->getLogin())->increaseNumSinc();
			break;
		}
		case 'P' : case 'p' : {
			if (! validDate(dados.at(3), DATE_FORMAT_PT_BR_SHORT)) throw FormatacaoException();
			time_t dataProva = parseDate(dados[2],DATE_FORMAT_PT_BR_SHORT);
			string horaProva = dados[4];
			string conteudoProva = dados[5];
			Prova* prova = new Prova(tipo, 1, nome, dataProva, horaProva, conteudoProva);
			atividade = prova;
			leitor->disciplinas.at(codigoDisc)->increaseNumSin();
			leitor->getDocentes().at(d->getDocente()->getLogin())->increaseNumSinc();
			break;
		}
		case 'T' : case 't' : {
			if (! validDate(dados.at(3), DATE_FORMAT_PT_BR_SHORT)) throw FormatacaoException();
			time_t dataTrabalho = parseDate(dados[2],DATE_FORMAT_PT_BR_SHORT);
			string cargaHorarioTrabalho = dados[7];
			int qtIntegrantesTrabalho = stoi(dados[6]);
			Trabalho* trabalho = new Trabalho(tipo, 1, nome, dataTrabalho, cargaHorarioTrabalho, qtIntegrantesTrabalho);
			atividade = trabalho;
			leitor->disciplinas.at(codigoDisc)->increaseNumAssinc();
			break;
		}
		case 'E' : case 'e' : {
			string conteudoEstudo = dados[5];
			Estudo* estudo = new Estudo(tipo, 1, nome, conteudoEstudo);
			atividade = estudo;
			leitor->disciplinas.at(codigoDisc)->increaseNumAssinc();
			break;
		}
	}
	atividade->setNumAtiv(atividade, leitor->disciplinas.at(codigoDisc)->getNumAtiv());
	leitor->disciplinas.at(codigoDisc)->putAtividade(atividade);
	leitor->getDocentes().at(d->getDocente()->getLogin())->setNumAtiv(d->getNumAtiv());
	lista.push_back(atividade);
}

void Leitor::lerAvaliacoes(string& nomeArquivoAvaliacoes){
	ConversorCSVAvaliacao conversor(this);
	conversor.lerArquivo(nomeArquivoAvaliacoes, avaliacoes);
}

void ConversorCSVAvaliacao::criarObjetoDeLinhaCSV(vector<string>& dados, vector<Avaliacao*>& lista) const {
	string codigoDisc = dados[0];
	long mat = stol(dados.at(1));
	int verifica = 0;
	for(Matricula* m : leitor->getMatriculas())
		if(m->getDisciplina()->getCodigo() == codigoDisc && m->getEstudante()->getMatricula() == mat) verifica = 1;
	if(verifica == 0) throw InconsistenciaException("Avaliacao: " + dados[1] + "em" + dados[0]);
	int num = stoi(dados[2]);
	replace(dados[3].begin(),dados[3].end(),',','.');
	float nota = stof(dados[3]);
	Atividade* ativ = leitor->getDisciplinas().at(codigoDisc)->getAtividades().at(num-1);
	Avaliacao* a = new Avaliacao(nota,ativ);
	leitor->getEstudantes().at(mat)->putAvaliacao(a);
	lista.push_back(a);
}

void Leitor::lerEstudantes(string& nomeArquivoEstudante) {
	vector<Estudante*> lista;
	ConversorCSVEstudante conversor(this);
	conversor.lerArquivo(nomeArquivoEstudante, lista);
	for (Estudante* e : lista)
		estudantes.insert(pair<long, Estudante*>(e->getMatricula(), e));
}

void ConversorCSVEstudante::criarObjetoDeLinhaCSV(vector<string>& dados, vector<Estudante*>& lista) const {
	string aux = dados[0];
	long mat = stol(aux);
	Estudante* e = new Estudante(mat,dados[1]);
	lista.push_back(e);
}


} /* namespace br_ufes_inf_prog3_trab20152_io */
