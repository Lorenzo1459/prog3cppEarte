#include "Escritor_csv.h"

namespace br_ufes_inf_prog3_trab20152_io {
    const string VISAO_GERAL = "1-visao-geral.csv";
	const string DOCENTES = "2-docentes.csv";
	const string ESTUDANTES = "3-estudantes.csv";
	const string DISCIPLINAS = "4-disciplinas.csv";
	
	Escritor_csv::Escritor_csv(){}
	
	void Escritor_csv::visao_geral(string texto_final){			
		ofstream out(VISAO_GERAL);
	    out << "Periodo;Codigo Disciplina;Disciplina;Docente Responsável;E-mail Docente;Qtd. Estudantes;Qtd. Atividades" << endl;
	    out << texto_final;
        out.close();
	}

	void Escritor_csv::docentes(string texto_final){			
		ofstream out(DOCENTES);
	    out << "Docente;Qtd. Disciplinas;Qtd. Períodos;Média Atividades/Disciplina;% Síncronas;% Assíncronas;Média de Notas" << endl;
	    out << texto_final;
        out.close();
	}

	void Escritor_csv::estudantes(string texto_final){			
		ofstream out(ESTUDANTES);
	    out << "Matrícula;Nome;Média Disciplinas/Período;Média Avaliações/Disciplina;Média Notas Avaliações" << endl;
	    out << texto_final;
        out.close();
	}

	void Escritor_csv::disciplinas(string texto_final){			
		ofstream out(DISCIPLINAS);
	    out << "Docente;Período;Código;Nome;Qtd. Atividades;% Síncronas;% Assíncronas;CH;Datas Avaliações" << endl;
	    out << texto_final;
        out.close();
	}
}
