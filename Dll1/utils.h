#pragma once

#include <random>

namespace sdk 
{
	struct vec2
	{
		double x, y;
	};

	struct vec3 
	{
		double x, y, z;
	};

	struct vec4
	{
		double x, y, z, w;
	};

	using qword = unsigned long long;

	inline float get_random(float start, float end)
	{
		std::random_device rd;
		std::mt19937_64 mt(rd());
		std::uniform_real_distribution<float> dist(start, end);
		return dist(mt);
	}

	inline double calc_distance(vec3 src, vec3 dst) {
		return sqrt(pow(src.x - dst.x, 2) + pow(src.y - dst.y, 2) + pow(src.z - dst.z, 2));
	}

};