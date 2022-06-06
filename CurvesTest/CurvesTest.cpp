// CurvesTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <math.h>
#define _USE_MATH_DEFINES
#include <algorithm>
#include <iostream>
#include <memory>
#include <numeric>
#include <random>
#include <vector>

#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"
#pragma comment(lib, "CurvesLib.lib")

using namespace std;
using namespace curves;

int main()
{
	const uint32_t MAX_CURVES_COUNT = 20;
	const double MAX_RADIUS = 1000;

	using CurvePtr = shared_ptr<Curve>;
	using CirclePtr = shared_ptr<Circle>;
	using CurvesVector = vector<CurvePtr>;
	using CircleVector = vector<CirclePtr>;

	CurvesVector curves;
	
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> int_distrib(CIRCLE_TYPE_ID, HELIX_TYPE_ID);
	std::uniform_real_distribution<> real_distrib(0, 1000);

	for (uint32_t i = 0; i < MAX_CURVES_COUNT; i++)
	{
		int mark = int_distrib(gen);
		if (mark == CIRCLE_TYPE_ID)
		{
			double r = real_distrib(gen);
			curves.push_back(static_pointer_cast<Curve>(make_shared<Circle>(r)));
		}
		else if (mark == ELLIPSE_TYPE_ID)
		{
			double rx = real_distrib(gen);
			double ry = real_distrib(gen);
			curves.push_back(static_pointer_cast<Curve>(make_shared<Ellipse>(rx, ry)));
		}
		else
		{
			double r = real_distrib(gen);
			double step = real_distrib(gen);
			curves.push_back(static_pointer_cast<Curve>(make_shared<Helix>(r, step)));
		}
	}

	cout << "\nAll curves:\n" << endl;
	for_each(curves.begin(), curves.end(), [](const auto& c)
		{
			cout << c->Description().c_str() << endl;
			cout << "Value at t=PI/4: " << c->GetPoint(M_PI / 4) << ", derivative: " << c->Derivative(M_PI / 4) << endl;
		}
	);

	CircleVector circles;
	cout << "\nCircles:\n" << endl;
	for_each(curves.begin(), curves.end(), [&circles](const auto& c)
		{
			if (c->GetTypeId() == CIRCLE_TYPE_ID)
			{
				auto circle = static_pointer_cast<Circle>(c);
				circles.push_back(circle);
				cout << circle->Description().c_str() << endl;
			}
		}
	);

	sort(circles.begin(), circles.end(), [](const auto& a, const auto& b)
		{
			return a->GetRadius() < b->GetRadius();
		});

	cout << "\nSorted circles:\n" << endl;
	for_each(circles.begin(), circles.end(), [](const auto& c)
		{
			cout << c->Description().c_str() << endl;
		}
	);

	auto radii_sum = accumulate(circles.begin(), circles.end(), 0.0, [](const auto& a, const auto& b)
		{
			return a + b->GetRadius();
		}
	);

	cout << "\nSum of radii of all circles: " << radii_sum << endl;
}
