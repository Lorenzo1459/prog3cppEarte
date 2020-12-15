#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
//#include "br_ufes_inf_prog3_trab20152/AplInveMid.h"
#include "br_ufes_inf_prog3_trab20152/io/Exceptions.h"
#include "br_ufes_inf_prog3_trab20152/io/Leitor.h"
#include "br_ufes_inf_prog3_trab20152/io/Escritor_csv.h"
#include "br_ufes_inf_prog3_trab20152/io/relatorio.h"

using namespace std;
//using namespace br_ufes_inf_prog3_trab20152;
using namespace br_ufes_inf_prog3_trab20152_io;

int main(int argc, char **argv){
    string nomeArquivoPeriodo, nomeArquivoDocente, nomeArquivoDisciplina, nomeArquivoEstudante, nomeArquivoMatriculas, nomeArquivoAtividades, nomeArquivoAvaliacoes;
		string pFlag("-p"), dFlag("-d"), oFlag("-o"), eFlag("-e"), mFlag("-m"), aFlag("-a"), nFlag("-n");

		for (int i = 0; i < argc; i++) {
			if (pFlag.compare(argv[i]) == 0 && argc > i + 1) nomeArquivoPeriodo = argv[i + 1];
			else if (dFlag.compare(argv[i]) == 0 && argc > i + 1) nomeArquivoDocente = argv[i + 1];
			else if (oFlag.compare(argv[i]) == 0 && argc > i + 1) nomeArquivoDisciplina = argv[i + 1];
			else if (eFlag.compare(argv[i]) == 0 && argc > i + 1) nomeArquivoEstudante = argv[i + 1];
            else if (mFlag.compare(argv[i]) == 0 && argc > i + 1) nomeArquivoMatriculas = argv[i + 1];
            else if (aFlag.compare(argv[i]) == 0 && argc > i + 1) nomeArquivoAtividades = argv[i + 1];
            else if (nFlag.compare(argv[i]) == 0 && argc > i + 1) nomeArquivoAvaliacoes = argv[i + 1];
		}
        if (! nomeArquivoPeriodo.empty() && ! nomeArquivoDocente.empty() && ! nomeArquivoDisciplina.empty() && ! nomeArquivoEstudante.empty() && ! nomeArquivoMatriculas.empty() && ! nomeArquivoAtividades.empty() && ! nomeArquivoAvaliacoes.empty()) {
            Leitor* leitor = new Leitor(nomeArquivoPeriodo, nomeArquivoDocente, nomeArquivoDisciplina, nomeArquivoEstudante, nomeArquivoMatriculas, nomeArquivoAtividades, nomeArquivoAvaliacoes);
            Relatorio* relatorio = new Relatorio();
            //cout << p.first << endl;
            relatorio->relatorioDisc(leitor->getDisciplinas(),leitor->getPeriodos());
			for(pair<string,Disciplina*> o : leitor->getDisciplinas()){
                cout << "------" << o.second->getCodigo() << "------" << endl;
                cout << o.second->getDocente()->getNome() << endl;
            }
            relatorio->relatorioDocente(leitor->getDocentes());
            relatorio->relatorioEstudante(leitor->getEstudantes());
            relatorio->relatorioDiscDocente(leitor->getDocentes(),leitor->getDisciplinas());
            return 0;
		}
		else {
			throw IOException();
        }
}