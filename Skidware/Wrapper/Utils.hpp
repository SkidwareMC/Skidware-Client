#pragma once
#include <string>
#include <iostream>

class Utils
{
public:
    static std::string RandomString(std::size_t);
    static std::string time_to_string(const char*, tm*);
};