#include "beast_atd.h"

using namespace std;

namespace Animals
{
Beast * beast_in(ifstream & ifst)
{
    Beast * B = new Beast;
    int TMP;
    ifst >> B->Name >> TMP >> B->Age;
    if (ifst.fail())
    {
        cout << "Error! The beast was not introduced!" << endl;
        return NULL;
    }
    if (!((0 <= TMP) && (TMP <= 2)))
    {
        cout << "Error! There is no such beast!" << endl;
        return NULL;
    }
    if (!(0 < B->Age))
    {
        cout << "Error! The beast has not yet been born! :(" << endl;
        return NULL;
    }
    B->D = (Diet)TMP;
    return B;
}
}
