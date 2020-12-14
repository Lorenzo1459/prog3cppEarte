#include "trabalho.h"

namespace br_ufes_inf_prog3_trab20152_atividade{

    Trabalho::Trabalho(char tipo, bool modelo, string nomeTrabalho, time_t dataTrabalho, string cargaHorariaTrabalho, int qntIntegrantes):
        Atividade(tipo, modelo){
            this->nomeTrabalho = nomeTrabalho;
            this->dataTrabalho = dataTrabalho;
            this->cargaHorariaTrabalho = cargaHorariaTrabalho;
            this->qntIntegrantes = qntIntegrantes;
    }
    
    time_t Trabalho::getDataTrabalho(){
        return this->dataTrabalho;
    }

    string Trabalho::getNomeTrabalho(){
        return this->nomeTrabalho;
    }

    string Trabalho::getCargaHorariaTrabalho(){
        return this->cargaHorariaTrabalho;
    }

    int Trabalho::getQtIntegrantesTrabalho(){
        return this->qntIntegrantes;
    }
}