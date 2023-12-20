# Overview
The Geometry DLL provides a set of fundamental geometric primitives for working with points, lines, and shapes in computer graphics. This README specifically covers the Point, Line, and Shape classes provided by the DLL.

## Class: Point

### Constructor:
```cpp
Point::Point(double inX, double inY, double inZ = 0);
```
### Destructor:
```cpp
Point::~Point();
```
### Methods:
+ double x() const: Returns the x-coordinate of the point.
+ double y() const: Returns the y-coordinate of the point.
+ double z() const: Returns the z-coordinate of the point.
+ void setX(double x): Sets the x-coordinate of the point.
+ void setY(double y): Sets the y-coordinate of the point.
+ void setZ(double z): Sets the z-coordinate of the point.
+ bool operator==(const Point& p1) const: Checks if two points are equal.

## Class: Line

### Constructors:
```cpp
Line::Line(Point p1, Point p2);
Line::Line(const Line& other);
```
### Destructor:
```cpp
Line::~Line();
```
### Methods:
+ Point& p1(): Returns a reference to the first point of the line.
+ Point& p2(): Returns a reference to the second point of the line.
+ Line& operator=(const Line& other): Assignment operator for copying lines.
## Class: Shape
### Constructors:
```cpp
Shape::Shape(const std::vector<Line>& polyLines);
Shape::Shape();
```
### Destructor:
```cpp
Shape::~Shape();
```
### Methods:
+ void addPoints(std::vector<Point> inPoints): Adds points to the shape.
+ std::vector<Point>& getPoints(): Returns a reference to the vector of points.
+ std::vector<Line>& getShape(): Returns a reference to the vector of lines forming the shape.
+ void setShape(std::vector<Line> vl): Sets the lines of the shape.
+ size_t getSize() const: Returns the number of lines in the shape.
+ void pointsToShape(): Converts the points into lines, forming the shape.
