#ifndef NUMBERUTILS_H_
#define NUMBERUTILS_H_

#include <locale>
#include <string>

#include "../br_ufes_inf_nemo_cpp_util/NumPunctPTBR.h"

namespace br_ufes_inf_nemo_cpp_util {

using namespace std;

/* Locale object for Brazilian Portuguese. */
static const locale LOCALE_PT_BR(locale(), new NumPunctPTBR());

/* Converts decimal numbers from textual format to double, following a locale configuration. */
double parseDouble(const string&, const locale&);

/* Converts decimal numbers from double format to text, following a locale configuration. */
string formatDouble(const double, const locale&);

/* Converts decimal numbers from double format to currency, following a locale configuration. */
string formatDoubleCurrency(const double, const locale&);

}
#endif
