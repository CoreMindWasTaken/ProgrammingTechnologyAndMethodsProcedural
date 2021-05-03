#include "node_atd.h"

using namespace std;

namespace Animals
{
bool animal_out(Animal * A, ofstream & ofst);
int animal_length_name(Animal * A);

bool node_out(Node * N, ofstream & ofst)
{
    if (!animal_out(N->A, ofst))
    {
        return false;
    }
    else
    {
        ofst << "Length animal name: " << animal_length_name(N->A) << endl;
        return true;
    }
}
}
