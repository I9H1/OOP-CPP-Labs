#include <cmath>
#include <algorithm>
#include "BitArray.h"
#define BYTE_SIZE 8

using namespace std;

int BitArray::toBytes(int size) const {
    return static_cast<int>(ceil(size / static_cast<float>(BYTE_SIZE)));
}

BitArray::BitArray(int num_bits, bool value) {
    int real_size = toBytes(num_bits);
    data = new unsigned char[real_size];
    for (int i = 0; i < real_size; ++i) {
        if (value)
            data[i] |= 255;
        else
            data[i] &= 0;
    }
    data_size = num_bits;
}

BitArray::~BitArray() {
    delete[] data;
}

int BitArray::getSize() const {
    return data_size;
}

int BitArray::getRealSize() const {
    return toBytes(data_size);
}

BitArray::BitArray(const BitArray& array) {
    int real_size = toBytes(array.data_size);
    data = new unsigned char[real_size];
    for (int i = 0; i < array.data_size; ++i) {
        data[i] = array.data[i];
    }
    data_size = array.data_size;
}

void BitArray::swap(BitArray &b) {
    unsigned char* a_data = data;
    int a_size = data_size;
    data = b.data;
    data_size = b.data_size;
    b.data = a_data;
    b.data_size = a_size;
}

void BitArray::clear() {
    resize(0);
}

void BitArray::resize(int new_num_bits, bool value) {
    if (new_num_bits < 0) {
        throw "Invalid size";
    }
    int real_size = toBytes(data_size);
    int new_real_size = toBytes(new_num_bits);
    unsigned char* new_data = new unsigned char[new_real_size];
    int last_byte = 0;
    for (int i = 0; i < min(data_size, new_num_bits) / BYTE_SIZE + 1; ++i) {
        new_data[i] = data[i];
        last_byte = i;
    }
    for (int i = real_size; i < new_real_size; ++i) {
        new_data[i] = (value)? (new_data[i] | 255) : (new_data[i] & 0);
    }
    int remainder = min(data_size, new_num_bits) % BYTE_SIZE;
    if (remainder != 0) {
        for (int i = BYTE_SIZE - remainder; i > 0; --i) {
            new_data[last_byte] = (((new_data[last_byte] >> i) << 1) | value) << (i - 1);
        }
    }
    delete[] data;
    data = new_data;
    data_size = new_num_bits;
}

void BitArray::pushBack(bool bit) {
    resize(data_size + 1, bit);
}

BitArray::Wrapper::Wrapper(int i, BitArray* array) {
    if (i >= array->data_size or i < 0) {
        throw "Wrong index";
    }
    index = i;
    link = array;
}

BitArray::Wrapper BitArray::operator[](int i) {
    Wrapper elem(i, this);
    return elem;
}

bool BitArray::operator[](int i) const {
    int byte = i / 8;
    int shift = BYTE_SIZE - i % 8 - 1;
    return (data[byte] >> shift) & 0x1;
}

BitArray::Wrapper::operator bool() const {
    const BitArray array = *link;
    return array.operator[](index);
}

BitArray::Wrapper& BitArray::Wrapper::operator=(bool value) {
    link->set(index, value);
    return *this;
}

void BitArray::set() {
    int real_size = toBytes(data_size);
    for (int i = 0; i < real_size; ++i) {
        data[i] = 255;
    }
}

void BitArray::set(int n, bool value) {
    int byte = n / 8;
    int shift = BYTE_SIZE - n % 8 - 1;
    if (value) {
        data[byte] |= (1 << shift);
    } else {
        data[byte] &= ~(1 << shift);
    }
}

void BitArray::reset() {
    int real_size = toBytes(data_size);
    for (int i = 0; i < real_size; ++i) {
        data[i] = 0;
    }
}

bool BitArray::any() const {
    for (int i = 0; i < data_size; ++i) {
        if (operator[](i)) {
            return true;
        }
    }
    return false;
}

bool BitArray::none() const {
    for (int i = 0; i < data_size; ++i) {
        if (operator[](i)) {
            return false;
        }
    }
    return true;
}

BitArray BitArray::operator~() {
    BitArray array(*this);
    for (int i = 0; i < toBytes(data_size); ++i) {
        array.data[i] = ~data[i];
    }
    return array;
}

int BitArray::count() const {
    int counter = 0;
    for (int i = 0; i < data_size; ++i) {
        counter += operator[](i);
    }
    return counter;
}

bool BitArray::isEmpty() const {
    return data_size == 0;
}

string BitArray::toString() const {
    string output = "";
    for (int i = 0; i < data_size; ++i) {
        output += (operator[](i)) ? "1" : "0";
    }
    return output;
}

bool BitArray::operator==(const BitArray &b) const {
    if (b.data_size != data_size) {
        return false;
    }
    for (int i = 0; i < data_size; ++i) {
        if (operator[](i) != b[i]) {
            return false;
        }
    }
    return true;
}

bool  BitArray::operator!=(const BitArray &b) const {
    if (b.data_size != data_size) {
        return true;
    }
    for (int i = 0; i < data_size; ++i) {
        if (operator[](i) != b[i]) {
            return true;
        }
    }
    return false;
}

BitArray BitArray::operator&(const BitArray &b) {
    if (data_size != b.data_size) {
        throw "Operation & requires same size of arrays";
    }
    BitArray array(b);
    for (int i = 0; i < data_size; ++i) {
        array[i] = b[i] & operator[](i);
    }
    return array;
}

BitArray BitArray::operator^(const BitArray &b) {
    if (data_size != b.data_size) {
        throw "Operation ^ requires same size of arrays";
    }
    BitArray array(b);
    for (int i = 0; i < data_size; ++i) {
        array[i] = b[i] ^ operator[](i);
    }
    return array;
}

BitArray BitArray::operator|(const BitArray &b) {
    if (data_size != b.data_size) {
        throw "Operation | requires same size of arrays";
    }
    BitArray array(b);
    for (int i = 0; i < data_size; ++i) {
        array[i] = b[i] | operator[](i);
    }
    return array;
}

BitArray &BitArray::operator&=(const BitArray &b) {
    if (data_size != b.data_size) {
        throw "Operation &= requires same size of arrays";
    }
    for (int i = 0; i < data_size; ++i) {
        operator[](i) = b[i] & operator[](i);
    }
    return *this;
}

BitArray &BitArray::operator|=(const BitArray &b) {
    if (data_size != b.data_size) {
        throw "Operation |= requires same size of arrays";
    }
    for (int i = 0; i < data_size; ++i) {
        operator[](i) = b[i] | operator[](i);
    }
    return *this;
}

BitArray &BitArray::operator^=(const BitArray &b) {
    if (data_size != b.data_size) {
        throw "Operation ^= requires same size of arrays";
    }
    for (int i = 0; i < data_size; ++i) {
        operator[](i) = b[i] ^ operator[](i);
    }
    return *this;
}

BitArray BitArray::operator<<(int n) const {
    if (n < 0) {
        return operator>>(-n);
    }
    if (n >= data_size) {
        return BitArray(data_size, false);
    }
    BitArray array(data_size, false);
    for (int i = n; i < data_size; ++i) {
        array[i - n] = operator[](i);
    }
    return array;
}

BitArray BitArray::operator>>(int n) const {
    if (n < 0) {
        return operator<<(-n);
    }
    if (n >= data_size) {
        return BitArray(data_size, false);
    }
    BitArray array(data_size, false);
    for (int i = 0; i < data_size - n; ++i) {
        array[i + n] = operator[](i);
    }
    return array;
}

BitArray& BitArray::operator<<=(int n) {
    if (n < 0) {
        return operator>>=(-n);
    }
    if (n >= data_size) {
        reset();
        return *this;
    }
    BitArray array(*this);
    reset();
    for (int i = n; i < data_size; ++i) {
        bool temp = array[i];
        operator[](i - n) = temp;
    }
    return *this;
}

BitArray& BitArray::operator>>=(int n) {
    if (n < 0) {
        return operator<<=(-n);
    }
    if (n >= data_size) {
        reset();
        return *this;
    }
    BitArray array(*this);
    reset();
    for (int i = 0; i < data_size - n; ++i) {
        bool temp = array[i];
        operator[](i + n) = temp;
    }
    return *this;
}
