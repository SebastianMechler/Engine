#include <stdio.h>

#include "CApplication.h"
#include "CWindow.h"
#include "CRandom.h"
#include "Vector3.h"


class Matrix3x3
{
public:
	float m00, m01, m02, m10, m11, m12, m20, m21, m22;

	// Constructors
	//Matrix3x3();
	//Matrix3x3(const float* a_floatValues);

	// Operator Overloading
	/*char* operator[] (int index)
	{
		printf("%i", index);
		return reinterpret_cast<char*>(&m01);
	}*/

	float& operator[](const int position)
	{
		switch (position)
		{
		case 0:
			return m00;
		case 1:
			return m10;
		case 2:
			return m20;

		default:
			return m00;
			break;
		}
	}

};

void main()
{
	Vector3 vector1 = Vector3(0.0f, 0.1f, 2.0f);
	Vector3 vector2(2, 4, 5);
	vector1 = Vector3(3.0f, 4.0f, 5.0f);
	vector1 = vector2;

	float xyz[3] = {1.0f, 2.0f, 3.0f};
	Vector3 vec = Vector3(&xyz[0], 4);
	vector1 = vector1 + Vector3(0,0,1);
	vec[1] = 10;
	//vector1.x = 10.0f;
	//vector1[4] = 10.0f;
	float& x = vector1[4];

	//vector1.components[3] = 20.0f;

	// hwnd saven
	// no defines
	Engine::CApplication application;

	Engine::SWindowDesc windowDesc;
	windowDesc.width = 1024;
	windowDesc.height = 768;
	windowDesc.isFullScreen = false;
	windowDesc.windowAlignment = Engine::EWindowAlignment::Center;
	windowDesc.name = "Engine";
	
	if (!application.Initialize(windowDesc))
	{
		return;
	}


	printf("%s", "Application will be run now.\n");

	application.Run();
}