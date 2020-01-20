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
#include <ctime>

int main()
{    
    Kontrol *kontrol = new Kontrol();
    kontrol->Baslat();
    delete kontrol;
    cin.get();
    return 0;
}