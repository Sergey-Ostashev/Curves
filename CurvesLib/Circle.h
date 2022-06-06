#pragma once
#include "Curve.h"
#include "Consts.h"

namespace curves
{
	class CURVESLIB_API Circle : public CurveImpl<CIRCLE_TYPE_ID>
	{
	public:
		Circle(double r);
		double GetRadius() const;

		std::string Description() const override;
		Point GetPoint(double t) const override;
		Point Derivative(double t) const override;

	private:
		double m_r;
	};
}

