#pragma once
#include "Converter.h"
#include "Mix.h"
#include "Mute.h"
#include "Slow.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

class AbstractConverterCreator {
public:
    virtual Converter *create() const = 0;
};

template<class Type>
class ConverterCreator : public AbstractConverterCreator {
public:
    Converter *create() const override { return new Type(); }
};

typedef map<string, AbstractConverterCreator *> FactoryMap;

class ConverterFactory {
private:
    FactoryMap factoryMap;

public:
    ConverterFactory();
    Converter *create(const string id) const;
    template<class Type>
    void add(string id);
    void printDescription();
    ~ConverterFactory();
};

template<class Type>
void ConverterFactory::add(std::string id) {
    if (factoryMap.find(id) == factoryMap.end()) {
        factoryMap[id] = new ConverterCreator<Type>;
    }
}
