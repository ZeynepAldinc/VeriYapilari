#ifndef DUGUM1_HPP
#define DUGUM1_HPP

#include <iostream>

using namespace std;


class Dugum1
{
public:
    int veri;
    int soy_sayisi;
	Dugum1 *sol;
	Dugum1 *sag;
    Dugum1(const int &);
    ~Dugum1();
};


#endif