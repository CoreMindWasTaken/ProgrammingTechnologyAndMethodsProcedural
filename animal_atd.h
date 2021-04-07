#pragma once
#include <fish_atd.h>
#include <bird_atd.h>
namespace Animals {
enum Type: int { FISH, BIRD };
struct Animal {
    Type Key;
};
}
