#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

void loop() {
    for (int i = 1; i <= 7; ++i) {
        if (i == 5)
            continue;

        cout << "Quadrat von " << i << ": " << i * i << endl;
    }
}

void loop2() {
    for (int i = 1; i <= 7; ++i) {
        if (i == 5)
            break;

        cout << "Quadrat von " << i << ": " << i * i << endl;
    }
}


void loop3() {
    cout << endl;
    int number;

    while(true) {
        cout << "Type a number (0 to end): ";
        cin >> number;

        if (number == 0)
            break;

        cout << " 2^" << number << " = " << pow(2.0, number);
        cout << endl << endl;

    }
}

int main() {
    
    loop3();

    return 0;
}