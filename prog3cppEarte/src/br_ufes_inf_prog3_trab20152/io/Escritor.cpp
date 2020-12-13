/*
 * Escritor.cpp
 *
 *  Created on: Dec 2, 2015
 *      Author: vitor
 

#include "Escritor.h"

namespace br_ufes_inf_prog3_trab20152_io {

const string RELATORIO_ESTATISTICAS = "1-estatisticas.txt";
const string RELATORIO_POR_PESSOA = "2-porpessoa.csv";
const string RELATORIO_EMPRESTIMOS = "3-emprestimos.csv";
const string RELATORIO_WISHLIST = "4-wishlist.csv";
const string SEPARADOR_CSV = ";";
const string SEPARADOR_PRODUCAO = ", ";
const string CABECALHO_RELATORIO_POR_PESSOA = "Pessoa" + SEPARADOR_CSV + "Produção";
const string CABECALHO_RELATORIO_EMPRESTIMOS = "Data" + SEPARADOR_CSV + "Tomador" + SEPARADOR_CSV + "Atrasado?" + SEPARADOR_CSV + "Dias de Atraso";
const string CABECALHO_RELATORIO_WISHLIST = "Tipo" + SEPARADOR_CSV + "Mídia" + SEPARADOR_CSV + "Gênero" + SEPARADOR_CSV + "Preço";
const time_t HOJE = parseDate("06/11/2015", DATE_FORMAT_PT_BR_SHORT);
const string EMPRESTIMO_ATRASADO_SIM = "Sim";
const string EMPRESTIMO_ATRASADO_NAO = "Não";
/*
void Escritor::escreverRelatorioEstatisticas(Estatisticas& stats) const {
	ofstream out(RELATORIO_ESTATISTICAS);
	out << "Horas consumidas: " << stats.horasConsumidas << " minutos" << endl;
	out << "Horas a consumir: " << stats.horasConsumir << " minutos" << endl;

	out << endl << "Mídias por gênero:" << endl;
	for (MidiasPorGenero* mpg : stats.midiasPorGenero)
		out << "\t" << *(mpg->genero) << ": " << mpg->qtd << endl;

	out << endl << "Temporadas por série:" << endl;
	for (TemporadasPorSerie* tps : stats.temporadasPorSerie)
		out << "\t" << *(tps->serie) << ": " << tps->qtdJa << " assistidas, " << tps->qtdA << " a assistir" << endl;
	out.close();
}

void Escritor::escreverRelatorioMidiasPorPessoa(MidiasPorPessoa& mpp) const {
	ofstream out(RELATORIO_POR_PESSOA);
	out << CABECALHO_RELATORIO_POR_PESSOA << endl;

	for (pair<Pessoa*, set<Midia*, MidiaComparator> > par : mpp.producoes) {
		stringstream stream;
		for (Midia* midia : par.second) {
			stream << *midia << SEPARADOR_PRODUCAO;
		}
		string producao;
		getline(stream, producao);
		producao.erase(producao.size() - SEPARADOR_PRODUCAO.size(), SEPARADOR_PRODUCAO.size());
		out << *(par.first) << SEPARADOR_CSV << producao << endl;
	}

	out.close();
}

void Escritor::escreverRelatorioEmprestimos(vector<Emprestimo*> emprestimos) const {
	sort(emprestimos.begin(), emprestimos.end(), comparaEmprestimos);

	ofstream out(RELATORIO_EMPRESTIMOS);
	out << CABECALHO_RELATORIO_EMPRESTIMOS << endl;

	for (Emprestimo* emprestimo : emprestimos) {
		string atraso = EMPRESTIMO_ATRASADO_NAO;
		long diff = difftime(HOJE, emprestimo->getDataDevolucao());

		if (diff > 0) {
			atraso = EMPRESTIMO_ATRASADO_SIM;
			diff = diff / (60 * 60 * 24);
		}
		else diff = 0;

		out << formatDate(emprestimo->getDataEmprestimo(), DATE_FORMAT_PT_BR_SHORT) << SEPARADOR_CSV << emprestimo->getTomador() << SEPARADOR_CSV << atraso << SEPARADOR_CSV << diff << endl;
	}

	out.close();
}

void Escritor::escreverRelatorioWishlist(Wishlist& wishlist) const {
	ofstream out(RELATORIO_WISHLIST);
	out << CABECALHO_RELATORIO_WISHLIST << endl;

	for (ItemWishlist* item : wishlist.itens) {
		Midia* midia = item->midia;
		out << midia->getTipo() << SEPARADOR_CSV << midia->getNome() << SEPARADOR_CSV << *(midia->getGenero()) << SEPARADOR_CSV << "R$ " << formatDoubleCurrency(midia->getPreco(), LOCALE_PT_BR) << endl;
	}

	out.close();
}

}  namespace br_ufes_inf_prog3_trab20152_io */
