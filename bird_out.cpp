#include "bird_atd.h"
using namespace std;
namespace Animals {
bool bird_out(Bird * B, ofstream & ofst)
{
    ofst << "It is ";
    switch (B->AttitudeFlight) {
    case MIGRATORY:
        ofst << "migrant";
        break;
    case NONMIGRATORY:
        ofst << "nonmigrant";
        break;
    default:
        return false;
    }
    ofst << " bird - " << B->Name << endl;
    return true;
}
}
