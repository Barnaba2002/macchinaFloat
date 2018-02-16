#include "Errore.h"

Errore::Errore(float n)
{
    statoErrore = false;
    numero = n;
}
Errore::Errore(int msg,int pos)
{
    nErr = msg;
    posErr = pos;
    statoErrore = true;
}
bool Errore::isErrore()
{
    return statoErrore;
}
std::string Errore::toString()
{
    if(statoErrore){
        std::string ritorno = ERRmsg[nErr];

        return ritorno;
    }else{
        return "Non si è verificato alcun errore";
    }
}
int Errore::getPosErr()
{
    return posErr;
}
float Errore::toFloat()
{
    if(!statoErrore)
    {
        return numero;
    }else{
        return 0;
    }
}
