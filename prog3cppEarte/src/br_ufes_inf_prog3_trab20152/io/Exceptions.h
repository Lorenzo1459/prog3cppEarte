#ifndef BR_UFES_INF_PROG3_TRAB20152_IO_EXCEPTIONS_H_
#define BR_UFES_INF_PROG3_TRAB20152_IO_EXCEPTIONS_H_

#include <exception>
#include <string>
using namespace std;

namespace br_ufes_inf_prog3_trab20152_io {

class InconsistenciaException: public exception {
	string motivo;

public:
	InconsistenciaException(string motivo);

	virtual const char* what() const noexcept;
};

class FormatacaoException: public exception { };

class IOException: public exception { };

} /* namespace br_ufes_inf_prog3_trab20152_io */

#endif /* BR_UFES_INF_PROG3_TRAB20152_IO_EXCEPTIONS_H_ */
