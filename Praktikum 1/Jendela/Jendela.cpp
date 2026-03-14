/*
	Nama	: Naufal Dwi Yusmawan
	NIM		: 24060124130075
	Lab		: D1
*/

#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // GL_QUADS: Bingkai Luar Jendela
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.0);
    glVertex2f(-0.6, -0.7);
    glVertex2f(0.6, -0.7);
    glVertex2f(0.6, 0.7);
    glVertex2f(-0.6, 0.7);
    glEnd();

    // GL_TRIANGLE_STRIP: Kaca Jendela
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.7, 0.9, 1.0);
    glVertex2f(-0.5, -0.6);
    glVertex2f(0.5, -0.6);
    glVertex2f(-0.5, 0.6);
    glVertex2f(0.5, 0.6);
    glEnd();

    // GL_QUAD_STRIP: Palang Tengah
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.3, 0.1, 0.0);
    glVertex2f(-0.05, -0.6); // Vertikal
    glVertex2f(0.05, -0.6);
    glVertex2f(-0.05, 0.6);
    glVertex2f(0.05, 0.6);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glVertex2f(-0.5, -0.05); // Horizontal
    glVertex2f(-0.5, 0.05);
    glVertex2f(0.5, -0.05);
    glVertex2f(0.5, 0.05);
    glEnd();

    // GL_TRIANGLE_FAN: Gagang Jendela Bulat
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.8, 0.8, 0.0);
    glVertex2f(0.15, -0.15);
    for (int i = 0; i <= 360; i += 10) {
        glVertex2f(0.15 + (0.05 * 0.7), -0.15 + (0.05 * 1.0)); 
    }
    glVertex2f(0.1, -0.15);
    glVertex2f(0.15, -0.1);
    glVertex2f(0.2, -0.15);
    glVertex2f(0.15, -0.2);
    glVertex2f(0.1, -0.15);
    glEnd();

    // GL_LINE_LOOP: Outline Penahan Kaca
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.5, -0.6);
    glVertex2f(0.5, -0.6);
    glVertex2f(0.5, 0.6);
    glVertex2f(-0.5, 0.6);
    glEnd();

    // GL_LINE_STRIP: Pantulan di Kaca
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.4, 0.5);
    glVertex2f(-0.1, 0.5);
    glVertex2f(-0.4, 0.2);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(0.1, 0.1, 0.1, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Tugas GTI - Jendela");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
