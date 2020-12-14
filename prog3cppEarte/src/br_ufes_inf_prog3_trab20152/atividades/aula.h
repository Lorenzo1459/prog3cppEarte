#ifndef AULA_H_
#define AULA_H_

#include <iostream>
#include <string>
#include <vector>

#include "atividade.h"

using namespace std;

namespace br_ufes_inf_prog3_trab20152_atividade{

    class Aula : public Atividade{
        string nomeAula;
        time_t dataAula;
        string horaAula;

        public: 
            Aula(char tipo, bool modelo, string nomeAula, time_t dataAula, string horaAula);

            string getNomeAula();
            time_t getDataAula();
            string getHoraAula();
    };

}

#endif