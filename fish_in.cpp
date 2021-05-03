#include "fish_atd.h"

using namespace std;

namespace Animals
{
Fish * fish_in(ifstream & ifst)
{
    Fish * F = new Fish;
    int TMP;
    ifst >> F->Name >> TMP >> F->Age;
    if (ifst.fail())
    {
        cout << "Error! The fish was not introduced!" << endl;
        return NULL;
    }
    if (!((0 <= TMP) && (TMP <= 2)))
    {
        cout << "Error! There is no such fish!" << endl;
        return NULL;
    }
    if (!(0 < F->Age))
    {
        cout << "Error! The fish has not yet been born! :(" << endl;
        return NULL;
    }
    F->Place = (Habitat)TMP;
    return F;
}
}
