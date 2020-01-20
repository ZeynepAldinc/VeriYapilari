#ifndef AGAC1_HPP
#define AGAC1_HPP

#include "Dugum1.hpp"

class Agac1
{
private:
    Dugum1 *root;
    int toplam_soy_sayisi;

    void AraveEkle(Dugum1 *&alt_Dugum, const int &yeni);
    bool DugumSil(Dugum1 *&alt_Dugum);
    int EnBuyuguSil(Dugum1 *&alt_Dugum);
    int RootSil(Dugum1 *&alt_Dugum);
    void Guncelle(Dugum1 *&alt_Dugum);
    void Postorder(Dugum1 *alt_Dugum) const;
    void SoySayisi(Dugum1 *alt_Dugum, int *);
    int SoySayisi(Dugum1 *alt_Dugum);
    void ToplamSoySayisi(Dugum1 *alt_Dugum);

public:
    Agac1();
    bool Bosmu() const;
    void Ekle(const int &yeni);
    int EnBuyuguSil();
    int RootSil();
    void Guncelle();
    void Postorder() const;
    void Temizle();
    int ToplamSoySayisi();
    ~Agac1();
};

#endif