#include <iostream>
#include <cmath>

using std::endl, std::cout;

//references are like synonyms for variables
int i = 3;
int &ir = i;

void swap(int& a, int& b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}


int main() {
    int n1 = 1;
    int n2 = 2;

    swap(n1, n2);
    
    ir = 4;
    

    cout << ir << endl;
    cout << n1 << n2 << endl;
    return 0;
}