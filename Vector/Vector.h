#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

typedef int DataType;

class Vector
{
public:
    Vector();
    Vector(const Vector& v);
    Vector& operator=(const Vector& v);
    ~Vector();
    size_t Size()const;
    size_t Capacity()const;   

    void Expand(size_t n);
    void Reserve(size_t n);
    void PushBack(DataType x);
    void PopBack();
    void PushFront(DataType x);
    void PopFront();
    void Insert(size_t pos, DataType x);
    void Erase(size_t pos);
    size_t Find(DataType x);
    void Print();

private:
    DataType *_first;
    DataType *_finish;
    DataType *_endofstorage;
};
