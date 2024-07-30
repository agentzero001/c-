#include <iostream>
#include <cmath>

using namespace std;


int i = 13;
int werte[3] = {11, 12, 14};

int *ptr1 = &i;
int *ptr2 = ptr1;
int *ptr3  = werte;
double *ptr4 = nullptr;

int a;

int *pointer = &a;


struct Demo {int *x; int *y;};

Demo obj;


int main() {
    *pointer = 7;

    obj.x = new int;
    obj.y = new int;



    *(obj.x) = 1;
    *(obj.y) = 2;
    
    cout << (obj.y) << (obj.x) << endl;

    return 0;
}