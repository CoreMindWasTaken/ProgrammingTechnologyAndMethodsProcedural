#pragma once
#include <fish_atd.h>
#include <bird_atd.h>
#include <beast_atd.h>
namespace Animals {
enum Type: int { FISH, BIRD, BEAST };
struct Animal {
    Type Key;
    std::string Name;
    int Age;
};
}
