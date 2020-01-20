#ifndef DUGUM2_HPP
#define DUGUM2_HPP

#include <iostream>
#include <cmath>

using namespace std;

class Dugum2
{
public:
    int veri;
    int soy_sayisi;
    Dugum2 *sol;
    Dugum2 *sag;

    Dugum2(const int &);
    ~Dugum2();
};

#endif