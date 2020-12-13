#include "periodo.h"

namespace br_ufes_inf_prog3_trab20152_dominio{

    Periodo::Periodo(int ano, char semestre){
        this->ano = ano;
        this->semestre = semestre;
    }

    int Periodo::getAno(){
        return this->ano;
    }

    char Periodo::getSemestre(){
        return this->semestre;
    }

    string Periodo::getPeriodoString(Periodo* p){
        return to_string(p->getAno()) + "/" + p->getSemestre();
    }

    void Periodo::imprimePeriodo(Periodo* p){
        cout << "    " << p->getAno() << "/";
        cout << p->getSemestre() << endl;
    }

} //namespace dominio

