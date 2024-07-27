#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;


double measured[100];
int amount = 0;

double average = 0;
double sum = 0;




int main() {

    cout << "how many (max 100):";
    cin >> amount;
    cout << endl;

    if (amount < 0 || amount >= 100){

        cout << "invalid amount" << endl;
        return 0;
    }

    for (int i = 0; i < amount; ++i) {
        cout << "Type in the " << (i+1) <<". measurement: ";
        cin >> measured[i];
    }

    for (int i = 0; i < amount; ++i)
        sum += measured[i];

    average = sum / amount;
    
    cout << endl;
    cout << "The average is " << average << endl;

    return 0;
}