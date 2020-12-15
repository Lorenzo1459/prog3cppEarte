#include "docente.h"

namespace br_ufes_inf_prog3_trab20152_dominio{

    Docente::Docente(string nome, string login, string paginaWeb){
        this->nome = nome;
        this->login = login;
        this->paginaWeb = paginaWeb;
    }

    int Docente::getNumDisc(){
        return this->numDisc;
    }

    void Docente::increaseNumDisc(){
        this->numDisc++;
    }

    string Docente::getNome(){
        return this->nome;
    }

    string Docente::getLogin(){
        return this->login;
    }

    string Docente::getPagWeb(){
        return this->paginaWeb;
    }

    void Docente::increasePeriodos(Periodo* p){
        periodos.insert(p);
    }
    int Docente::getNumPeriodosDoc(){
        return periodos.size();
    }

    void Docente::setNumAtiv(int n){
        this->numAtiv = n;
    }

    float Docente::getMediaAtiv(){
        return (float)this->numAtiv/this->numDisc;
    }

    void Docente::increaseNumSinc(){
        this->numSinc++;
    }
    float Docente::getPercentSinc(){
        if(this->numAtiv != 0)
            return (float)this->numSinc/this->numAtiv *100;
        return 0;
    }
    float Docente::getPercentAssin(){
        if(this->numAtiv != 0)
            return 100 - this->getPercentSinc();
        return 0;
    }
} //namespace dominio
