//DONE!!!

#include <sstream>
#include <iomanip>
#include "book.h"
#include "util.h"
using namespace std;

Book::Book(string productName, double productPrice, int productQuantity, string bookIsbn, string bookAuthor) : Product("book", productName, productPrice, productQuantity) {

    isbn_ = bookIsbn;
    author_ = bookAuthor;
}

Book::~Book() {

}

set<string> Book::keywords() const {

    set<string> keywordSet;
    set<string> nameWords = parseStringToWords(name_);
    set<string> authorWords = parseStringToWords(author_);
    set<string>::iterator nameIterator;
    set<string>::iterator authorIterator;

    for(nameIterator = nameWords.begin(); nameIterator != nameWords.end(); ++nameIterator) {
        keywordSet.insert(*nameIterator);
    }
        

    for(authorIterator = authorWords.begin(); authorIterator != authorWords.end(); authorIterator++) {
        keywordSet.insert(*authorIterator);
    }
        

    string lowerCaseIsbn = convToLower(isbn_);
    keywordSet.insert(lowerCaseIsbn);
    return keywordSet;
}

string Book::displayString() const {

    stringstream displayStream;
    displayStream << name_ << "\n";
    displayStream << "Author: " << author_ << " ISBN: " << isbn_ << "\n";
    displayStream << fixed << setprecision(2) << price_;
    displayStream << " ";
    displayStream << qty_;
    displayStream << " left.";
    return displayStream.str();
}

void Book::dump(ostream& outputStream) const {
    outputStream << category_ << "\n";
    outputStream << name_ << "\n";
    outputStream << fixed << setprecision(2) << price_ << "\n";
    outputStream << qty_ << "\n";
    outputStream << isbn_ << "\n";
    outputStream << author_ << endl;
}