//LIBRARY MANAGMENT SYSTEM IN C++
#include<iostream>
#include<cstring>
using namespace std;

struct Book
{
    string Title;
    string Author;
    int ISBN;
    int copies;
};

void add_books(Book* library[], int& num_books)
{
    cout << "Enter title of book: ";
    cin >> library[num_books]->Title;

    cout << "Enter author of book: ";
    cin >> library[num_books]->Author;

    cout << "Enter ISBN of book: ";
    cin >> library[num_books]->ISBN;

    cout << "Enter number of copies of book: ";
    cin >> library[num_books]->copies;

    num_books++;
}

void search_book(Book* library[], int num_books)
{
    int ISBN;
    cout << "Enter ISBN of book: ";
    cin >> ISBN;

    for (int i = 0; i < num_books; i++)
    {
        if (library[i]->ISBN == ISBN)
        {
            cout << "Title: " << library[i]->Title << endl;
            cout << "Author: " << library[i]->Author << endl;
            cout << "ISBN: " << library[i]->ISBN << endl;
            cout << "Number of copies: " << library[i]->copies << endl;
            return;
        }
    }
    cout << "Book not found" << endl;
}

void Display_book(Book *book)
{
    cout << "Title: " << book->Title << endl;
    cout << "Author: " << book->Author << endl;
    cout << "ISBN: " << book->ISBN << endl;
    cout << "Number of copies: " << book->copies << endl;
}

void update_book(Book *book)
{
    cout << "Enter title of book: ";
    cin >> book->Title;

    cout << "Enter author of book: ";
    cin >> book->Author;

    cout << "Enter ISBN of book: ";
    cin >> book->ISBN;

    cout << "Enter number of copies of book: ";
    cin >> book->copies;
}

void delete_book(Book* library[], int& num_books)
{
    int ISBN;
    cout << "Enter ISBN of book: ";
    cin >> ISBN;

    for (int i = 0; i < num_books; i++)
    {
        if (library[i]->ISBN == ISBN)
        {
            for (int j = i; j < num_books - 1; j++)
            {
                library[j] = library[j + 1];
            }
            num_books--;
            return;
        }
    }
    cout << "Book not found" << endl;
}

int main()
{
    Book* library[100];
    int num_books = 0;
    int choice;

    while (true)
    {
        cout << "1. Add books" << endl;
        cout << "2. Search book" << endl;
        cout << "3. Update book" << endl;
        cout << "4. Delete book" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            library[num_books] = new Book;
            add_books(library, num_books);
            break;
        case 2:
            search_book(library, num_books);
            break;
        case 3:
            search_book(library, num_books);
            update_book(library[num_books - 1]);
            break;
        case 4:
            delete_book(library, num_books);
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
