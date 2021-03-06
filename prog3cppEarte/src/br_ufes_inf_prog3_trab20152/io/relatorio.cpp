#include "relatorio.h"

namespace br_ufes_inf_prog3_trab20152_io {

Relatorio::Relatorio(){}

void Relatorio::relatorioDisc(map<string, Disciplina*> mapa, map<string, Periodo*> per) {		
		Escritor_csv* writer = new Escritor_csv();
		string texto_final;
        for(auto const& periodo : per)
        {
            for(auto const& aux : mapa) {
                if(aux.second->getPeriodo()->getPeriodoString().compare(periodo.first) == 0) {
                    string periodo = aux.second->getPeriodo()->getPeriodoString();
					Tokenizer tok(aux.second->getCodigo(),'-');
					vector<string> cods = tok.remaining();
                    string cod = cods[0];
                    string nome = aux.second->getNomeDisc();
                    string docente = aux.second->getDocente()->getNome();
                    string email = aux.second->getDocente()->getLogin() + "@ufes.br";
                    int num_estud = aux.second->getEstudantes().size();
                    int num_ativs = aux.second->getNumAtiv();	
                    texto_final += periodo + ";" + cod + ";" + nome + ";" + docente + ";" + email + ";" + to_string(num_estud) + ";" + to_string(num_ativs) + "\n";
                }			
            }	
        }
		writer->visao_geral(texto_final);
}
	
void Relatorio::relatorioDocente(map<string, Docente*> mapa) {	
			Escritor_csv* writer = new Escritor_csv();
			string texto_final;
			//Z-A nome docente
			for(auto const& aux : mapa) {
				stringstream percentSinc, percentAssinc, mediaAtiv_Disc, mediaNotas;
				string nome = aux.second->getNome();
				string num_disc = to_string(aux.second->getNumDisc());
				string num_periodos_dif = to_string(aux.second->getNumPeriodosDoc());
				percentSinc << fixed << setprecision(0) << aux.second->getPercentSinc();
				percentAssinc << fixed << setprecision(0) << aux.second->getPercentAssin();
				mediaAtiv_Disc << fixed << setprecision(1) << aux.second->getMediaAtiv();
				mediaNotas << fixed << setprecision(1) << aux.second->getMediaNotasDocente();
				texto_final += nome + ";" + num_disc + ";" + num_periodos_dif + ";" + mediaAtiv_Disc.str() + ";" + percentSinc.str() + "%" + ";" + percentAssinc.str() + "%" + ";" + mediaNotas.str() + "\n";
			}			
			writer->docentes(texto_final);
	}	
	
	void Relatorio::relatorioEstudante(map<long, Estudante*> mapa) {
		Escritor_csv* writer = new Escritor_csv();
		string texto_final;
		//99-0 avaliações && A-Z nome
		
		for(auto const& aux : mapa) {
			stringstream mediaDisc_per,mediaAv_disc,mediaNotas;
			string mat = to_string(aux.second->getMatricula());
			string nome = aux.second->getNomeEstudante();
			mediaDisc_per << fixed << setprecision(1) << aux.second->getMediaDiscPer();
			mediaAv_disc << fixed << setprecision(1) << aux.second->getMediaAvDisc();	
			mediaNotas << fixed << setprecision(1) << aux.second->getMediaNota();
			texto_final += mat + ";" + nome + ";" + mediaDisc_per.str() + ";" + mediaAv_disc.str() + ";" + mediaNotas.str() + "\n";
		}
		writer->estudantes(texto_final);
	}
	
	void Relatorio::relatorioDiscDocente(map<string,Docente*> doc,map<string, Disciplina*> mapa) {
		Escritor_csv* writer = new Escritor_csv();
		string texto_final;
		for(auto const& aux : mapa) {
			for(auto const& docente : doc){
				if(aux.second->getDocente()->getLogin().compare(docente.first) == 0){
					stringstream percentSinc, percentAssinc;
					string docente = aux.second->getDocente()->getLogin();
					string periodo = aux.second->getPeriodo()->getPeriodoString();
					Tokenizer tok(aux.second->getCodigo(),'-');
					vector<string> cods = tok.remaining();
					string codigo = cods[0];
					string disc = aux.second->getNomeDisc();
					percentSinc << fixed << setprecision(0) << aux.second->getPercentSinc();
					percentAssinc << fixed << setprecision(0) << aux.second->getPercentAssinc();
					texto_final += docente + ";" + periodo + ";" + codigo + ";" + disc + ";" + percentSinc.str() + "%" + ";" + percentAssinc.str() + "%" + "\n";
				}
			}
		}
		writer->disciplinas(texto_final);
	}
}