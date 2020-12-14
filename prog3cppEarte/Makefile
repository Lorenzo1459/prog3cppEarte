all: main

run:
	@./main -p periodos.csv -d docentes.csv -o disciplinas.csv -e estudantes.csv -m matriculas.csv -a atividades.csv

clean:
	@rm -rf bin main

#
# Classes do nemo-utils-cpp:
#
PACOTE_UTILS=bin/br_ufes_inf_nemo_cpp_util/DateUtils.o bin/br_ufes_inf_nemo_cpp_util/NumberUtils.o bin/br_ufes_inf_nemo_cpp_util/NumPunctPTBR.o bin/br_ufes_inf_nemo_cpp_util/StringUtils.o bin/br_ufes_inf_nemo_cpp_util/Tokenizer.o

bin/br_ufes_inf_nemo_cpp_util:
	mkdir -p bin/br_ufes_inf_nemo_cpp_util

bin/br_ufes_inf_nemo_cpp_util/DateUtils.o: bin/br_ufes_inf_nemo_cpp_util src/br_ufes_inf_nemo_cpp_util/DateUtils.cpp src/br_ufes_inf_nemo_cpp_util/DateUtils.h
	g++ -std=c++11 -o bin/br_ufes_inf_nemo_cpp_util/DateUtils.o -c src/br_ufes_inf_nemo_cpp_util/DateUtils.cpp

bin/br_ufes_inf_nemo_cpp_util/NumberUtils.o: bin/br_ufes_inf_nemo_cpp_util src/br_ufes_inf_nemo_cpp_util/NumberUtils.cpp src/br_ufes_inf_nemo_cpp_util/NumberUtils.h src/br_ufes_inf_nemo_cpp_util/NumPunctPTBR.h
	g++ -std=c++11 -o bin/br_ufes_inf_nemo_cpp_util/NumberUtils.o -c src/br_ufes_inf_nemo_cpp_util/NumberUtils.cpp

bin/br_ufes_inf_nemo_cpp_util/NumPunctPTBR.o: bin/br_ufes_inf_nemo_cpp_util src/br_ufes_inf_nemo_cpp_util/NumPunctPTBR.cpp src/br_ufes_inf_nemo_cpp_util/NumPunctPTBR.h
	g++ -std=c++11 -o bin/br_ufes_inf_nemo_cpp_util/NumPunctPTBR.o -c src/br_ufes_inf_nemo_cpp_util/NumPunctPTBR.cpp

bin/br_ufes_inf_nemo_cpp_util/StringUtils.o: bin/br_ufes_inf_nemo_cpp_util src/br_ufes_inf_nemo_cpp_util/StringUtils.cpp src/br_ufes_inf_nemo_cpp_util/StringUtils.h
	g++ -std=c++11 -o bin/br_ufes_inf_nemo_cpp_util/StringUtils.o -c src/br_ufes_inf_nemo_cpp_util/StringUtils.cpp

bin/br_ufes_inf_nemo_cpp_util/Tokenizer.o: bin/br_ufes_inf_nemo_cpp_util src/br_ufes_inf_nemo_cpp_util/Tokenizer.cpp src/br_ufes_inf_nemo_cpp_util/Tokenizer.h
	g++ -std=c++11 -o bin/br_ufes_inf_nemo_cpp_util/Tokenizer.o -c src/br_ufes_inf_nemo_cpp_util/Tokenizer.cpp

#
# Classes de atividades:
#
PACOTE_ATIVIDADES=bin/br_ufes_inf_prog3_trab20152/atividades/atividade.o bin/br_ufes_inf_prog3_trab20152/atividades/aula.o bin/br_ufes_inf_prog3_trab20152/atividades/trabalho.o bin/br_ufes_inf_prog3_trab20152/atividades/prova.o bin/br_ufes_inf_prog3_trab20152/atividades/estudo.o

bin/br_ufes_inf_prog3_trab20152/atividades:
	mkdir -p bin/br_ufes_inf_prog3_trab20152/atividades

bin/br_ufes_inf_prog3_trab20152/atividades/aula.o: bin/br_ufes_inf_prog3_trab20152/atividades src/br_ufes_inf_prog3_trab20152/atividades/aula.cpp src/br_ufes_inf_prog3_trab20152/atividades/aula.h src/br_ufes_inf_prog3_trab20152/atividades/atividade.h
	g++ -std=c++11 -o bin/br_ufes_inf_prog3_trab20152/atividades/aula.o -c src/br_ufes_inf_prog3_trab20152/atividades/aula.cpp

bin/br_ufes_inf_prog3_trab20152/atividades/atividade.o: bin/br_ufes_inf_prog3_trab20152/atividades src/br_ufes_inf_prog3_trab20152/atividades/atividade.cpp src/br_ufes_inf_prog3_trab20152/atividades/atividade.h
	g++ -std=c++11 -o bin/br_ufes_inf_prog3_trab20152/atividades/atividade.o -c src/br_ufes_inf_prog3_trab20152/atividades/atividade.cpp

bin/br_ufes_inf_prog3_trab20152/atividades/estudo.o: bin/br_ufes_inf_prog3_trab20152/atividades src/br_ufes_inf_prog3_trab20152/atividades/estudo.cpp src/br_ufes_inf_prog3_trab20152/atividades/estudo.h src/br_ufes_inf_prog3_trab20152/atividades/atividade.h
	g++ -std=c++11 -o bin/br_ufes_inf_prog3_trab20152/atividades/estudo.o -c src/br_ufes_inf_prog3_trab20152/atividades/estudo.cpp

bin/br_ufes_inf_prog3_trab20152/atividades/prova.o: bin/br_ufes_inf_prog3_trab20152/atividades src/br_ufes_inf_prog3_trab20152/atividades/prova.cpp src/br_ufes_inf_prog3_trab20152/atividades/prova.h src/br_ufes_inf_prog3_trab20152/atividades/atividade.h
	g++ -std=c++11 -o bin/br_ufes_inf_prog3_trab20152/atividades/prova.o -c src/br_ufes_inf_prog3_trab20152/atividades/prova.cpp

bin/br_ufes_inf_prog3_trab20152/atividades/trabalho.o: bin/br_ufes_inf_prog3_trab20152/atividades src/br_ufes_inf_prog3_trab20152/atividades/trabalho.cpp src/br_ufes_inf_prog3_trab20152/atividades/trabalho.h src/br_ufes_inf_prog3_trab20152/atividades/atividade.h
	g++ -std=c++11 -o bin/br_ufes_inf_prog3_trab20152/atividades/trabalho.o -c src/br_ufes_inf_prog3_trab20152/atividades/trabalho.cpp

#
# Classes de domínio:
#
PACOTE_DOMINIO=bin/br_ufes_inf_prog3_trab20152/dominio/Estudante.o bin/br_ufes_inf_prog3_trab20152/dominio/Periodo.o bin/br_ufes_inf_prog3_trab20152/dominio/Disciplina.o bin/br_ufes_inf_prog3_trab20152/dominio/Docente.o bin/br_ufes_inf_prog3_trab20152/dominio/Matricula.o

bin/br_ufes_inf_prog3_trab20152/dominio:
	mkdir -p bin/br_ufes_inf_prog3_trab20152/dominio

bin/br_ufes_inf_prog3_trab20152/dominio/Estudante.o: bin/br_ufes_inf_prog3_trab20152/dominio src/br_ufes_inf_prog3_trab20152/dominio/Estudante.cpp src/br_ufes_inf_prog3_trab20152/dominio/Estudante.h src/br_ufes_inf_prog3_trab20152/dominio/Disciplina.h
	g++ -std=c++11 -o bin/br_ufes_inf_prog3_trab20152/dominio/Estudante.o -c src/br_ufes_inf_prog3_trab20152/dominio/Estudante.cpp

bin/br_ufes_inf_prog3_trab20152/dominio/Periodo.o: bin/br_ufes_inf_prog3_trab20152/dominio src/br_ufes_inf_prog3_trab20152/dominio/Periodo.cpp src/br_ufes_inf_prog3_trab20152/dominio/Periodo.h
	g++ -std=c++11 -o bin/br_ufes_inf_prog3_trab20152/dominio/Periodo.o -c src/br_ufes_inf_prog3_trab20152/dominio/Periodo.cpp

bin/br_ufes_inf_prog3_trab20152/dominio/Disciplina.o: bin/br_ufes_inf_prog3_trab20152/dominio src/br_ufes_inf_prog3_trab20152/dominio/Disciplina.cpp src/br_ufes_inf_prog3_trab20152/dominio/Disciplina.h src/br_ufes_inf_prog3_trab20152/dominio/Periodo.h src/br_ufes_inf_prog3_trab20152/dominio/Docente.h src/br_ufes_inf_prog3_trab20152/atividades/atividade.h
	g++ -std=c++11 -o bin/br_ufes_inf_prog3_trab20152/dominio/Disciplina.o -c src/br_ufes_inf_prog3_trab20152/dominio/Disciplina.cpp

bin/br_ufes_inf_prog3_trab20152/dominio/Matricula.o: bin/br_ufes_inf_prog3_trab20152/dominio src/br_ufes_inf_prog3_trab20152/dominio/Matricula.cpp src/br_ufes_inf_prog3_trab20152/dominio/Matricula.h src/br_ufes_inf_prog3_trab20152/dominio/Disciplina.h src/br_ufes_inf_prog3_trab20152/dominio/Estudante.h 
	g++ -std=c++11 -o bin/br_ufes_inf_prog3_trab20152/dominio/Matricula.o -c src/br_ufes_inf_prog3_trab20152/dominio/Matricula.cpp
	
bin/br_ufes_inf_prog3_trab20152/dominio/Docente.o: bin/br_ufes_inf_prog3_trab20152/dominio src/br_ufes_inf_prog3_trab20152/dominio/Docente.cpp src/br_ufes_inf_prog3_trab20152/dominio/Docente.h
	g++ -std=c++11 -o bin/br_ufes_inf_prog3_trab20152/dominio/Docente.o -c src/br_ufes_inf_prog3_trab20152/dominio/Docente.cpp

#
# Classes de I/O:
#
PACOTE_IO=bin/br_ufes_inf_prog3_trab20152/io/Escritor.o bin/br_ufes_inf_prog3_trab20152/io/Exceptions.o bin/br_ufes_inf_prog3_trab20152/io/Leitor.o bin/br_ufes_inf_prog3_trab20152/io/ConversorCSV.o

bin/br_ufes_inf_prog3_trab20152/io:
	mkdir -p bin/br_ufes_inf_prog3_trab20152/io
	
bin/br_ufes_inf_prog3_trab20152/io/ConversorCSV.o: src/br_ufes_inf_prog3_trab20152/io/ConversorCSV.cpp
	g++ -std=c++11 -o bin/br_ufes_inf_prog3_trab20152/io/ConversorCSV.o -c src/br_ufes_inf_prog3_trab20152/io/ConversorCSV.cpp

bin/br_ufes_inf_prog3_trab20152/io/Escritor.o: bin/br_ufes_inf_prog3_trab20152/io src/br_ufes_inf_prog3_trab20152/io/Escritor.cpp src/br_ufes_inf_prog3_trab20152/io/Escritor.h src/br_ufes_inf_nemo_cpp_util/DateUtils.h src/br_ufes_inf_nemo_cpp_util/NumberUtils.h
	g++ -std=c++11 -o bin/br_ufes_inf_prog3_trab20152/io/Escritor.o -c src/br_ufes_inf_prog3_trab20152/io/Escritor.cpp

#bin/br_ufes_inf_prog3_trab20152/io/Estatisticas.o: bin/br_ufes_inf_prog3_trab20152/io src/br_ufes_inf_prog3_trab20152/io/Estatisticas.cpp src/br_ufes_inf_prog3_trab20152/io/Estatisticas.h src/br_ufes_inf_prog3_trab20152/dominio/Periodo.h src/br_ufes_inf_prog3_trab20152/dominio/Disciplina.h
#	g++ -std=c++11 -o bin/br_ufes_inf_prog3_trab20152/io/Estatisticas.o -c src/br_ufes_inf_prog3_trab20152/io/Estatisticas.cpp

bin/br_ufes_inf_prog3_trab20152/io/Exceptions.o: bin/br_ufes_inf_prog3_trab20152/io src/br_ufes_inf_prog3_trab20152/io/Exceptions.cpp src/br_ufes_inf_prog3_trab20152/io/Exceptions.h 
	g++ -std=c++11 -o bin/br_ufes_inf_prog3_trab20152/io/Exceptions.o -c src/br_ufes_inf_prog3_trab20152/io/Exceptions.cpp

bin/br_ufes_inf_prog3_trab20152/io/Leitor.o: bin/br_ufes_inf_prog3_trab20152/io src/br_ufes_inf_prog3_trab20152/io/Leitor.cpp src/br_ufes_inf_prog3_trab20152/io/Leitor.h src/br_ufes_inf_prog3_trab20152/io/ConversorCSV.cpp src/br_ufes_inf_prog3_trab20152/dominio/Estudante.h src/br_ufes_inf_prog3_trab20152/dominio/Matricula.h src/br_ufes_inf_prog3_trab20152/dominio/Periodo.h src/br_ufes_inf_prog3_trab20152/dominio/Disciplina.h src/br_ufes_inf_prog3_trab20152/dominio/Docente.h src/br_ufes_inf_nemo_cpp_util/DateUtils.h src/br_ufes_inf_nemo_cpp_util/NumberUtils.h src/br_ufes_inf_nemo_cpp_util/Tokenizer.h src/br_ufes_inf_prog3_trab20152/atividades/aula.h src/br_ufes_inf_prog3_trab20152/atividades/prova.h src/br_ufes_inf_prog3_trab20152/atividades/estudo.h src/br_ufes_inf_prog3_trab20152/atividades/trabalho.h
	g++ -std=c++11 -o bin/br_ufes_inf_prog3_trab20152/io/Leitor.o -c src/br_ufes_inf_prog3_trab20152/io/Leitor.cpp	

#
# Aplicação e programa principal:
#
bin/br_ufes_inf_prog3_trab20152:
	mkdir -p bin/br_ufes_inf_prog3_trab20152

bin/br_ufes_inf_prog3_trab20152/AplInveMid.o: bin/br_ufes_inf_prog3_trab20152 src/br_ufes_inf_prog3_trab20152/AplInveMid.cpp src/br_ufes_inf_prog3_trab20152/AplInveMid.h src/br_ufes_inf_prog3_trab20152/io/Escritor.h src/br_ufes_inf_prog3_trab20152/io/Leitor.h
	g++ -std=c++11 -o bin/br_ufes_inf_prog3_trab20152/AplInveMid.o -c src/br_ufes_inf_prog3_trab20152/AplInveMid.cpp

main: ${PACOTE_UTILS} ${PACOTE_ATIVIDADES} ${PACOTE_DOMINIO} ${PACOTE_IO} src/br_ufes_inf_prog3_trab20152/AplInveMid.h bin/br_ufes_inf_prog3_trab20152/AplInveMid.o src/main.cpp
	g++ -std=c++11 -o main src/main.cpp ${PACOTE_UTILS} ${PACOTE_ATIVIDADES} ${PACOTE_DOMINIO} ${PACOTE_IO} bin/br_ufes_inf_prog3_trab20152/AplInveMid.o