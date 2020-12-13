/*
 * ConversorCSV.h
 *
 *  Created on: Nov 30, 2015
 *      Author: vitor
 */

#ifndef BR_UFES_INF_PROG3_TRAB20152_IO_CONVERSORCSV_CPP_
#define BR_UFES_INF_PROG3_TRAB20152_IO_CONVERSORCSV_CPP_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../../br_ufes_inf_nemo_cpp_util/StringUtils.h"
#include "../../br_ufes_inf_nemo_cpp_util/Tokenizer.h"
#include "Exceptions.h"
using namespace std;
using namespace br_ufes_inf_nemo_cpp_util;

namespace br_ufes_inf_prog3_trab20152_io {

class Leitor;

template <class T>
class ConversorCSV {
protected:
	Leitor* leitor;

public:
	ConversorCSV(Leitor* leitor) { this->leitor = leitor; }
	virtual ~ConversorCSV() { }

	virtual void lerArquivo(string nomeArquivo, vector<T>& lista);
	virtual void criarObjetoDeLinhaCSV(vector<string>& dados, vector<T>& lista) const = 0;
};

template <class T>
void ConversorCSV<T>::lerArquivo(string nomeArquivo, vector<T>& lista) {

	ifstream in(nomeArquivo);
	if (! in.good()) {
		in.close();
		throw IOException();
	}
	string linha;
	getline(in, linha);
	while (getline(in, linha)) {
		Tokenizer tok(linha, ';');
		vector<string> vec = tok.remaining();
		for (int i = 0; i < vec.size(); i++) vec[i] = trim(vec[i]);
		criarObjetoDeLinhaCSV(vec, lista);
	}
	in.close();
}

} /* namespace br_ufes_inf_prog3_trab20152_io */

#endif /* BR_UFES_INF_PROG3_TRAB20152_IO_CONVERSORCSV_CPP_ */
