#ifndef ERRORE_H
#define ERRORE_H
#include <string>
const static std::string ERRmsg[] =
        {
            "Carattere non riconosciuto",//0
            "Fine imprevista",//1
            "Esponente non valido",//2
            "Parte intera non valida",//3
            "Parte decimale non valida"//4
        };

class Errore
{
    public:
        Errore(float numero);
        Errore(int msg,int pos);
        std::string toString();
        float toFloat();
        bool isErrore();
        int getPosErr();
    private:
        bool statoErrore;
        int nErr;
        int posErr;
        float numero;
};

#endif
