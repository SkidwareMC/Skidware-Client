#include "Utils.hpp"
#include <vector>
#include <random>
#include "../JNI/jni.h"


std::string Utils::RandomString(std::size_t length)
{
    static const char alphanum[] = "0123456789" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";

    std::mt19937 engine(std::time(nullptr));
    std::uniform_int_distribution<std::size_t> distribution(0, sizeof(alphanum) - 2);

    std::string result;
    result.reserve(length);

    for (std::size_t i = 0; i < length; ++i) {
        result += alphanum[distribution(engine)];
    }

    return result;
}

std::string Utils::time_to_string(const char* format, tm* time)
{
    std::vector<char> buf(100, '\0');
    buf.resize(std::strftime(buf.data(), buf.size(), format, time));
    return std::string(buf.begin(), buf.end());
}

using qword = unsigned long long;
using t_createdvms = jint(__stdcall*)(JavaVM**, jsize, jsize*);

