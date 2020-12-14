#ifndef DISCIPLINA_H_
#define DISCIPLINA_H_

#include <iostream>
#include <string>
#include <vector>
#include "../atividades/atividade.h"
#include "docente.h"
#include "periodo.h"

using namespace std;
using namespace br_ufes_inf_prog3_trab20152_atividade;

namespace br_ufes_inf_prog3_trab20152_dominio{

    class Disciplina{
    string codigo;
    string nome;
    Periodo* periodo;
    Docente* docente;
    vector<Atividade*> atividades;

    public:
        Disciplina(string cdg, string nome, Periodo* p, Docente* d);

        string getCodigo();
        string getNomeDisc();
        Periodo* getPeriodo();
        Docente* getDocente();
        Disciplina* cadastraDisciplina();
        vector<Atividade*> getAtividades();

        void putAtividade(Atividade* ativ);
        void imprimeAtividades(Disciplina* d);
    };
} // namespace dominio

#endif /* DISCIPLINA_H_ */