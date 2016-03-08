//
//  View.c
//  OpenGLPerspective
//
//  Created by Laura del Pino Díaz on 7/3/16.
//  Copyright © 2016 Laura del Pino Díaz. All rights reserved.
//

#include "View.h"

float puntos[8 * 6] = {
    -0.5,  0.5, 0.0, 1.0 ,0.0, 0.0,
    -0.8,  0.8, 0.0, 1.0, 0.0, 0.0,
    0.5,  0.5, 0.0, 1.0, 0.0, 0.0,
    0.8,  0.8, 0.0, 1.0, 0.0, 0.0,
    0.5, -0.5, 0.0, 1.0, 0.0, 0.0,
    0.8, -0.8, 0.0, 1.0, 0.0, 0.0,
    -0.5, -0.5, 0.0, 1.0, 0.0, 0.0,
    -0.8, -0.8, 0.0, 1.0, 0.0, 0.0
};

int indices[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 0, 1 };


void Init(){
    
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-gl_width/2.0, gl_width/2.0, -gl_height/2.0, gl_height/2.0, gl_near, gl_far);
}


void Display(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // // TO DO
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    
    unsigned int stride = 6 * sizeof(float); // salto entre el comienzo de datos de un vertice y otro
    glVertexPointer(3, GL_FLOAT, stride, puntos); // numero de datos por vertices, tipo, salto y comienzo
    glColorPointer(3, GL_FLOAT, stride, &(puntos[3]));
    
    //glDrawElements(GL_TRIANGLE_STRIP, 10, GL_UNSIGNED_INT, indices);
                   
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 10);
    

    
    glFlush(); // actualiza el framebuffer
}

void ReshapeSize(int width, int height){
    
    float dx = gl_width;
    float dy = gl_height;
    
    dx *= (float)width / (float)w_width;
    dy *= (float)height / (float)w_height;
    
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-dx / 2.0, dx / 2.0, -dy / 2.0, dy / 2.0, gl_near, gl_far); // espacio de trabajo
    glutPostRedisplay();
}