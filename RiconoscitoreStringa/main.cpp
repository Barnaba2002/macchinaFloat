#include <iostream>
#include <string>
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
bool goodReal(string n)
{
    Stato statoAttuale=iniziale;
    for(int i = 0;i<n.size();i++)
    {
        switch(statoAttuale)
        {
            case iniziale:{
                if(n[i]=='+'||n[i]=='-'){
                    statoAttuale=segno;
                }else if(n[i]=='.'){
                    statoAttuale = puntoP;
                }else if(n[i]<='9'&&n[i]>='0'){
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
                    statoAttuale=parteDecimale;
                }else{
                    return false;
                }
                break;
            };
            case puntoI:{
                if(n[i]<='9'&&n[i]>='0'){
                    statoAttuale=parteDecimale;
                }else{
                    return false;
                }
                break;
            };
            case parteDecimale:{
                if(n[i]<='9'&&n[i]>='0')
                {
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
        cout<<"Inserisci il numero: ";
        cin>>read;
        if(goodReal(read))
        {
            cout<<"Il numero e' corretto!"<<endl;
        }else{
            cout<<"Il numero non e' corretto!"<<endl;
        }
    }
    return 0;
}
