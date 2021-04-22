#include "container_atd.h"
using namespace std;
namespace Animals {
bool node_out(Node * N, ofstream & ofst);
void container_out(Container * C, ofstream & ofst)
{
    ofst << "Container contains " << C->Size << " elements!" << endl;
    Node * N = C->LastNode;
    while ((N != NULL) && (N->PrevNode != NULL))
    {
        N = N->PrevNode;
    }
    while (N != NULL)
    {
        if (!node_out(N, ofst))
        {
            ofst << "Node is broken!" << endl;
        }
        N = N->NextNode;
    }
    return;
}
}
