#include <iostream>
#include <string>
#include <math.h>
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
bool goodReal(string n,float & numero)
{
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
                    return false;
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
                    return false;
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
                    return false;
                }
                break;
            };
            case puntoP: {
                if(n[i]<='9'&&n[i]>='0')
                {
                    numero = numero + (n[i]-48)/pow(10,++decCount);
                    statoAttuale=parteDecimale;
                }else{
                    return false;
                }
                break;
            };
            case puntoI:{
                if(n[i]<='9'&&n[i]>='0'){
                numero = numero + (n[i]-48)/pow(10,++decCount);
                    statoAttuale=parteDecimale;
                }else{
                    return false;
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
                    return false;
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
                    return false;
                }
                break;
            };
            case segnoE:{
                if(n[i]<='9'&&n[i]>='0')
                {
                    esp = esp*10+n[i]-48;
                    statoAttuale=parteEsponente;
                }else{
                    return false;
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
                    return false;
                }
                break;
            };
        }
    }
    if(!segE) esp*=-1;
    numero = numero*pow(10,esp);
    return true;
}
int main()
{
    while(true)
    {
        string read;
        float ritorno;
        cout<<"Inserisci il numero: ";
        cin>>read;
        if(goodReal(read,ritorno))
        {
            cout<<"Il numero "<<ritorno<<" e' corretto!"<<endl;
        }else{
            cout<<"Il numero non e' corretto!"<<endl;
        }
    }
    return 0;
}
