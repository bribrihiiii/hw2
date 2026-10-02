//DONE


#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src) {

    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords) {

    set<string> setOfWords;

    string currentWord = "";

    int index;

    rawWords = convToLower(rawWords);
 
    for(index = 0; index < (int)rawWords.size(); index++) {

        char currentCharacter = rawWords[index];

        if(ispunct(currentCharacter) == 0 && isspace(currentCharacter) == 0) {
            currentWord = currentWord + currentCharacter;
        }

        else {
            //cout << "word is " << currentWord << endl;
            int lengthOfWord = currentWord.size();

            if(lengthOfWord >= 2) {
                setOfWords.insert(currentWord);
            }

            currentWord = "";
        }
    }
    // the last word has nothing after it so it needs its own check
    if(currentWord.size() >= 2) {
        setOfWords.insert(currentWord);
    }
 
    return setOfWords;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {

    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {

    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {

    return ltrim(rtrim(s));
}
