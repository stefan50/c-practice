#include <iostream>
using namespace std;
// It means arguments vector and it contains the arguments passed to the programe.

int main(int argc, char* argv[])
{
        for(int i=0; i<argc; ++i)
                cout << "argv[" << i << "]=" << argv[i] << endl;
        return 0;
}
