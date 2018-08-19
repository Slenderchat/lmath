#include "lmath.h"

int main() {
    fstream io;
    char *b1 = static_cast<char *>(malloc(100 * sizeof(char))), *b2 = static_cast<char *>(malloc(
            100 * sizeof(char))), *b3 = static_cast<char *>(malloc(100 * sizeof(char)));
    lint x, y, z;
    io.open("INPUT.TXT", ios::in);
    if (io.is_open()) {
        io >> b1 >> b2 >> b3;
    }
    io.close();
    x = lint(b1);
    y = lint(b2);
    z = lint(b3);
    y < x;
    bool r = z < y;
    r = z < x;
    if ((x > y) && (x > z)) {
        x.print();
    } else if ((y > x) && (y > z)) {
        y.print();
    } else {
        z.print();
    }
    return (0);
}
