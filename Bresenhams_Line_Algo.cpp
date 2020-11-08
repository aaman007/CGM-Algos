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

    if(X1 > X2) {
        swap(X1, X2);
        swap(Y1, Y2);
    }

    double x = X1, y = Y1;
    double m = getSlope(), delX = fabs(X1-X2), delY = fabs(Y1-Y2);
    double p0 = 2*delY - delX , param1 = 2*delY , param2 = 2*delY - 2*delX;

    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
        glVertex2f(x, y);
        for(int i=1;i<=delX;i++) {
            if(p0 < 0) {
                x++;
                p0 += param1;
            }
            else {
                x++;
                y++;
                p0 += param2;
            }
            glVertex2f(x,y);
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
    glutCreateWindow("Bresenham's Line Algorithm");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glOrtho(-200, 200, -150, 150, -1, 1);
    glutDisplayFunc(displayMe);
    glutMainLoop();

    return 0;
}
