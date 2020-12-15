#include "avaliacao.h"

namespace br_ufes_inf_prog3_trab20152_dominio{

    Avaliacao::Avaliacao(float nota, Atividade* a){
        this->nota = nota;
        this->a = a;
    }

    float Avaliacao::getNota(){
        return this->nota;
    }

    Atividade* Avaliacao::getAtividade(){
        return this->a;
    }
}