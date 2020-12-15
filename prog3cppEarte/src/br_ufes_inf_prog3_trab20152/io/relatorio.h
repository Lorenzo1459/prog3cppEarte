#ifndef BR_UFES_INF_PROG3_TRAB20152_IO_ESTATISTICAS_H_
#define BR_UFES_INF_PROG3_TRAB20152_IO_ESTATISTICAS_H_

#include <set>
#include <map>
#include <string>
#include <iostream>

#include "../dominio/periodo.h"
#include "../dominio/disciplina.h"
#include "../dominio/docente.h"
#include "../dominio/estudante.h"
#include "../dominio/avaliacao.h"
#include "Escritor_csv.h"

#include "../../br_ufes_inf_nemo_cpp_util/StringUtils.h"
using namespace std;
using namespace br_ufes_inf_prog3_trab20152_dominio;
using namespace br_ufes_inf_nemo_cpp_util;

namespace br_ufes_inf_prog3_trab20152_io {
    class Relatorio{
        public:
            Relatorio();
            void relatorioDisc(map<string, Disciplina*> mapa, map<string, Periodo*> per);
            void relatorioDocente(map<string, Docente*> mapa);
            void relatorioEstudante(map<long, Estudante*> mapa);
            void relatorioDiscDocente(map<string, Docente*> doc,map<string, Disciplina*> mapa);
    };
}

#endif