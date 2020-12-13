/*
 * Estatisticas.h
 *
 *  Created on: Dec 2, 2015
 *      Author: vitor
 

#ifndef BR_UFES_INF_PROG3_TRAB20152_IO_ESTATISTICAS_H_
#define BR_UFES_INF_PROG3_TRAB20152_IO_ESTATISTICAS_H_

#include <set>
#include <map>

#include "../dominio/Genero.h"
#include "../dominio/Midia.h"
#include "../dominio/Serie.h"

#include "../../br_ufes_inf_nemo_cpp_util/StringUtils.h"
using namespace std;
using namespace br_ufes_inf_prog3_trab20152_dominio;
using namespace br_ufes_inf_nemo_cpp_util;

namespace br_ufes_inf_prog3_trab20152_io {

class MidiasPorGenero {
	Genero* genero;
	int qtd;

public:
	MidiasPorGenero(Genero* genero, int qtd);

	friend class Escritor;
	friend class Estatisticas;
	friend class MidiasPorGeneroComparator;
};

class MidiasPorGeneroComparator {
public:
	bool operator()(const MidiasPorGenero* esq, const MidiasPorGenero* dir) const;
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
	set<MidiasPorGenero*, MidiasPorGeneroComparator> midiasPorGenero;
	set<TemporadasPorSerie*, TemporadasPorSerieComparator> temporadasPorSerie;

public:
	Estatisticas(const map<string, Genero*>& generos, const map<int, Midia*>& midias, const map<string, Serie*>& series);

	friend class Escritor;
};



}  namespace br_ufes_inf_prog3_trab20152_io 

#endif  BR_UFES_INF_PROG3_TRAB20152_IO_ESTATISTICAS_H_ */
