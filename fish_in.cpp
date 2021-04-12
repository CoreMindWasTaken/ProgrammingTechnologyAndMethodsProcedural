#include "fish_atd.h"
using namespace std;
namespace Animals {
Fish * fish_in(ifstream & ifst)
{
    Fish * F = new Fish;
    int TMP;
    ifst >> F->Name >> TMP >> F->Age;
    F->Place = (Habitat)TMP;
    return F;
}
}
