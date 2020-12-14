#ifndef MATRICULA_H_
#define MATRICULA_H_

#include <iostream>

#include "disciplina.h"
#include "estudante.h"

using namespace std;

namespace br_ufes_inf_prog3_trab20152_dominio{

    class Matricula{
        Disciplina* disc;
        Estudante* e;

        public:
            Matricula(Disciplina* disc, Estudante* e);

            Disciplina* getDisciplina() const;
            Estudante* getEstudante() const;
    };

} /*namespace br_ufes_inf_prog3_trab20152_dominio*/

#endif