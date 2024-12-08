#pragma once
#include "Converter.h"
#include "Mix.h"
#include "Mute.h"
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
public:
    ConverterFactory();
    Converter *create(const string id) const;
    template<class Type> void add(string id);
    ~ConverterFactory();

private:
    FactoryMap factoryMap;
};

template<class Type>
void ConverterFactory::add(std::string id) {
    if (factoryMap.find(id) == factoryMap.end()) {
        factoryMap[id] = new ConverterCreator<Type>;
    }
}
