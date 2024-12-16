#pragma once
#include <tuple>

template<class Ch, class Tr, class TupleType, std::size_t size>
struct TuplePrinter {
    static void print(std::ostream &outstream, const TupleType &tuple) {
        TuplePrinter<Ch, Tr, TupleType, size - 1>::print(outstream, tuple);
        outstream << ", " << std::get<size - 1>(tuple);
    }
};

template<class Ch, class Tr, class TupleType>
struct TuplePrinter<Ch, Tr, TupleType, 1> {
    static void print(std::basic_ostream<Ch, Tr> &outstream, const TupleType &tuple) {
        outstream << std::get<0>(tuple);
    }
};

template<class Ch, class Tr, class... Types>
std::ostream &operator<<(std::basic_ostream<Ch, Tr> &output, const std::tuple<Types...> &tuple) {
    output << "(";
    TuplePrinter<Ch, Tr, decltype(tuple), sizeof...(Types)>::print(output, tuple);
    output << ")";
    return output;
}
