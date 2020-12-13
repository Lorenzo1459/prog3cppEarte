#include "docente.h"

namespace br_ufes_inf_prog3_trab20152_dominio{

    Docente::Docente(string nome, string login, string paginaWeb){
        this->nome = nome;
        this->login = login;
        this->paginaWeb = paginaWeb;
    }

    Docente* Docente::cadastraDocente(){
        string nome;
        string login;
        string pgWeb;
        cout << "Nome: " << endl;
        cin.ignore();
        getline(cin,nome);
        cout << "Login: " << endl;
        cin >> login;
        cout << "Pagina Web: " << endl;
        cin >> pgWeb;
        Docente* d = new Docente(nome,login,pgWeb);
        return d;
    }

    string Docente::getNome(){
        return this->nome;
    }

    string Docente::getLogin(){
        return this->login;
    }

    string Docente::getPagWeb(){
        return this->paginaWeb;
    }

    void Docente::imprimeDocente(Docente* d){
        cout << "    " << d->getNome() << endl;
        cout << "    " << d->getLogin() << endl;
        cout << "    " << d->getPagWeb() << endl;
        cout << "-----------------------------------" << endl;
    }
} //namespace dominio
