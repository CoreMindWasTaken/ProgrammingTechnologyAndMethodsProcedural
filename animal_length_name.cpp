#include "animal_atd.h"
using namespace std;
namespace Animals {
int fish_length_name(Fish * F);
int bird_length_name(Bird * B);
int animal_length_name(Animal * A) {
    switch(A->Key) {
    case FISH:
        return fish_length_name((Fish *)A);
    case BIRD:
        return bird_length_name((Bird *)A);
    default:
        return -1;
    }
}
}
