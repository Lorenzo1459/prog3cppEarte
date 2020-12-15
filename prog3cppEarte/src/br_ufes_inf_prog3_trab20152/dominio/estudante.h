#ifndef ESTUDANTE_H_
#define ESTUDANTE_H_

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "avaliacao.h"

using namespace std;

namespace br_ufes_inf_prog3_trab20152_dominio{

    class Estudante{
    long matricula;
    string nome;
    vector<Avaliacao*> avaliacoes;
    int qtDisc = 0;
    set<string> periodos;

    public:
        Estudante(long mat, string nome);
        long getMatricula();
        string getNomeEstudante();
        vector<Avaliacao*> getAvaliacao();
        void putAvaliacao(Avaliacao* a);
        void imprimeEstudante(Estudante* e);
        void increaseDisc();
        int getQtDisc();
        void increasePer(string per);
        int getQtPer();
        float getMediaDiscPer();
        float getMediaNota();
        float getMediaAvDisc();
    };

} //namespace dominio

#endif /* ESTUDANTE_H_ */