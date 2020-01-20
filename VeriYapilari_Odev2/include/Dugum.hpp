/**
* @file Dugum.hpp
* @description txt dosyasına girilen veriyi okuyarak kelime kelime ayırıp her bir kelimeyi bağlı listeye aktaran tekrar eden kelimeleri
yazmak yerine daha önce kelimenin geçtiği düğüme olan uzaklığı yazan ve böylelikle ne kadarlık bir byte kazancında olunduğunu belirten
bir program.
* @course  2. Öğretim A Grubu 
* @assignment Ödev 2
* @date 17.11.2019
* @author Zeynep ALDİNÇ  zeynep.aldinc1@ogr.sakarya.edu.tr
*/

#ifndef DUGUM_HPP
#define DUGUM_HPP

#include <iostream>
#include <fstream>
using namespace std;
class Dugum
{
public:
	string eleman;
	int sayi;
	int numara;
	Dugum *ileri;
	Dugum *geri;
	Dugum(string, int, int);
	~Dugum();
};
#endif