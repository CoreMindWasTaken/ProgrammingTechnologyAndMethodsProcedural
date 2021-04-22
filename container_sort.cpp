#include "container_atd.h"
using namespace std;
namespace Animals {
bool animal_compare(Animal * FirstA, Animal * SecondA);
void container_sort(Container * C) {
    Node * FirstNode = C->LastNode;
    if (FirstNode != NULL)
    {
        while(FirstNode->PrevNode != NULL)
        {
            FirstNode = FirstNode->PrevNode;
        }
        Animal * A;
        for(Node * i = FirstNode; i->NextNode != NULL; i = i->NextNode) {
            for(Node * j = i->NextNode; j != NULL; j = j->NextNode) {
                if(animal_compare(i->A, j->A)) {
                    A = i->A;
                    i->A = j->A;
                    j->A = A;
                }
            }
        }
    }
}
}
