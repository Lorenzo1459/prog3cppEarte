#include "matricula.h"

namespace br_ufes_inf_prog3_trab20152_dominio{

    Matricula::Matricula(Disciplina* disc, Estudante* e){
        this->disc = disc;
        this->e = e;
    }

    Disciplina* Matricula::getDisciplina() const{
        return this->disc;
    }

    Estudante* Matricula::getEstudante() const{
        return this->e;
    }

} /*namespace br_ufes_inf_prog3_trab20152_dominio*/