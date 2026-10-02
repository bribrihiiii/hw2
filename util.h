//DONE!!!


#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */



template <typename T>
std::set<T> setIntersection(std::set<T>& firstSet, std::set<T>& secondSet) {

    std::set<T> resultSet;
    typename std::set<T>::iterator firstSetIterator;

    for (firstSetIterator = firstSet.begin(); firstSetIterator != firstSet.end(); ++firstSetIterator) {

        //std::cout << "checking" << std::endl;
        typename std::set<T>::iterator searchIterator = secondSet.find(*firstSetIterator);

        if(searchIterator != secondSet.end()) {
            resultSet.insert(*firstSetIterator);
        }

        else {
            // not in both so skip it
        }
    }
    return resultSet;
}

////////////////////
template <typename T>
std::set<T> setUnion(std::set<T>& firstSet, std::set<T>& secondSet) {

    std::set<T> resultSet;
    typename std::set<T>::iterator firstSetIterator;
    typename std::set<T>::iterator secondSetIterator;

    for (firstSetIterator = firstSet.begin(); firstSetIterator != firstSet.end(); ++firstSetIterator) {

        resultSet.insert(*firstSetIterator);
    }

    for (secondSetIterator = secondSet.begin(); secondSetIterator != secondSet.end(); ++secondSetIterator) {

        resultSet.insert(*secondSetIterator);   // dupes dont matter
    }

    return resultSet;
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
