#include "node_atd.h"
using namespace std;
namespace Animals {
bool animal_out(Animal * A, ofstream & ofst);
bool node_out(Node * N, ofstream & ofst)
{
    if (!animal_out(N->A, ofst))
    {
        return false;
    }
    return true;
}
}
