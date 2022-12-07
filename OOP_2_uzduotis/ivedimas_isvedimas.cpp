#include "build_lib.h"
#include "studentas.h"
#include "ivedimas_isvedimas.h"


unsigned int Zodziai_eiluteje(string const& str)
{
    /*! 
    *   Funkcija randa zodziu skaiciu duotame string tekste.
    * 
    *   @param str Tekstas, kuriame atliekama paieska.
    */
    stringstream stream(str);
    return std::distance(istream_iterator<string>(stream), istream_iterator<string>());
}


void ivedimas_vector(vector<studentas>& studentai, string failo_pavadinimas, int* nd_skaicius)
{
    /*! \brief Funkcija uzpildo nurodyta studentu vektoriu.
    *
    *   Funkcija uzpildo nurodyta studentu vektoriu studentais, esanciais nurodytame faile. Jei failo atidaryti nepavyko,
    *   vartotojui ismetama klaida. Taip pat yra matuojama, kiek laiko uztrunka sis procesas.
    * 
    *   @param studentai Vektorius, kuri norima uzpildyti.
    *   @param failo_pavadinimas Failas, is kurio skaitomi duomenys.
    *   @param nd_skaicius Namu darbu kiekis.
    */
    auto matavimo_pradzia = high_resolution_clock::now();
    string eilute;
    ifstream studentu_failas(failo_pavadinimas);

    int studentu_skaicius = 0;
    int temp;

    string buff;
    ifstream r;
    try {
        r.open(failo_pavadinimas);
        if (!r)
            throw std::runtime_error("Failo tokiu pavadinimu nera.");

        getline(r >> std::ws, buff);
        *nd_skaicius = Zodziai_eiluteje(buff) - 3;
        while (true)
        {
            studentas stud;
            string vardas, pavarde;
            int egzaminas;
            vector<int> pazymiai;
            r >> vardas;
            if (r.eof())
            {
                studentai.pop_back();
                break;
            }
            r >> pavarde;
            for (int i = 0; i < *nd_skaicius; i++)
            {
                r >> temp;
                pazymiai.push_back(temp);
            }
            r >> egzaminas;

            stud.sukurti_zmogu(vardas, pavarde, pazymiai, egzaminas);
            stud.skaiciuoti_galutini_med();
            stud.skaiciuoti_galutini_vid();
            studentu_skaicius += 1;
            studentai.resize(studentu_skaicius);
            studentai.push_back(stud);
        }
        r.close();
    }
    catch (int e) {}

    auto matavimo_pabaiga = high_resolution_clock::now();
    duration<double> skirtumas = matavimo_pabaiga - matavimo_pradzia;
    cout << "Failo nuskaitymas uztruko: " << skirtumas.count() << "s" << endl;

    if (studentai.size() == 0)
    {
        cout << "Negalima atidaryti failo arba jis tuscias." << endl;
    }
}


void isvedimas_vector(string failo_pav, vector<studentas> vektorius)
{
    /*! \brief Funkcija spausdina nurodyta studentu vektoriu i faila.
    *
    *   Funkcija spausdina nurodyta studentu vektoriu i nurodyta faila. Taip pat yra atliekamas matavimas, kuris nurodo, kiek laiko uztruko
    *   sis procesas.
    *
    *   @param failo_pav Failas, i kuri rasomi duomenys.
    *   @param vektorius Studentu vektorius, kurio duomenys yra spausdinami.
    */
    ofstream stud_failas(failo_pav);

    auto matavimo_pradzia = high_resolution_clock::now();

    stud_failas << left << setw(25) << "Vardas" << setw(25) << "Pavarde" << setw(15) << "Gal.(vid)" << setw(15) << "Gal.(med)" << endl;

    for (int i = 0; i < vektorius.size(); i++)
    {
        studentas dab_stud = vektorius[i];
        stud_failas << left << setw(25) << dab_stud.paimti_varda() << setw(25) << dab_stud.paimti_pavarde() << setw(15) << dab_stud.paimti_galutini_vid() <<
            setw(15) << dab_stud.paimti_galutini_med() << endl;
    }

    stud_failas.close();

    auto matavimo_pabaiga = high_resolution_clock::now();
    duration<double> skirtumas = matavimo_pabaiga - matavimo_pradzia;
    cout << "Failo " + failo_pav + " kurimas uztruko: " << skirtumas.count() << "s" << endl;
}
