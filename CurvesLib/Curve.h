#pragma once
#include <string>
#include <typeinfo>
#include "Point.h"

namespace CurvesLib
{
	class CURVESLIB_API Curve
	{
	public:
		size_t GetTypeHash() const;
		virtual std::string Description() const = 0;
		virtual Point GetPoint(double t) const = 0;
		virtual Point Derivative(double t) const = 0;
	};
}

