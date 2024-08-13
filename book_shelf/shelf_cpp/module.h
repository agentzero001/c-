#ifndef MY_MODULE_H
#define MY_MODULE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;


void function();

vector<vector<string>> read_file(const string& path);

class Book {

    std::string title;
    std::string author;
    std::string genere;
    std::string publisher;
    double height;
    bool availible;

public:
    // Constructor
    Book(std::string t, std::string a, std::string g, double h, std::string p);
    // Method to display details
    void display_details();
};


class Shelf {
public:
    vector<Book> books;
    
    // Constructor
    Shelf(const vector<vector<string>>& bookList);


    // Method to print information about the shelf
    void info();
    

private:
    // Method to convert tuples to Book objects
    vector<Book> saveBooks(const vector<vector<string>>& bookList);

    vector<vector<string>> bookList;
    size_t bookCount;
};

#endif 