#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


struct Book {
    string title;
    string author;
    string publisher;
    string genre;
};

void PrintAllBooks(const Book books[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Book " << i + 1 << ":\n";
        cout << "Title: " << books[i].title << "\n";
        cout << "Author: " << books[i].author << "\n";
        cout << "Publisher: " << books[i].publisher << "\n";
        cout << "Genre: " << books[i].genre << "\n";
        cout << "--------------------------\n";
    }
}

void EditBook(Book& book) {
    cout << "Editing book...\n";
    cout << "Enter new title: ";
    cin.ignore();
    getline(cin, book.title);
    cout << "Enter new author: ";
    getline(cin, book.author);
    cout << "Enter new publisher: ";
    getline(cin, book.publisher);
    cout << "Enter new genre: ";
    getline(cin, book.genre);
}

void SearchByAuthor(const Book books[], int size, const string& author) {
    cout << "Books by author " << author << ":\n";
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (books[i].author == author) {
            cout << "Title: " << books[i].title << "\n";
            cout << "Publisher: " << books[i].publisher << "\n";
            cout << "Genre: " << books[i].genre << "\n";
            cout << "--------------------------\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No books found by this author.\n";
    }
}

void SearchByTitle(const Book books[], int size, const string& title) {
    cout << "Searching for book titled \"" << title << "\":\n";
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (books[i].title == title) {
            cout << "Author: " << books[i].author << "\n";
            cout << "Publisher: " << books[i].publisher << "\n";
            cout << "Genre: " << books[i].genre << "\n";
            cout << "--------------------------\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No book found with this title.\n";
    }
}

void SortByTitle(Book books[], int size) {
    sort(books, books + size, [](const Book& a, const Book& b) {
        return a.title < b.title;
        });
    cout << "Books sorted by title.\n";
}

void SortByAuthor(Book books[], int size) {
    sort(books, books + size, [](const Book& a, const Book& b) {
        return a.author < b.author;
        });
    cout << "Books sorted by author.\n";
}

void SortByPublisher(Book books[], int size) {
    sort(books, books + size, [](const Book& a, const Book& b) {
        return a.publisher < b.publisher;
        });
    cout << "Books sorted by publisher.\n";
}


//struct Date {
//	string name;
//	int firstmark;
//	int secondmark;
//	int therdmark;
//	//string therdmark;
//	int fourthmark;
//};
//
//union {
//	short a;
//	int b;
//	long c;
//} u;
//
//void Show(Date dat) {
//	cout << "name: " << dat.name << endl;
//	cout << "first mark: " << dat.firstmark << endl;
//	cout << "second mark: " << dat.secondmark << endl;
//	cout << "therd mark: " << dat.therdmark << endl;
//	cout << "fourth mark: " << dat.fourthmark << endl;
//}
//Date Initialize()
//{
//	Date d;
//	cout << "Enter name: ";
//	cin >> d.name;
//	cout << "Enter first mark: ";
//	cin >> d.firstmark;
//	cout << "Enter second mark: ";
//	cin >> d.secondmark;
//	cout << "Enter therd mark: ";
//	cin >> d.therdmark;
//	cout << "Enter fourth mark: ";
//	cin >> d.fourthmark;
//	return d;
//}


int main()
{
    const int SIZE = 10;
    Book library[SIZE] = {
        {"The Great Gatsby", "F. Scott Fitzgerald", "Scribner", "Novel"},
        {"To Kill a Mockingbird", "Harper Lee", "J.B. Lippincott & Co.", "Fiction"},
        {"1984", "George Orwell", "Secker & Warburg", "Dystopian"},
        {"Moby Dick", "Herman Melville", "Harper & Brothers", "Adventure"},
        {"Pride and Prejudice", "Jane Austen", "T. Egerton", "Romance"},
        {"War and Peace", "Leo Tolstoy", "The Russian Messenger", "Historical"},
        {"The Catcher in the Rye", "J.D. Salinger", "Little, Brown and Company", "Novel"},
        {"The Hobbit", "J.R.R. Tolkien", "George Allen & Unwin", "Fantasy"},
        {"Crime and Punishment", "Fyodor Dostoevsky", "The Russian Messenger", "Philosophical"},
        {"Brave New World", "Aldous Huxley", "Chatto & Windus", "Science Fiction"}
    };//самі назви книг (Book library[SIZE] = {...}) писав chat GPT бо писати код легше ніж придумувати назви, автора та титульну сторінку книг.

    int choice;
    do {
        cout << "Library Menu:\n";
        cout << "1. Edit a book\n";
        cout << "2. Print all books\n";
        cout << "3. Search books by author\n";
        cout << "4. Search book by title\n";
        cout << "5. Sort books by title\n";
        cout << "6. Sort books by author\n";
        cout << "7. Sort books by publisher\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int index;
            cout << "Enter book index to edit (1-10): ";
            cin >> index;
            if (index >= 1 && index <= SIZE) {
                EditBook(library[index - 1]);
            }
            else {
                cout << "Invalid index.\n";
            }
            break;
        }
        case 2:
            PrintAllBooks(library, SIZE);
            break;
        case 3: {
            cout << "Enter author to search: ";
            string author;
            cin.ignore();
            getline(cin, author);
            SearchByAuthor(library, SIZE, author);
            break;
        }
        case 4: {
            cout << "Enter title to search: ";
            string title;
            cin.ignore();
            getline(cin, title);
            SearchByTitle(library, SIZE, title);
            break;
        }
        case 5:
            SortByTitle(library, SIZE);
            break;
        case 6:
            SortByAuthor(library, SIZE);
            break;
        case 7:
            SortByPublisher(library, SIZE);
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
    

//	/*u.a = 10;
//	cout << u.a << endl;
//	u.b = 165156165;
//	cout << u.b << endl;
//	cout << u.a << endl;*/
//	//Date d1{ 2,11,2024, "Saturday", 6};
//	//cout << d1.day << ":" << d1.mounth << ":" << d1.year << ":" << d1.nameOfDay << ":" << d1.weekday << endl;
//	Date d2;
//	d2 = Initialize();
//	Show(d2);
//	//cout << "************************\n";
//	////Show(d2);
//	//Date* dptr = &d1;
//	//cout << "Day : " << dptr->day;
//	//if (dptr->day > 31)
//	//{
//	//	cout << "Invalid" << endl;
//	//}
}

