#include "studentas.h"
#include "build_lib.h"


studentas::~studentas()
{
    pazymiai.clear();
    egzaminas = NULL;
    galutinis_med = NULL;
    galutinis_vid = NULL;
}


studentas::studentas(const studentas& kitas)
{
    vardas = kitas.vardas;
    pavarde = kitas.pavarde;
    pazymiai = kitas.pazymiai;
    egzaminas = kitas.egzaminas;
    galutinis_med = kitas.galutinis_med;
    galutinis_vid = kitas.galutinis_vid;
}


studentas &studentas::operator=(studentas& kitas)
{
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


void studentas::sukurti_zmogu(string vardas_, string pavarde_, vector<int> pazymiai_, int egzaminas_)
{
	vardas =  vardas_;
	pavarde =  pavarde_;
	pazymiai =  pazymiai_;
	egzaminas =  egzaminas_;
	galutinis_vid = 0;
	galutinis_med = 0;
}


void studentas::sukurti_pazymi(int paz)
{
    pazymiai.resize(pazymiai.size() + 1);
    pazymiai.push_back(paz);
}


void studentas::istrinti_nd()
{
    pazymiai.clear();
}


void studentas::skaiciuoti_galutini_vid()
{
	int pazymiu_suma = accumulate(pazymiai.begin(), pazymiai.end(), 0);;
	int pazymiu_vidurkis = pazymiu_suma / pazymiai.size();
	galutinis_vid = 0.4 * pazymiu_vidurkis + 0.6 * egzaminas;
}


void studentas::skaiciuoti_galutini_med()
{
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