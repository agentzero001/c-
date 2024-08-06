#include <iostream>
#include <cmath>


using namespace std;


struct Point {int x; int y;};

int main() {

    const int MAX_POINTS = 3;
    Point points[MAX_POINTS];

    for (int i = 0; i < MAX_POINTS; i++) {
        cout << endl;
        cout << " " << i+1 << ". Point" << endl;
        
        cout << " x:";
        cin >> points[i].x;

        cout << " y:";
        cin >> points[i].y;
    }

    cout << endl;

    double distance = 0.0;

    int index = -1;

    for (int i = 0; i < MAX_POINTS; i++) {
        
        double d = sqrt((double) points[i].x * points[i].x + points[i].y * points[i].y);

        if (d > distance) {
            distance = d;
            index = i;
        }
    }

    cout << endl;
    cout << "The farthest point is: " << "(" << points[index].x << "," << points[index].x << ")";
    cout << endl << endl;
}