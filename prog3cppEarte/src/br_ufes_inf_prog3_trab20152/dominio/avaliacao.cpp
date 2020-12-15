#include "avaliacao.h"

namespace br_ufes_inf_prog3_trab20152_dominio{

    Avaliacao::Avaliacao(float nota){
        this->nota = nota;
    }

    float Avaliacao::getNota(){
        return this->nota;
    }
}