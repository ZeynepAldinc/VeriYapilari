/**
* @file Dosya adı
* @description Adedi kullanıcıdan alınacak şekilde kova nesneleri, ve verilen seçeneklerle bu kova nesnelerinin içerisine yine kullanıcının isteğiyle 
top nesneleri oluşturacak (aynı zamanda her kovanın altına o kovanın ve içerisindeki topun heap bellekteki konumunu yazacak);
sonrasında yine kullanıcıya verilecek seçenekler yardımıyla topları yok edecek, topları değiştirecek, kovaları
değiştirecek, topları tersten yerleştirecek veya kovaları tersten yerleştirecek bir program örneği.
* @course 2. Öğretim A Grubu
* @assignment Ödev-1
* @date 17.10.2019
* @author Zeynep ALDİNÇ zeynep.aldinc1@ogr.sakarya.edu.tr
*@author Ömerfaruk YETİM g161210309@ogr.sakarya.edu.tr
*/

#ifndef KOVA_HPP
#define KOVA_HPP

#include "Top.hpp"

class Kova
{
private:
    int kovaRengi;
public:
    Top *top;
    
    Kova();
    void Yazdir();
    void TopOlustur();
    char TopDondur();
    ~Kova();
    int RenkDondur();
};

#endif