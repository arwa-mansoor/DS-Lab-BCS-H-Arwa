#include <iostream>
using namespace std;

int main() {
    int totalCategories;
    cout << "Enter the number of categories: ";
    cin >> totalCategories;
    
    string* categories = new string[totalCategories];

    int** books = new int*[totalCategories];
    int* noOfBooks = new int[totalCategories];

    for (int i = 0; i < totalCategories; i++) {
        cout << "Enter category " << i + 1 << " name: ";
        cin >> categories[i];

        cout << "Enter number of books in " << categories[i] << ": ";
        cin >> noOfBooks[i];

        books[i] = new int[noOfBooks[i]];

        cout << "Enter book IDs for " << categories[i] << ":\n";
        for (int j = 0; j < noOfBooks[i]; j++) {
            cout << "Book " << j + 1 << " ID: ";
            cin >> books[i][j];
        }
    }

    int searchID;
    cout << "Enter the book ID to search: ";
    cin >> searchID;

    bool found = false;
    for (int i = 0; i < totalCategories; i++) {
        for (int j = 0; j < noOfBooks[i]; j++) {
            if (books[i][j] == searchID) {
                cout << "Book with ID " << searchID << " is found in category: " << categories[i] << endl;
                found = true;
                break;
            }
        }
    }
    if (!found) {
        cout << "Book with ID " << searchID << " not found.\n";
    }

    for (int i = 0; i < totalCategories; i++) {
        delete[] books[i];
    }
    delete[] books;
    delete[] noOfBooks;
    delete[] categories;

    return 0;
}