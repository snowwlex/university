# -*- coding: utf-8 -*-

from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
import random
import sys
import Image

rx,ry,rz = 0,0,0

texture = []
filter = 0
blend = False
light = True
LightAmbient = [ 0.8, 0.8, 0.8, 1.0 ]
LightDiffuse = [ 1,1,1,1 ]
LightPosition = [ 0,0, 2, 1]
fogMode = [ GL_EXP, GL_EXP2, GL_LINEAR, None ]
fogColor = [0.5,0.5,0.5,1]
fog = 0
zlevel = -6

def get_image( file_name):
    image  = Image.open ( file_name )
    width,height  = image.size
    image  = image.tostring ( "raw", "RGBX", 0, -1 )
    return image, width, height

def make_texture( file_name, min=GL_LINEAR, max=GL_LINEAR):
    #    glTexParameterf   ( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT )
#    glTexParameterf   ( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT )

    image, width, height = get_image( file_name )
    glTexParameteri   ( GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,max )
    glTexParameteri   ( GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,min)

    texture = glGenTextures ( 1 )
    glBindTexture     ( GL_TEXTURE_2D, texture )
    gluBuild2DMipmaps ( GL_TEXTURE_2D, 3, width, height, GL_RGBA, GL_UNSIGNED_BYTE, image )
    return texture

def LoadGLTextures():
    global texture
    filenames = ['data/derevo1.jpg', 'data/derevo1.jpg', 'data/derevo1.jpg']
    texture = []
    texture.append ( make_texture( filenames[0], GL_NEAREST, GL_NEAREST ))
    texture.append ( make_texture( filenames[1]))
    texture.append ( make_texture( filenames[2], GL_LINEAR_MIPMAP_NEAREST,  GL_LINEAR))

def InitGL(Width, Height):

    glColor4f(1,1,1,0.5)   # Полная яркость, 50% альфа (НОВОЕ)
    glBlendFunc(GL_SRC_ALPHA,GL_ONE) # Функция смешивания для непрозрачности,
                                       # базирующаяся на значении альфы(НОВОЕ)

    LoadGLTextures()			# Загрузка текстур
    glEnable(GL_TEXTURE_2D)		# Разрешение наложение текстуры

    glShadeModel( GL_SMOOTH )   # Разрешить плавное цветовое сглаживание
    
    glClearColor(0.5,0.5,0.5, 1)

    glClearDepth(1.0) # Разрешить очистку буфера глубины
    glDepthFunc(GL_LEQUAL) # Тип теста глубины
    glEnable(GL_DEPTH_TEST) # Разрешить тест глубины

    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST ) # Улучшение в вычислении перспективы

    global LightAmbient, LightDiffuse, LightPosition
    glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient)    # Установка Фонового Света
    glLightfv(GL_LIGHT2, GL_DIFFUSE, LightDiffuse)    # Установка Диффузного Света
    glLightfv(GL_LIGHT3, GL_DIFFUSE, LightDiffuse)    # Установка Диффузного Света
    glLightfv(GL_LIGHT2, GL_POSITION, LightPosition)   # Позиция света
    glLightfv(GL_LIGHT3, GL_POSITION, [0,4,0,1])   # Позиция света
    glEnable(GL_LIGHT1)
    glEnable(GL_LIGHT2)
    glEnable(GL_LIGHT3)
    glEnable(GL_LIGHTING)

    glEnable(GL_FOG);                       # Включает туман (GL_FOG)
    glFogi(GL_FOG_MODE, fogMode[fog]) # Выбираем тип тумана
    glFogfv(GL_FOG_COLOR, fogColor);        # Устанавливаем цвет тумана
    glFogf(GL_FOG_DENSITY, 0.35);          # Насколько густым будет туман
    glHint(GL_FOG_HINT, GL_DONT_CARE);      # Вспомогательная установка тумана
    glFogf(GL_FOG_START, 1.0);             # Глубина, с которой начинается туман
    glFogf(GL_FOG_END, 5.0);               # Глубина, где туман заканчивается.


def ReSizeGLScene(width, height):
    if height == 0: height = 1
    glViewport(0, 0, width, height)

    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()

    gluPerspective(45.0, float(width)/float(height), 0.1, 100.0)

    glMatrixMode(GL_MODELVIEW)


def DrawGLScene():

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT )      # Очистить экран и буфер глубины
    glLoadIdentity()                                          # Сбросить текущую матрицу

    glTranslatef(0,0,zlevel)



    glRotatef(rx,1.0,0.0,0.0)
    glRotatef(ry,0.0,1.0,0.0)
    glRotatef(rz,0.0,0.0,1.0)

    glBindTexture( GL_TEXTURE_2D, texture[filter])
    glBegin(GL_QUADS)

    #нижняя грань
    glNormal3f( 0, -1, 0)
    glTexCoord2f(1,1)
    glVertex3f(  1,  -1, -1) #1
    glTexCoord2f(1,0)
    glVertex3f(  1,  -1,  1) #2
    glTexCoord2f(0,0)
    glVertex3f( -1,  -1,  1) #3
    glTexCoord2f(0,1)
    glVertex3f( -1,  -1, -1) #4


#    glTexCoord2f(0,0)
#    glVertex3f(  1,  1, -1) #1
#    glTexCoord2f(0,1)
#    glVertex3f(  1,  1,  1) #2
#    glTexCoord2f(1,1)
#    glVertex3f( -1,  1,  1) #3
#    glTexCoord2f(1,0)
#    glVertex3f( -1,  1, -1) #4

    #задняя грань
    glNormal3f( 0, 0, -1)
    glTexCoord2f(1,1)
    glVertex3f(  1,   1, -1) #1
    glTexCoord2f(1,0)
    glVertex3f(  1,  -1, -1) #2
    glTexCoord2f(0,0)
    glVertex3f( -1,  -1, -1) #3
    glTexCoord2f(0,1)
    glVertex3f( -1,   1, -1) #4

    #передняя грань
    glNormal3f( 0, 0, 1)
    glTexCoord2f(1,1)
    glVertex3f(  1,   1, 1) #1
    glTexCoord2f(1,0)
    glVertex3f(  1,  -1, 1) #2
    glTexCoord2f(0,0)
    glVertex3f( -1,  -1, 1) #3
    glTexCoord2f(0,1)
    glVertex3f( -1,   1, 1) #4

    #левая грань
    glNormal3f( -1, 0, 0)
    glTexCoord2f(1,1)
    glVertex3f(  -1,   1,  1) #1
    glTexCoord2f(0,1)
    glVertex3f(  -1,   1, -1) #2
    glTexCoord2f(0,0)
    glVertex3f(  -1,  -1, -1) #3
    glTexCoord2f(1,0)
    glVertex3f(  -1,  -1,  1) #4

    #правая грань
    glNormal3f( 1, 0, 0)
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
    global zlevel
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
    if args[0]=='f':
        global filter,texture
        filter +=1
        filter %= len(texture)
    if args[0]=='l':
        global light
        light = not light
        print light
        if light:
            glEnable(GL_LIGHTING)
        else:
            glDisable(GL_LIGHTING)
    if args[0]=='[':
        zlevel -= 0.5
    elif args[0]==']':
        zlevel +=0.5
    if args[0]=='b':
        global blend
        blend = not blend
        if blend:
            glEnable(GL_BLEND)
            glDisable(GL_DEPTH_TEST)
        else:
            glDisable(GL_BLEND);        # Выключаем смешивание
            glEnable(GL_DEPTH_TEST);    # Включаем тест глубины
    if args[0]=='g':
        global fog
        fog +=1
        fog %= len(fogMode)
        mode = fogMode[fog]
        if mode:
            glEnable(GL_FOG)
            glFogi(GL_FOG_MODE, fogMode[fog])
        else:
            glDisable(GL_FOG)

    



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