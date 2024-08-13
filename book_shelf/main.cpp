#include "module.h"
#include <iostream> 
#include <vector>
#include <string>

using namespace std;


int main() {
    vector<vector<string>> data = read_file("books.csv");
    data.erase(data.begin());

    //Book myBook("The Great Gatsby", "F. Scott Fitzgerald", "Fiction", 7.5, "Scribner", 5);
    Shelf shelf1(data);
    shelf1.info();
    
    shelf1.books[0].display_details();
    cin.get();

    return 0;
}