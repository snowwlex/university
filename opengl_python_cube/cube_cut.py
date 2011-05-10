# -*- coding: utf-8 -*-

from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
import random
import sys

rtri = 0
rquad = 0
colors = {}

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

    global rtri, rquad
    rtri = (rtri + 1 ) % 360
    rquad = (rquad + 1 ) % 360

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT )      # Очистить экран и буфер глубины
    glLoadIdentity()                                          # Сбросить текущую матрицу

    glTranslatef(-1.5,0,-6)

    glPushMatrix()
    
    glRotatef(rtri,1.0,0.0,0.0)

    glBegin(GL_TRIANGLES)
    glColor3f(1.0,0.0,0.0)                      # Красный
    glVertex3f(0.0, 1.0, 0.0)                  # Верх треугольника (Передняя)
    glColor3f(0.0,1.0,0.0)                      # Зеленный
    glVertex3f(-1.0,-1.0, 1.0)                  # Левая точка
    glColor3f(0.0,0.0,1.0)                      # Синий
    glVertex3f( 1.0,-1.0, 1.0)                  # Правая точка

    glColor3f(1.0,0.0,0.0)                      # Красная
    glVertex3f( 0.0, 1.0, 0.0)                  #Верх треугольника (Правая)
    glColor3f(0.0,0.0,1.0)                      #Синия
    glVertex3f( 1.0,-1.0, 1.0)                  #Лево треугольника (Правая)
    glColor3f(0.0,1.0,0.0)                      #Зеленная
    glVertex3f( 1.0,-1.0, -1.0)                 #Право треугольника (Правая)

    glColor3f(1.0,0.0,0.0)                      # Красный
    glVertex3f( 0.0, 1.0, 0.0)                  # Низ треугольника (Сзади)
    glColor3f(0.0,1.0,0.0)                      # Зеленный
    glVertex3f( 1.0,-1.0, -1.0)                 # Лево треугольника (Сзади)
    glColor3f(0.0,0.0,1.0)                      # Синий
    glVertex3f(-1.0,-1.0, -1.0)                 # Право треугольника (Сзади)

    glColor3f(1.0,0.0,0.0)                      # Красный
    glVertex3f( 0.0, 1.0, 0.0)                  # Верх треугольника (Лево)
    glColor3f(0.0,0.0,1.0)                      # Синий
    glVertex3f(-1.0,-1.0,-1.0)                  # Лево треугольника (Лево)
    glColor3f(0.0,1.0,0.0)                      # Зеленный
    glVertex3f(-1.0,-1.0, 1.0)                  # Право треугольника (Лево)

    glEnd()

    glColor3f(0.5,1.0,0.5)
    glBegin(GL_QUADS)
    glVertex3f(  1,  -1, -1) #1
    glVertex3f(  1,  -1,  1) #2
    glVertex3f( -1,  -1,  1) #3
    glVertex3f( -1,  -1, -1) #4
    glEnd()


    #glRotatef(-rtri,1.0,0.0,0.0)
    glPopMatrix()




    
    glTranslatef(3,0.0,0.0)      # Сдвинем вправо на 3 единицы

    glRotatef(rquad,0.0,1.0,0.0)
   


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
