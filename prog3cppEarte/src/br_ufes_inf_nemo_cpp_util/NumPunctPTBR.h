#ifndef NUMPUNCTBR_H_
#define NUMPUNCTBR_H_

#include <locale>
#include <string>

namespace br_ufes_inf_nemo_cpp_util {

using namespace std;

class NumPunctPTBR: public numpunct<char> {
protected:
	char do_decimal_point() const;
	string do_grouping() const;
	char do_thousands_sep() const;
};

}
#endif
