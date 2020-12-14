#include "prova.h"

namespace br_ufes_inf_prog3_trab20152_atividade{

    Prova::Prova(char tipo, bool modelo, string nomeProva, time_t dataProva, string horaProva, string conteudoProva):
        Atividade(tipo, modelo){
            this->nomeProva = nomeProva;
            this->dataProva = dataProva;
            this->horaProva = horaProva;
            this->conteudoProva = conteudoProva;
    }
    
    time_t Prova::getDataProva(){
        return this->dataProva;
    }

    string Prova::getNomeProva(){
        return this->nomeProva;
    }

    string Prova::getHoraProva(){
        return this->horaProva;
    }

    string Prova::getConteudoProva(){
        return this->conteudoProva;
    }
}