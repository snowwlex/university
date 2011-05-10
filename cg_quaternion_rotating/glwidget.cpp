#include <QtGui>
#include "glwidget.h"

// ----------------------------------------------------------------------
GlWidget::GlWidget(QWidget* pwgt/*= 0*/) : QGLWidget(pwgt) {
    m_xRotate = 0;
    m_yRotate = 0;

    for (int i=0; i<4;++i) {
        for (int j=0;j<4; ++j) {
            myMatrix[i*4+j] = i==j? 1 : 0;
        }
    }


}

// ----------------------------------------------------------------------

void GlWidget::loadTextures() {
    glEnable(GL_TEXTURE_2D);
    QPixmap t( QString(":/images/derevo1.jpg") );
    QPixmap t2( QString(":/images/derevo2.jpg") );
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    textures[0] = bindTexture( t, GL_TEXTURE_2D, QGLContext::MipmapBindOption); 
    textures[1] = bindTexture( t2, GL_TEXTURE_2D, QGLContext::MipmapBindOption);
}

/*virtual*/ void GlWidget::initializeGL()
{
    loadTextures();
    qglClearColor(Qt::black);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);

}

// ----------------------------------------------------------------------
/*virtual*/ void GlWidget::resizeGL(int nWidth, int nHeight)
{
    glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 10.0);
    gluPerspective(45.0, float(nWidth)/float(nHeight), 0.1, 100.0);
}

// ----------------------------------------------------------------------
/*virtual*/ void GlWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, -6.0);


    glMultMatrixd(myMatrix);

    glRotatef(m_xRotate, 1.0, 0.0, 0.0);
    glRotatef(m_yRotate, 0.0, 1.0, 0.0);




    glBindTexture( GL_TEXTURE_2D, textures[1] );
    glBegin(GL_QUADS);
        glTexCoord2f(0,0);
        glVertex3f(  1,  -1, -1); //1
        glTexCoord2f(0,1);
        glVertex3f(  1,  -1,  1); //2
        glTexCoord2f(1,1);
        glVertex3f( -1,  -1,  1); //3
        glTexCoord2f(1,0);
        glVertex3f( -1,  -1, -1); //4
    glEnd();

    glBindTexture( GL_TEXTURE_2D, textures[0] );
    glBegin(GL_QUADS);

//            glTexCoord2f(1,1);
//            glVertex3f(  1,  1, -1); //1
//            glTexCoord2f(1,0);
//            glVertex3f(  1,  1,  1); //2
//            glTexCoord2f(0,0);
//            glVertex3f( -1,  1,  1); //3
//            glTexCoord2f(0,1);
//            glVertex3f( -1,  1, -1); //4


        glTexCoord2f(1,1);
        glVertex3f(  1,   1, -1); //1
        glTexCoord2f(1,0);
        glVertex3f(  1,  -1, -1); //2
        glTexCoord2f(0,0);
        glVertex3f( -1,  -1, -1); //3
        glTexCoord2f(0,1);
        glVertex3f( -1,   1, -1); //4

        glTexCoord2f(1,1);
        glVertex3f(  1,   1, 1); //1
        glTexCoord2f(1,0);
        glVertex3f(  1,  -1, 1); //2
        glTexCoord2f(0,0);
        glVertex3f( -1,  -1, 1); //3
        glTexCoord2f(0,1);
        glVertex3f( -1,   1, 1); //4

        glTexCoord2f(1,1);
        glVertex3f(  -1,   1,  1); //1
        glTexCoord2f(0,1);
        glVertex3f(  -1,   1, -1); //2
        glTexCoord2f(0,0);
        glVertex3f(  -1,  -1, -1); //3
        glTexCoord2f(1,0);
        glVertex3f(  -1,  -1,  1); //4

        glTexCoord2f(0,1);
        glVertex3f(  1,   1,  1); //1
        glTexCoord2f(1,1);
        glVertex3f(  1,   1, -1); //2
        glTexCoord2f(1,0);
        glVertex3f(  1,  -1, -1); //3
        glTexCoord2f(0,0);
        glVertex3f(  1,  -1,  1); //4
    glEnd();

}

// ----------------------------------------------------------------------
/*virtual*/ void  GlWidget::mousePressEvent(QMouseEvent* pe)
{
    m_ptPosition = pe->pos();
}

// ----------------------------------------------------------------------
/*virtual */ void GlWidget ::mouseMoveEvent(QMouseEvent* pe)
{
    m_xRotate += 180 * (GLfloat)(pe->y() - m_ptPosition.y()) / height();
    m_yRotate += 180 * (GLfloat)(pe->x() - m_ptPosition.x()) / width();
    updateGL();

    m_ptPosition = pe->pos();
}

void GlWidget::setMatrix( GLdouble matrix[4*4]) {
   for (int i=0; i<16;++i) {
       this->myMatrix[i] = matrix[i];
   }

}
