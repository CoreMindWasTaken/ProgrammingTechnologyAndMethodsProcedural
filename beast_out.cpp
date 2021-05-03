#include "beast_atd.h"

using namespace std;

namespace Animals
{
bool beast_out(Beast * B, ofstream & ofst)
{
    switch (B->D)
    {
    case PREDATOR:
        ofst << "It is ";
        ofst << "predator";
        break;
    case HERBIVORE:
        ofst << "It is ";
        ofst << "herbivore";
        break;
    case INSECTIVOROUS:
        ofst << "It is ";
        ofst << "insectivorous";
        break;
    default:
        return false;
    }
    ofst << " beast (" << B->Age << " age) - " << B->Name << endl;
    return true;
}
}
