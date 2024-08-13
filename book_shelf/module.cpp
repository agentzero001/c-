#include "module.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>


using namespace std;

// constructor definition
Book::Book(std::string t, std::string a, std::string g, double h, std::string p):
    title(t), author(a), genere(g), height(h), publisher(p), availible(true) {}

// Method to display details
void Book::display_details() {
    std::string status = availible ? "availible" : "checked out";
    std::cout << "Title: " << title
              << ", Author: " << author
              << ", Genere: " << genere
              << ", Height: " << height
              << ", Publisher: " << publisher
              << ", Status: " << status
              << std::endl;
}


Shelf::Shelf(const std::vector<std::vector<std::string>> &bookList)
    : bookList(bookList), bookCount(bookList.size()), books(saveBooks(bookList)) {}

vector<Book> Shelf::saveBooks(const vector<vector<string>>& bookList) {
    vector<Book> booksVector;

    for (const vector<string> &book : bookList) {  
        
        if (book.size() != 5) {
            throw std::invalid_argument("Each book must have exactly 5 details: title, author, genre, height, publisher");
        }
        
        
        booksVector.emplace_back(
            book[0],                  
            book[1],                  
            book[2],            
            std::stod(book[3]),
            book[4]
            );                   
    }
    
    return booksVector;
}


void Shelf::info() {
    cout << "SUCCESS" << endl;
}

vector<vector<string>> read_file(const string& path){
    vector<vector<string>> data; 
    string line;
    ifstream file(path);
    if (!file.is_open()) {
        cerr << "Error opening file: " << path << endl;
        return data;
    }
    while (getline(file, line)) {
        stringstream ss(line);
        string value;
        vector<string> row;
        // Split the line by commas to extract values
        while (getline(ss, value, ',')) {
            row.push_back(value);
        }
        data.push_back(row);
    }
    file.close();
    return data;
}




