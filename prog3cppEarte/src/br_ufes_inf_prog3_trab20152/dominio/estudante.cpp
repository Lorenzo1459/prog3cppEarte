#include "estudante.h"

namespace br_ufes_inf_prog3_trab20152_dominio{

    Estudante::Estudante(long mat, string nome){
        this->matricula = mat;
        this->nome = nome;
    }

    vector<Avaliacao*> Estudante::getAvaliacao(){
        return this->avaliacoes;
    }

    void Estudante::putAvaliacao(Avaliacao* a){
        avaliacoes.push_back(a);
    }

    long Estudante::getMatricula(){
        return this->matricula;
    }

    string Estudante::getNomeEstudante(){
        return this->nome;
    }

    void Estudante::increaseDisc(){
        this->qtDisc++;
    }

    int Estudante::getQtDisc(){
        return this->qtDisc;
    }

    void Estudante::increasePer(string per){
        this->periodos.insert(per);
    }

    int Estudante::getQtPer(){
        return periodos.size();
    }

    float Estudante::getMediaDiscPer(){
        return (float)this->getQtDisc()/this->getQtPer();
    }

    float Estudante::getMediaNota(){
        float soma = 0;
        for(Avaliacao* a : avaliacoes)
            soma += a->getNota();
        if(avaliacoes.size() != 0)
            return soma/avaliacoes.size();
        return 0;
    }

    float Estudante::getMediaAvDisc(){
        return (float)avaliacoes.size()/this->qtDisc;
    }  

} //namespace dominio

