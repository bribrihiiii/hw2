//DONE!!!

#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <set>
#include "product.h"

class Movie : public Product {

public:
    Movie(std::string productName, double productPrice, int productQuantity, std::string movieGenre, std::string movieRating);

    ~Movie();
    std::set<std::string> keywords() const;
    std::string displayString() const;
    void dump(std::ostream& outputStream) const;

private:
    std::string genre_;
    std::string rating_;
};

#endif