#include <iostream>
#include <cmath>

using namespace std;

int n = 0;
char input;

int main() {

    do {
        cout << endl;
        cout << "FORMAT <a>" << endl;
        cout << "wash   <b>" << endl;
        cout << "end    <d>" << endl;
        cout << endl;

        cout << "Your input:";
        cin >> input;
        cout << endl;

        switch(input) {
            case 'a': 
                cout << "Initializing formatting" << endl;
                break;
            case 'd':
                break;
            default: 
                cout << "Invalid input" << endl;
        }
    } while (input != 'd');

    return 0;
}