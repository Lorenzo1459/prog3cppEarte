#ifndef DISCIPLINA_H_
#define DISCIPLINA_H_

#include <iostream>
#include <string>
#include <vector>
#include "../atividades/atividade.h"
#include "docente.h"
#include "periodo.h"
#include "estudante.h"

using namespace std;
using namespace br_ufes_inf_prog3_trab20152_atividade;

namespace br_ufes_inf_prog3_trab20152_dominio{

    class Disciplina{
    string codigo;
    string nome;
    Periodo* periodo;
    Docente* docente;
    vector<Atividade*> atividades;
    vector<Estudante*> estudantes;
    float numSinc = 0;
    float numAssinc = 0;

    public:
        Disciplina(string cdg, string nome, Periodo* p, Docente* d);

        string getCodigo();
        string getNomeDisc();
        Periodo* getPeriodo();
        Docente* getDocente();
        Disciplina* cadastraDisciplina();
        vector<Atividade*> getAtividades();
        vector<Estudante*> getEstudantes();
        int getNumAtiv();
        int getNumSinc();
        void increaseNumSin();
        void increaseNumAssinc();
        float getPercentSinc();
        float getPercentAssinc();
        void putAtividade(Atividade* ativ);
        void putEstudante(Estudante* e);
        void imprimeAtividades(Disciplina* d);
    };
} // namespace dominio

#endif /* DISCIPLINA_H_ */