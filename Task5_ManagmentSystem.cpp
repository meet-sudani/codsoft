#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    string isbn;
    bool available = true;
};

int main() {
    vector<Book> library;
    int choice;

    do {
        cout << "\n========== LIBRARY MANAGEMENT SYSTEM ==========\n";
        cout << "1. Add Book\n";
        cout << "2. View All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Calculate Fine\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {

        case 1: {
            Book b;

            cout << "Enter Book Title: ";
            getline(cin, b.title);

            cout << "Enter Author Name: ";
            getline(cin, b.author);

            cout << "Enter ISBN: ";
            getline(cin, b.isbn);

            b.available = true;

            library.push_back(b);

            cout << "\nBook Added Successfully!\n";
            break;
        }

        case 2: {
            if(library.empty()) {
                cout << "\nNo Books Available!\n";
            } else {
                cout << "\n----------- BOOK LIST -----------\n";
                for(int i = 0; i < library.size(); i++) {
                    cout << "\nBook " << i + 1 << endl;
                    cout << "Title : " << library[i].title << endl;
                    cout << "Author: " << library[i].author << endl;
                    cout << "ISBN  : " << library[i].isbn << endl;
                    cout << "Status: ";

                    if(library[i].available)
                        cout << "Available\n";
                    else
                        cout << "Issued\n";
                }
            }
            break;
        }

        case 3: {
            string searchTitle;
            bool found = false;

            cout << "Enter Book Title: ";
            getline(cin, searchTitle);

            for(int i = 0; i < library.size(); i++) {
                if(library[i].title == searchTitle) {
                    cout << "\nBook Found!\n";
                    cout << "Title : " << library[i].title << endl;
                    cout << "Author: " << library[i].author << endl;
                    cout << "ISBN  : " << library[i].isbn << endl;

                    if(library[i].available)
                        cout << "Status: Available\n";
                    else
                        cout << "Status: Issued\n";

                    found = true;
                    break;
                }
            }

            if(!found)
                cout << "Book Not Found!\n";

            break;
        }

        case 4: {
            string title;
            bool found = false;

            cout << "Enter Book Title to Issue: ";
            getline(cin, title);

            for(int i = 0; i < library.size(); i++) {

                if(library[i].title == title) {

                    if(library[i].available) {
                        library[i].available = false;
                        cout << "Book Issued Successfully!\n";
                    } else {
                        cout << "Book Already Issued!\n";
                    }

                    found = true;
                    break;
                }
            }

            if(!found)
                cout << "Book Not Found!\n";

            break;
        }

        case 5: {
            string title;
            bool found = false;

            cout << "Enter Book Title to Return: ";
            getline(cin, title);

            for(int i = 0; i < library.size(); i++) {

                if(library[i].title == title) {

                    if(!library[i].available) {
                        library[i].available = true;
                        cout << "Book Returned Successfully!\n";
                    } else {
                        cout << "Book is Already Available!\n";
                    }

                    found = true;
                    break;
                }
            }

            if(!found)
                cout << "Book Not Found!\n";

            break;
        }

        case 6: {
            int days;
            double fine = 0;

            cout << "Enter Number of Overdue Days: ";
            cin >> days;

            if(days > 0)
                fine = days * 5;

            cout << "Total Fine = Rs. " << fine << endl;
            break;
        }

        case 7:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while(choice != 7);

    return 0;
}