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
        int num = 0;

        public:
            Atividade(char tipoAtividade, bool modelo);
            virtual char getTipoAtividade() const;
            virtual bool ehSincrona() const;
            virtual int getNumAtiv() const;
            virtual void setNumAtiv(Atividade* ativ, int anterior) const;
    };

}

#endif