#ifndef DISCIPLINA_H_
#define DISCIPLINA_H_

#include <iostream>
#include <string>
#include <vector>

#include "docente.h"
#include "periodo.h"

using namespace std;

namespace br_ufes_inf_prog3_trab20152_dominio{

    class Disciplina{
    string codigo;
    string nome;
    string periodo;
    string docente;
    //vector<Atividade*>* atividades;
    //vector<Estudante*>* estudantes;

    public:
        Disciplina(string cdg, string nome, string p, string d);

        string getCodigo();
        string getNomeDisc();
        string getPeriodo();
        string getDocente();
        Disciplina* cadastraDisciplina();

        void imprimeDisciplina(Disciplina* d);
    };
} // namespace dominio

#endif /* DISCIPLINA_H_ */