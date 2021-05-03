#include "container_atd.h"

using namespace std;

namespace Animals
{
bool node_out(Node * N, ofstream & ofst);

void container_out_fish(Container * C, ofstream & ofst)
{
    ofst << "Only fish!" << endl;
    Node * N = C->LastNode;
    while ((N != NULL) && (N->PrevNode != NULL))
    {
        N = N->PrevNode;
    }
    for(unsigned int i = 0; i < C->Size; i++)
    {
        if(N->A->Key == FISH)
        {
            ofst << (i + 1) << ") ";
            if (!node_out(N, ofst))
            {
                ofst << "Node is broken!" << endl;
            }
        }
        N = N->NextNode;
    }
    return;
}
}
