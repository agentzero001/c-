
class Book:
    def __init__(self, title, author, genere, height, publisher):
        self.title = title
        self.author = author
        self.genere = genere
        self.publisher = publisher
        self.height = height
        self.availible = True
        
    def display_details(self):
        status = 'availible' if self.availible else 'check out'
        print("Title: {}, Author: {}, Genere: {}, Height: {}, Publisher: {},  Status: {}".format(self.title,
                                                                                                 self.author,
                                                                                                 self.genere,                                                                                       self.height,
                                                                                                 self.publisher,
                                                                                                 status))        
class Shelf:
    def __init__(self, book_list):
        self.book_list = book_list
        self.book_count = len(book_list)
        self.books = self.save_books()
    
    def save_books(self):
        return [Book(*book) for book in self.book_list]
    
    def info(self):
        print("book count: {}".format(len(self.books)))
    
               
        
