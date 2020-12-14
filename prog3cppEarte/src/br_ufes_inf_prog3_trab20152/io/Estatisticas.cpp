/*
#include "Estatisticas.h"

namespace br_ufes_inf_prog3_trab20152_io {

Estatisticas::Estatisticas(const map<string, Periodo*>& periodos, const map<string, Disciplina*>& disciplinas, const map<string, Docente*>& docentes) {
	//horasConsumidas = horasConsumir = 0;

	map<Periodo*, int> qtdPer;
	for (pair<string, Genero*> par : generos) qtdGen.insert(pair<Genero*, int>(par.second, 0));

	map<Serie*, int> qtdSerJa;
	map<Serie*, int> qtdSerA;
	for (pair<string, Serie*> par : series) {
		qtdSerJa.insert(pair<Serie*, int>(par.second, 0));
		qtdSerA.insert(pair<Serie*, int>(par.second, 0));
	}

	for (pair<int, Midia*> par : midias) {
		Midia* midia = par.second;
		if (midia->isConsumiu()) horasConsumidas += midia->calcularHoras();
		if (midia->isDeseja()) horasConsumir += midia->calcularHoras();

		Genero* genero = midia->getGenero();
		map<Genero*, int>::iterator itGen = qtdGen.find(genero);
		if (itGen != qtdGen.end()) itGen->second += 1;

		Serie* serie = midia->getSerie();
		if (serie) {
			if (midia->isConsumiu()) {
				map<Serie*, int>::iterator itJa = qtdSerJa.find(serie);
				if (itJa != qtdSerJa.end()) itJa->second += 1;
			}
			if (midia->isDeseja()) {
				map<Serie*, int>::iterator itA = qtdSerA.find(serie);
				if (itA != qtdSerA.end()) itA->second += 1;
			}
		}
	}

	for (pair<string, Periodo*> par : periodos)
		DisciplinasPorPeriodo.insert(new DisciplinasPorPeriodo(par.second, qtdPer.at(par.second)));

	for (pair<string, Serie*> par : series)
		temporadasPorSerie.insert(new TemporadasPorSerie(par.second, qtdSerJa.at(par.second), qtdSerA.at(par.second)));
}

DisciplinasPorPeriodo::DisciplinasPorPeriodo(Periodo* periodo, int qtd) {
	this->periodos = periodos;
	this->qtd = qtd;
}

bool DisciplinasPorPeriodoComparator::operator()(const DisciplinasPorPeriodo* esq, const DisciplinasPorPeriodo* dir) const {
	int cmp = esq->qtd - dir->qtd;
	if (cmp != 0) return (cmp > 0);
	return (esq != dir) && stringCompare(esq->periodos->getPeriodoString(esq->periodos), dir->periodos->getPeriodoString(dir->periodos));
}

TemporadasPorSerie::TemporadasPorSerie(Serie* serie, int qtdJa, int qtdA) {
	this->serie = serie;
	this->qtdJa = qtdJa;
	this->qtdA = qtdA;
}

bool TemporadasPorSerieComparator::operator()(const TemporadasPorSerie* esq, const TemporadasPorSerie* dir) const {
	return (esq != dir) && stringCompare(esq->serie->getNome(), dir->serie->getNome());
}

} /* namespace br_ufes_inf_prog3_trab20152_io */

