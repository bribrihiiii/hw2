//DONE!!!

#include <iostream>
#include <iomanip>
#include "mydatastore.h"
#include "util.h"
using namespace std;

MyDataStore::MyDataStore() {

}

MyDataStore::~MyDataStore() {

    for(unsigned int index = 0; index < products_.size(); index++) {

        delete products_[index];
    }
        
    for(unsigned int index = 0; index < users_.size(); index++) {

        delete users_[index];

    } 
}

void MyDataStore::addProduct(Product* newProduct) {

    products_.push_back(newProduct);
    set<string> keywordSet = newProduct->keywords();
    set<string>::iterator keywordIterator;

    for(keywordIterator = keywordSet.begin(); keywordIterator != keywordSet.end(); ++keywordIterator) {

        index_[*keywordIterator].insert(newProduct);
    }
}

void MyDataStore::addUser(User* newUser) {

    users_.push_back(newUser);
    vector<Product*> emptyCart;
    carts_[convToLower(newUser->getName())] = emptyCart;
}

vector<Product*> MyDataStore::search(vector<string>& terms, int type) {

    vector<Product*> finalResults;
    int numberOfTermsCombined = 0;
    if(terms.size() == 0) return finalResults;

    set<Product*> currentResults;

    if(index_.find(terms[0]) != index_.end()){

        currentResults = index_[terms[0]];
    }

    for(unsigned int termIndex = 1; termIndex < terms.size(); termIndex++) {

        set<Product*> productsForThisTerm;

        if(index_.find(terms[termIndex]) != index_.end()) {

            productsForThisTerm = index_[terms[termIndex]];
        }

        if(type == 0) {

            currentResults = setIntersection(currentResults, productsForThisTerm);
        }

        else {
            currentResults = setUnion(currentResults, productsForThisTerm);
        }

        numberOfTermsCombined++;
    }

    set<Product*>::iterator resultsIterator;

    for(resultsIterator = currentResults.begin(); resultsIterator != currentResults.end(); ++resultsIterator) {

        finalResults.push_back(*resultsIterator);
    }

    return finalResults;
}

void MyDataStore::dump(ostream& ofile) {

    ofile << fixed << setprecision(2);
    ofile << "<products>" << endl;

    for(unsigned int index = 0; index < products_.size(); index++) {
        products_[index]->dump(ofile);
    }

    ofile << "</products>" << endl;
    ofile << "<users>" << endl;

    for(unsigned int index = 0; index < users_.size(); index++) {

        users_[index]->dump(ofile);


    }
        

    ofile << "</users>" << endl;
}

bool MyDataStore::addToCart(string username, vector<Product*>& hits, int hitNumber) {

    // find the user
    User* foundUser = NULL;

    for(unsigned int index = 0; index < users_.size(); index++) {

        if(convToLower(users_[index]->getName()) == convToLower(username)) {
            foundUser = users_[index];
        }
    }

    if(foundUser == NULL) {
        return false;
    }

    if(hitNumber < 1) {
        return false;
    }

    if(hitNumber > (int)hits.size()) { 
        return false;
    }

    //cout << "adding " << hitNumber << endl;
    string lowerCaseUsername = convToLower(username);
    carts_[lowerCaseUsername].push_back(hits[hitNumber-1]);

    return true;
}

bool MyDataStore::viewCart(string username) {

    // find the user (same as above, copy pasted)
    User* foundUser = NULL;
    for(unsigned int index = 0; index < users_.size(); index++) {

        if(convToLower(users_[index]->getName()) == convToLower(username)) {
            foundUser = users_[index];
        }
    }

    if(foundUser == NULL) {
        return false;
    }

    vector<Product*> cartContents = carts_[convToLower(username)];
    for(unsigned int index = 0; index < cartContents.size(); index++) {

        cout << "Item " << setw(3) << index+1 << endl;
        cout << cartContents[index]->displayString() << endl;
        cout << endl;
    }

    return true;
}

bool MyDataStore::buyCart(string username) {
    // find the user (copy pasted AGAIN)
    User* foundUser = NULL;
    for(unsigned int index = 0; index < users_.size(); index++) {

        if(convToLower(users_[index]->getName()) == convToLower(username)) {
            foundUser = users_[index];
        }
    }

    if(foundUser == NULL) {
        return false;
    }

    vector<Product*> cartContents = carts_[convToLower(username)];
    vector<Product*> itemsThatDidNotGetBought;

    for(unsigned int index = 0; index < cartContents.size(); index++) {

        bool inStock = false;
        bool canAfford = false;

        if(cartContents[index]->getQty() > 0) {
            inStock = true;
        }

        if(foundUser->getBalance() >= cartContents[index]->getPrice()) { 
            canAfford = true;
        }

        if(inStock == true && canAfford == true) {
            cartContents[index]->subtractQty(1);
            foundUser->deductAmount(cartContents[index]->getPrice());
        }

        else {
            itemsThatDidNotGetBought.push_back(cartContents[index]);
        }
    }

    carts_[convToLower(username)] = itemsThatDidNotGetBought;
    return true;
}