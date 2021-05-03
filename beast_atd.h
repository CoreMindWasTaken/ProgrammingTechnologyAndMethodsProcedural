#pragma once

#include <string>
#include <fstream>
#include <iostream>

namespace Animals
{
enum Diet { PREDATOR, HERBIVORE, INSECTIVOROUS };

struct Beast
{
    int Key;
    std::string Name;
    int Age;
    Diet D;
};
}
