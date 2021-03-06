#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>

typedef unsigned int uint;

class Vector{

  public:
    explicit Vector();
    explicit Vector(const size_t);
    Vector(const Vector&);
    ~Vector();

    uint& operator[](const size_t);
    const uint& operator[](const size_t) const;
    Vector& operator=(const Vector&);

    uint *elems;
    size_t size; //total number of elements
    size_t max_size;

    void reset();
    void print();
    void push_back(const size_t&);
    void change_size(size_t);
};


#endif
