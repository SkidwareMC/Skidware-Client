#pragma once
#include <string>
#include <iostream>

struct vector3 {
    double x, y, z;

    vector3 add(vector3 other) {
        return vector3(this->x + other.x, this->y + other.y, this->z + other.z);
    }
};

class Utils
{
public:
    static std::string RandomString(std::size_t);
    static std::string time_to_string(const char*, tm*);
};