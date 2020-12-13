/*
 * Leitor.h
 *
 *  Created on: Nov 30, 2015
 *      Author: vitor
 */

#ifndef BR_UFES_INF_PROG3_TRAB20152_IO_LEITOR_H_
#define BR_UFES_INF_PROG3_TRAB20152_IO_LEITOR_H_

#include <ctime>
#include <map>
#include <string>
#include <vector>
#include "../dominio/disciplina.h"
#include "../dominio/docente.h"
#include "../dominio/estudante.h"
#include "../dominio/periodo.h"
#include "../../br_ufes_inf_nemo_cpp_util/DateUtils.h"
#include "../../br_ufes_inf_nemo_cpp_util/NumberUtils.h"
#include "../../br_ufes_inf_nemo_cpp_util/Tokenizer.h"
#include "ConversorCSV.cpp"
#include "Exceptions.h"
using namespace std;
using namespace br_ufes_inf_prog3_trab20152_dominio;
using namespace br_ufes_inf_nemo_cpp_util;

namespace br_ufes_inf_prog3_trab20152_io {

class Leitor {
	map<string, Periodo*> periodos;
	map<string, Docente*> docentes;
	map<string, Disciplina*> disciplinas;
	map<long, Estudante*> estudantes;
	//map<string, Serie*> series;
	//vector<Emprestimo*> emprestimos;

	void lerPeriodos(string& nomeArquivoPeriodos);
	void lerDocente(string& nomeArquivoDocente);
	void lerDisciplina(string& nomeArquivoDisciplina);
	void lerEstudantes(string& nomeArquivoEstudantes);

public:
	Leitor(string nomeArquivoPeriodos, string nomeArquivoDocente, string nomeArquivoDisciplina, string nomeArquivoEstudantes);

	map<string, Periodo*> getPeriodos() const;
	map<string, Docente*> getDocentes() const;
	map<string, Disciplina*> getDisciplinas() const;
	map<long, Estudante*> getEstudantes() const;

	friend class ConversorCSVPeriodo;
	friend class ConversorCSVDocente;
	friend class ConversorCSVDisciplina;
	friend class ConversorCSVEstudante;
};


class ConversorCSVPeriodo: public ConversorCSV<Periodo*> {
public:
	ConversorCSVPeriodo(Leitor* leitor): ConversorCSV<Periodo*>(leitor) { }
	void criarObjetoDeLinhaCSV(vector<string>& dados, vector<Periodo*>& lista) const;
};

class ConversorCSVDocente: public ConversorCSV<Docente*> {
public:
	ConversorCSVDocente(Leitor* leitor): ConversorCSV<Docente*>(leitor) { }
	void criarObjetoDeLinhaCSV(vector<string>& dados, vector<Docente*>& lista) const;
};

class ConversorCSVDisciplina: public ConversorCSV<Disciplina*> {
public:
	ConversorCSVDisciplina(Leitor* leitor): ConversorCSV<Disciplina*>(leitor) { }
	void criarObjetoDeLinhaCSV(vector<string>& dados, vector<Disciplina*>& lista) const;
};

class ConversorCSVEstudante: public ConversorCSV<Estudante*> {
public:
	ConversorCSVEstudante(Leitor* leitor): ConversorCSV<Estudante*>(leitor) { }
	void criarObjetoDeLinhaCSV(vector<string>& dados, vector<Estudante*>& lista) const;
};

} /* namespace br_ufes_inf_prog3_trab20152_io */

#endif /* BR_UFES_INF_PROG3_TRAB20152_IO_LEITOR_H_ */
