#include "StringUtils.h"

using namespace std;

namespace br_ufes_inf_nemo_cpp_util {

string& ltrim(string &s) {
	s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
	return s;
}

string& rtrim(string &s) {
	s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
	return s;
}

string& trim(string& s) {
	return ltrim(rtrim(s));
}

bool stringCompare(string s1, string s2) {
	   const collate<char>& col = use_facet<collate<char> >(locale());
	   transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
	   transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
	   const char* pb1 = s1.data();
	   const char* pb2 = s2.data();
	   return (col.compare(pb1, pb1 + s1.size(), pb2, pb2 + s2.size()) < 0);
}

bool isNumber(string& s) {
	if (s.empty()) return false;
	for (int i = 0; i < s.size(); i++)
		if (! isdigit(s.at(i))) return false;
	return true;
}

}
