#include "ConverterFactory.h"

using namespace std;

ConverterFactory::ConverterFactory() {
    add<Mix>("mix");
    add<Mute>("mute");
    add<Slow>("slow");
}

Converter *ConverterFactory::create(const string id) const {
    if (factoryMap.find(id) != factoryMap.end()) {
        return factoryMap.find(id)->second->create();
    }
    return NULL;
}

ConverterFactory::~ConverterFactory() {
    for (auto i = factoryMap.begin(); i != factoryMap.end(); ++i) {
        delete i->second;
    }
}

void ConverterFactory::printDescription() {
    for (auto i: factoryMap) {
        Converter *converter = i.second->create();
        cout << "=================================================================\n";
        cout << converter->getDescription();
    }
}
