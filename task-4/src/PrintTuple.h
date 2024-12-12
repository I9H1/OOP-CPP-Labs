#pragma once
#include <iostream>
#include <tuple>

using namespace std;

template<size_t index = 0, class Ch, class Tr, class ...Types>
void printTuple(basic_ostream<Ch, Tr>& output, const tuple<Types...>& tuple) {
    if constexpr (index < sizeof...(Types)) {
        output << get<index>(tuple);
        if constexpr (index + 1 < sizeof...(Types)) {
            output << ", ";
        }
        printTuple<index + 1>(output, tuple);
    }
}

template<class Ch, class Tr, class ...Types>
ostream& operator<<(basic_ostream<Ch, Tr>& output, const tuple<Types...>& tuple) {
    output << "(";
    printTuple(output, tuple);
    output << ")";
    return output;
}
