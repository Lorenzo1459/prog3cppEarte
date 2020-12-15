#ifndef AVALIACAO_H_
#define AVALIACAO_H_

#include <iostream>
#include <string>
#include <vector>
#include "../atividades/atividade.h"

using namespace std;
using namespace br_ufes_inf_prog3_trab20152_atividade;

namespace br_ufes_inf_prog3_trab20152_dominio{
    class Avaliacao{
        float nota;
        Atividade* a;

        public:
            Avaliacao(float nota, Atividade* a);
            float getNota();
            Atividade* getAtividade();
    };
}

#endif