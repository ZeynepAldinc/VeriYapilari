#ifndef AGAC2_HPP
#define AGAC2_HPP

#include "Dugum2.hpp"

class Agac2
{
private:
    Dugum2 *root;
    int toplam_soy_sayisi;

    void AraveEkle(Dugum2 *&alt_Dugum, const int &yeni);
    bool DugumSil(Dugum2 *&alt_Dugum);
    int EnBuyuguSil(Dugum2 *&alt_Dugum);
    int RootSil(Dugum2 *&alt_Dugum);
    void Guncelle(Dugum2 *&alt_Dugum);
    void Postorder(Dugum2 *alt_Dugum) const;
    void SoySayisi(Dugum2 *alt_Dugum, int *);
    int SoySayisi(Dugum2 *alt_Dugum);
    void ToplamSoySayisi(Dugum2 *alt_Dugum);

public:
    Agac2();
    bool Bosmu() const;
    void Ekle(const int &yeni);
    int EnBuyuguSil();
    int RootSil();
    void Guncelle();
    void Postorder() const;
    void Temizle();
    int ToplamSoySayisi();
    ~Agac2();
};

#endif