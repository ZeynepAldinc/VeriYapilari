
#include "KovaKontrol.hpp"

void Menu()
{
	cout << "[1] Toplari Yerlestir" << endl;
	cout << "[2]Toplari Yok Et" << endl;
	cout << "[3]Kova Degistir" << endl;
	cout << "[4]Top Degistir" << endl;
	cout << "[5]Kovalari Tersten Yerlestir" << endl;
	cout << "[6]Toplari Tersten Yerlestir" << endl;
	cout << "[7]Cikis" << endl;
	cout << "Secim: ";
}
void Calistir()
{
	int secim = 0;
	KovaKontrol *kovaKontrol = new KovaKontrol();
	while (secim != 7)
	{
		kovaKontrol->Yazdir();
		Menu();
		cin >> secim;
		switch (secim)
		{
		case 1:
			kovaKontrol->ToplariYerlestir();
			break;
		case 2:
			kovaKontrol->ToplariYoket();
			break;
		case 3:
			kovaKontrol->KovaDegistir();
			break;
		case 4:
			kovaKontrol->TopDegistir();
			break;
		case 5:
			kovaKontrol->KovalariTerstenYerlestir();
			break;
		case 6:
			kovaKontrol->ToplariTerstenYerlestir();
			break;
		case 7:
			delete kovaKontrol;
			return;
		default:
			cout << "Hatali Secim Yaptiniz!";
			break;
		}
	}
}

int main()
{
	srand(time(NULL));
	Calistir();

	return 0;
}