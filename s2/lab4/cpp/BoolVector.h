#pragma once
#include <iostream>
#include <vector>

using namespace std;

class BoolVector {
    int size;
    bool* vec;
public:
    explicit BoolVector(int n);
    explicit BoolVector(string line);
    explicit BoolVector(const bool* nums, int len);
    BoolVector(const BoolVector &obj);
    ~BoolVector(){delete[] vec;}
    bool* get_vec(){return vec;}
    int get_size() const{return size;}
    bool** get_vecs_same_size(const BoolVector& sec);
    BoolVector operator|(const BoolVector& sec);
    BoolVector operator^(const BoolVector& sec);
    bool is_prev(const BoolVector& sec);
};

