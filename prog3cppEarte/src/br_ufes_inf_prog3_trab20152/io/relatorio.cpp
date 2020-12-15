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
                    string cod = aux.second->getCodigo();					
                    string nome = aux.second->getNomeDisc();
                    string docente = aux.second->getDocente()->getNome();
                    string email = aux.second->getDocente()->getLogin() + "@ufes.br";
                    int num_estud = aux.second->getEstudantes().size();
                    int num_ativs = aux.second->getNumAtiv();	
                    texto_final += periodo + ";" + cod + ";" + nome + ";" + docente + ";" + email + ";" + to_string(num_estud) + ";" + to_string(num_ativs) + ";" + "\n";
                }			
            }	
        }
		writer->visao_geral(texto_final);
}
/*	
void Relatorio::relatorioDocente(map<string, Docente*> mapa, File file2) {	
			//Escritor_csv writer = new Escritor_csv();
			//Z-A nome docente
			
			for(auto const& aux : mapa) {		
				string nome = aux.getValue().getNomeDocente();
				int num_disc = aux.getValue().getNumDisc();
				int num_periodos_dif = aux.getValue().contaPeriodosDif();
				float percentSinc = aux.getValue().percentSinc();
				float percentAssinc = aux.getValue().percentAssinc();
				float mediaAtiv_Disc = aux.getValue().getAtivPorDisc();
				float mediaNotas = aux.getValue().getMediaNotasDocente();
								
				writer.docentes(nome, num_disc, num_periodos_dif, mediaAtiv_Disc, percentSinc, percentAssinc, mediaNotas, file2);
			}			
	}	
	
	public void relatorioEstudante(Map<Long, Estudante> mapa, File file3) {
		Escritor_csv writer = new Escritor_csv();
		//99-0 avaliações && A-Z nome
		
		for(Map.Entry<Long, Estudante> aux : mapa.entrySet()) {
			Long mat = aux.getValue().getMatricula();
			String nome = aux.getValue().getNomeEstudante();
			Float mediaDisc_per = aux.getValue().mediaDiscPeriodo();
			Float mediaAv_disc = aux.getValue().getQtAvalicaoPorDisc(aux.getValue());
			Float mediaNotas = aux.getValue().mediaNotasAluno(aux.getValue());
						
			writer.estudantes(mat, nome, mediaDisc_per, mediaAv_disc, mediaNotas, file3);
		}
	}
	
	public void relatorioDiscDocente(Docente d,Map<String, Disciplina> mapa, File file4) {
		Escritor_csv writer = new Escritor_csv();
		for(Map.Entry<String, Disciplina> aux : mapa.entrySet()) {
			if(aux.getValue().getDocenteDisc().getLogin().equals(d.getLogin()))
			{
				String docente = aux.getValue().getDocenteDisc().getLogin();
				String periodo = aux.getValue().getPeriodoDisc().getNomePeriodo();
				String codigo = aux.getValue().getCodigo();
				String disc = aux.getValue().getNomediscip();
				float percentSinc = aux.getValue().getPerSinc();
				float percentAssinc = aux.getValue().getPerAssinc();
				
				writer.disciplinas(docente,periodo,codigo,disc,percentSinc,percentAssinc,file4);
			}
		}
	}
*/
}