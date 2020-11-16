#include<bits/stdc++.h>

using namespace std;

void translation(double x, double y, double tx, double ty) {
    cout << "Translation Chosen......\n";

    double x1 = x+tx, y1 = y+ty;

    cout << "New Coordinate: " << x1 << " " << y1 << endl;
}

void rotation(double x, double y, double deg) {
    cout << "Rotating Chosen......\n";

    double x1 = x*cos(deg) - y*sin(deg);
    double y1 = x*sin(deg) + y*cos(deg);

    cout << "New coordinate: " << x1 << " " << y1 << endl;
}

void scaling(double x, double y, double sx, double sy) {
    cout << "Scaling Chosen......\n";

    double x1 = x*sx, y1 = y*sy;

    cout << "New Coordinate: " << x1 << " " << y1 << endl;
}

void mirroring(double x, double y, char axis) {
    cout << "Mirroring Chosen......\n";

    double x1, y1;
    if (axis == 'X' || axis == 'x') {
        x1 = x, y1 = -y;
    }
    else {
        x1 = -x, y1 = y;
    }

    cout << "New coordinate: " << x1 << " " << y1 << endl;
}

int main() {
    char type, axis;
    double x, y, deg, tx, ty, sx, sy;

    while(1) {
        cout << "Choose the transformation:\n1.Translation\n2.Rotating\n3.Scaling\n4.Mirroring\nAnything Else. Exit\n";
        cin >> type;

        if (type != '1' && type != '2' && type != '3' && type != '4')
            break;

        cout << "Enter the coordinate of the point: ";
        cin >> x >> y;

        switch (type) {
            case '1':
                cout << "Enter translation values: ";
                cin >> tx >> ty;
                translation(x, y, tx, ty);
                break;
            case '2':
                cout << "Enter degree : ";
                cin >> deg;
                rotation(x, y, deg);
                break;
            case '3':
                cout << "Enter scaling values: ";
                cin >> sx >> sy;
                scaling(x, y, sx, sy);
                break;
            case '4':
                cout << "Enter axis: ";
                cin >> axis;
                mirroring(x, y, axis);
                break;
            default:
                break;
        }

        cout << " ------------- END --------------- \n";
    }
}
