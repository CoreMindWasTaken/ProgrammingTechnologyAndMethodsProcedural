#include "container_atd.h"

using namespace std;

namespace Animals
{
bool node_out(Node * N, ofstream & ofst);

void multimethod(Container * C, ofstream & ofst)
{
    ofst << "Multimethod." << endl;

    Node * N = C->LastNode;
    Node * TMP;

    while (N != NULL)
    {
        TMP = N->PrevNode;
        while (TMP != NULL)
        {
            switch(N->A->Key)
            {
            case FISH:
                switch(TMP->A->Key)
                {
                case FISH:
                    ofst << "Fish and Fish." << endl;
                    break;
                case BIRD:
                    ofst << "Fish and bird." << endl;
                    break;
                case BEAST:
                    ofst << "Fish and beast." << endl;
                    break;
                default:
                    ofst << "Unknown type." << endl;
                }
                break;
            case BIRD:
                switch(TMP->A->Key)
                {
                case FISH:
                    ofst << "Bird and fish." << endl;
                    break;
                case BIRD:
                    ofst << "Bird and bird." << endl;
                    break;
                case BEAST:
                    ofst << "Bird and beast." << endl;
                    break;
                default:
                    ofst << "Unknown type." << endl;
                }
                break;
            case BEAST:
                switch(TMP->A->Key)
                {
                case FISH:
                    ofst << "Beast and fish." << endl;
                    break;
                case BIRD:
                    ofst << "Beast and bird." << endl;
                    break;
                case BEAST:
                    ofst << "Beast and beast." << endl;
                    break;
                default:
                    ofst << "Unknown type." << endl;
                }
                break;
            default:
                ofst << "Unknown type." << endl;
            }
            node_out(N, ofst);
            node_out(TMP, ofst);
            TMP = TMP->PrevNode;
        }
        N = N->PrevNode;
    }
}
}
