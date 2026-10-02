//DONE!!!

#include <sstream>
#include <iomanip>
#include "movie.h"
#include "util.h"
using namespace std;

Movie::Movie(string productName, double productPrice, int productQuantity, string movieGenre, string movieRating) : Product("movie", productName, productPrice, productQuantity) {

    genre_ = movieGenre;
    rating_ = movieRating;
}

Movie::~Movie() {

}

set<string> Movie::keywords() const {

    set<string> keywordSet;
    set<string> nameWords = parseStringToWords(name_);
    set<string>::iterator nameIterator;

    for(nameIterator = nameWords.begin(); nameIterator != nameWords.end(); ++nameIterator) {
        keywordSet.insert(*nameIterator);
    }

    string lowerCaseGenre = convToLower(genre_);
    keywordSet.insert(lowerCaseGenre);

    //keywordSet.insert(rating_);   not needed i think
    return keywordSet;
}

string Movie::displayString() const {

    stringstream displayStream;
    displayStream << name_ << "\n";
    displayStream << "Genre: " << genre_ << " Rating: " << rating_ << "\n";
    displayStream << fixed << setprecision(2) << price_ << " " << qty_ << " left.";
    return displayStream.str();

}

void Movie::dump(ostream& outputStream) const {

    outputStream << category_ << "\n";
    outputStream << name_ << "\n";
    outputStream << fixed << setprecision(2) << price_ << "\n";
    outputStream << qty_ << "\n";
    outputStream << genre_ << "\n";
    outputStream << rating_ << endl;
}