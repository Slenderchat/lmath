#include "lmath.h"

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
    if (x > NUMBASE - 1) {
        do {
            this->num.push_back(x % NUMBASE);
            x /= NUMBASE;
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
        if (buff < NUMBASE - 1) {
            b.num[i] = buff;
        } else {
            b.num[i] = NUMBASE - 1;
            overflow += buff % NUMBASE;
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
    if (this->num.size() < x.num.size()) this->isneg = true;
    while (b.num.size() < x.num.size()) {
        b.num.insert(b.num.begin(), 0);
    }
    while (b.num.size() > x.num.size()) {
        x.num.insert(x.num.begin(), 0);
    }
    for (int i = 0; i < b.num.size(); i++) {
        long long buff = b.num[i] - x.num[i];
        if (buff > 0) {
            b.num[i] = buff;
        } else if (buff < 0 && i < (b.num.size() - 1)) {
            if (b.num[i + 1] > 0) {
                b.num[i + 1] -= 1;
                buff = (b.num[i] + NUMBASE) - x.num[i];
                b.num[i] = buff;
            }
        } else if (buff < 0 && i == (b.num.size() - 1)) {
            b.num[i] = abs(buff);
            b.isneg = true;
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

//region Comparision Operators

bool lint::operator==(lint x) {
    lint b = *this - x;
    return ((b.num.size() == 1) && (b.num[0] == 0));
}

bool lint::operator<(lint x) {
    lint b = *this - x;
    return (b.isneg);
}

bool lint::operator>(lint x) {
    lint b = *this - x;
    return (!b.isneg);
}

bool lint::operator<=(lint x) {
    lint b = *this - x;
    return ((b.isneg) && (*this == x));
}

bool lint::operator>=(lint x) {
    lint b = *this - x;
    return ((!b.isneg) && (*this == x));
}

//endregion

//endregion

//region Members

void lint::print(IO x) {
    short z = static_cast<short>(NUMBASEZEROES * (this->num.size() - 1));
    stringstream b;
    string o;
    for (int i = 0; i < this->num.size(); i++) {
        b << this->num[i];
    }
    b >> o;
    if (o.length() < z) {
        do {
            b << '0';
            b >> o;
        } while (o.length() < z);
    }
    if (x == FL) {
        std::fstream iof;
        iof.open("OUTPUT.TXT", ios::out);
        if (iof.is_open()) {
            iof << o.c_str();
        }
        iof.close();
    } else {
        printf(o.c_str());
    }
}

//endregion
