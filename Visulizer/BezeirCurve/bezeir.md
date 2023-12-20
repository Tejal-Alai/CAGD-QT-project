# Overview
The Bezier Curve algorithm, implemented in the BezierCurve.cpp file, is used to draw a Bézier curve based on four control points. Bézier curves are widely used in computer graphics for smooth curve interpolation.

## Class: BezierCurve
The BezierCurve class encapsulates the Bézier Curve algorithm. It is instantiated with four control points (inP0, inP1, inP2, inP3), defining the shape of the curve.

### Constructor:
```cpp
BezierCurve::BezierCurve(Point inP0, Point inP1, Point inP2, Point inP3);
```

### Destructor:
```cpp
BezierCurve::~BezierCurve();
```

Method: drawCurve
The drawCurve method of the BezierCurve class computes the points on the Bézier curve and populates the vertex and color vectors for rendering.

Method Signature:
```cpp
void BezierCurve::drawCurve(Point inP0, Point inP1, Point inP2, Point inP3, vector<float>& mVertices, vector<float>& mColors);
```
Parameters:
+ `inP0, inP1, inP2, inP3:` Control points of the Bézier curve.
+ `mVertices:` Vector to store the computed vertex coordinates.
+ `mColors:` Vector to store the color information for each vertex.

### Usage:
Instantiate the BezierCurve class and call the drawCurve method with the desired control points and vectors to store the resulting vertex coordinates and colors.

```cpp
BezierCurve bezierCurve(inP0, inP1, inP2, inP3);
bezierCurve.drawCurve(inP0, inP1, inP2, inP3, mVertices, mColors);
```
### Example
```cpp
#include "BezierCurve.h"

// Define control points
Point p0(0.0f, 0.0f, 0.0f);
Point p1(1.0f, 1.0f, 0.0f);
Point p2(2.0f, -1.0f, 0.0f);
Point p3(3.0f, 0.0f, 0.0f);

// Instantiate Bezier curve
BezierCurve bezierCurve(p0, p1, p2, p3);

// Draw the Bezier curve and store vertices and colors
bezierCurve.drawCurve(p0, p1, p2, p3, mVertices, mColors);
```
The resulting mVertices vector will contain the computed coordinates of the Bézier curve, and mColors will contain the corresponding color information.
