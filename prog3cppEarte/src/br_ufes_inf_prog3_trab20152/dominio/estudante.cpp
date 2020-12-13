#include "estudante.h"

namespace br_ufes_inf_prog3_trab20152_dominio{

    Estudante::Estudante(long mat, string nome){
        this->matricula = mat;
        this->nome = nome;
    }

    Estudante* Estudante::cadastraEstudante(){
        long matricula;
        string nome;
        cout << "Matricula: " << endl;
        cin >> matricula;
        cout << "Nome: " << endl;
        cin.ignore();
        getline(cin,nome);

        Estudante* e = new Estudante(matricula,nome);
        return e;
    }

    long Estudante::getMatricula(){
        return this->matricula;
    }

    string Estudante::getNomeEstudante(){
        return this->nome;
    }

    void Estudante::imprimeEstudante(Estudante* e){
        cout << "    " << e->getMatricula() << endl;
    }

} //namespace dominio

