#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
	ostringstream ostr;
	string s;
	ostr << argv[1] << argv[2];
	s = ostr.str();
	cout << s << endl;
	istringstream istr(s);
	char a,b;
	istr >> a >> b;
	cout << a << endl << b << endl;
	return 0;
}
