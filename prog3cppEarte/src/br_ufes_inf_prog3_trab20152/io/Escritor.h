/*
#ifndef BR_UFES_INF_PROG3_TRAB20152_IO_ESCRITOR_H_
#define BR_UFES_INF_PROG3_TRAB20152_IO_ESCRITOR_H_

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

#include "Estatisticas.h"
#include "../dominio/Emprestimo.h"
#include "../dominio/periodo.h"
#include "../dominio/docente.h"
#include "../dominio/disciplina.h"
#include "../dominio/estudante.h"

#include "../../br_ufes_inf_nemo_cpp_util/DateUtils.h"
#include "../../br_ufes_inf_nemo_cpp_util/NumberUtils.h"
using namespace std;
using namespace br_ufes_inf_prog3_trab20152_dominio;
using namespace br_ufes_inf_nemo_cpp_util;


namespace br_ufes_inf_prog3_trab20152_io {

class Escritor {
public:
	void escreverRelatorioEstatisticas(Estatisticas& stats) const;
	void escreverRelatorioDisciplinaPorPeriodo(DisciplinasPorPeriodo& mpp) const;
	void escreverRelatorioDocente(vector<Docente*> docentes) const;
	void escreverRelatorioEstudante(vector<Estudante*> estudantes) const;
};

}  namespace br_ufes_inf_prog3_trab20152_io 

#endif /* BR_UFES_INF_PROG3_TRAB20152_IO_ESCRITOR_H_ */
