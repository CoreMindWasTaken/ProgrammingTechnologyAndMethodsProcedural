#include "bird_atd.h"

using namespace std;

namespace Animals
{
Bird * bird_in(ifstream & ifst)
{
    Bird * B = new Bird;
    int TMP;
    ifst >> B->Name >> TMP >> B->Age;
    if (ifst.fail())
    {
        cout << "Error! The bird was not introduced!" << endl;
        return NULL;
    }
    if (!((0 <= TMP) && (TMP <= 1)))
    {
        cout << "Error! There is no such bird!" << endl;
        return NULL;
    }
    if (!(0 < B->Age))
    {
        cout << "Error! The bird has not yet been born! :(" << endl;
        return NULL;
    }
    B->AttitudeFlight = (Migration)TMP;
    return B;
}
}
