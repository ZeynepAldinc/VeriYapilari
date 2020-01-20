/**
* @file Dosya adı
* @description İki farklı ağaç oluşturan, iki farklı dosyaki değerleri ağaçlara düğüm oluşturup, tek tek içine yerleştiren ve her bir düğümün soy sayısını hesaplayan
* sistem. Soy sayısı hesaplama işlemi bittikten sonra sayılara toplayarak her ağacın toplam soy sayısını belirleyen sistem, bu sayıları karşılaştırarak sayısı küçük
* olan ağacı kazanan ilan eder ve kaybeden ağacın en büyük değerli düğümünü kendine katar. Bu işlemden sonra da taraflar, karşı tarafın kök düğümünü kendine katar ve
* kendi köklerini siler. Tur bu şekilde sona erer ve ağaçların dengeleri değişeceği için soy sayıları yeniden hesaplanır ve bir taraf 5 turu alana kadar oyun bu şekilde
* devam eder. 
* @course 2. Öğretim A Grubu
* @assignment Ödev 3
* @date 10.12.2019
* @author Zeynep ALDİNÇ zeynep.aldinc1@ogr.sakarya.edu.tr
          Ömerfaruk YETİM omerfarukyetim@gmail.com
*/
#include "Agac2.hpp"

void Agac2::AraveEkle(Dugum2 *&alt_Dugum, const int &yeni)
{
    if (alt_Dugum == NULL)
        alt_Dugum = new Dugum2(yeni);
    else if (yeni <= alt_Dugum->veri)
    {
        alt_Dugum->soy_sayisi++;
        AraveEkle(alt_Dugum->sol, yeni);
    }
    else if (yeni > alt_Dugum->veri)
    {
        alt_Dugum->soy_sayisi++;
        AraveEkle(alt_Dugum->sag, yeni);
    }
    else
        return; // Aynı eleman var.
}
bool Agac2::DugumSil(Dugum2 *&alt_Dugum)
{
    Dugum2 *silinecekDugum = alt_Dugum;

    if (alt_Dugum->sag == NULL)
        alt_Dugum = alt_Dugum->sol;
    else if (alt_Dugum->sol == NULL)
        alt_Dugum = alt_Dugum->sag;
    else
    {
        silinecekDugum = alt_Dugum->sol;
        Dugum2 *ebeveynDugum = alt_Dugum;
        while (silinecekDugum->sag != NULL)
        {
            ebeveynDugum = silinecekDugum;
            silinecekDugum = silinecekDugum->sag;
        }
        alt_Dugum->veri = silinecekDugum->veri;
        if (ebeveynDugum == alt_Dugum)
            alt_Dugum->sol = silinecekDugum->sol;
        else
            ebeveynDugum->sag = silinecekDugum->sol;
    }
    delete silinecekDugum;
    return true;
}
int Agac2::EnBuyuguSil(Dugum2 *&alt_Dugum)
{
    int deger = 0;
    if(alt_Dugum->sag == NULL)
    {
        deger = alt_Dugum->veri;
        DugumSil(alt_Dugum);
        return deger;
    }
    else
        EnBuyuguSil(alt_Dugum->sag);
}
int Agac2::RootSil(Dugum2 *&alt_Dugum)
{
    int deger = alt_Dugum->veri;
    DugumSil(alt_Dugum);
    return deger;
}
void Agac2::Guncelle(Dugum2 *&alt_Dugum)
{
    int soy = 0;
    if(alt_Dugum != NULL)
    {
        Guncelle(alt_Dugum->sag);
        Guncelle(alt_Dugum->sol);
        alt_Dugum->soy_sayisi = SoySayisi(alt_Dugum) - 1;
    }
}
void Agac2::Postorder(Dugum2 *alt_Dugum) const
{
    if (alt_Dugum != NULL)
    {
        Postorder(alt_Dugum->sol);
        Postorder(alt_Dugum->sag);
        cout << "<" << alt_Dugum->veri << "," << alt_Dugum->soy_sayisi <<"> ";
    }
}
void Agac2::SoySayisi(Dugum2 *alt_Dugum, int *soy_sayisi)
{
    if (alt_Dugum == NULL)
    {
        return;
    }
    else
    {
        *soy_sayisi = *soy_sayisi + 1;
        SoySayisi(alt_Dugum->sol, soy_sayisi);
        SoySayisi(alt_Dugum->sag, soy_sayisi);
    }
}
int Agac2::SoySayisi(Dugum2 *alt_Dugum)
{
    int deger = 0;
    SoySayisi(alt_Dugum, &deger);
    return deger;
}
void Agac2::ToplamSoySayisi(Dugum2 *alt_Dugum)
{
    if (alt_Dugum != NULL)
    {
        ToplamSoySayisi(alt_Dugum->sag);
        ToplamSoySayisi(alt_Dugum->sol);
        toplam_soy_sayisi += alt_Dugum->soy_sayisi;
    }
}
Agac2::Agac2()
{
    root = NULL;
    toplam_soy_sayisi = 0;
}
bool Agac2::Bosmu() const
{
    return root == NULL;
}
void Agac2::Ekle(const int &yeni)
{
    AraveEkle(root, yeni);
}
int Agac2::EnBuyuguSil()
{
    return EnBuyuguSil(root);
}
int Agac2::RootSil()
{
    return RootSil(root);
}
void Agac2::Guncelle()
{
    Guncelle(root);
}
void Agac2::Postorder() const
{
    Postorder(root);
}
void Agac2::Temizle()
{
    while (!Bosmu())
        DugumSil(root);
}
int Agac2::ToplamSoySayisi()
{
    toplam_soy_sayisi = 0;
    ToplamSoySayisi(root);
    return toplam_soy_sayisi;
}
Agac2::~Agac2()
{
    cout << "\tAgac2 Temizleniyor...\n";
    Temizle();
    cout << "\tAgac2 Temizlendi\n";
}