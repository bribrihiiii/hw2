//DONE!!!

#ifndef CLOTHING_H
#define CLOTHING_H
#include <string>
#include <set>
#include "product.h"

class Clothing : public Product {

public:
    Clothing(std::string productName, double productPrice, int productQuantity, std::string clothingSize, std::string clothingBrand);
    ~Clothing();

    std::set<std::string> keywords() const;
    std::string displayString() const;
    void dump(std::ostream& outputStream) const;

private:
    std::string size_;
    std::string brand_;
};

#endif