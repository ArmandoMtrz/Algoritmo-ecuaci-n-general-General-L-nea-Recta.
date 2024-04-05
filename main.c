// Autor: José Armando ALarcón
#include <stdio.h>
#include <stdlib.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<GL/freeglut.h>
#include <math.h>

void pendiente(float x1, float y1, float x2, float y2) {
    float m, b;
    int isVertical = 0; // 0 indica que no es vertical

    if (x1 == x2) {
        printf("La línea es vertical.\n");
        isVertical = 1;
    } else {
        m = (float)(y2 - y1) / (x2 - x1);
        b = y1 - m * x1;

        printf("Pendiente (m): %.2f\n", m);
        printf("Intercepto (b): %.2f\n", b);
    }

    glBegin(GL_POINTS);

    if (isVertical) {
        int y_start = fmin(y1, y2);
        int y_end = fmax(y1, y2);
        for (int y = y_start; y <= y_end; y++) {
            glVertex2i(x1, y);
        }
    } else {
        int x_start = fmin(x1, x2);
        int x_end = fmax(x1, x2);
        int y_start = fmin(y1, y2);
        int y_end = fmax(y1, y2);
        if (m >= 0 && m <= 1) { // Dibujar de izquierda a derecha
            for (int x = x_start; x <= x_end; x++) {
                int y = round(m * x + b);
                glVertex2i(x, y);
            }
        } else { // Dibujar de arriba hacia abajo
            for (int y = y_start; y <= y_end; y++) {
                int x = round((y - b) / m);
                glVertex2i(x, y);
            }
        }
    }

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 700, 0, 700);

    pendiente(436.6791704932321, 511.333667850818, 438.4682530341299, 556.0607313732633); // Entrada de Coordenadas

    glFlush();
}

int main(int argc, char** argv) {
    printf("Examen parcial de");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(700, 700);
    glutCreateWindow("Linea Recta");
    glClearColor(1, 1, 1, 1);
    glutDisplayFunc(display);
    glutMainLoop();
    printf("=== fin ===");
    return (EXIT_SUCCESS);
}
