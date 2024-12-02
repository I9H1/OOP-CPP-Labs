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
    int toBytes(int size) const;
public:
    explicit BitArray(int num_bits, bool value = false);
    BitArray(const BitArray& array);
    ~BitArray();
    int getSize() const;
    int getRealSize() const;
    void swap(BitArray &b);
    void clear();
    void resize(int new_num_bits, bool value = false);
    void pushBack(bool bit);
    bool operator[](int i) const;
    Wrapper operator[](int i);
    void set();
    void set(int n, bool value = true);
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
