/*
 * AplInveMid.cpp
 *
 *  Created on: Nov 30, 2015
 *      Author: vitor
 

#include "AplInveMid.h"

namespace br_ufes_inf_prog3_trab20152 {

AplInveMid::AplInveMid() {
	//estatisticas = nullptr;
	//midiasPorPessoa = nullptr;
	//wishlist = nullptr;
}

AplInveMid::~AplInveMid() {
	//delete estatisticas;
	//delete midiasPorPessoa;
	//delete wishlist;
}

void AplInveMid::lerDados(string nomeArquivoPeriodo, string nomeArquivoDocente, string nomeArquivoDisciplina, string nomeArquivoEstudante) {
	Leitor leitor(nomeArquivoPeriodo, nomeArquivoDocente, nomeArquivoDisciplina, nomeArquivoEstudante);
	//estatisticas = new Estatisticas(leitor.getGeneros(), leitor.getMidias(), leitor.getSeries());
	//midiasPorPessoa = new MidiasPorPessoa(leitor.getMidias());
	//wishlist = new Wishlist(leitor.getMidias());
	//emprestimos = leitor.getEmprestimos();
}

void AplInveMid::escreverRelatorios(Escritor& escritor) const {
	//escritor.escreverRelatorioEstatisticas(*estatisticas);
	//escritor.escreverRelatorioMidiasPorPessoa(*midiasPorPessoa);
	//escritor.escreverRelatorioEmprestimos(emprestimos);
	//escritor.escreverRelatorioWishlist(*wishlist);
}

} namespace br_ufes_inf_prog3_trab20152_dominio */
