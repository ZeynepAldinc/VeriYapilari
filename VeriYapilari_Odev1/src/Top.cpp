#include "Top.hpp"

Top::Top()
{
    TopIsmi = '\0';
    TopVarMi = false;
}

void Top::IsimAta()
{
    TopIsmi = rand() % 25 + 65;
    TopVarMi = true;
}
char Top::TopDondur()
{
    return TopIsmi;
}
void Top::TopVarMiSet(bool deger)
{
    TopVarMi = deger;
}
bool Top::TopVarMiGet()
{
    return TopVarMi;
}