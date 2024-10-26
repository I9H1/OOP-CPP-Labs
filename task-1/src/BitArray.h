#pragma once
#include <iostream>
#include <string>

using namespace std;

class BitArray {
private:
    unsigned char *data;
    int data_size;
    class Wrapper {
    private:
        BitArray* link;
        int index;
    public:
        Wrapper(int i, BitArray* array);
        Wrapper& operator=(bool value);
        operator bool() const;
    };
    int getSizeInBytes(int size);
public:
    explicit BitArray(int num_bits, bool value = false);
    BitArray(const BitArray& array);
    ~BitArray();
    int getSize() const;
    void swap(BitArray &b);
    void clear();
    void resize(int new_num_bits, bool value = false);
    void pushBack(bool bit);
    Wrapper operator[](int i);
    bool operator[](int i) const;
    void set();
    void reset();
    bool any() const;
    bool none() const;
    BitArray operator~();
    int count() const;
    bool isEmpty() const;
    string toString() const;
    BitArray operator<<(int n) const;
    BitArray operator>>(int n) const;
    BitArray& operator<<=(int n);
    BitArray& operator>>=(int n);
    bool operator==(const BitArray& b) const;
    bool operator!=(const BitArray& b) const;
    BitArray operator&(const BitArray& b);
    BitArray operator|(const BitArray& b);
    BitArray operator^(const BitArray& b);
    BitArray& operator&=(const BitArray& b);
    BitArray& operator|=(const BitArray& b);
    BitArray& operator^=(const BitArray& b);
};
