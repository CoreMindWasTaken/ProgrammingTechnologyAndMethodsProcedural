#include "animal_atd.h"

using namespace std;

namespace Animals
{
int animal_length_name(Animal * A);

bool animal_compare(Animal * FirstA, Animal * SecondA)
{
    return (animal_length_name(FirstA) < animal_length_name(SecondA));
}
}
