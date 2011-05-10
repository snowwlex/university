# -*- coding: utf-8 -*-

from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
import random
import sys
import math
import numpy

step = 0.5
angle = 0

colors = {}
zlevel = -6

def InitGL(Width, Height):
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


    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT )      # Очистить экран и буфер глубины
    glLoadIdentity()
    #glTranslatef(0,0,zlevel)
    glMatrixMode(GL_MODELVIEW)
    #glRotatef(rquad,0.0,1.0,0.0)

    f = lambda alpha: (math.cos(alpha), math.sin(alpha))
    

    matrix_trans = [ [1,0,0,0],
                     [0,1,0,0],
                     [0,0,1,0],
                     [0,0,zlevel,1] ]

    c,s = f(angle)
    matrix_x = [ [1,0,0,0],
                 [0,c,s,0],
                 [0,-s,c,0],
                 [0,0,0,1] ]
    matrix_z = [ [c,s,0,0],
               [-s,c,0,0],
               [0,0,1,0],
               [0,0,0,1] ]

    matrix_y = [[c,0,-s,0],
               [0,1,0,0],
               [s,0,c,0],
               [0,0,0,1] ]

#    matrix_trans, matrix_x, matrix_y, matrix_z = [ numpy.array(matrix,'f')
#                                                   for matrix in [matrix_trans, matrix_x, matrix_y, matrix_z] ]
#
#    m = numpy.dot(matrix_trans, matrix_x)
#    m = numpy.dot(m, matrix_y)
#    m = numpy.dot(m, matrix_z)
    #glMultMatrixf(m.tolist())

    
    glMultMatrixf(matrix_trans)
    glMultMatrixf(matrix_x)
    glMultMatrixf(matrix_y)
    #glMultMatrixf(matrix_z)



    glBegin(GL_QUADS)

    randColor(1)
    glVertex3f(  1,  -1, -1) #1
    glVertex3f(  1,  -1,  1) #2
    glVertex3f( -1,  -1,  1) #3
    glVertex3f( -1,  -1, -1) #4

    randColor(2)
    glVertex3f(  1,  1, -1) #1
    glVertex3f(  1,  1,  1) #2
    glVertex3f( -1,  1,  1) #3
    glVertex3f( -1,  1, -1) #4

    randColor(3)
    glVertex3f(  1,   1, -1) #1
    glVertex3f(  1,  -1, -1) #2
    glVertex3f( -1,  -1, -1) #3
    glVertex3f( -1,   1, -1) #4

    randColor(3)
    glVertex3f(  1,   1, 1) #1
    glVertex3f(  1,  -1, 1) #2
    glVertex3f( -1,  -1, 1) #3
    glVertex3f( -1,   1, 1) #4

    randColor(4)
    glVertex3f(  -1,   1,  1) #1
    glVertex3f(  -1,   1, -1) #2
    glVertex3f(  -1,  -1, -1) #3
    glVertex3f(  -1,  -1,  1) #4

    randColor(4)
    glVertex3f(  1,   1,  1) #1
    glVertex3f(  1,   1, -1) #2
    glVertex3f(  1,  -1, -1) #3
    glVertex3f(  1,  -1,  1) #4
    glEnd()

    glutSwapBuffers()


def randColor(id):
    global colors
    if id not in colors:
        colors[id] = [ float(y)/10 for y in [random.randrange(0,11) for x in range(3)] ]
    r,g,b = colors[id]
    glColor3f(r,g,b)


    
def KeyPressed(*args):
    if args[0]=="\033": sys.exit()
    if args[0]=="f" :
        global colors
        colors.clear()
    global zlevel
    if args[0]=='[':
        zlevel -= 0.5
    elif args[0]==']':
        zlevel +=0.5
    #print
    print glGetFloatv(GL_MODELVIEW_MATRIX)
    if args[0]=='r':
        global angle
        angle += step
        angle %= 360    


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
