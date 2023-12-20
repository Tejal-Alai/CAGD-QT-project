#pragma once
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include "Shape.h"

class QOpenGLTexture;
class QOpenGLShader;
class QOpenGLShaderProgram;

class QOpenGLPaintDevice;

class OpenGLWindow :public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
signals:
    void shapesUpdated();
public:
    OpenGLWindow(const QColor& background, QWidget* parent);
    ~OpenGLWindow();

    void addShape(Shape inShape);
 

    void translate(std::vector<Point> shapePoints, int translateIndex);
    void rotate(std::vector<Point> shapePoints, int rotateIndex);
    void scale(std::vector<Point> shapePoints, int scaleIndex);
    void addClippingArea(Shape inShape);
    void clip();
    void updateData(const QVector<GLfloat>& vertices, const QVector<GLfloat>& colors, int  flag);
    int mFlag;
protected:
    void paintGL() override;
    void initializeGL() override;

private:
  
    void reset();

private:
    int mflag;
    bool mAnimating = false;
    QOpenGLContext* mContext = nullptr;
    QOpenGLPaintDevice* mDevice = nullptr;

    QOpenGLShader* mVshader = nullptr;
    QOpenGLShader* mFshader = nullptr;
    QOpenGLShaderProgram* mProgram = nullptr;

    QList<Shape> mShapes;
    QList<QVector3D> mNormals;
    QOpenGLBuffer mVbo;
    int mVertexAttr;
    int mNormalAttr;
    int mMatrixUniform;
    QColor mBackground;
    QMetaObject::Connection mContextWatchConnection;

    GLint m_posAttr = 0;
    GLint m_colAttr = 0;
    GLint m_matrixUniform = 0;

    Shape clippingArea;
    std::vector<Shape> shapes;
    std::vector<Shape> translatedShape;

    QVector<GLfloat> verticesOfOrignalLine;
    QVector<GLfloat> colorOfOrignalLine;
 
};
