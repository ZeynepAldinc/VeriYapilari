#ifndef KONTROL_HPP
#define KONTROL_HPP

#include <iostream>
#include <fstream>
#include "Agac1.hpp"
#include "Agac2.hpp"

using namespace std;

class Kontrol
{
private:
    Agac1 *agac1;
    Agac2 *agac2;
    int benim_skor;
    int rakip_skor;
    void DosyaOku();
    void Yazdir();
public:
    Kontrol();
    void Baslat();
    ~Kontrol();

};


#endif