#ifndef DOCENTE_H_
#define DOCENTE_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace br_ufes_inf_prog3_trab20152_dominio{

    class Docente{
        string nome;
        string login;
        string paginaWeb;

        public:
            Docente(string nome, string login, string paginaWeb);
            Docente* cadastraDocente();
            string getNome();
            string getLogin();
            string getPagWeb();

            void imprimeDocente(Docente* d);
    };

} //namespace dominio

#endif /* DOCENTE_H_ */