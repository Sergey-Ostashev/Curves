#pragma once
#include <string>
#include "Point.h"

namespace curves
{
	class CURVESLIB_API Curve
	{
	public:
		virtual std::string Description() const = 0;
		virtual Point GetPoint(double t) const = 0;
		virtual Point Derivative(double t) const = 0;
		int GetTypeId() const { return m_type_id; }
	protected:
		Curve(int id) : m_type_id(id) {}
		int m_type_id;
	};

	template<int CurveId>
	class CurveT : public Curve
	{
	public:
		CurveT() : Curve(CurveId) {}
	};
}

