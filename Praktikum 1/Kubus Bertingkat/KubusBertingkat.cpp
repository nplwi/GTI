/*
 Nama : Naufal Dwi Yusmawan
 NIM  : 24060124130075
 Lab  : D1
*/


#include <GL/glut.h>

#include <stdlib.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    glColor3f(0.2, 0.5, 0.8);
    glVertex2f(-0.7, -0.6);
    glVertex2f(-0.3, -0.6);
    glVertex2f(-0.3, -0.2);
    glVertex2f(-0.7, -0.2);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(0.3, 0.6, 0.9);
    glVertex2f(-0.2, -0.6);
    glVertex2f(0.2, -0.6);
    glVertex2f(-0.2, -0.2);
    glVertex2f(0.2, -0.2);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.4, 0.7, 1.0);
    glVertex2f(0.3, -0.6);
    glVertex2f(0.7, -0.6);
    glVertex2f(0.3, -0.2);
    glVertex2f(0.7, -0.2);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.1, 0.4, 0.7);
    glVertex2f(-0.45, 0.1);
    glVertex2f(-0.65, -0.1);
    glVertex2f(-0.25, -0.1);
    glVertex2f(-0.25, 0.3);
    glVertex2f(-0.65, 0.3);
    glVertex2f(-0.65, -0.1);
    glEnd();

    glLineWidth(3.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.25, -0.1);
    glVertex2f(0.65, -0.1);
    glVertex2f(0.65, 0.3);
    glVertex2f(0.25, 0.3);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.8, 1.0);
    glVertex2f(0.25, -0.1);
    glVertex2f(0.65, -0.1);
    glVertex2f(0.65, 0.3);
    glVertex2f(0.25, 0.3);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.9, -0.65);
    glVertex2f(0.9, -0.65);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tugas GTI - Kubus Bertingkat");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
