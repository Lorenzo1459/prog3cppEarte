#ifndef DISCDOCENTE_H_
#define DISCDOCENTE_H_

#include <iostream>
#include <vector>

#include "disciplina.h"
#include "docente.h"

using namespace std;

namespace br_ufes_inf_prog3_trab20152_dominio{
    class DiscDocente{
        Docente* d;
        vector<Disciplina*> disciplinas;
        int numDisc = 0;
        int numAtiv = 0;
        int numSinc = 0;

        public:
            DiscDocente(Docente* d, Disciplina* disc);
            int getNumDisc();
            void increaseNumDisc();
            void setNumAtiv(int n);
            float getMediaAtiv();
            void increaseNumSinc(int n);
            float getPercentSinc();
            float getPercentAssin();
    };
}

#endif