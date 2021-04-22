#include "beast_atd.h"
using namespace std;
namespace Animals {
Beast * beast_in(ifstream & ifst)
{
    Beast * B = new Beast;
    int TMP;
    ifst >> B->Name >> TMP >> B->Age;
    B->D = (Diet)TMP;
    return B;
}
}
