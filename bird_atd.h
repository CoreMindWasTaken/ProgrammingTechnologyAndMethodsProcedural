#pragma once
#include <string>
#include <fstream>
namespace Animals {
enum Migration { MIGRATORY, NONMIGRATORY };
struct Bird {
    int Key;
    std::string Name;
    Migration AttitudeFlight;
    int Age;
};
}
