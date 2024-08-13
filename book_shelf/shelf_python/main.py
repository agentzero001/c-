from module import Shelf
import csv


with open('books.csv', 'r') as file:
    reader = csv.reader(file)
    data = list(reader)
    
columns = data[0]
books = data[1:]
       
shelf = Shelf(books)
shelf.info()
shelf.books[0].display_details()




# ignore this (it is how you could make a dict out of it, and then convert it back into a list)
# book_dict = {column: [] for column in columns}
# for row in books:
#     for entry, column in zip(row, columns):
#          book_dict[column].append(entry)
                  
# all_books = [[] for i in range(len(books))]

# for list_ in book_dict.values():
#     for book, i in zip(list_, range(len(list_))):
#         all_books[i].append(book)