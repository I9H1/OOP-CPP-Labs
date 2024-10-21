#include "Tokenizer.h"

using namespace std;

list<string> Tokenizer::getTokens(std::string line) {
    list<string> tokens;
    string word;
    for (char letter : line) {
        if (isalnum(letter)) {
            word += letter;
        } else if (word !=  "") {
            tokens.push_back(word);
            word = "";
        }
    }
    if (word != "") {
        tokens.push_back(word);
    }
    return tokens;
}
