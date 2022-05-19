#include "BoolVector.h"

using namespace std;

BoolVector::BoolVector(const BoolVector &obj){
    size = obj.size;
    vec = new bool [size];
    for (int i = 0; i < size; ++i) {
        vec[i] = obj.vec[i];
    }
}

BoolVector::BoolVector(int n) {
    size = n;
    vec = new bool [n];
}

BoolVector::BoolVector(string line) {
    size = line.length();
    vec = new bool [size];
    for (int i = 0; i < size; i++) {
        vec[i] = (bool)(line[i]-48);
    }
}

BoolVector::BoolVector(const bool* nums, int len) {
    size = len;
    vec = new bool [len];
    for (int i = 0; i < len; i++) {vec[i] = nums[i];}
}

BoolVector BoolVector::operator|(const BoolVector& sec) {
    bool** vecs = get_vecs_same_size(sec);
    bool* f_vec = vecs[0];
    bool* s_vec = vecs[1];
    int length = max(size, sec.size);
    bool* res = new bool [length];
    for (int i = 0; i < length; ++i) {
        res[i] = f_vec[i] | s_vec[i];
    }
    return BoolVector(res, length);
}

BoolVector BoolVector::operator^(const BoolVector& sec) {
    bool** vecs = get_vecs_same_size(sec);
    bool* f_vec = vecs[0];
    bool* s_vec = vecs[1];
    int len = max(size, sec.size);
    bool* res = new bool [len];
    for (int i = 0; i < len; ++i) {
        res[i] = f_vec[i]^s_vec[i];
    }
    return BoolVector(res, len);
}

bool BoolVector::is_prev(const BoolVector& sec) {
    bool** res = get_vecs_same_size(sec);
    int len = max(size, sec.size);
    for (int i = 0; i < len; ++i) {
        if (res[0][i] && !res[1][i]) return false;
    }
    return true;
}

bool** BoolVector::get_vecs_same_size(const BoolVector& sec){
    bool** vecs = new bool* [2];
    if (size > sec.size){
        bool* s_vec = new bool [size];
        for (int i = 0; i < size-sec.size; i++){s_vec[i] = false;}
        for (int i = size-sec.size; i < size ; i++) { s_vec[i]=sec.vec[i-size+sec.size];}
        vecs[0] = vec;
        vecs[1] = s_vec;
    }
    else if (sec.size > size){
        bool* f_vec = new bool [sec.size];
        for (int i = 0; i < sec.size-size; i++){f_vec[i] = false;}
        for (int i = sec.size-size; i < sec.size ; i++) { f_vec[i]=vec[i-sec.size+size];}
        vecs[0] = f_vec;
        vecs[1] = sec.vec;
    }
    else {
        vecs[0] = vec;
        vecs[1] = sec.vec;
    }
    return vecs;
}
