#include <GL/glut.h>

static int shoulder = 0, elbow = 0, wrist = 0, finger = 0;

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
        // --- BAHU & LENGAN ATAS ---
        glTranslatef(-1.0, 0.0, 0.0);
        glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);
        glPushMatrix();
            glScalef(2.0, 0.4, 1.0);
            glutWireCube(1.0);
        glPopMatrix();

        // --- SIKU & LENGAN BAWAH ---
        glTranslatef(1.0, 0.0, 0.0);
        glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);
        glPushMatrix();
            glScalef(2.0, 0.4, 1.0);
            glutWireCube(1.0);
        glPopMatrix();

        // --- PERGELANGAN & TELAPAK TANGAN ---
        glTranslatef(1.0, 0.0, 0.0); // Pindah ke ujung lengan bawah
        glRotatef((GLfloat)wrist, 0.0, 0.0, 1.0);
        glTranslatef(0.3, 0.0, 0.0); // Pivot telapak
        glPushMatrix();
            glScalef(0.6, 0.5, 0.8);
            glutWireCube(1.0);
        glPopMatrix();

        // --- JARI-JARI (Contoh satu engsel jari) ---
        glTranslatef(0.3, 0.0, 0.0); // Pindah ke ujung telapak
        glRotatef((GLfloat)finger, 0.0, 0.0, 1.0);
        glTranslatef(0.2, 0.0, 0.0); 
        glPushMatrix();
            glScalef(0.4, 0.2, 0.2);
            glutWireCube(1.0);
        glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 's': shoulder = (shoulder + 5) % 360; break;
        case 'S': shoulder = (shoulder - 5) % 360; break;
        case 'e': elbow = (elbow + 5) % 360; break;
        case 'E': elbow = (elbow - 5) % 360; break;
        case 'w': wrist = (wrist + 5) % 360; break;
        case 'W': wrist = (wrist - 5) % 360; break;
        case 'f': finger = (finger + 5) % 360; break;
        case 'F': finger = (finger - 5) % 360; break;
        case 27: exit(0); break;
    }
    glutPostRedisplay();
}
