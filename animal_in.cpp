#include "animal_atd.h"

using namespace std;

namespace Animals
{
Fish * fish_in(ifstream & ifst);
Bird * bird_in(ifstream & ifst);
Beast * beast_in(ifstream & ifst);

Animal * animal_in(ifstream & ifst)
{
    Animal * A;
    int TMP;
    ifst >> TMP;

    if (ifst.fail())
    {
        cout << "Error! The type of animal is undefined!" << endl;
        return NULL;
    }

    switch (TMP)
    {
    case FISH:
        A = (Animal *)fish_in(ifst);
        if (A == NULL)
        {
            return NULL;
        }
        A->Key = FISH;
        break;
    case BIRD:
        A = (Animal *)bird_in(ifst);
        if (A == NULL)
        {
            return NULL;
        }
        A->Key = BIRD;
        break;
    case BEAST:
        A = (Animal *)beast_in(ifst);
        if (A == NULL)
        {
            return NULL;
        }
        A->Key = BEAST;
        break;
    default:
        cout << "Error! The type of animal is undefined!" << endl;
        return NULL;
    }

    return A;
}
}
