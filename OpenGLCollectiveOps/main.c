//
//  main.c
//  OpenGLPerspective
//
//  Created by Laura del Pino Díaz on 7/3/16.
//  Copyright © 2016 Laura del Pino Díaz. All rights reserved.
//

#include <stdio.h>
#include "View.h"


int w_width = 500,w_height = 500;
float gl_width = 2.0,gl_height = 2.0,gl_near = -1.0,gl_far =5.0;

int main(int argc, const char * argv[]) {
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(w_width
                       , w_height);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    
    glutCreateWindow("OpenGL Practica ");
    Init();
    glutDisplayFunc(Display); // registra la funcion de rendering
    glutReshapeFunc(ReshapeSize);
    
    glutMainLoop(); // bucle principal
    
    return 0;
}
