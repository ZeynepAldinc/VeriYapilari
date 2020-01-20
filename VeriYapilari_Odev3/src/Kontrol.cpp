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
#include "Kontrol.hpp"

Kontrol::Kontrol()
{
    agac1 = new Agac1();
    agac2 = new Agac2();
    benim_skor = 0;
    rakip_skor = 0;
    DosyaOku();
}

void Kontrol::DosyaOku()
{
    fstream dosya("Benim.txt");
    if (dosya.is_open())
    {
        int deger;
        while (dosya >> deger)
        {
            agac1->Ekle(deger);
        }
    }
    dosya.close();

    dosya.open("Rakip.txt");
    if (dosya.is_open())
    {
        int deger;
        while (dosya >> deger)
        {
            agac2->Ekle(deger);
        }
    }
    dosya.close();
}
void Kontrol::Yazdir()
{
    int agac1_soy_sayisi = agac1->ToplamSoySayisi();
    int agac2_soy_sayisi = agac2->ToplamSoySayisi();
    
    cout << "Benim Agac Postorder :" << endl;
    agac1->Postorder();
    cout << "\nBenim Agac Toplam Soy Sayisi: " << agac1_soy_sayisi << endl;
    cout << "_____________________________________\n\n";

    cout << "Rakip Agac Postorder :" << endl;
    agac2->Postorder();
    cout << "\nRakip Agac Toplam Soy Sayisi: " << agac2_soy_sayisi << endl;
    cout << "_____________________________________\n\n";

    if(agac1_soy_sayisi < agac2_soy_sayisi)
    {
        cout << "--TEBRIKLER TURU KAZANDINIZ.--" << endl;
        benim_skor++;
        agac1->Ekle(agac2->EnBuyuguSil());
        agac2->Ekle(agac1->RootSil());
    }
    else if(agac1_soy_sayisi > agac2_soy_sayisi)
    {
        cout << "--MAALESEF TURU KAYBETTINIZ.--" << endl;
        rakip_skor++;
        agac2->Ekle(agac1->EnBuyuguSil());
        agac1->Ekle(agac2->RootSil());
    }
    else
    {
        cout << "--BERABERE.--" << endl;
        agac1->Ekle(agac2->RootSil());
        agac2->Ekle(agac1->RootSil());
    }
    
    cout << "\n\nSKOR" << endl;
    cout << "Benim: " << benim_skor << endl;
    cout << "Rakip: " << rakip_skor << endl << endl << endl;
    agac1->Guncelle();
    agac2->Guncelle();
}
void Kontrol::Baslat()
{
    //system("CLS");
    for (int tur = 1; tur <= 20; tur++)
    {
        if(benim_skor == 5 || rakip_skor == 5)
        {
            cout << "Mac Bitti. ";
            if(benim_skor < rakip_skor)
                cout << "Rakip Kazandi." << endl;
            else if(benim_skor > rakip_skor)
                cout << "KAZANDIN." << endl;
            break;
        }
        cout << tur << ". TUR BASLADI.\n\n";
        Yazdir();
        cin.get();
    }
    if(benim_skor == rakip_skor)
        cout << "Mac Berabere Bitti." << endl;
}
Kontrol::~Kontrol()
{
    delete agac1;
    delete agac2;
}
