#pragma once
#include "animal_atd.h"
namespace Animals {
struct Node
{
    Animal * A;
    Node * NextNode;
    Node * PrevNode;
};
}
