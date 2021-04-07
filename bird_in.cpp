#include "bird_atd.h"
using namespace std;
namespace Animals {
Bird * bird_in(ifstream & ifst)
{
    Bird * B = new Bird;
    int TMP;
    ifst >> B->Name >> TMP;
    B->AttitudeFlight = (Migration)TMP;
    return B;
}
}
