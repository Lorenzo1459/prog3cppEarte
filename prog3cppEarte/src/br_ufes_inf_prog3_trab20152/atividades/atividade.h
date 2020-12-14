#ifndef ATIVIDADE_H_
#define ATIVIDADE_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace br_ufes_inf_prog3_trab20152_atividade{

    class Atividade{
        char tipoAtividade;
        bool modelo; //Sinc ou Assin

        public:
            Atividade(char tipoAtividade, bool modelo);
            virtual char getTipoAtividade() const;
            virtual bool ehSincrona() const;
    };

}

#endif