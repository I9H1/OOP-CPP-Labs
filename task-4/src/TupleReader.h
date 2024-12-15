#pragma once
#include <sstream>
#include <tuple>

#include <iostream>

template<class Type>
static void parse(std::istringstream &stream, Type &value, char shield, char delim) {
    std::string tmp = "";
    char letter;
    bool is_shielded = false;
    while (stream.get(letter)) {
        if (is_shielded) {
            if (letter == shield)
                is_shielded = false;
            else
                tmp += letter;
        } else {
            if (letter == shield)
                is_shielded = true;
            else if (letter == delim or letter == '\n')
                break;
            else
                tmp += letter;
        }
    }

    if (tmp.empty()) {
        throw std::runtime_error("Empty field!");
    }
    std::istringstream value_stream(tmp);
    value_stream >> value;
    if (value_stream.fail()) {
        throw std::runtime_error("Cannot convert to asked type!");
    }
}

template<class Head, class... Tail>
struct TupleReader {
    static std::tuple<Head, Tail...> read(std::istringstream &stream, char shield, char delim) {
        Head value;
        parse(stream, value, shield, delim);
        return std::tuple_cat(std::make_tuple(value), TupleReader<Tail...>::read(stream, shield, delim));
    }
};

template<class Head>
struct TupleReader<Head> {
    static std::tuple<Head> read(std::istringstream &stream, char shield, char delim) {
        Head value;
        parse(stream, value, shield, delim);
        return std::make_tuple(value);
    }
};
