#include "Kova.hpp"

Kova::Kova()
{
    kovaRengi = rand() % 14 + 1;
    top = NULL;
}

Kova::~Kova()
{
}
void Kova::TopOlustur()
{
    if (top == NULL)
    {
        top = new Top();
        top->IsimAta();
    }
}
char Kova::TopDondur()
{
    return top->TopDondur();
}
int Kova::RenkDondur()
{
    return kovaRengi;
}
