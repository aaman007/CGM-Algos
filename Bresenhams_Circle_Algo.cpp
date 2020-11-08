#include<bits/stdc++.h>
#include<windows.h>
#include <GL/glut.h>

using namespace std;

double X, Y, R;

void drawAxis() {
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
        // X-axis
        glVertex2f(-200, 0);
        glVertex2f(200, 0);

        // Y-axis
        glVertex2f(0, 150);
        glVertex2f(0, -150);
    glEnd();
}

void drawEightPoints(int x, int y) {
    glVertex2f(x+X, y+Y);
    glVertex2f(-x+X, y+Y);
    glVertex2f(x+X, -y+Y);
    glVertex2f(-x+X, -y+Y);
    glVertex2f(y+X, x+Y);
    glVertex2f(y+X, -x+Y);
    glVertex2f(-y+X, x+Y);
    glVertex2f(-y+X, -x+Y);
}

void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawAxis();

    double d = 3 - 2*R , x = 0, y = R;

    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
        while(x < y) {
            drawEightPoints(x, y);
            if (d < 0) {
                d += (4*x + 6);
                x++;
            }
            else {
                d += (4*(x-y) + 10);
                x++;
                y--;
            }
        }
        if (x == y) {
            drawEightPoints(x, y);
        }
        glVertex2f(X, Y);
    glEnd();

    glFlush();
}

int main(int argc, char *argv[])
{
    cin >> X >> Y >> R;

    glutInit(&argc, argv);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham's Circle algorithm");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glOrtho(-200, 200, -150, 150, -1, 1);
    glutDisplayFunc(displayMe);
    glutMainLoop();

    return 0;
}
/**
5 5 100
2 2 90
**/
