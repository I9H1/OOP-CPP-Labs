#include "Tokenizer.h"

using namespace std;

void Tokenizer::get_tokens(std::string line) {
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
    Tokenizer::tokens = tokens;
}

bool Tokenizer::is_list_empty() {
    return tokens.empty();
}

string Tokenizer::get_last_token() {
    return tokens.back();
}

void Tokenizer::remove_last_token() {
    tokens.pop_back();
}
