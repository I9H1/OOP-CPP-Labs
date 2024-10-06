#pragma once
#include <list>
#include <string>

using namespace std;

class Tokenizer {
    private:
        list<string> tokens;
    public:
        void get_tokens(string line);
        bool is_list_empty();
        string get_last_token();
        void remove_last_token();
};
