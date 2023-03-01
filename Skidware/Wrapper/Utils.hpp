#pragma once
#include <string>
#include <iostream>
#define M_PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679

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

/// NOTE: They're all inline LULW
namespace util {
	inline float wrap_to_180(float value)
	{
		if (value >= 180.f)
			value -= 360.f;
		if (value < -180.f)
			value += 360.f;
		return value;
	}

	inline float radiants_to_deg(float x)
	{
		return x * 180.f / M_PI;
	}

	inline float deg_to_radiants(float r)
	{
		return r * M_PI / 180;
	}

	inline std::pair<float, float> get_angles(vector3 pos, vector3 pos1)
	{
		double d_x = pos1.x - pos.x;
		double d_y = pos1.y - pos.y;
		double d_z = pos1.z - pos.z;

		double hypothenuse = sqrt(d_x * d_x + d_z * d_z);
		float yaw = radiants_to_deg(atan2(d_z, d_x)) - 90.f;
		float pitch = radiants_to_deg(-atan2(d_y, hypothenuse));

		return std::make_pair(yaw, pitch);
	}

	inline static double distance(double x, double y) {
		return sqrt(pow(x, 2) + pow(y, 2));
	}

	inline static double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
		return distance(y1 - y2, distance(x1 - x2, z1 - z2));
	}
}