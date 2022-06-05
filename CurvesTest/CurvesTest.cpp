// CurvesTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <memory>
#include <numeric>
#include <vector>

#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"
#pragma comment(lib, "CurvesLib.lib")

using namespace std;
using namespace CurvesLib;

int main()
{
	vector<shared_ptr<Curve>> curves;
	curves.push_back(make_shared<Circle>(8));
	curves.push_back(make_shared<Ellipse>(2, 3));
	curves.push_back(make_shared<Helix>(5, 1));
	curves.push_back(make_shared<Circle>(7));

	vector<shared_ptr<Circle>> circles;
	for_each(curves.begin(), curves.end(), [&circles](const auto& c)
		{
			if (c->GetTypeHash() == typeid(Circle).hash_code())
				circles.push_back(static_pointer_cast<Circle>(c));
		}
	);

	sort(circles.begin(), circles.end(), [](const auto& a, const auto& b)
		{
			return a->GetRadius() < b->GetRadius();
		});

	auto radius_sum = accumulate(circles.begin(), circles.end(), 0.0, [](const auto& a, const auto& b)
		{
			return a + b->GetRadius();
		}
	);

    cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
