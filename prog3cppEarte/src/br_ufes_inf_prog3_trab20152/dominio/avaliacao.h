#ifndef PERIODO_H_
#define PERIODO_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace br_ufes_inf_prog3_trab20152_dominio{
    class Avaliacao{
        float nota;

        public:
            Avaliacao(float nota);
            float getNota();
    };
}

#endif