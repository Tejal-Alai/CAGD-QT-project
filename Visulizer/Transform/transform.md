# Overview
The Transform library, implemented in the Transform.cpp file, provides functionality for translating, rotating, and scaling a collection of 3D points. This library is useful for performing basic transformations on geometric shapes in computer graphics.

## Class: Transform
The Transform class contains methods for translating, rotating, and scaling a vector of Point objects.

#### Constructor:
```cpp
Transform::Transform();
```
#### Destructor:
```cpp
Transform::~Transform();
```
#### Method: translate
```cpp
void Transform::translate(std::vector<Point>& points, const Point& translationPoint);
```
The `translate` method shifts each point in the vector by the specified translation coordinates.
#### Method: rotate
```cpp
void Transform::rotate(std::vector<Point>& points, double angle);
```
The `rotate` method rotates each point in the vector around the Z-axis by the specified angle in degrees.
#### Method: scale
```cpp
void Transform::scale(std::vector<Point>& points, double scaleFactor);
```
The `scale` method scales each point in the vector by the specified factor.

## Usage
To use the Transform library, instantiate the Transform class and call the desired transformation methods with a vector of Point objects.

```cpp
// Example usage
Transform transformer;

// Define a vector of points
std::vector<Point> points = { /* initialize points here */ };

// Translate the points
Point translationVector(1.0, 2.0, 0.0);
transformer.translate(points, translationVector);

// Rotate the points
double rotationAngle = 45.0; // in degrees
transformer.rotate(points, rotationAngle);

// Scale the points
double scaleFactor = 2.0;
transformer.scale(points, scaleFactor);
```
