#ifndef DOCENTE_H_
#define DOCENTE_H_

#include <iostream>
#include <string>
#include <vector>
#include <set>

#include "periodo.h"
#include "avaliacao.h"
using namespace std;

namespace br_ufes_inf_prog3_trab20152_dominio{

    class Docente{
        string nome;
        string login;
        string paginaWeb;
        set<Periodo*> periodos;
        vector<Avaliacao*> avaliacoes;
        int numDisc = 0;
        int numAtiv = 0;
        int numSinc = 0;

        public:
            Docente(string nome, string login, string paginaWeb);
            string getNome();
            string getLogin();
            string getPagWeb();
            int getNumDisc();
            void increaseNumDisc();
            void increasePeriodos(Periodo* p);
            int getNumPeriodosDoc();
            void setNumAtiv(int n);
            float getMediaAtiv();
            void increaseNumSinc();
            float getPercentSinc();
            float getPercentAssin();
            void putAvaliacaoDocente(Avaliacao* a);
            float getMediaNotasDocente();
    };

} //namespace dominio

#endif /* DOCENTE_H_ */