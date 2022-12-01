#pragma once
#include "build_lib.h"

class studentas
{
private:
    string vardas;
    string pavarde;
    vector<int> pazymiai;
    int egzaminas;
    double galutinis_vid;
    double galutinis_med;
public:
    studentas() : egzaminas(0) { };
    void sukurti_studenta(string vardas_, string pavarde_, vector<int> pazymiai_, int egzaminas_);
    void sukurti_pazymi(int paz);
    void istrinti_nd();
    string paimti_varda() const { return vardas; }
    string paimti_pavarde() const { return pavarde; }
    int paimti_egzamina() const { return egzaminas; }
    int paimt_nd_skaiciu() const { return pazymiai.size(); }
    void skaiciuoti_galutini_vid();
    void skaiciuoti_galutini_med();
    double paimti_galutini_vid() const { return galutinis_vid; }
    double paimti_galutini_med() const { return galutinis_med; }

    ~studentas();
    studentas(const studentas &kitas);
    studentas& operator=(studentas& kitas);
};