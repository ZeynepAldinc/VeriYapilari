#include "Dugum.hpp"

Dugum::Dugum(string eleman, int sayi, int numara)
{
    this->eleman = eleman;
    this->sayi = sayi;
    this->numara = numara;
    ileri = NULL;
    geri = NULL;
}
Dugum::~Dugum()
{
    cout << numara << " Numarali Dugum Silindi." << endl;
}