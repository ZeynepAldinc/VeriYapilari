#include "KovaKontrol.hpp"

KovaKontrol::KovaKontrol()
{
    KovaOlustur();
}

void KovaKontrol::KovaOlustur()
{
    cout << "Kova Sayisi Giriniz: ";
    cin >> kovaSayisi;

    kovalar = new Kova *[kovaSayisi];
    for (int i = 0; i < kovaSayisi; i++)
    {
        kovalar[i] = new Kova();
    }
}

void KovaKontrol::Yazdir()
{
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < kovaSayisi; i++)
    {
        cout << i + 1 << ". Kova" << endl;
        SetConsoleTextAttribute(hConsole,kovalar[i]->RenkDondur());
        cout << "  .|." << endl;
        cout << " .   . " << endl;
        cout << ".     ." << endl;
        cout << "#     #" << endl;
        if (kovalar[i]->top != NULL)
            cout << "#  " << kovalar[i]->top->TopDondur() << "  #" << endl;
        else
            cout << "#  "
                 << "-"
                 << "  #" << endl;
        cout << "#     #" << endl;
        cout << "#######" << endl;
        cout << "Kova Adresi: " << kovalar[i] << endl;
        cout << "Topun Adresi: ";
        if (kovalar[i]->top == NULL)
            cout << "NULL" << endl;
        else
            cout << kovalar[i]->top << endl;
         SetConsoleTextAttribute(hConsole,15);
        cout << endl << endl;
            
    }
}

void KovaKontrol::ToplariYerlestir()
{
    for (int i = 0; i < kovaSayisi; i++)
    {
        kovalar[i]->TopOlustur();
    }
}

void KovaKontrol::ToplariYoket()
{
    for (int i = 0; i < kovaSayisi; i++)
    {
        if (kovalar[i]->top->TopVarMiGet() == true)
        {
            delete kovalar[i]->top;
            kovalar[i]->top = NULL;
        }
        else
            return;
    }
}

void KovaKontrol::KovaDegistir()
{
    int ilkKova = -1;
    int ikinciKova = -1;
    while (ilkKova <= 0 || ilkKova > kovaSayisi)
    {
        cout << "Ilk Kova: ";
        cin >> ilkKova;
    }
    while (ikinciKova <= 0 || ikinciKova > kovaSayisi)
    {
        cout << "Ikinci Kova: ";
        cin >> ikinciKova;
    }
    Kova *geciciDeger;

    geciciDeger = kovalar[ilkKova - 1];
    kovalar[ilkKova - 1] = kovalar[ikinciKova - 1];
    kovalar[ikinciKova - 1] = geciciDeger;
}

void KovaKontrol::TopDegistir()
{
    int ilkTop;
    int ikinciTop;
    Top *GeciciTop;

    while (ilkTop <= 0 || ilkTop > kovaSayisi)
    {
        cout << "Ilk Top: ";
        cin >> ilkTop;
    }
    while (ikinciTop <= 0 || ikinciTop > kovaSayisi)
    {
        cout << "Ikinci Top: ";
        cin >> ikinciTop;
    }
    GeciciTop = kovalar[ilkTop - 1]->top;
    kovalar[ilkTop - 1]->top = kovalar[ikinciTop - 1]->top;
    kovalar[ikinciTop - 1]->top = GeciciTop;
}

void KovaKontrol::KovalariTerstenYerlestir()
{
    Kova **GeciciKovalar = new Kova *[kovaSayisi];
    int j = kovaSayisi - 1;
    for (int i = 0; i < kovaSayisi; i++)
    {

        GeciciKovalar[i] = kovalar[j];
        j--;
    }
    for (int i = 0; i < kovaSayisi; i++)
    {
        kovalar[i] = GeciciKovalar[i];
    }

    delete GeciciKovalar;
    
}

void KovaKontrol::ToplariTerstenYerlestir()
{
    Top **GeciciToplar = new Top *[kovaSayisi];
    int j = kovaSayisi - 1;
    for (int i = 0; i < kovaSayisi; i++)
    {

        GeciciToplar [i] = kovalar[j]->top;
        j--;
    }
    for (int i = 0; i < kovaSayisi; i++)
    {
        kovalar[i]->top = GeciciToplar [i];
    }
    delete GeciciToplar;
}
KovaKontrol::~KovaKontrol()
{
    for(int i = 0; i < kovaSayisi; i++)
    {
        delete kovalar[i];
    }
}