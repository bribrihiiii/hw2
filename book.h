//DONE!!!

#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <set>
#include "product.h"

class Book : public Product {

public:
    Book(std::string productName, double productPrice, int productQuantity, std::string bookIsbn, std::string bookAuthor);

    ~Book();

    std::set<std::string> keywords() const;
    std::string displayString() const;

    void dump(std::ostream& outputStream) const;

private:
    std::string isbn_;
    std::string author_;
};

#endif