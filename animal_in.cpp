#include "animal_atd.h"
using namespace std;
namespace Animals {
Fish * fish_in(ifstream & ifst);
Bird * bird_in(ifstream & ifst);
Animal * animal_in(ifstream & ifst)
{
    Animal * A;
    int TMP;
    ifst >> TMP;
    switch (TMP) {
    case FISH:
        A = (Animal *)fish_in(ifst);
        A->Key = FISH;
        break;
    case BIRD:
        A = (Animal *)bird_in(ifst);
        A->Key = BIRD;
        break;
    default:
        return NULL;
    }
    return A;
}
}
