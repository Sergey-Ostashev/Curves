#pragma once
#include "Curve.h"
#include "Consts.h"

namespace curves
{
	class CURVESLIB_API Ellipse : public CurveT<ELLIPSE_TYPE_ID>
	{
	public:
		Ellipse(double rx, double ry);
		double GetRadiusX() const;
		double GetRadiusY() const;
		std::string Description() const override;
		Point GetPoint(double t) const override;
		Point Derivative(double t) const override;
	private:
		double m_rx;
		double m_ry;
	};
}

