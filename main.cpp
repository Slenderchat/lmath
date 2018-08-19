#include "lmath.h"

#include <fstream>

using std::fstream,
std::ios;

int main() {
    fstream io;
    char b[100], b1[100], b2[100], b3[100];
    lint x, y, z;
    io.open("INPUT.TXT", ios::in);
    if (io.is_open()) {
        io.read(b, sizeof(b));
    }
    io.close();
    sscanf(b, "%s %s %s", b1, b2, b3);
    x = lint(b1);
    y = lint(b2);
    z = lint(b3);
    return (0);
}
