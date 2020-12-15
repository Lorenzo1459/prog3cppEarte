#include "disciplina.h"

namespace br_ufes_inf_prog3_trab20152_dominio{

    Disciplina::Disciplina(string cdg, string nome, Periodo* p, Docente* d){
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

    Periodo* Disciplina::getPeriodo(){
        return this->periodo;
    }

    Docente* Disciplina::getDocente(){
        return this->docente;
    }

    void Disciplina::putAtividade(Atividade* ativ){
        atividades.push_back(ativ);
    }

    void Disciplina::putEstudante(Estudante* e){
        estudantes.push_back(e);
    }

    vector<Estudante*> Disciplina::getEstudantes(){
        return this->estudantes;
    }

    vector<Atividade*> Disciplina::getAtividades(){
        return this->atividades;
    }

    int Disciplina::getNumAtiv(){
        return atividades.size();
    }

    void Disciplina::imprimeAtividades(Disciplina* d){
        for(int i=0; i < d->atividades.size(); i++)
            cout << d->getAtividades().at(i)->getTipoAtividade() << endl;
    }
  
} //namespace dominio