#pragma once

#include <string>
#include <fstream>
#include <iostream>

namespace Animals
{
enum Habitat { RIVER, SEA, LAKE };

struct Fish
{
    int Key;
    std::string Name;
    int Age;
    Habitat Place;
};
}
