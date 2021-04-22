#include "beast_atd.h"
using namespace std;
namespace Animals {
bool beast_out(Beast * B, ofstream & ofst)
{
    ofst << "It is ";
    switch (B->D) {
    case PREDATOR:
        ofst << "predator";
        break;
    case HERBIVORE:
        ofst << "herbivore";
        break;
    case INSECTIVOROUS:
        ofst << "insectivorous";
        break;
    default:
        return false;
    }
    ofst << " beast (" << B->Age << " age) - " << B->Name << endl;
    return true;
}
}
