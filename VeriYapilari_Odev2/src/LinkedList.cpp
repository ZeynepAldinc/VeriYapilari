#include "LinkedList.hpp"

LinkedList::LinkedList()
{
    i = 0;
    kelime = "";
    uzunluk = 0;
    numara = 1;
    DosyaOku();
    basDugum = new Dugum(dizi[i++], 0, numara++);
    gecici = basDugum;
    size = 1;
    for (int i = 1; i < uzunluk; i++)
    {
        add();
    }
}
void LinkedList::add()
{
    Dugum *gezici = basDugum;
    gecici->ileri = new Dugum(dizi[i++], 0, numara++);
    gecici->ileri->geri = gecici;
    gecici = gecici->ileri;
    while (gezici != NULL && gezici != gecici)
    {
        if (gezici->eleman != gecici->eleman)
        {
            gezici = gezici->ileri;
        }
        else
        {
            gecici->sayi = gecici->numara - gezici->numara;
            gecici->eleman = "";
            break;
        }
    }
    size++;
}
void LinkedList::Yazdir()
{
    cout << "NULL<-:";
    for (Dugum *gezici = basDugum; gezici != NULL; gezici = gezici->ileri)
    {

        if (gezici->ileri != NULL)
            cout << gezici->eleman << " - " << gezici->sayi << " :<->: ";
        else
            cout << gezici->eleman << " - " << gezici->sayi;
    }
    cout << ":->NULL" << endl;

    cout << "Toplam Kazanc: " << Kazanc() << " Byte";
}
int LinkedList::Kazanc()
{
    int _byte = 0;
    for (Dugum *gezici = basDugum; gezici != NULL; gezici = gezici->ileri)
    {
        if (gezici->eleman == "")
        {
            Dugum *gezici2 = gezici;
            for (int i = 0; i < gezici->sayi; i++)
            {
                gezici2 = gezici2->geri;
            }
            _byte += gezici2->eleman.length() - 1;
        }
    }
    return _byte;
}
void LinkedList::DosyaOku()
{
    fstream dosya("icerik.txt");
    kelime = "";
    uzunluk = 0;
    int i = 0;
    if (dosya.is_open())
    {
        while (dosya >> kelime)
        {
            dizi[i++] = kelime;
            uzunluk++;
        }
    }
    else
    {
        cout << "Dosya Acilamadi." << endl;
    }

    dosya.close();
}
void LinkedList::remove()
{
    Dugum *eskiDugum = basDugum;
    basDugum->ileri->geri = NULL;
    basDugum = basDugum->ileri;   
    delete eskiDugum;                                        
    size--;
}
void LinkedList::clear()
{
    while (size != 1)
        remove();
}
LinkedList::~LinkedList()
{
    cout << "Bagli Liste Temizleniyor..." << endl;
    clear();
    delete basDugum;
    cout << "Bagli Liste Temizlendi." << endl;
}