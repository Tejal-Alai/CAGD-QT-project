# CAGD-QT-project

# Visulizer

## Overview

The Visualizer project is designed to provide a graphical interface for performing various transformation operations and clipping on geometric shapes. 
The project is organized into three main components: Geometry, Algorithm, and Visualizer.

### DLLs

#### 1. Geometry DLL

The Geometry DLL contains classes and functions for handling geometric entities such as points, lines, and shapes. It serves as the foundational library for storing and manipulating geometric data within the Visualizer project.
 
Classes:

+ Point: Represents a 2D point in Cartesian coordinates.

+ Line: Represents a line segment defined by two points.

+ Shape: Base class for different geometric shapes.

#### 2. Transformations DLL
Overview:
The Transformations DLL provides functions for translating, rotating, and scaling shapes.

Files:
Transform.cpp: Implements the Transform class with methods for translation, rotation, and scaling.

#### 3. Clipping DLL
Overview:
The Clipping DLL contains the algorithm for clipping shapes against a specified region.

Files:
Clipping.cpp: Defines the Clipping class for clipping shapes based on a region.
#### 4. Bezier Curve DLL
Overview:
The BezierCurve DLL offers functionality for generating Bezier and Hermite curves.

Files:
+ BezierCurve.cpp: Implements the BezierCurve class for drawing Bezier curves.
+ *`HermiteCurve.cpp:`* Defines the HermiteCurve class for drawing Hermite curves.
#### 5. Visualizer (Main Project)
Overview:
The Visualizer project integrates the functionalities of the Geometry, Transformations, Clipping, and BezierCurve DLLs to create a comprehensive OpenGL-based geometric data visualization tool.

Files:
OpenGLWindow.cpp: Main application file, using OpenGL for rendering.
ShapeContainer.cpp: Manages the collection of shapes for visualization.

Features:

+ Shape Container: Allows users to add circles and rectangles to the visualizer canvas.

+ Transformation Operations: Perform translation, rotation, and scaling on the added shapes.

+ Clipping: Define a clipping region and clip shapes accordingly.

+ Bazier Curve: Draw Bezier curve according to inputted control points.

+ Hermite Curve: Draw Hermite curve according to inputted control points.

+ Real-time Visualization: Shapes are rendered in real-time through OpenGL, providing immediate feedback on transformations and clipping.
  
### Usage

1. Initialization:
+ Instantiate the Geometry, Transformations, Clipping, and Bezier Curve classes as needed.
+ Create a ShapeContainer to manage shapes.
2. Geometric Operations:
+ Use the Geometry DLL to create points, lines, and shapes.
3. Transformations:
+ Apply transformations (translation, rotation, scaling) using the Transformations DLL.
4. Clipping:
+ Utilize the Clipping DLL to clip shapes against a specified region.
5. Curves:
+ Generate Bezier and Hermite curves using the Bezier Curve DLL and Hermite Curve DLL respectively.
6. OpenGL Visualization:
+ Use OpenGL to visualize the transformed, clipped shapes, and curves in the main Visualizer project.

## Project Screenshots

### Initial State

![Initial State] ![image](https://github.com/Tejal-Alai/CAGD-QT-project/assets/131939644/14bea44e-0750-4c07-ab64-3769bc53a800)

### Performing Transformations

![Translate] ![image](https://github.com/Tejal-Alai/CAGD-QT-project/assets/131939644/1c0a7eb0-45a2-4df4-a7d0-69df66f544aa)


![Rotate] ![image](https://github.com/Tejal-Alai/CAGD-QT-project/assets/131939644/d1a3444e-11ee-423f-abe9-e3139486411b)

![Scale] ![image](https://github.com/Tejal-Alai/CAGD-QT-project/assets/131939644/3e308898-75bf-4a16-8a1f-4cf1c02bc37f)



### Clipping in Action

![Before Clipping Action] ![image](https://github.com/Tejal-Alai/CAGD-QT-project/assets/131939644/92e12f4a-75a6-4aae-b301-52281935837c)


![After Clipping Action] ![image](https://github.com/Tejal-Alai/CAGD-QT-project/assets/131939644/34632737-4817-4266-8ceb-cd767930c052)


### Bezier Curve
![Bezier Curve] ![image](https://github.com/Tejal-Alai/CAGD-QT-project/assets/131939644/55ebc082-9168-414d-aa72-8f253aed65f4)


### Hermite Curve
![Hermite Curve] ![image](https://github.com/Tejal-Alai/CAGD-QT-project/assets/131939644/c689333f-b2b0-443f-9f4c-85889c8b8827)





