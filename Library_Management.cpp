#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
private:
    string title;
    string author;
    bool isIssued;

public:
    Book(string t, string a) : title(t), author(a), isIssued(false) {}

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    bool getIssuedStatus() const {
        return isIssued;
    }

    void issueBook() {
        if (!isIssued) {
            isIssued = true;
            cout << "Book \"" << title << "\" has been issued." << endl;
        } else {
            cout << "Book \"" << title << "\" is already issued." << endl;
        }
    }

    void returnBook() {
        if (isIssued) {
            isIssued = false;
            cout << "Book \"" << title << "\" has been returned." << endl;
        } else {
            cout << "Book \"" << title << "\" was not issued." << endl;
        }
    }
};

class Member {
private:
    string name;
    int memberID;

public:
    Member(string n, int id) : name(n), memberID(id) {}

    void issueBook(Book& book) {
        book.issueBook();
    }

    void returnBook(Book& book) {
        book.returnBook();
    }

    void displayMemberInfo() const {
        cout << "Member Name: " << name << ", ID: " << memberID << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:
    Library() {}

    void addBook(const Book& book) {
        books.push_back(book);
    }

    void checkAvailability(const string& title) const {
        for (const auto& book : books) {
            if (book.getTitle() == title) {
                if (book.getIssuedStatus()) {
                    cout << "Book \"" << title << "\" is currently issued." << endl;
                } else {
                    cout << "Book \"" << title << "\" is available." << endl;
                }
                return;
            }
        }
        cout << "Book \"" << title << "\" not found in the library." << endl;
    }

    void displayAllBooks() const {
        cout << "Library Book List: " << endl;
        for (const auto& book : books) {
            cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << endl;
        }
    }
};

int main() {
    // Creating books
    Book book1("C++ Programming", "Bjarne Stroustrup");
    Book book2("Data Structures", "Mark Allen Weiss");
    Book book3("Design Patterns", "Erich Gamma");

    // Creating library
    Library library;
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    // Creating members
    Member member1("John Doe", 101);
    Member member2("Alice Smith", 102);

    // Display library books
    library.displayAllBooks();

    // Checking availability
    library.checkAvailability("C++ Programming");

    // Issue and Return books
    member1.issueBook(book1);
    member2.issueBook(book1); // Should show it's already issued

    // Return books
    member1.returnBook(book1);

    // Check availability again
    library.checkAvailability("C++ Programming");

    return 0;
}
