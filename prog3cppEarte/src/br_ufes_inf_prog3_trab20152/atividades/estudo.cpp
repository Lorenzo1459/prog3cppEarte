#include "estudo.h"

namespace br_ufes_inf_prog3_trab20152_atividade{

    Estudo::Estudo(char tipo, bool modelo, string nomeEstudo, string materialEstudo):
        Atividade(tipo, modelo){
            this->nomeEstudo = nomeEstudo;
            this->materialEstudo = materialEstudo;
    }

    string Estudo::getNomeEstudo(){
        return this->nomeEstudo;
    }

    string Estudo::getMaterialEstudo(){
        return this->materialEstudo;
    }
}