#include "../br_ufes_inf_nemo_cpp_util/NumPunctPTBR.h"

namespace br_ufes_inf_nemo_cpp_util {

/* In pt-BR, integer and decimal parts of decimal numbers are separated with a ',': e.g., 3,14. */
char NumPunctPTBR::do_decimal_point() const {
	return ',';
}

/* This locale uses grouping (at every 3 digits). */
string NumPunctPTBR::do_grouping() const {
	return "\03";
}

/* In pt-BR, grouping of thousands are separated with a '.': e.g., 1.000 for a thousand. */
char NumPunctPTBR::do_thousands_sep() const {
	return '.';
}

}
