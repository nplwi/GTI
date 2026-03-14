/*
 Nama : Naufal Dwi Yusmawan
 NIM  : 24060124130075
 Lab  : D1
*/

#include <GL/glut.h>
#include <math.h>

#define PI 3.141592653589

// Fungsi pembantu untuk menggambar lingkaran
void drawCircle(float x, float y, float radius, int segments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++) {
        float angle = 2.0f * PI * i / segments;
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();
}

// Fungsi untuk menggambar pohon sederhana
void drawTree(float x, float y) {
    glPushMatrix();
        glTranslatef(x, y, 0.0f);
        
        // Batang Pohon (Cokelat)
        glColor3f(0.4f, 0.26f, 0.13f);
        glRectf(-0.02f, 0.0f, 0.02f, 0.2f);
        
        // Daun (Hijau)
        glColor3f(0.0f, 0.6f, 0.0f);
        drawCircle(0.0f, 0.25f, 0.1f, 30);
    glPopMatrix();
}

// AWAN
void drawCloud(float x, float y) {
    glPushMatrix();
        glTranslatef(x, y, 0.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        drawCircle(0.0f, 0.0f, 0.06f, 30);
        drawCircle(0.05f, 0.02f, 0.05f, 30);
        drawCircle(-0.05f, 0.02f, 0.05f, 30);
        drawCircle(0.03f, -0.02f, 0.04f, 30);
        drawCircle(-0.03f, -0.02f, 0.04f, 30);
    glPopMatrix();
}

void RenderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // MATAHARI
    glPushMatrix();
        // Lingkaran Luar
        glColor3f(1.0f, 0.9f, 0.0f);
        drawCircle(-0.7f, 0.7f, 0.15f, 50);
        // Lingkaran Dalam
        glColor3f(1.0f, 0.5f, 0.0f);
        drawCircle(-0.7f, 0.7f, 0.08f, 50);
    glPopMatrix();

    // AWAN
    drawCloud(0.5f, 0.75f);
    drawCloud(-0.2f, 0.82f);
    drawCloud(0.1f, 0.65f);

    // JALAN RAYA
    glColor3f(0.2f, 0.2f, 0.2f);
    glRectf(-1.0f, -0.4f, 1.0f, -1.0f);

    // POHON-POHON
    drawTree(-0.8f, -0.4f);
    drawTree(-0.5f, -0.4f);
    drawTree(0.7f, -0.4f);

    // MOBIL
    glPushMatrix();
        glTranslatef(-0.1f, -0.3f, 0.0f);
        
        // Badan Mobil
        glColor3f(1.0f, 0.0f, 0.0f);
        glRectf(-0.4f, 0.0f, 0.4f, 0.2f);

        // Atap Mobil
        glColor3f(0.8f, 0.0f, 0.0f);
        glBegin(GL_POLYGON);
            glVertex2f(-0.25f, 0.2f);
            glVertex2f(0.25f, 0.2f);
            glVertex2f(0.15f, 0.35f);
            glVertex2f(-0.15f, 0.35f);
        glEnd();

        // Jendela
        glColor3f(0.7f, 0.9f, 1.0f);
        glRectf(-0.12f, 0.22f, 0.12f, 0.32f);

        // Lampu Depan
        glColor3f(1.0f, 1.0f, 0.8f);
        glRectf(0.35f, 0.12f, 0.41f, 0.18f);

        // Roda Belakang
        glPushMatrix();
            glTranslatef(-0.25f, 0.0f, 0.0f);
            glColor3f(0.0f, 0.0f, 0.0f);
            drawCircle(0.0f, 0.0f, 0.08f, 30);
            glColor3f(0.5f, 0.5f, 0.5f);
            drawCircle(0.0f, 0.0f, 0.04f, 20);
        glPopMatrix();

        // Roda Depan
        glPushMatrix();
            glTranslatef(0.25f, 0.0f, 0.0f);
            glColor3f(0.0f, 0.0f, 0.0f);
            drawCircle(0.0f, 0.0f, 0.08f, 30);
            glColor3f(0.5f, 0.5f, 0.5f);
            drawCircle(0.0f, 0.0f, 0.04f, 20);
        glPopMatrix();

    glPopMatrix();

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Tugas GTI - Mobil");
    
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
    glutDisplayFunc(RenderScene);
    glutMainLoop();
    return 0;
}
