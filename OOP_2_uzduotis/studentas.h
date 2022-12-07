#pragma once
#include "build_lib.h"

class zmogus
{
public:
    virtual string paimti_varda() const = 0;
    virtual string paimti_pavarde() const = 0;
protected:
    string vardas;
    string pavarde;
};


class studentas : public zmogus
{
private:
    vector<int> pazymiai;
    int egzaminas;
    double galutinis_vid;
    double galutinis_med;
public:
    studentas() : egzaminas(0) { };
    void sukurti_zmogu(string vardas_, string pavarde_, vector<int> pazymiai_, int egzaminas_);
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

    friend ostream& operator<<(ostream& output, const studentas& S) {
        output << left << setw(25) << S.paimti_varda() << setw(25) << S.paimti_pavarde() << setw(15) << S.paimti_galutini_vid() <<
            setw(15) << S.paimti_galutini_med() << endl;
        return output;
    }

    friend istream& operator>>(istream& input, studentas& S) {
        input >> S.vardas >> S.pavarde;
        return input;
    }
};