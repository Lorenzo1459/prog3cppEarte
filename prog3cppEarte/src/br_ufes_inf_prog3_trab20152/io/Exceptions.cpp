#include "Exceptions.h"

namespace br_ufes_inf_prog3_trab20152_io {

InconsistenciaException::InconsistenciaException(string motivo) {
	this->motivo = motivo;
}

const char* InconsistenciaException::what() const noexcept {
	return motivo.c_str();
}

} /* namespace br_ufes_inf_prog3_trab20152_io */
