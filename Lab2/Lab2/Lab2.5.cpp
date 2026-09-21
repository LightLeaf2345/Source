#include <iostream>
#include <cstring>
using namespace std;

#define MAX_BOOKS 100

struct Book {
    char code[7];         
    char title[31];    
    int publicationYear; 
    int price;            
};

void inputBooks(Book books[], int& n) {
    cout << "So Luong Sach: ";
    cin >> n;
    cin.ignore();  

    for (int i = 0; i < n; i++) {
        cout << "MaSach: ";
        cin.getline(books[i].code, 7);
        cout << "TuaSach: ";
        cin.getline(books[i].title, 31);
        cout << "NamXuatBan: ";
        cin >> books[i].publicationYear;
        cout << "Gia: ";
        cin >> books[i].price;
        cin.ignore();  
    }
}

void displayBooks(const Book books[], int n) {
    cout << "Danh Sach Sach:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "MaSach: " << books[i].code
            << ", TuaSach: " << books[i].title
            << ", NamXuatBan: " << books[i].publicationYear
            << ", Gia: " << books[i].price << endl;
    }
}

void updateBookPriceByTitle(Book books[], int n, const char* title, int newPrice) {
    for (int i = 0; i < n; i++) {
        if (strcmp(books[i].title, title) == 0) {
            books[i].price = newPrice;
            cout << "Gia sach \"" << title << "\" da duoc cap nhat thanh: " << newPrice << endl;
            return;
        }
    }
    cout << "Sach co TuaSach \"" << title << "\" khong tim thay." << endl;
}

int main() {
    Book books[MAX_BOOKS];
    int n = 0;
    inputBooks(books, n);
    displayBooks(books, n);
    updateBookPriceByTitle(books, n, "Example Title", 300); 
    return 0;
}
