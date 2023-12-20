#include "stdafx.h"
#include "OpenGLWindow.h"

#include <QOpenGLContext>
#include <QOpenGLPaintDevice>
#include <QOpenGLShaderProgram>
#include <QPainter>
#include "Shape.h"

OpenGLWindow::OpenGLWindow(const QColor& background, QWidget* parent):
    mBackground(background)
{
    setParent(parent);
    setMinimumSize(300, 250);   
 
}
OpenGLWindow::~OpenGLWindow()
{
    reset();
}

void OpenGLWindow::addShape(Shape inShape)
{
    mShapes.push_back(inShape);
    emit shapesUpdated();
}



void OpenGLWindow::translate(std::vector<Point> shapePoints, int translateIndex)
{
    mShapes[translateIndex-1].addPoints(shapePoints);
    emit shapesUpdated();
}

void OpenGLWindow::rotate(std::vector<Point> shapePoints, int rotateIndex)
{
    mShapes[rotateIndex - 1].addPoints(shapePoints);
    emit shapesUpdated();
}

void OpenGLWindow::scale(std::vector<Point> shapePoints, int scaleIndex)
{
    mShapes[scaleIndex - 1].addPoints(shapePoints);
    emit shapesUpdated();
}

void OpenGLWindow::addClippingArea(Shape inShape)
{
    clippingArea = inShape;
    emit shapesUpdated();
}

void OpenGLWindow::clip()
{
    emit shapesUpdated();
}



void OpenGLWindow::updateData(const QVector<GLfloat>& vertices, const QVector<GLfloat>& colors, int  flag=0)
{
    verticesOfOrignalLine = vertices;
    colorOfOrignalLine = colors;
    mFlag = flag;
    update();  // Schedule a repaint
}
void OpenGLWindow::reset()
{
    // And now release all OpenGL resources.
    makeCurrent();
    delete mProgram;
    mProgram = nullptr;
    delete mVshader;
    mVshader = nullptr;
    delete mFshader;
    mFshader = nullptr;
    mVbo.destroy();
    doneCurrent();

    // We are done with the current QOpenGLContext, forget it. If there is a
    // subsequent initialize(), that will then connect to the new context.
    QObject::disconnect(mContextWatchConnection);
}

void OpenGLWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    mProgram->bind();

    QMatrix4x4 matrix;
    matrix.ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.1f, 100.0f);
    matrix.translate(0, 0, -2);

    mProgram->setUniformValue(m_matrixUniform, matrix);

    QVector<GLfloat> vertices;

    QVector<GLfloat> color;

    std::vector<Point> points = clippingArea.getPoints();

    for (size_t i = 0; i < points.size(); i++)
    {
        vertices.push_back(points[i].x());
        vertices.push_back(points[i].y());
        vertices.push_back(points[(i + 1) % points.size()].x());
        vertices.push_back(points[(i + 1) % points.size()].y());
        color.push_back(1.0f);
        color.push_back(1.0f);
        color.push_back(1.0f);
        color.push_back(1.0f);
        color.push_back(1.0f);
        color.push_back(0.0f);
    }

    for (size_t i = 0; i < mShapes.size(); i++)
    {
        std::vector<Point> ps = mShapes[i].getPoints();
        for (size_t i = 0; i < ps.size(); i++)
        {
            vertices.push_back(ps[i].x());
            vertices.push_back(ps[i].y());
            vertices.push_back(ps[(i + 1)% ps.size()].x());
            vertices.push_back(ps[(i + 1) % ps.size()].y());
            color.push_back(1.0f);
            color.push_back(0.0f);
            color.push_back(0.0f);
            color.push_back(1.0f);
            color.push_back(0.0f);
            color.push_back(0.0f);
        }
    }
    for (size_t i = 0; i < mShapes.size(); i++)
    {
        std::vector<Line> ps = mShapes[i].getShape();
        for (size_t i = 0; i < ps.size(); i++)
        {
            vertices.push_back(ps[i].p1().x());
            vertices.push_back(ps[i].p1().y());
            vertices.push_back(ps[i].p2().x());
            vertices.push_back(ps[i].p2().y());
            color.push_back(1.0f);
            color.push_back(0.0f);
            color.push_back(1.0f);
            color.push_back(1.0f);
            color.push_back(0.0f);
            color.push_back(1.0f);
        }
    }
    if (mFlag == 1)
    {
        GLfloat* verticesData = verticesOfOrignalLine.data();
        GLfloat* colorsData = colorOfOrignalLine.data();

        glVertexAttribPointer(m_posAttr, 3, GL_FLOAT, GL_FALSE, 0, verticesData);
        glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colorsData);

        glEnableVertexAttribArray(m_posAttr);
        glEnableVertexAttribArray(m_colAttr);

        glDrawArrays(GL_LINES, 0, verticesOfOrignalLine.size() / 3);
    }
    else
    {
        glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, vertices.data());
        glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, color.data());

        glEnableVertexAttribArray(m_posAttr);
        glEnableVertexAttribArray(m_colAttr);

        glDrawArrays(GL_LINES, 0, vertices.size() / 2);

        glDisableVertexAttribArray(m_colAttr);
        glDisableVertexAttribArray(m_posAttr);
    }

    

}

void OpenGLWindow::initializeGL()
{
    static const char* vertexShaderSource =
        "attribute highp vec4 posAttr;\n"
        "attribute lowp vec4 colAttr;\n"
        "varying lowp vec4 col;\n"
        "uniform highp mat4 matrix;\n"
        "void main() {\n"
        "   col = colAttr;\n"
        "   gl_Position = matrix * posAttr;\n"
        "}\n";

    static const char* fragmentShaderSource =
        "varying lowp vec4 col;\n"
        "void main() {\n"
        "   gl_FragColor = col;\n"
        "}\n";

    initializeOpenGLFunctions();

    mProgram = new QOpenGLShaderProgram(this);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    mProgram->link();
    m_posAttr = mProgram->attributeLocation("posAttr");
    Q_ASSERT(m_posAttr != -1);
    m_colAttr = mProgram->attributeLocation("colAttr");
    Q_ASSERT(m_colAttr != -1);
    m_matrixUniform = mProgram->uniformLocation("matrix");
    Q_ASSERT(m_matrixUniform != -1);
}

