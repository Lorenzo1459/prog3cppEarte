#ifndef PROVA_H_
#define PROVA_H_

#include <iostream>
#include <string>
#include <vector>

#include "atividade.h"

using namespace std;

namespace br_ufes_inf_prog3_trab20152_atividade{

    class Prova : public Atividade{
        string nomeProva;
        time_t dataProva;
        string horaProva;
        string conteudoProva;

        public: 
            Prova(char tipo, bool modelo, string nomeProva, time_t dataProva, string horaProva, string conteudoProva);

            string getNomeProva();
            time_t getDataProva();
            string getHoraProva();
            string getConteudoProva();

    };

}

#endif