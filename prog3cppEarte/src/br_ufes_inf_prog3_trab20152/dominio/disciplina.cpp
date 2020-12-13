#include "disciplina.h"

namespace br_ufes_inf_prog3_trab20152_dominio{

    Disciplina::Disciplina(string cdg, string nome, string p, string d){
    this->codigo = cdg;
    this->nome = nome;
    this->periodo = p;
    this->docente = d;
}

    string Disciplina::getCodigo(){
        return this->codigo;
    }

    string Disciplina::getNomeDisc(){
        return this->nome;
    }

    string Disciplina::getPeriodo(){
        return this->periodo;
    }

    string Disciplina::getDocente(){
        return this->docente;
    }

    void Disciplina::imprimeDisciplina(Disciplina* d){
        cout << "    " << d->getCodigo() << "-" << endl;
        //periodo
    }
    
} //namespace dominio