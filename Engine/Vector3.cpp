#include "Vector3.h"

Vector3::Vector3()
	: x(0.0f), y(0.0f), z(0.0f)
{
}

Vector3::Vector3(const float x, const float y, const float z)
	: x(x), y(y), z(z)
{
}

Vector3::Vector3(const float * values, const unsigned char size)
	: x(0), y(0), z(0)
{
	if (values == nullptr)
		return;
	
	if (size > (sizeof(this->components) / sizeof(float)))
	{
		// vector can only be initialized with the maximum amount of components
		return;
	}

	for (int i = 0; i < size; i++)
	{
		this->components[i] = values[i];
	}
}

Vector3::Vector3(const Vector3 & vector)
{
	this->x = vector.x;
	this->y = vector.y;
	this->z = vector.z;
}

Vector3::Vector3(const Vector3 && vector)
{
	this->x = vector.x;
	this->y = vector.y;
	this->z = vector.z;
}

void Vector3::Normalized()
{
	float length = Magnitude();
	this->x /= length;
	this->y /= length;
	this->z /= length;
}

float Vector3::Magnitude() const
{
	return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

void Vector3::Scale(const Vector3 & vector)
{
	this->x *= vector.x;
	this->y *= vector.y;
	this->z *= vector.z;
}

void Vector3::Scale(const float scalar)
{
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
}

Vector3 Vector3::operator+(const Vector3 & vector) const
{
	Vector3 temp;
	temp.x = this->x + vector.x;
	temp.y = this->y + vector.y;
	temp.z = this->z + vector.z;
	return temp;
}

Vector3 Vector3::operator-(const Vector3 & vector) const
{
	Vector3 temp;
	temp.x = this->x - vector.x;
	temp.y = this->y - vector.y;
	temp.z = this->z - vector.z;
	return temp;
}

Vector3 Vector3::operator*(const Vector3 & vector) const
{
	Vector3 temp;
	temp.x = this->x * vector.x;
	temp.y = this->y * vector.y;
	temp.z = this->z * vector.z;
	return temp;
}

Vector3 Vector3::operator/(const Vector3 & vector) const
{
	Vector3 temp;
	temp.x = this->x / vector.x;
	temp.y = this->y / vector.y;
	temp.z = this->z / vector.z;
	return temp;
}

Vector3 Vector3::operator/(const float divisor) const
{
	Vector3 temp;
	temp.x = this->x / divisor;
	temp.y = this->y / divisor;
	temp.z = this->z / divisor;
	return temp;
}

void Vector3::operator=(const Vector3 & vector)
{
	this->x = vector.x;
	this->y = vector.y;
	this->z = vector.z;
}

void Vector3::operator+=(const Vector3 & vector)
{
	this->x += vector.x;
	this->y += vector.y;
	this->z += vector.z;
}

void Vector3::operator-=(const Vector3 & vector)
{
	this->x -= vector.x;
	this->y -= vector.y;
	this->z -= vector.z;
}

void Vector3::operator*=(const Vector3 & vector)
{
	this->x *= vector.x;
	this->y *= vector.y;
	this->z *= vector.z;
}

void Vector3::operator*=(const float scalar)
{
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
}

void Vector3::operator/=(const Vector3 & vector)
{
	this->x /= vector.x;
	this->y /= vector.y;
	this->z /= vector.z;
}

void Vector3::operator/=(const float scalar)
{
	this->x /= scalar;
	this->y /= scalar;
	this->z /= scalar;
}

bool Vector3::operator!=(const Vector3 & vector) const
{
	return !(*this == vector);
}

bool Vector3::operator==(const Vector3 & vector) const
{
	return (abs(abs(this->x) - abs(vector.x)) < epsilon) 
		&& (abs(abs(this->y) - abs(vector.y)) < epsilon) 
		&& (abs(abs(this->z) - abs(vector.z)) < epsilon);
}

float& Vector3::operator[](const unsigned char index)
{
	if (index > (sizeof(components) / sizeof(float) - 1))
		return this->components[2];
	else
		return this->components[index];
}

Vector3 Vector3::Normalize(const Vector3& a)
{
	Vector3 temp(a);
	temp /= temp.Magnitude();
	return temp;
}

Vector3 Vector3::Lerp(const Vector3 & a, const Vector3 & b, const float t)
{
	return (1 - t)*a + t*b;
}

Vector3 Vector3::Cross(const Vector3& a, const Vector3& b)
{
	Vector3 temp;
	temp.x = a.x * b.z - a.z * b.y;
	temp.y = a.z * b.x - a.x * b.z;
	temp.z = a.x * b.y - a.y * b.x;
	return temp;
}

Vector3 Vector3::Reflect(const Vector3& direction, const Vector3& normal)
{
	return -2.0f * Vector3::Dot(normal, direction)  * normal  + direction;
}

float Vector3::Distance(const Vector3& a, const Vector3& b)
{
	Vector3 vector = Vector3(a.x - b.x, a.y - b.y, a.z - b.z);
	return vector.Magnitude();
}

float Vector3::Dot(const Vector3& a, const Vector3& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

float Vector3::epsilon = 0.000001f;
Vector3 Vector3::forward(0.0f, 0.0f, 1.0f);
Vector3 Vector3::back(0.0f, 0.0f, -1.0f);
Vector3 Vector3::up(0.0f, 1.0f, 0.0f);
Vector3 Vector3::down(0.0f, -1.0f, 0.0f);
Vector3 Vector3::left(-1.0f, 0.0f, 0.0f);
Vector3 Vector3::right(1.0f, 0.0f, 0.0f);
Vector3 Vector3::one(1.0f, 1.0f, 1.0f);
Vector3 Vector3::zero(0.0f, 0.0f, 0.0f);

//
// Non-Memeber overloads
//
inline Vector3 operator*(const float scalar, const Vector3 & vector)
{
	return Vector3(vector.x * scalar, vector.y * scalar, vector.z * scalar);
}

inline Vector3 operator/(const float scalar, const Vector3 & vector)
{
	return Vector3(vector.x / scalar, vector.y / scalar, vector.z / scalar);
}