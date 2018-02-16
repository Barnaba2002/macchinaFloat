#include <iostream>
#include <string>
#include <math.h>
#include "Errore.h"
using namespace std;
enum Stato
{
    iniziale,       // 0
    segno,          // 1
    parteIntera,    // 2
    puntoP,         // 3
    puntoI,         // 4
    parteDecimale,  // 5
    esponente,      // 6
    segnoE,         // 7
    parteEsponente, // 8
};
Errore goodReal(string n)
{
    float numero;
    Stato statoAttuale=iniziale;
    bool segN = true;
    bool segE = true;
    long esp = 0;
    numero = 0;
    int decCount = 0;
    for(int i = 0;i<n.size();i++)
    {
        switch(statoAttuale)
        {
            case iniziale:{
                if(n[i]=='+'||n[i]=='-'){
                    statoAttuale=segno;
                    if(n[i]=='+') segN = true;
                    else segN = false;
                }else if(n[i]=='.'){
                    statoAttuale = puntoP;
                }else if(n[i]<='9'&&n[i]>='0'){
                    numero = numero*10 + n[i]-48;
                    statoAttuale=parteIntera;
                }else{
                    return Errore(0,i);
                }
                break;
            };
            case segno:{
                if(n[i]=='.'){
                    statoAttuale=puntoP;
                }else if(n[i]<='9'&&n[i]>='0'){
                    numero = numero*10 + n[i]-48;
                    statoAttuale=parteIntera;
                }else{
                    if(i==n.size()-1){
                        return Errore(1,i);
                    }else{
                        return Errore(0,i);
                    }
                }
                break;
            };
            case parteIntera:{
                if(n[i]=='.'){
                    statoAttuale=puntoI;
                }
                else if(n[i]<='9'&&n[i]>='0'){
                    numero = numero*10 + n[i]-48;
                    statoAttuale=parteIntera;
                }
                else if(n[i]=='E'||n[i]=='e')
                {
                    esp=0;
                    statoAttuale=esponente;
                }
                else{
                    return Errore(3,i);
                }
                break;
            };
            case puntoP: {
                if(n[i]<='9'&&n[i]>='0')
                {
                    numero = numero + (n[i]-48)/pow(10,++decCount);
                    statoAttuale=parteDecimale;
                }else{
                    if(i==n.size()-1){
                        return Errore(1,i);
                    }else{
                        return Errore(0,i);
                    }
                }
                break;
            };
            case puntoI:{
                if(n[i]<='9'&&n[i]>='0'){
                    numero = numero + (n[i]-48)/pow(10,++decCount);
                    statoAttuale=parteDecimale;
                }
                else if(n[i]=='E'||n[i]=='e'){
                    esp=0;
                    statoAttuale=esponente;
                }else{
                    return Errore(4,i);
                }
                break;
            };
            case parteDecimale:{
                if(n[i]<='9'&&n[i]>='0')
                {
                    numero = numero + (n[i]-48)/pow(10,++decCount);
                    statoAttuale=parteDecimale;
                }
                else if(n[i]=='E'||n[i]=='e')
                {
                    esp=0;
                    statoAttuale=esponente;
                }else{
                    return Errore(4,i);
                }
                break;
            };
            case esponente:{
                if(n[i]=='+'||n[i]=='-')
                {
                    if(n[i]=='+')
                    {
                        segE=true;
                    }else{
                        segE=false;
                    }
                    statoAttuale=segnoE;
                }else if(n[i]<='9'&&n[i]>='0')
                {
                    esp = esp*10+n[i]-48;
                    statoAttuale=parteEsponente;
                }else{
                    return Errore(2,i);
                }
                break;
            };
            case segnoE:{
                if(n[i]<='9'&&n[i]>='0')
                {
                    esp = esp*10+n[i]-48;
                    statoAttuale=parteEsponente;
                }else{
                    return Errore(2,i);
                }
                break;
            };
            case parteEsponente:{
                if(n[i]<='9'&&n[i]>='0')
                {
                    esp = esp*10+n[i]-48;
                    statoAttuale=parteEsponente;
                }
                else{
                    return Errore(2,i);
                }
                break;
            };
        }
    }
    if(!segE) esp*=-1;
    numero = numero*pow(10,esp);
    return Errore(numero);
}

int main()
{
    Errore err(0);
    while(true)
    {
        string read;
        float ritorno;
        cout<<"Inserisci il numero: ";
        cin>>read;
        err = goodReal(read);
        if(err.isErrore())
        {
            cout<<err.toString()<<" alla posizione "<<err.getPosErr()<<endl;
        }else{
            cout<<err.toFloat()<<endl;
        }
    }
    return 0;
}
