#include<iostream>
#include <string>
using namespace std;

class Library{
public:
    Library();

    bool addBook(string bookName);

    bool removeBook(string bookName);

    void print();

private:
    string books[10];
    int bookCount; // to keep track of the number of books
};

Library::Library() : bookCount(0)
{
    for(int i=0;i<10;i++)
    {
        books[i]="";
    }
}

bool Library::addBook(string bookName)
{
    if(bookCount >= 10) return false; // library is full

    for(int i=0;i<10;i++)
    {
        if(books[i]==bookName) return false; // book already exists
        if(books[i]=="") // found an empty slot
        {
            books[i] = bookName;
            bookCount++;
            return true;
        }
    }
    return false;
}

bool Library::removeBook(string bookName)
{
    for(int i=0;i<10;i++)
    {
        if(books[i]==bookName) // found the book
        {
            books[i] = "";
            bookCount--;
            return true;
        }
    }
    return false; // book not found
}

void Library::print()
{
    for(int i=0;i<10;i++)
    {
        if(books[i] != "") // print only non-empty strings
        {
            cout << books[i] << endl;
        }
    }
}

int main()
{
    Library library;
    string bookName;
    char command;

    while(true)
    {
        cout<<"Enter a command : ";
        cin>>command;

        if(command=='q')
         {
            cout<<"Exiting"<<endl;
            break;
        }

        else if(command=='p')
        {
            cout<<"Library contents: "<<endl;
            library.print();
        }
        
        else if(command=='a')
         {
            cin>>bookName;
            library.addBook(bookName);
        }
        
        else if(command=='r')
        {
            cin>>bookName;
            library.removeBook(bookName);
        }
    }
    return 0;
}