/*
#ifndef BR_UFES_INF_PROG3_TRAB20152_IO_ESTATISTICAS_H_
#define BR_UFES_INF_PROG3_TRAB20152_IO_ESTATISTICAS_H_

#include <set>
#include <map>

#include "../dominio/periodo.h"
#include "../dominio/disciplina.h"
#include "../dominio/docente.h"

#include "../../br_ufes_inf_nemo_cpp_util/StringUtils.h"
using namespace std;
using namespace br_ufes_inf_prog3_trab20152_dominio;
using namespace br_ufes_inf_nemo_cpp_util;

namespace br_ufes_inf_prog3_trab20152_io {

class DisciplinasPorPeriodo {
	Periodo* periodos;
	int qtd;

public:
	DisciplinasPorPeriodo(Periodo* periodo, int qtd);

	friend class Escritor;
	friend class Estatisticas;
	friend class DisciplinasPorPeriodoComparator;
};

class DisciplinasPorPeriodoComparator {
public:
	bool operator()(const DisciplinasPorPeriodo* esq, const DisciplinasPorPeriodo* dir) const;
};

class TemporadasPorSerie {
	Serie *serie;
	int qtdJa;
	int qtdA;

public:
	TemporadasPorSerie(Serie* serie, int qtdJa, int qtdA);

	friend class Escritor;
	friend class Estatisticas;
	friend class TemporadasPorSerieComparator;
};

class TemporadasPorSerieComparator {
public:
	bool operator()(const TemporadasPorSerie* esq, const TemporadasPorSerie* dir) const;
};

class Estatisticas {
	int horasConsumidas;
	int horasConsumir;
	set<DisciplinasPorPeriodo*, DisciplinasPorPeriodoComparator> DisciplinasPorPeriodo;
	set<TemporadasPorSerie*, TemporadasPorSerieComparator> temporadasPorSerie;

public:
	Estatisticas(const map<string, Periodo*>& periodos, const map<string, Disciplina*>& disciplinas, const map<string, Docente*>& docentes);

	friend class Escritor;
};



}  namespace br_ufes_inf_prog3_trab20152_io 

#endif /* BR_UFES_INF_PROG3_TRAB20152_IO_ESTATISTICAS_H_ */
