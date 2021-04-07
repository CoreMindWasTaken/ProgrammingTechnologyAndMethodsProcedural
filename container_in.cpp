#include "container_atd.h"
using namespace std;
namespace Animals {
Node * node_in(ifstream & ifst);
bool container_in(Container * C, ifstream & ifst)
{
    Node * N;
    while (!ifst.eof())
    {
        N = node_in(ifst);
        if (N != 0)
        {
            C->Size++;
            if (C->LastNode != NULL)
            {
                C->LastNode->NextNode = N;
                N->PrevNode = C->LastNode;
                C->LastNode = N;
            }
            else
            {
                C->LastNode = N;
            }
        }
        else
        {
            cout << "The input received incorrect data!" << endl;
            return false;
        }
    }
    return true;
}
}
