#include "container_atd.h"

using namespace std;

namespace Animals
{
void container_clear(Container * C)
{
    Node * N = C->LastNode;
    Node * TMP;
    while (N != NULL)
    {
        TMP = N->PrevNode;
        switch (N->A->Key)
        {
        case FISH:
            delete (Fish *)N->A;
            break;
        case BIRD:
            delete (Bird *)N->A;
            break;
        case BEAST:
            delete (Beast *)N->A;
            break;
        default:
            delete N->A;
            break;
        }
        delete N;
        N = TMP;
    }
    C->LastNode = NULL;
    C->Size = 0;
}
}
