#include "Escritor_csv.h"

namespace br_ufes_inf_prog3_trab20152_io {
    const string VISAO_GERAL = "1-visao-geral.csv";
	
	Escritor_csv::Escritor_csv(){}
	
	void Escritor_csv::visao_geral(string texto_final){			
		ofstream out(VISAO_GERAL);
	    out << "Periodo;Codigo Disciplina;Disciplina;Docente Responsável;E-mail Docente;Qtd. Estudantes;Qtd. Atividades" << endl;
	    out << texto_final;
        out.close();
	}
/*	
	public void docentes(String nome, Integer num_disc, Integer num_periodos_dif, Float mediaAtiv_Disc,Float percSinc, Float percAssinc, Float mediaNotas, File file2) {		
		int existe = 0;
			
		if(file2.exists()) {
			existe = 1;
		}
		try {
			PrintWriter printwriter = new PrintWriter(new FileOutputStream(file2,true));
			String cabecalho = String.format("Docente;Qtd. Disciplinas;Qtd. Periodos;Média Atividades/Disciplina;%c Síncronas;%c Assíncronas;Média de Notas", 37, 37);
			String format = String.format("%s;%d;%d;%.1f;%d%c;%d%c;%.1f", nome, num_disc, num_periodos_dif, mediaAtiv_Disc, Math.round(percSinc), 37, Math.round(percAssinc), 37, mediaNotas);
			if(existe == 0)
				printwriter.println(cabecalho);
			printwriter.println(format);
			printwriter.flush();			
			printwriter.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}		
	}
	
	public void estudantes(Long mat, String nome, Float mediaDisc_per, Float mediaAv_disc, Float mediaNotas, File file3) {		
		int existe = 0;
				
		if(file3.exists()) {
			existe = 1;
		}
		try {
			PrintWriter printwriter = new PrintWriter(new FileOutputStream(file3,true));
			String cabecalho = String.format("Matrícula;Nome;Média Disciplinas/Período;Média Avaliações/Disciplina;Média Notas Avaliações");
			String format = String.format("%d;%s;%.1f;%.1f;%.1f", mat, nome, mediaDisc_per, mediaAv_disc, mediaNotas);
			if(existe == 0)
				printwriter.println(cabecalho);
			printwriter.println(format);
			printwriter.flush();			
			printwriter.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}		
	}
	
	public void disciplinas(String login, String per, String codigo, String nome, float perSinc,float perAssinc, File file4) {
		int existe = 0;			
		if(file4.exists()) {
			existe = 1;
		}
		try {
			PrintWriter printwriter = new PrintWriter(new FileOutputStream(file4,true));
			String cabecalho = String.format("Docente;Período;Código;Nome;Qtd. Atividades;%c Síncronas;%c Assíncronas;CH;Datas Avaliações",37,37);
			String format = String.format("%s;%s;%s;%s;%d%c;%d%c", login, per, codigo, nome, Math.round(perSinc),37,Math.round(perAssinc),37);
			if(existe == 0)
				printwriter.println(cabecalho);
			printwriter.println(format);
			printwriter.flush();			
			printwriter.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
    */
}
