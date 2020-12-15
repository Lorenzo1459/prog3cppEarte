#include "discDocente.h"

namespace br_ufes_inf_prog3_trab20152_dominio{

    DiscDocente::DiscDocente(Docente* d, Disciplina* disc){
        this->d = d;
        this->disciplinas.push_back(disc);
    }

    void DiscDocente::setNumAtiv(int n){
        this->numAtiv = n;
    }

    float DiscDocente::getMediaAtiv(){
        return (float)this->numAtiv/this->numDisc;
    }

    void DiscDocente::increaseNumSinc(int n){
        cout << "increaseSin N: " << n << endl;     
        this->numSinc += n;
        cout << "IncresaseSINcnumSIN: " << this->numSinc << endl;
    }
    float DiscDocente::getPercentSinc(){
        return (float)this->numSinc/this->numAtiv *100;
    }
    float DiscDocente::getPercentAssin(){
        return 100 - this->getPercentSinc();
    }

    int DiscDocente::getNumDisc(){
        return this->numDisc;
    }

    void DiscDocente::increaseNumDisc(){
        this->numDisc++;
    }

}