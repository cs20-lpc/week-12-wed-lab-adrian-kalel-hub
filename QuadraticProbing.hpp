#pragma once
#include "HashTableClosed.hpp"

template <typename T>
class QuadraticProbing : public HashTableClosed<T> {
public:
    explicit QuadraticProbing(int size = 101)
        : HashTableClosed<T>(size) {}

    int probeIndex(const T& key, int i) const override {
        // TODO: Implement quadratic probing
        return (this->hash1(key) + i * i) % this->M;
        //vsc ai suggestion
        return 0;
    }

   
};
