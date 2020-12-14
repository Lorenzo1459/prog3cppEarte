#include "atividade.h"

namespace br_ufes_inf_prog3_trab20152_atividade{

    Atividade::Atividade(char tipoAtividade, bool modelo){
        this->tipoAtividade = tipoAtividade;
        this->modelo = modelo;
    }

    char Atividade::getTipoAtividade() const{
        return this->tipoAtividade;
    }

    bool Atividade::ehSincrona() const{
        return this->modelo;
    }

}