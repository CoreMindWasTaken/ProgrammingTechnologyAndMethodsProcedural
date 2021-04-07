#include "fish_atd.h"
using namespace std;
namespace Animals {
bool fish_out(Fish * F, ofstream & ofst)
{
    ofst << "It is ";
    switch (F->Place) {
    case RIVER:
        ofst << "river";
        break;
    case SEA:
        ofst << "sea";
        break;
    case LAKE:
        ofst << "lake";
        break;
    default:
        return false;
    }
    ofst << " fish - " << F->Name << endl;
    return true;
}
}
