#ifndef LMATH_LIBRARY_H
#define LMATH_LIBRARY_H

#define BASE 10000000000000000000

#include <vector>
#include <algorithm>
#include <string>

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

    //endregion
};

#endif