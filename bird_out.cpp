#include "bird_atd.h"

using namespace std;

namespace Animals
{
bool bird_out(Bird * B, ofstream & ofst)
{
    switch (B->AttitudeFlight)
    {
    case MIGRATORY:
        ofst << "It is ";
        ofst << "migrant";
        break;
    case NONMIGRATORY:
        ofst << "It is ";
        ofst << "nonmigrant";
        break;
    default:
        return false;
    }
    ofst << " bird (" << B->Age << " age) - " << B->Name << endl;
    return true;
}
}
