#include "pch.h"
#include "Transform.h"

Transform::Transform()
{

}
Transform::~Transform()
{

}

void Transform::translate(std::vector<Point>& points, const Point& translationPoint)
{
    for (Point& point : points)
    {

        point.setX(point.x() + translationPoint.x());

        point.setY(point.y() + translationPoint.y());
    }
}

void Transform::rotate(std::vector<Point>& points, double angle)
{
    // Convert angle to radians
    double angleRadians = angle * 3.14159 / 180.0;

    // Compute sin and cos of the angle
    double cosTheta = cos(angleRadians);
    double sinTheta = sin(angleRadians);

    // Iterate over the vector and rotate each Point3D around the Z-axis
    for (Point& point : points) {
        double x = point.x();
        double y = point.y();

        // Perform rotation
        point.setX(x * cosTheta - y * sinTheta);
        point.setY(x * sinTheta + y * cosTheta);
        // Z-coordinate remains unchanged for rotation around Z-axis
    }
}

void Transform::scale(std::vector<Point>& points, double scaleFactor)
{
    for (Point& point : points)
    {
        point.setX(point.x() * scaleFactor);
        point.setY(point.y() * scaleFactor);
    }
}