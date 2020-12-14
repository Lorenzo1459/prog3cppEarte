/*

#ifndef BR_UFES_INF_PROG3_TRAB20152_APLINVEMID_H_
#define BR_UFES_INF_PROG3_TRAB20152_APLINVEMID_H_

#include <string>
#include <vector>
#include "io/Leitor.h"
#include "io/Escritor.h"

#include "io/Estatisticas.h"
#include "io/MidiasPorPessoa.h"
#include "io/Wishlist.h"

using namespace std;
using namespace br_ufes_inf_prog3_trab20152_io;

namespace br_ufes_inf_prog3_trab20152 {

class AplInveMid {
	//Estatisticas *estatisticas;
	//MidiasPorPessoa *midiasPorPessoa;
	//Wishlist *wishlist;
	//vector<Emprestimo*> emprestimos;

public:
	AplInveMid();
	~AplInveMid();

	void lerDados(string nomeArquivoGeneros, string nomeArquivoPessoas, string nomeArquivoMidias, string nomeArquivoEmprestimos);
	void escreverRelatorios(Escritor& escritor) const;
};

}  namespace br_ufes_inf_prog3_trab20152_dominio 

#endif  BR_UFES_INF_PROG3_TRAB20152_APLINVEMID_H_ */
