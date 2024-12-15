#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <tuple>
#include "TupleReader.h"

#include <iostream>

template<class... Types>
class CSVParser {
private:
    std::ifstream &file;
    int line_number;
    char shield;
    char delim;
    std::streampos begin_pos;

public:
    explicit CSVParser(std::ifstream &file, int lines_to_skip = 0, char delim = ';', char shield = '\"')
        : file(file), shield(shield), delim(delim) {
        for (line_number = 0; line_number < lines_to_skip; ++line_number) {
            std::string tmp;
            getline(file, tmp);
        }
        begin_pos = file.tellg();
    }
    class Iterator {
    private:
        std::ifstream *file;
        int line_number;
        std::string line;
        std::tuple<Types...> line_tuple;
        char shield;
        char delim;

        void parseLine() {
            std::istringstream stream(line);
            line_tuple = TupleReader<Types...>::read(stream, shield, delim);
        }

    public:
        Iterator(std::ifstream *file, int line_number, char shield, char delim)
            : file(file), line_number(line_number), shield(shield), delim(delim) {
            ++(*this);
        }
        Iterator() : file(nullptr) {}
        bool operator!=(const Iterator &other) const {
            return file != other.file;
        }
        Iterator &operator++() {
            if (file && getline(*file, line)) {
                ++line_number;
                try {
                    parseLine();
                } catch (const std::exception& error) {
                    throw std::runtime_error("Error in line " + std::to_string(line_number) + ": " + error.what());
                }
            } else {
                file = nullptr;
            }
            return *this;
        }
        std::tuple<Types...> operator*() const {
            return line_tuple;
        }
    };
    Iterator begin() {
        file.clear();
        file.seekg(begin_pos);
        return Iterator(&file, line_number, shield, delim);
    }
    Iterator end() {
        return Iterator();
    }
};
