#include "fish_atd.h"

using namespace std;

namespace Animals
{
bool fish_out(Fish * F, ofstream & ofst)
{
    switch (F->Place)
    {
    case RIVER:
        ofst << "It is ";
        ofst << "river";
        break;
    case SEA:
        ofst << "It is ";
        ofst << "sea";
        break;
    case LAKE:
        ofst << "It is ";
        ofst << "lake";
        break;
    default:
        return false;
    }
    ofst << " fish (" << F->Age << " age)- " << F->Name << endl;
    return true;
}
}
