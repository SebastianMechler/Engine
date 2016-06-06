#pragma once
#include <iostream>

class Vector3
{
public:
	//
	// Constructors
	//
	Vector3(); // Default Constructor
	Vector3(const float x, const float y, const float z); // Constructor with three elements
	Vector3(const float* values, const unsigned char size); // Constructor with float-array e.g. &myArry[0]
	Vector3(const Vector3& vector); // Copy Constructor
	Vector3(const Vector3&& vector); // Move Constructor

	//
	// Methods
	//
	void Normalized(); // sets vector's length to 1.0f
	float Magnitude() const; // Reads the length of vector
	void Scale(const Vector3& vector); // Scales vector by vector
	void Scale(const float scalar); // Scales vector by float value

	//
	// Operator Overloading
	//
	// all methods are lvalue(&) => rvalue(&&) is not required
	Vector3 operator+(const Vector3& vector) const; // +
	Vector3 operator-(const Vector3& vector) const; // -
	Vector3 operator*(const Vector3& vector) const; // *
	Vector3 operator/(const Vector3& vector) const; // /
	Vector3 operator/(const float divisor) const; // /
	void operator=(const Vector3& vector); // =
	void operator+=(const Vector3& vector); // +=
	void operator-=(const Vector3& vector); // -=
	void operator*=(const Vector3& vector); // *=
	void operator*=(const float scalar); // *=
	void operator/=(const Vector3& vector); // /=
	void operator/=(const float scalar); // /=
	bool operator!=(const Vector3& vector) const; // !=
	bool operator==(const Vector3& vector) const; // ==

	float& operator[](const unsigned char index); // [] Read-Write-Access

	//
	// Static Functions
	//
	static inline Vector3 Normalize(const Vector3& a); // sets vector's length to 1.0f
	static inline Vector3 Lerp(const Vector3& a, const Vector3& b, const float t); // generates a vector between a and b depending on t
	static inline Vector3 Cross(const Vector3& a, const Vector3& b); // cross product
	static inline Vector3 Reflect(const Vector3& direction, const Vector3& normal); // reflects a vector
	static inline float Distance(const Vector3& a, const Vector3& b); // calculates a distance between two vectors
	static inline float Dot(const Vector3& a, const Vector3& b); // calculates relation between two normalized vectors (ranges from: 1.0f to -1.0f)

	//
	// Public Member variables
	//
	union
	{
		struct
		{
			float x, y, z;
		};
		float components[3];
	};
	
	//
	// Static Variables
	//
	static float epsilon;
	static Vector3 forward;
	static Vector3 back;
	static Vector3 up;
	static Vector3 down;
	static Vector3 left;
	static Vector3 right;
	static Vector3 one;
	static Vector3 zero;
};


//
// Non-Memeber overloads
//
Vector3 operator*(const float scalar, const Vector3& vector);
Vector3 operator/(const float scalar, const Vector3& vector);