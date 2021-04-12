#include "animal_atd.h"
using namespace std;
namespace Animals {
bool fish_out(Fish * F, ofstream & ofst);
bool bird_out(Bird * B, ofstream & ofst);
bool beast_out(Beast * B, ofstream & ofst);
bool animal_out(Animal * A, ofstream & ofst) {
    switch(A->Key) {
    case FISH:
        if (fish_out((Fish *)A, ofst))
        {
            return true;
        }
        return false;
    case BIRD:
        if (bird_out((Bird *)A, ofst))
        {
            return true;
        }
        return false;
    case BEAST:
        if (beast_out((Beast *)A, ofst))
        {
            return true;
        }
        return false;
    default:
        return false;
    }
}
}
