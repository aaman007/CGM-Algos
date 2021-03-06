#include<bits/stdc++.h>
#include<windows.h>
#include <GL/glut.h>

using namespace std;

double X1, X2, Y1, Y2;

double getSlope() {
    return (Y2-Y1) / (X2-X1);
}

double getBias() {
    return Y1 - getSlope()*X1;
}

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

/**
    10 -100
    100 20
**/
void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawAxis();

    double m = getSlope(), x, y;

    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
        if(fabs(m) <= 1) {
            if(X1 > X2) {
                swap(X1, X2);
                swap(Y1, Y2);
            }

            x = X1, y = Y1;

            while(x <= X2) {
                glVertex2f(x, round(y));
                x++;
                y += m;
            }
        }
        else {
            if(Y1 > Y2) {
                swap(X1, X2);
                swap(Y1, Y2);
            }

            x = X1, y = Y1;

            while(y <= Y2) {
                glVertex2f(round(x), y);
                y++;
                x += (1/m);
            }
        }
    glEnd();

    glFlush();
}

int main(int argc, char *argv[])
{
    cin >> X1 >> Y1 >> X2 >> Y2;

    glutInit(&argc, argv);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("DDA Algorithm");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glOrtho(-200, 200, -150, 150, -1, 1);
    glutDisplayFunc(displayMe);
    glutMainLoop();

    return 0;
}
