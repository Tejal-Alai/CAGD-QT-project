# Clipping Algorithm

# Overview

The Clipping algorithm, implemented in the `Clipping.cpp` file, is designed to clip a polygon against a region defined by a set of lines. This is useful for restricting the visible portion of a polygon to a specific region.

## Class: Clipping

The `Clipping` class takes two parameters during instantiation - the `region` (defining the clipping area) and the `polygon` to be clipped. The result is a clipped polygon that lies within the specified region.

#### Constructor:

```cpp
Clipping::Clipping(Shape region, Shape polygon);
```
##### Destructor:
```cpp
Clipping::~Clipping();
```

##### Method: getClippedPolygon
```cpp
Shape Clipping::getClippedPolygon();
```
The `getClippedPolygon` method computes the clipped polygon based on the specified region and returns a new Shape object representing the result.

##### Method: clipAlongLine
```cpp
void Clipping::clipAlongLine(Line l);
```
The `clipAlongLine` method performs the clipping of the polygon along the specified line l. It uses the Sutherland-Hodgman algorithm for polygon clipping.

##### Method: xIntersect
```cpp
double Clipping::xIntersect(Line l1, Line l2);
```
The `xIntersect` method calculates the x-coordinate of the intersection point between two lines, l1 and l2.

##### Method: yIntersect
```cpp
double Clipping::yIntersect(Line l1, Line l2);
```
The `yIntersect` method calculates the y-coordinate of the intersection point between two lines, l1 and l2.

### Usage
To use the Clipping algorithm, instantiate the Clipping class with the desired clipping region and polygon. Call the getClippedPolygon method to obtain the clipped polygon.

```cpp
// Example usage
Shape region;  // Define the clipping region
Shape polygon; // Define the polygon to be clipped

Clipping clipping(region, polygon);
Shape clippedPolygon = clipping.getClippedPolygon();
```
