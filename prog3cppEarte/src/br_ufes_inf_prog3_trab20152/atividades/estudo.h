#ifndef ESTUDO_H_
#define ESTUDO_H_

#include <iostream>
#include <string>
#include <vector>

#include "atividade.h"

using namespace std;

namespace br_ufes_inf_prog3_trab20152_atividade{

    class Estudo : public Atividade{
        string nomeEstudo;
        string materialEstudo;

        public: 
            Estudo(char tipo, bool modelo, string nomeEstudo, string materialEstudo);

            string getNomeEstudo();
            string getMaterialEstudo();
    };

}

#endif