#include "lmath.h"

using std::vector, std::string, std::strtoull,
std::reverse;

//region Constructors

lint::lint() {
    this->num.push_back(0);
}

lint::lint(lint *x) {
    this->num = x->num;
}

lint::lint(const char *x) {
    string s = x;
    for (int i = static_cast<int>(s.length()); i > 0; i -= 19) {
        if (i < 19) {
            this->num.push_back(strtoull(s.substr(0, i).c_str(), nullptr, 10));
        } else {
            this->num.push_back(strtoull(s.substr(i - 19, 19).c_str(), nullptr, 10));
        }
    }
    reverse(this->num.begin(), this->num.end());
}

lint::lint(long long x) {
    if (x > BASE - 1) {
        do {
            this->num.push_back(x % BASE);
            x /= BASE;
        } while (x > 0);
    } else {
        this->num.push_back(x);
    }
    reverse(this->num.begin(), this->num.end());
}

//endregion

//region Operators

//region Operator=

lint &lint::operator=(lint x) {
    this->num = x.num;
    return (*this);
}

lint &lint::operator=(long long x) {
    this->num = lint(x).num;
    return (*this);
}

//endregion

//region Operator+

lint lint::operator+(lint x) {
    lint b = *this;
    while (b.num.size() < x.num.size()) {
        b.num.push_back(0);
    }
    while (b.num.size() > x.num.size()) {
        x.num.push_back(0);
    }
    unsigned long long overflow = 0;
    for (int i = static_cast<int>(b.num.size() - 1); i >= 0; i--) {
        unsigned long long buff = b.num[i] + x.num[i];
        if (overflow > 0) {
            buff += overflow;
            overflow = 0;
        }
        if (buff < BASE - 1) {
            b.num[i] = buff;
        } else {
            b.num[i] = BASE - 1;
            overflow += buff % BASE;
        }
    }
    return (b);
}

lint lint::operator+(long long x) {
    lint b(*this + lint(x));
    return (b);
}

lint &lint::operator+=(lint x) {
    *this = *this + x;
    return (*this);
}

lint &lint::operator+=(long long x) {
    *this = *this + lint(x);
    return (*this);
}

//endregion

//region Operator-

lint lint::operator-(lint x) {
    lint b = *this;
    while (b.num.size() < x.num.size()) {
        b.num.push_back(0);
    }
    while (b.num.size() > x.num.size()) {
        x.num.push_back(0);
    }
    for (int i = static_cast<int>(b.num.size() - 1); i >= 0; i--) {
        unsigned long long buff = b.num[i] - x.num[i];
        if (buff > 0) {
            b.num[i] = buff;
        } else {
            b.num[i - 1] -= 1;
            b.num[i] = BASE - x.num[i];
        }
    }
    int i = 0;
    while (b.num[i] == 0) {
        b.num.erase(b.num.begin() + i);
        ++i;
    }
    return (b);
}

lint lint::operator-(long long x) {
    lint b(*this - lint(x));
    return (b);
}

lint &lint::operator-=(lint x) {
    *this = *this - x;
    return (*this);
}

lint &lint::operator-=(long long x) {
    *this = *this - lint(x);
    return (*this);
}

//endregion

//region Operator/

lint lint::operator/(lint x) {
    lint b = *this;
    while (b.num.size() < x.num.size()) {
        b.num.push_back(0);
    }
    while (b.num.size() > x.num.size()) {
        x.num.push_back(0);
    }
    for (int i = static_cast<int>(b.num.size() - 1); i >= 0; i--) {

    }
    return (b);
}

lint lint::operator/(long long x) {

}

lint &lint::operator/=(lint x) {

}

lint &lint::operator/=(long long x) {

}

//endregion

//region Operator*

lint lint::operator*(lint x) {

}

lint lint::operator*(long long x) {

}

lint &lint::operator*=(lint x) {

}

lint &lint::operator*=(long long x) {

}

//endregion

//region Operator%

lint lint::operator%(lint x) {

}

lint lint::operator%(long long x) {

}

lint &lint::operator%=(lint x) {

}

lint &lint::operator%=(long long x) {

}

//endregion

//endregion