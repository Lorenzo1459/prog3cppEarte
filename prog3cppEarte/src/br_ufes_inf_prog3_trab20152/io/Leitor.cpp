/*
 * Leitor.cpp
 *
 *  Created on: Nov 30, 2015
 *      Author: vitor
 */

#include "Leitor.h"

namespace br_ufes_inf_prog3_trab20152_io {

Leitor::Leitor(string nomeArquivoPeriodo, string nomeArquivoDocente, string nomeArquivoDisciplina, string nomeArquivoEstudante) {
	lerPeriodos(nomeArquivoPeriodo);
	lerDocente(nomeArquivoDocente);
	lerDisciplina(nomeArquivoDisciplina);
	lerEstudantes(nomeArquivoEstudante);
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

void Leitor::lerPeriodos(string& nomeArquivoPeriodo) {
	vector<Periodo*> lista;
	ConversorCSVPeriodo conversor(this);
	conversor.lerArquivo(nomeArquivoPeriodo, lista);
	for (Periodo* p : lista)
		periodos.insert(pair<string, Periodo*>(p->getPeriodoString(p), p));
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
	Docente* docente = new Docente(dados[0], dados[1], dados[2]);
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
	Disciplina* d = new Disciplina(dados[0],dados[1],dados[2],dados[3]);
	lista.push_back(d);
}

/*
vector<Pessoa*> recuperarPessoas(string& codigos, map<int, Pessoa*>& pessoas) {
	Tokenizer tok(codigos, ',');
	vector<string> vec = tok.remaining();
	vector<Pessoa*> lista;
	for (string codigo : vec) {
		int codPessoa = stoi(codigo);
		if (pessoas.count(codPessoa) == 0) throw InconsistenciaException("A(u)tor: " + codigo);
		Pessoa* pessoa = pessoas.at(codPessoa);
		lista.push_back(pessoa);
	}
	return lista;
} */
/*
void ConversorCSVDisciplina::criarObjetoDeLinhaCSV(vector<string>& dados, vector<Disciplina*>& lista) const {
	Midia* midia = nullptr;

	if (leitor->generos.count(dados[6]) == 0) throw InconsistenciaException("Gênero: " + dados[6]);
	Genero* genero = leitor->generos[dados[6]];

	string cabecalhos[3] = { "Possui?", "Consumiu?", "Deseja?" };
	for (int i = 0; i < 3; i++) {
		int idx = i + 9;
		if (dados.size() > idx && ! (dados.at(idx).empty() || stringCompare(dados.at(idx), "x") == 0))
			throw InconsistenciaException(cabecalhos[i] + ": " + dados.at(idx));
	}

	double preco = (dados.size() > 12) ? parseDouble(dados.at(12), LOCALE_PT_BR) : 0;
	bool possui = (dados.size() > 9 && (dados.at(9).compare("x") == 0 || dados.at(9).compare("X") == 0));
	bool consumiu = (dados.size() > 10 && (dados.at(10).compare("x") == 0 || dados.at(10).compare("X") == 0));
	bool deseja = (dados.size() > 11 && (dados.at(11).compare("x") == 0 || dados.at(11).compare("X") == 0));

	if (dados.at(2).empty() || dados.at(2).size() > 1) throw InconsistenciaException("Tipo: " + dados.at(2));
	char tipo = dados.at(2).at(0);
	switch (tipo) {
	case 'F': case 'f': {
		int codDiretor = stoi(dados.at(3));
		if (leitor->pessoas.count(codDiretor) == 0) throw InconsistenciaException("Diretor: " + dados.at(3));
		Pessoa* diretor = leitor->pessoas.at(codDiretor);
		Filme* filme = new Filme(stoi(dados.at(0)), dados.at(1), stoi(dados.at(5)), preco, possui, consumiu, deseja, genero, diretor);
		midia = filme;

		if (dados.size() < 13 && filme->isDeseja() && ! filme->isPossui())
			throw InconsistenciaException("Preço: " + to_string(preco));

		string atores(dados.at(4));
		if (atores.size() > 0) {
			vector<Pessoa*> pessoas = recuperarPessoas(atores, leitor->pessoas);
			for (Pessoa* pessoa : pessoas) filme->adicionarAtor(pessoa);
		}
		break;
	}

	case 'L': case 'l': {
		vector<Pessoa*> pessoas = recuperarPessoas(dados.at(4), leitor->pessoas);
		midia = new Livro(stoi(dados.at(0)), dados.at(1), stoi(dados.at(5)), preco, possui, consumiu, deseja, genero, pessoas);
		break;
	}

	case 'S': case 's': {
		Temporada* temporada = nullptr;
		if (leitor->series.count(dados.at(7)) > 0) {
			Serie* serie = leitor->series.at(dados.at(7));
			temporada = new Temporada(stoi(dados.at(0)), dados.at(1), stoi(dados.at(5)), preco, possui, consumiu, deseja, genero, serie);
		}
		else {
			temporada = new Temporada(stoi(dados.at(0)), dados.at(1), stoi(dados.at(5)), preco, possui, consumiu, deseja, genero, dados.at(7));
			leitor->series.insert(pair<string, Serie*>(dados.at(7), temporada->getSerie()));
		}
		midia = temporada;

		string atores(dados.at(4));
		if (atores.size() > 0) {
			vector<Pessoa*> pessoas = recuperarPessoas(atores, leitor->pessoas);
			for (Pessoa* pessoa : pessoas) temporada->adicionarAtor(pessoa);
		}
		break;
	}
	default:
		throw InconsistenciaException("Tipo: " + dados.at(2));
	}

	lista.push_back(midia);
}
*/


void Leitor::lerEstudantes(string& nomeArquivoEstudante) {
	vector<Estudante*> lista;
	ConversorCSVEstudante conversor(this);
	conversor.lerArquivo(nomeArquivoEstudante, lista);
	for (Estudante* e : lista)
		estudantes.insert(pair<long, Estudante*>(e->getMatricula(), e));
}

void ConversorCSVEstudante::criarObjetoDeLinhaCSV(vector<string>& dados, vector<Estudante*>& lista) const {
	string teste = dados[0];
	long mat = stol(teste);
	Estudante* e = new Estudante(mat,dados[1]);
	lista.push_back(e);
}


} /* namespace br_ufes_inf_prog3_trab20152_io */
