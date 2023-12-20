#pragma once
#include "Point.h"
#include "Shape.h"
#include "pch.h"

class TRANSFORM_API Transform
{
public:
	Transform();
	~Transform();

	std::vector<Point> tPoint;
	void translate(std::vector<Point>& points, const Point& translationPoint);
	void rotate(std::vector<Point>& points, double angle);
	void scale(std::vector<Point>& points, double scaleFactor);
};

