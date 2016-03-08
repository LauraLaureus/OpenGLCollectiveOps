//
//  View.h
//  OpenGLPerspective
//
//  Created by Laura del Pino Díaz on 7/3/16.
//  Copyright © 2016 Laura del Pino Díaz. All rights reserved.
//

#ifndef View_h
#define View_h

#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

#endif /* View_h */


#ifndef GLOBAL_VARS
extern int visualiza,w_width,w_height,win1;
extern float gl_width,gl_height,gl_near,gl_far;
#endif

void Display();
void Init();
void ReshapeSize();