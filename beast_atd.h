#pragma once
#include <string>
#include <fstream>
namespace Animals {
enum  Diet { PREDATOR, HERBIVORE, INSECTIVOROUS };
struct Beast {
    int Key;
    std::string Name;
    int Age;
    Diet D;
};
}
