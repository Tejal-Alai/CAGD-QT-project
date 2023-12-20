Hermite Curve Algorithm
# Overview

The Hermite Curve algorithm, implemented in the Hermite.cpp file, is used to draw a Hermite curve based on four control points. Hermite curves are commonly used in computer graphics for smooth interpolation between keyframe positions.

### Class: Hermite
The Hermite class encapsulates the Hermite Curve algorithm. It is instantiated with four control points (inP0, inP1, inP2, inP3), defining the shape of the curve.

### Constructor:

```cpp
Hermite::Hermite(Point inP0, Point inP1, Point inP2, Point inP3);
```

### Destructor:

```cpp
Hermite::~Hermite();
```

### Method: drawCurve

The drawCurve method of the Hermite class computes the points on the Hermite curve and populates the vertex and color vectors for rendering.

Method Signature:

void Hermite::drawCurve(Point inP0, Point inP1, Point inP2, Point inP3, vector<float>& mVertices, vector<float>& mColors);

Parameters:

+  `inP0, inP1, inP2, inP3:` Control points of the Hermite curve.
+ `mVertices:` Vector to store the computed vertex coordinates.
+ `mColors:` Vector to store the color information for each vertex.

### Usage:

Instantiate the Hermite class and call the drawCurve method with the desired control points and vectors to store the resulting vertex coordinates and colors.


```cpp
Hermite hermiteCurve(inP0, inP1, inP2, inP3);
hermiteCurve.drawCurve(inP0, inP1, inP2, inP3, mVertices, mColors);
```

### Example
```cpp

#include "Hermite.h"

// Define control points
Point p0(0.0f, 0.0f, 0.0f);
Point p1(1.0f, 1.0f, 0.0f);
Point p2(2.0f, -1.0f, 0.0f);
Point p3(3.0f, 0.0f, 0.0f);

// Instantiate Hermite curve
Hermite hermiteCurve(p0, p1, p2, p3);

// Draw the Hermite curve and store vertices and colors
hermiteCurve.drawCurve(p0, p1, p2, p3, mVertices, mColors);

```
The resulting mVertices vector will contain the computed coordinates of the Hermite curve, and mColors will contain the corresponding color information.
