#ifndef _GlWidget_h_
#define _GlWidget_h_

#include <QGLWidget>

// ======================================================================
class GlWidget : public QGLWidget {


public:
    GlWidget(QWidget* pwgt = 0);

public:
    void setMatrix(  GLdouble matrix[4*4]  );



protected:
    virtual void   initializeGL   (                       );
    virtual void   resizeGL       (int nWidth, int nHeight);
    virtual void   paintGL        (                       );
    virtual void   mousePressEvent(QMouseEvent* pe        );
    virtual void   mouseMoveEvent (QMouseEvent* pe        );

protected:
    void loadTextures();

private:
    GLfloat m_xRotate;
    GLfloat m_yRotate;
    QPoint  m_ptPosition;
    GLuint textures[2];
    GLdouble myMatrix[4*4];



};
#endif  //_GlWidget_h_
