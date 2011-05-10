# -*- coding: utf-8 -*-

from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
import random
import sys
import Image

rx,ry,rz = 0,0,0

texture = []

def loadTexture ( fileName ):

#    glPixelStorei     ( GL_UNPACK_ALIGNMENT,1 )
    glTexParameterf   ( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT )
    glTexParameterf   ( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT )

    glTexParameteri   ( GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR )
    glTexParameteri   ( GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR )

    
    image  = Image.open ( fileName )
    width,height  = image.size
    image  = image.tostring ( "raw", "RGBX", 0, -1 )

    texture = glGenTextures ( 1 )
    glBindTexture     ( GL_TEXTURE_2D, texture )
    gluBuild2DMipmaps ( GL_TEXTURE_2D, 3, width, height, GL_RGBA, GL_UNSIGNED_BYTE, image )

    return texture

def LoadGLTextures():


    global texture
    texture = [loadTexture('data/tex2.jpg'), loadTexture('data/tex.png')]
    #texture.reverse()

def InitGL(Width, Height):

    LoadGLTextures()			# Загрузка текстур
    glEnable(GL_TEXTURE_2D)		# Разрешение наложение текстуры

    glShadeModel( GL_SMOOTH )   # Разрешить плавное цветовое сглаживание
    
    glClearColor(0.5, 0.5, 0.5, 0.0)

    glClearDepth(1.0) # Разрешить очистку буфера глубины
    glDepthFunc(GL_LESS) # Тип теста глубины
    glEnable(GL_DEPTH_TEST) # Разрешить тест глубины

    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST ) # Улучшение в вычислении перспективы


def ReSizeGLScene(width, height):
    if height == 0: height = 1
    glViewport(0, 0, width, height)

    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()

    gluPerspective(45.0, float(width)/float(height), 0.1, 100.0)

    glMatrixMode(GL_MODELVIEW)


def DrawGLScene():
    global texture

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT )      # Очистить экран и буфер глубины
    glLoadIdentity()                                          # Сбросить текущую матрицу

    glTranslatef(0,0,-6)


    glBindTexture( GL_TEXTURE_2D, texture[0] )
    glRotatef(rx,1.0,0.0,0.0)
    glRotatef(ry,0.0,1.0,0.0)
    glRotatef(rz,0.0,0.0,1.0)

    glBegin(GL_QUADS)

    glTexCoord2f(1,1)
    glVertex3f(  1,  -1, -1) #1
    glTexCoord2f(1,0)
    glVertex3f(  1,  -1,  1) #2
    glTexCoord2f(0,0)
    glVertex3f( -1,  -1,  1) #3
    glTexCoord2f(0,1)
    glVertex3f( -1,  -1, -1) #4



    glTexCoord2f(0,0)
    glVertex3f(  1,  1, -1) #1
    glTexCoord2f(0,1)
    glVertex3f(  1,  1,  1) #2
    glTexCoord2f(1,1)
    glVertex3f( -1,  1,  1) #3
    glTexCoord2f(1,0)
    glVertex3f( -1,  1, -1) #4

    #glBindTexture( GL_TEXTURE_2D, texture[0] )
    glTexCoord2f(1,1)
    glVertex3f(  1,   1, -1) #1
    glTexCoord2f(1,0)
    glVertex3f(  1,  -1, -1) #2
    glTexCoord2f(0,0)
    glVertex3f( -1,  -1, -1) #3
    glTexCoord2f(0,1)
    glVertex3f( -1,   1, -1) #4

    
    glTexCoord2f(1,1)
    glVertex3f(  1,   1, 1) #1
    glTexCoord2f(1,0)
    glVertex3f(  1,  -1, 1) #2
    glTexCoord2f(0,0)
    glVertex3f( -1,  -1, 1) #3
    glTexCoord2f(0,1)
    glVertex3f( -1,   1, 1) #4

    glTexCoord2f(1,1)
    glVertex3f(  -1,   1,  1) #1
    glTexCoord2f(0,1)
    glVertex3f(  -1,   1, -1) #2
    glTexCoord2f(0,0)
    glVertex3f(  -1,  -1, -1) #3
    glTexCoord2f(1,0)
    glVertex3f(  -1,  -1,  1) #4

    glTexCoord2f(0,1)
    glVertex3f(  1,   1,  1) #1
    glTexCoord2f(1,1)
    glVertex3f(  1,   1, -1) #2
    glTexCoord2f(1,0)
    glVertex3f(  1,  -1, -1) #3
    glTexCoord2f(0,0)
    glVertex3f(  1,  -1,  1) #4
    glEnd()

    glutSwapBuffers()


    
def KeyPressed(*args):
    if args[0]=="\033": sys.exit()
    global rx
    global ry
    global rz
    step = 10
    if args[0]=="w" :
        rx -= step
    if args[0]=="s" :
        rx += step
    if args[0]=="a" :
        ry += step
    if args[0]=="d" :
        ry -= step
    rx,ry,rz = [ r % 360 for r in (rx,ry,rz) ]
    if args[0]=='q':
        glTexParameteri   ( GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR)



def main():
    glutInit(sys.argv)
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH)
    glutInitWindowSize(400, 300)
    glutInitWindowPosition(0, 0)
    glutCreateWindow("OpenGL demo")
    glutDisplayFunc(DrawGLScene)
    glutIdleFunc(DrawGLScene)
    glutReshapeFunc(ReSizeGLScene)
    glutKeyboardFunc(KeyPressed)
    
    InitGL(400, 300)
    glutMainLoop()

if __name__ == "__main__":
    main()