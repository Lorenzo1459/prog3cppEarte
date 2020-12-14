#ifndef TRABALHO_H_
#define TRABALHO_H_

#include <iostream>
#include <string>
#include <vector>

#include "atividade.h"

using namespace std;

namespace br_ufes_inf_prog3_trab20152_atividade{

    class Trabalho : public Atividade{
        string nomeTrabalho;
        time_t dataTrabalho;
        string cargaHorariaTrabalho;
        int qntIntegrantes;

        public: 
            Trabalho(char tipo, bool modelo, string nomeTrabalho, time_t dataTrabalho, string cargaHorariaTrabalho, int qntIntegrantes);

            string getNomeTrabalho();
            time_t getDataTrabalho();
            string getCargaHorariaTrabalho();
            int getQtIntegrantesTrabalho();

    };

}

#endif