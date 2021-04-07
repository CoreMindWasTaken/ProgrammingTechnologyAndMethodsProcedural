#pragma once
#include <string>
#include <fstream>
namespace Animals {
enum Habitat { RIVER, SEA, LAKE };
struct Fish {
    int Key;
    std::string Name;
    Habitat Place;
};
}
