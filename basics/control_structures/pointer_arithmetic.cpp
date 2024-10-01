#include <iostream>
#include <cmath>

using std::endl, std::cout;









int main() {

    int values[3] = {11, 12, 14};

    int *ptr = values;



    cout << *(ptr + 1) << endl;
    cout << ptr[1] << endl;
    
    cout << (ptr + 1) << endl;

    return 0;
}