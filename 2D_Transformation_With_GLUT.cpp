#include<bits/stdc++.h>
#include<windows.h>
#include <GL/glut.h>

using namespace std;

int n;
char type;

struct Node
{
    double x, y;
};
Node a[1005], b[1005];


void drawAxis() {
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
        // X-axis
        glVertex2f(-300, 0);
        glVertex2f(300, 0);

        // Y-axis
        glVertex2f(0, -300);
        glVertex2f(0, 300);
    glEnd();
}

void drawObject(Node *obj)
{
    glBegin(GL_LINES);
        for(int i=0;i<n;i++)
        {
            int next = (i+1)%n;
            glVertex2f(obj[i].x, obj[i].y);
            glVertex2f(obj[next].x, obj[next].y);
        }
    glEnd();
}

void translation()
{
    double tx , ty;
    cout << "Enter translation along X and Y\n=> ";
    cin >> tx >> ty;

    for(int i=0;i<n;i++)
    {
        b[i].x = a[i].x + tx;
        b[i].y = a[i].y + ty;
    }
}

double degToRad(double x)
{
    double PI = acos(-1);
    return (x * PI)/ 180.0;
}
void rotation()
{
    double angle;
    cout << "Enter angle of rotation\n=> ";
    cin >> angle;

    for (int i=0;i<n;i++)
    {
        b[i].x = a[i].x * cos(degToRad(angle)) - a[i].y * sin(degToRad(angle));
        b[i].y = a[i].x * sin(degToRad(angle)) + a[i].y * cos(degToRad(angle));
    }
}

void scaling()
{
    double sx, sy;
    cout << "Enter scaling ratios across X and Y\n=> ";
    cin >> sx >> sy;

    for(int i=0;i<n;i++)
    {
        b[i].x = a[i].x * sx;
        b[i].y = a[i].y * sy;
    }
}

void reflection()
{
    int choice;
    cout << "Enter your choice number for reflection\n";
    cout << "1. X-axis or it's parallel\n2. Y-axis or it's parallel\n=> ";
    cin >> choice;

    int mirrX = (choice == 1) ? -1 : 1;
    int mirrY = (choice == 1) ? 1 : -1;

    for(int i=0;i<n;i++)
    {
        b[i].x = a[i].x * mirrX;
        b[i].y = a[i].y * mirrY;
    }
}

void transformObject()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawAxis();

    glColor3f(1, 0, 0);
    drawObject(a);

    glColor3d(0, 1, 0);
    drawObject(b);

    glFlush();
}

int main(int argc, char *argv[])
{
    cout << "Enter the number of nodes\n=> ";
    cin >> n;

    cout << "Enter " << n << " coordinate pairs in clockwise or counter-clockwise\n";
    for(int i=0;i<n;i++)
    {
        cout << "=> ";
        cin >> a[i].x >> a[i].y;
    }

    cout << "Enter your choice number\n";
    cout << "Choose the transformation:\n1.Translation\n2.Rotation\n3.Scaling\n4.Reflection\n=> ";
    cin >> type;

    switch(type)
    {
        case '1':
            translation();
            break;
        case '2':
            rotation();
            break;
        case '3':
            scaling();
            break;
        case '4':
            reflection();
            break;
        default:
            break;
    }

    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("2D Transformation");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glOrtho(-300, 300, -300, 300, -1, 1);
    glutDisplayFunc(transformObject);
    glutMainLoop();

    return 0;
}
