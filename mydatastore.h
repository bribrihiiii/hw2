//DONE!!!

#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <vector>
#include <set>
#include <map>
#include "datastore.h"
#include "product.h"
#include "user.h"

class MyDataStore : public DataStore {

public:
    MyDataStore();
    ~MyDataStore();

    void addProduct(Product* newProduct);
    void addUser(User* newUser);

    std::vector<Product*> search(std::vector<std::string>& terms, int type);

    void dump(std::ostream& ofile);

    // extra commands for the menu
    bool addToCart(std::string username, std::vector<Product*>& hits, int hitNumber);

    bool viewCart(std::string username);

    bool buyCart(std::string username);

private:
    std::vector<Product*> products_;
    std::vector<User*> users_;
    std::map<std::string, std::set<Product*> > index_;
    std::map<std::string, std::vector<Product*> > carts_;
};

#endif