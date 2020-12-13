#ifndef ESTUDANTE_H_
#define ESTUDANTE_H_

#include <iostream>
#include <string>
#include <vector>
//#include "disciplina.h"

using namespace std;

namespace br_ufes_inf_prog3_trab20152_dominio{

    class Estudante{
    long matricula;
    string nome;
    //vector<Disciplina*>* disciplinas;

    public:
        Estudante(long mat, string nome);
        Estudante* cadastraEstudante();
        long getMatricula();
        string getNomeEstudante();

        void imprimeEstudante(Estudante* e);
    };

} //namespace dominio

#endif /* ESTUDANTE_H_ */