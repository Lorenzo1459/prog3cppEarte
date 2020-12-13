#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
//#include "br_ufes_inf_prog3_trab20152/AplInveMid.h"
#include "br_ufes_inf_prog3_trab20152/io/Exceptions.h"
#include "br_ufes_inf_prog3_trab20152/io/Leitor.h"

using namespace std;
//using namespace br_ufes_inf_prog3_trab20152;
using namespace br_ufes_inf_prog3_trab20152_io;

int main(int argc, char **argv){
    string nomeArquivoPeriodo, nomeArquivoDocente, nomeArquivoDisciplina, nomeArquivoEstudante;
		string pFlag("-p"), dFlag("-d"), oFlag("-o"), eFlag("-e");

		for (int i = 0; i < argc; i++) {
			if (pFlag.compare(argv[i]) == 0 && argc > i + 1) nomeArquivoPeriodo = argv[i + 1];
			else if (dFlag.compare(argv[i]) == 0 && argc > i + 1) nomeArquivoDocente = argv[i + 1];
			else if (oFlag.compare(argv[i]) == 0 && argc > i + 1) nomeArquivoDisciplina = argv[i + 1];
			else if (eFlag.compare(argv[i]) == 0 && argc > i + 1) nomeArquivoEstudante = argv[i + 1];
		}
        if (! nomeArquivoPeriodo.empty() && ! nomeArquivoDocente.empty() && ! nomeArquivoDisciplina.empty() && ! nomeArquivoEstudante.empty()) {
            Leitor* leitor = new Leitor(nomeArquivoPeriodo, nomeArquivoDocente, nomeArquivoDisciplina, nomeArquivoEstudante);
            for(pair<string,Periodo*> p : leitor->getPeriodos()){
                cout << p.first << endl;
            }
			for(pair<string,Docente*> d : leitor->getDocentes()){
                cout << d.first << endl;
            }
			for(pair<string,Disciplina*> o : leitor->getDisciplinas()){
                cout << o.first << endl;
            }
            return 0;
		}
		else {
			throw IOException();
        }
}