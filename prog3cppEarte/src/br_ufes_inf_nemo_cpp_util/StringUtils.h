#ifndef STRINGUTILS_H_
#define STRINGUTILS_H_

#include <algorithm>
#include <cctype>
#include <functional>
#include <locale>
#include <string>

namespace br_ufes_inf_nemo_cpp_util {

using namespace std;

string& ltrim(string &s);

string& rtrim(string &s);

string& trim(string& s);

bool stringCompare(string s1, string s2);

bool isNumber(string& s);

}
#endif
