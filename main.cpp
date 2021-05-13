#include "container_atd.h"
using namespace std;
namespace Animals {
void container_init(Container * C);
void container_clear(Container * C);
bool container_in(Container * C, ifstream & ifst);
void container_out(Container * C, ofstream & ofst);
void multimethod(Container * C, ofstream & ofst);
}
using namespace Animals;
int main(int argc, char * argv[]) {
    if(argc != 3) {
        cout << "Incorrect command line! "
                "Waited: command infile outfile" << endl;
        exit(1);
    }
    ifstream ifst(argv[1]);
    ofstream ofst(argv[2]);
    cout << "Start!" << endl;
    Container * C = new Container;
    container_init(C);
    if (container_in(C, ifst))
    {
        ofst << "Filled container!" << endl;
        container_out(C, ofst);
        multimethod(C, ofst);
        container_clear(C);
        ofst << "Empty container!" << endl;
        container_out(C, ofst);
    }
    cout << "End!" << endl;
    return 0;
}

