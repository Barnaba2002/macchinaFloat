#include <iostream>
#include <string>
using namespace std;
enum Stato
{
    iniziale, //0
    errore, //1
    segno,//2
    parteIntera, //3
    puntoP, //4
    puntoI, //5
    parteDecimale, //6
    esponente, //7
    segnoE, //8
    parteEsponente, //9
    finale //10
};
bool goodReal(string n)
{
    Stato statoAttuale=iniziale;
    for(int i = 0;i<n.size();i++)
    {
        cout<<statoAttuale<<"\t'"<<n[i]<<"' i= "<<i<<endl;
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
                    statoAttuale=errore;
                }
                break;
            };
            case segno:{
                if(n[i]=='.'){
                    statoAttuale=puntoP;
                }else if(n[i]<='9'&&n[i]>='0'){
                    statoAttuale=parteIntera;
                }else{
                    statoAttuale=errore;
                }
                break;
            };
            case parteIntera:{
                if(n[i]=='.'){
                    statoAttuale=puntoI;
                }else if(n[i]<='9'&&n[i]>='0'){
                    if(i==n.size()-1){
                        statoAttuale=finale;
                    }else{
                        statoAttuale=parteIntera;
                    }
                }else if(n[i]=='E'||n[i]=='e')
                {
                    statoAttuale=esponente;
                }else{
                    statoAttuale=errore;
                }
                break;
            };
            case puntoP: {
                if(n[i]<='9'&&n[i]>='0')
                {
                    statoAttuale=parteDecimale;
                }else{
                    statoAttuale=errore;
                }
                break;
            };
            case puntoI:{
                if(n[i]<='9'&&n[i]>='0'){
                    statoAttuale=parteDecimale;
                }else if(i==n.size()-1){
                    statoAttuale=finale;
                }else{
                    statoAttuale=errore;
                }
                break;
            };
            case parteDecimale:{
                if(n[i]<='9'&&n[i]>='0')
                {
                    if(i==n.size()-1)
                    {
                        statoAttuale=finale;
                    }else{
                        statoAttuale=parteDecimale;
                    }
                }
                else if(n[i]=='E'||n[i]=='e')
                {
                    statoAttuale=esponente;
                }else{
                    statoAttuale=errore;
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
                    statoAttuale=errore;
                }
                break;
            };
            case segnoE:{
                if(n[i]<='9'&&n[i]>='0')
                {
                    statoAttuale=parteEsponente;
                }else{
                    statoAttuale=errore;
                }
                break;
            };
            case parteEsponente:{
                if(n[i]<='9'&&n[i]>='0')
                {

                    if(i==n.size()-1){
                        statoAttuale=finale;
                    }else{
                        statoAttuale=parteEsponente;
                    }
                }
                else{
                    statoAttuale=errore;
                }
                break;
            };
            case errore:{
                return false;
            };
            case finale:{
                return true;
            };
        }

    }
    if(statoAttuale==errore){
        return false;
    }else if(statoAttuale==finale){
        return true;
    }

}
int main()
{
    while(true)
    {
        string read;
        cin>>read;
        cout<<goodReal(read)<<endl;
    }
    return 0;
}
