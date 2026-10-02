//DONE!!!

#include <sstream>
#include <iomanip>
#include "clothing.h"
#include "util.h"
using namespace std;

Clothing::Clothing(string productName, double productPrice, int productQuantity, string clothingSize, string clothingBrand) : Product("clothing", productName, productPrice, productQuantity) {
    size_ = clothingSize;
    brand_ = clothingBrand;
}

Clothing::~Clothing() { 

}

set<string> Clothing::keywords() const {

    set<string> keywordSet;
    set<string> nameWords = parseStringToWords(name_);
    set<string> brandWords = parseStringToWords(brand_);
    set<string>::iterator nameIterator;
    set<string>::iterator brandIterator;

    for(nameIterator = nameWords.begin(); nameIterator != nameWords.end(); ++nameIterator) {
        keywordSet.insert(*nameIterator);
    }

    for(brandIterator = brandWords.begin(); brandIterator != brandWords.end(); ++brandIterator) {
        keywordSet.insert(*brandIterator);
    }

    //keywordSet.insert(size_);    size isnt a keyword
    return keywordSet;
}

string Clothing::displayString() const {

    stringstream displayStream;
    displayStream << name_ << "\n";
    displayStream << "Size: " << size_ << " Brand: " << brand_ << "\n";
    displayStream << fixed << setprecision(2) << price_ << " " << qty_ << " left.";
    return displayStream.str();
}

void Clothing::dump(ostream& outputStream) const {
    outputStream << category_ << "\n";
    outputStream << name_ << "\n";
    outputStream << fixed << setprecision(2) << price_ << "\n";
    outputStream << qty_ << "\n";
    outputStream << size_ << "\n";
    outputStream << brand_ << endl;
}