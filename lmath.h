#pragma once

#ifndef LMATH_LIBRARY_H
#define LMATH_LIBRARY_H

#define NUMBASE 1000000000000000000ULL
#define NUMBASEZEROES 18ULL

#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

enum IO {
    FL = 0,
    CL = 1
};

class lint {
private:
    std::vector<unsigned long long> num;
public:
    //region Constructors

    lint();

    explicit lint(lint *x);

    explicit lint(const char *x);

    explicit lint(long long x);

    //endregion

    //region Operators

    lint &operator=(lint x);

    lint &operator=(long long x);

    lint operator+(lint x);

    lint operator+(long long x);

    lint &operator+=(lint x);

    lint &operator+=(long long x);

    lint operator-(lint x);

    lint operator-(long long x);

    lint &operator-=(lint x);

    lint &operator-=(long long x);

    lint operator/(lint x);

    lint operator/(long long x);

    lint &operator/=(lint x);

    lint &operator/=(long long x);

    lint operator*(lint x);

    lint operator*(long long x);

    lint &operator*=(lint x);

    lint &operator*=(long long x);

    lint operator%(lint x);

    lint operator%(long long x);

    lint &operator%=(lint x);

    lint &operator%=(long long x);

    //region Comparision Operators

    bool operator==(lint x);

    bool operator<(lint x);

    bool operator>(lint x);

    bool operator<=(lint x);

    bool operator>=(lint x);

//endregion

    //endregion

    //region Members

    void print(IO x = FL);

    //endregion
};

#endif
