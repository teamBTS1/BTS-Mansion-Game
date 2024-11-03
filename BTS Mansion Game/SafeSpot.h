#pragma once
#include <string>
class SafeSpot {
public:
    std::string name;
    bool isSafe;

    SafeSpot(std::string name, bool isSafe = true) : name(name), isSafe(isSafe) {}
};

