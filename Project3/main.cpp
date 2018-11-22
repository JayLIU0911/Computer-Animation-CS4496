#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "particle.h"
#include "simulator.h"

#include "Timer.h"
#include <Eigen/Dense>

using namespace std;

// opengl setup related variables
unsigned int window_width = 800, window_height = 600;

// ui related variables
bool mouse_down = false;

// simulation related variables
Simulator mySimulator;
bool simulating = false;
int frame_number = 0;
Timer timer;

// opengl functions
void myGlutResize(int w, int h);

void myGlutIdle(void);

void myGlutDisplay(void);

void myGlutKeyboard(unsigned char key, int x, int y);

void myGlutMouse(int button, int state, int x, int y);

void myGlutMotion(int x, int y);

void ShowText();

void DrawBackground();

// main function
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(window_width, window_height);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
    glutCreateWindow("Tinker Toy");
    glutIdleFunc(myGlutIdle);
    glutDisplayFunc(myGlutDisplay);
    glutReshapeFunc(myGlutResize);
    glutKeyboardFunc(myGlutKeyboard);
    glutMouseFunc(myGlutMouse);
    glutMotionFunc(myGlutMotion);
    
    // anti aliasing
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glutMainLoop();
    return 0;
}

void myGlutResize(int w, int h)
{
    window_width = w;
    window_height = h;
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glutPostRedisplay();
}

void myGlutIdle(void) {
    if (simulating) {
        timer.stop();
        double time_diff_in_sec = timer.getLastElapsedTime();
        //cout << time_diff_in_sec << endl;
        if (time_diff_in_sec > mySimulator.getTimeStep()) {
            while (time_diff_in_sec > mySimulator.getTimeStep()) {
                mySimulator.simulate();
                frame_number++;
                time_diff_in_sec -= mySimulator.getTimeStep();
            }
            timer.start();
        }
    }
    
    glutPostRedisplay();
}

void myGlutDisplay(void) {
    glClearColor(1.f , 1.f, 1.f ,1.0f);
    ::glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 1);
    
    glMatrixMode(GL_PROJECTION);    // opengl matrix for camera
    glLoadIdentity();
    gluPerspective(45, window_width*1.0/window_height, 0.01, 1000);
    glMatrixMode(GL_MODELVIEW);     // opengl matrix for object
    glLoadIdentity();
    
    // lighting
    glEnable(GL_LIGHTING);
    float ambient[4] = {0.5, 0.5, 0.5, 1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
    float diffuse[4] = {0.5, 0.5, 0.5, 1};
    float position[4] = {10, 10, 10, 0};
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    
    glTranslatef(0, 0, -1);
    
    // Draw a circle
    glColor3d(0, 0, 0);
    glDisable(GL_LIGHTING);
    glBegin(GL_LINE_LOOP);
    double rad = 3.14 / 180.0;
    double radius = 0.2;
    for (int i = 0; i < 360; i++) {
        double angle = i * rad;
        glVertex3d(radius * cos(angle), radius * sin(angle), 0.0);
    }
    glEnd();
    // Draw a line
    
    glBegin(GL_LINES);
    Eigen::Vector3d p1 = mySimulator.getParticle(0)->mPosition;
    Eigen::Vector3d p2 = mySimulator.getParticle(1)->mPosition;
    glVertex3f(p1[0], p1[1], p1[2]);
    glVertex3f(p2[0], p2[1], p2[2]);
    glEnd();
    glEnable(GL_LIGHTING);
    
    // Draw particles
    for (int i = 0; i < mySimulator.getNumParticles(); i++) {
        mySimulator.getParticle(i)->draw();
    }
    
    // render the text
    ShowText();
    
    glutSwapBuffers();
}

void myGlutKeyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 27:    // esc
            exit(0);
            break;
        case ' ':   // toggle simulation
            simulating = !simulating;
            if (simulating) timer.start();
            break;
        case 'r':   // reset simulation
            mySimulator.reset();
            frame_number = 0;
            simulating = false;
            break;
        default:
            break;
    }
    
    glutPostRedisplay();
}

void myGlutMouse(int button, int state, int x, int y) {
    mouse_down = (state == GLUT_DOWN);
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        cout << "Left Mouse Clicked" << endl;
    } else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        cout << "Right Mouse Clicked" << endl;
    }
    
    glutPostRedisplay();
}

void myGlutMotion(int x, int y) {
    
    glutPostRedisplay();
}

void RenderBitmapString(float x, float y, void *font,char *string)
{
    char *c;
    ::glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        ::glutBitmapCharacter(font, *c);
    }
    ::glRasterPos2f(x+1, y);
    for (c=string; *c != '\0'; c++) {
        ::glutBitmapCharacter(font, *c);
    }
}

void ShowText()
{
    int* pFont=(int*)GLUT_BITMAP_TIMES_ROMAN_24;
    
    GLint viewport[4];
    ::glGetIntegerv(GL_VIEWPORT,viewport);
    const int win_w = viewport[2];
    const int win_h = viewport[3];
    
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, window_width, 0, window_height);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glScalef(1, -1, 1);
    glTranslatef(0, -win_h, 0);
    
    // Display the frame count in 2D text
    char s_tmp[256];
    sprintf(s_tmp,"%d",frame_number);
    glColor3d(0.0, 0.0, 0.0);
    RenderBitmapString(10, window_height - 20, pFont, s_tmp);
    
    pFont=(int*)GLUT_BITMAP_8_BY_13;
    // Display control instructions
    
    strcpy(s_tmp,"\' \': Start/Stop simulation");
    RenderBitmapString(10, 20 + 14, pFont, s_tmp);
    
    strcpy(s_tmp,"\'r\': Reset simulation");
    RenderBitmapString(10, 20 + 28, pFont, s_tmp);
    
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}


