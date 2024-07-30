#include <iostream>
#include <cmath>

using namespace std;

class Point {
    //won't be able to access any of these outside the class
    //these are private by default as well
    //private:
    int x;
    int y;
    
    public: 

    Point() {x = 0; y = 0;}
    Point(int n, int m) {x = n; y = m;}


    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    void get_values() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};


class Point2 {
    public: 
    
    int x;
    int y;

    //this is one hell of a syntax
    Point2(int x_val, int y_val): x(x_val), y(y_val) {
        //when the instance is created this code is going to run as well
         cout << "Point2 created at (" << x << ", " << y << ")" << endl;
    }

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }
};



Point p1(2, 3);
Point2 p2(2, 3);


int main() {

    p1.move(3, 4);
    p2.move(1, 2);

    p1.get_values();
    cout << p2.x << p2.y << endl;

    return 0;
}
