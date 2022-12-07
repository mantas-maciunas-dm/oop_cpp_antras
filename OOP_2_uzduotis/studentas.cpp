#include "studentas.h"
#include "build_lib.h"


studentas::~studentas()
{
    /*!
    *   Klases studentas destruktorius.
    */
    pazymiai.clear();
    egzaminas = NULL;
    galutinis_med = NULL;
    galutinis_vid = NULL;
}


studentas::studentas(const studentas& kitas)
{
    /*!
    *   Klases studentas studentu prilyginimas.
    *
    *   @param kitas Studentas, kurio atributu reiksmes priskiriamos esamam studentui.
    */
    vardas = kitas.vardas;
    pavarde = kitas.pavarde;
    pazymiai = kitas.pazymiai;
    egzaminas = kitas.egzaminas;
    galutinis_med = kitas.galutinis_med;
    galutinis_vid = kitas.galutinis_vid;
}


studentas &studentas::operator=(studentas& kitas)
{
    /*!
    *   Operatorius sukeicia dvieju studentu atributus vietomis ir grazina dabartini studenta.
    *
    *   @param kitas Studentas, kurio atributu reiksmes naudojamos keitimui.
    */
    if (&kitas == this)
        return *this;
    swap(vardas, kitas.vardas);
    swap(pavarde, kitas.pavarde);
    swap(pazymiai, kitas.pazymiai);
    swap(egzaminas, kitas.egzaminas);
    swap(galutinis_vid, kitas.galutinis_vid);
    swap(galutinis_med, kitas.galutinis_med);
    return *this;
}


void studentas::sukurti_studenta(string vardas_, string pavarde_, vector<int> pazymiai_, int egzaminas_)
{
    /*!
    *   Klases studentas metodas, skirtas studento sukurimui suteikus funkcijai duomenis.
    *
    *   @param vardas_ Norimas vardas.
    *   @param pavarde_ Norima pavarde.
    *   @param pazymiai_ Norimas namu darbu pazymiu vektorius.
    *   @param egzaminas_ Norimas egzamino rezultatas.
    */
	vardas =  vardas_;
	pavarde =  pavarde_;
	pazymiai =  pazymiai_;
	egzaminas =  egzaminas_;
	galutinis_vid = 0;
	galutinis_med = 0;
}


void studentas::sukurti_pazymi(int paz)
{
    /*!
    *   Klases studentas metodas, skirtas studentui priskirti namu darbo pazymi.
    *
    *   @param paz Norimas namu darbu pazymys.
    */
    pazymiai.resize(pazymiai.size() + 1);
    pazymiai.push_back(paz);
}


void studentas::istrinti_nd()
{
    /*!
    *   Klases studentas metodas, skirtas studento namu darbu vektoriaus sunaikinimui.
    */
    pazymiai.clear();
}


void studentas::skaiciuoti_galutini_vid()
{
    /*!
    *   Klases studentas metodas, skirtas studento galutinio pazymio skaiciavimui naudojant vidurki.
    */
	int pazymiu_suma = accumulate(pazymiai.begin(), pazymiai.end(), 0);;
	int pazymiu_vidurkis = pazymiu_suma / pazymiai.size();
	galutinis_vid = 0.4 * pazymiu_vidurkis + 0.6 * egzaminas;
}


void studentas::skaiciuoti_galutini_med()
{
    /*!
    *   Klases studentas metodas, skirtas studento galutinio pazymio skaiciavimui naudojant mediana.
    */
    vector<int> pazymiu_masyvas;
    for (int i = 0; i < pazymiai.size(); i++)
        pazymiu_masyvas.push_back(pazymiai[i]);
    pazymiu_masyvas.push_back(egzaminas);

    sort(pazymiu_masyvas.begin(), pazymiu_masyvas.end());
    float pazymiu_mediana;

    if (pazymiu_masyvas.size() == 0)
    {
        pazymiu_mediana = 0;
    }
    else if (pazymiu_masyvas.size() % 2 == 0)
    {
        pazymiu_mediana = (pazymiu_masyvas[pazymiu_masyvas.size() / 2] + pazymiu_masyvas[pazymiu_masyvas.size() / 2 - 1]) / 2.0;
    }
    else
    {
        pazymiu_mediana = pazymiu_masyvas[(pazymiu_masyvas.size() - 1) / 2];
    }
    galutinis_med = 0.4 * pazymiu_mediana + 0.6 * egzaminas;
}