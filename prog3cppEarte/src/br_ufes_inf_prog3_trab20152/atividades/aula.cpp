#include "aula.h"

namespace br_ufes_inf_prog3_trab20152_atividade{

    Aula::Aula(char tipo,bool modelo, string nomeAula, time_t dataAula, string horaAula):
        Atividade(tipo, modelo){
            this->nomeAula = nomeAula;
            this->dataAula = dataAula;
            this->horaAula = horaAula;
    }
    
    time_t Aula::getDataAula(){
        return this->dataAula;
    }

    string Aula::getNomeAula(){
        return this->nomeAula;
    }

    string Aula::getHoraAula(){
        return this->horaAula;
    }
}