#ifndef PERIODO_H_
#define PERIODO_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace br_ufes_inf_prog3_trab20152_dominio{
    
    class Periodo{
    int ano;
    char semestre;
    //vector<Disciplina*>* disciplinas;
        
    public:
        Periodo(int ano, char semestre);

        int getAno();
        char getSemestre();
        void imprimePeriodo(Periodo* p);
        Periodo* cadastroPeriodo();
        void imprimeVectorPeriodos(vector<Periodo*>* vp);

        string getPeriodoString();
    };

} //namespace dominio

#endif /*PERIODO_H_*/