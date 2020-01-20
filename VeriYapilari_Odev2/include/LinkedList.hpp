/**
* @file LinkedList.hpp
* @description txt dosyasına girilen veriyi okuyarak kelime kelime ayırıp her bir kelimeyi bağlı listeye aktaran tekrar eden kelimeleri
yazmak yerine daha önce kelimenin geçtiği düğüme olan uzaklığı yazan ve böylelikle ne kadarlık bir byte kazancında olunduğunu belirten
bir program.
* @course  2. Öğretim A Grubu 
* @assignment Ödev 2
* @date 18.11.2019
* @author Zeynep ALDİNÇ  zeynep.aldinc1@ogr.sakarya.edu.tr
*/

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Dugum.hpp"

class LinkedList
{
private:
	Dugum *basDugum;
	Dugum *gecici;
	int size;
	int numara;
	int uzunluk;
	int i;
	string kelime;
	string dizi[100];

	void DosyaOku();
	int Kazanc();
	void remove();
	void clear();
public:
	LinkedList();
	void add();
	void Yazdir();
	
	
	~LinkedList();
	
};

#endif