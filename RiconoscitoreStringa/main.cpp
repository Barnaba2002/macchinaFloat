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
    finale          // 9
};
bool goodReal(string n,float & numero)
{
    Stato statoAttuale=iniziale;
    bool segN;
    long esp = 1;
    numero = 0;
    int decCount = 0;
    for(int i = 0;i<n.size();i++)
    {
        cout<<statoAttuale<<"\t'"<<n[i]<<"' i= "<<i<<endl;
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
                    statoAttuale=esponente;
                }else{
                    return false;
                }
                break;
            };
            case esponente:{
                if(n[i]=='+'||n[i]=='-')
                {
                    statoAttuale=segnoE;
                }else if(n[i]<='9'&&n[i]>='0')
                {

                    statoAttuale=parteEsponente;
                }else{
                    return false;
                }
                break;
            };
            case segnoE:{
                if(n[i]<='9'&&n[i]>='0')
                {
                    statoAttuale=parteEsponente;
                }else{
                    return false;
                }
                break;
            };
            case parteEsponente:{
                if(n[i]<='9'&&n[i]>='0')
                {
                    statoAttuale=parteEsponente;
                }
                else{
                    return false;
                }
                break;
            };
        }
    }
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
