#include "node_atd.h"

using namespace std;

namespace Animals
{
Animal * animal_in(ifstream & ifst);
Node * node_in(ifstream & ifst)
{
   Animal * A;
   A = animal_in(ifst);
   if (A != NULL)
   {
       Node * N = new Node;
       N->A = A;
       N->NextNode = NULL;
       N->PrevNode = NULL;
       return N;
   }
   else
   {
       return NULL;
   }
}
}
