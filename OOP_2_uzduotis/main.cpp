#include "build_lib.h"
#include "studentas.h"
#include "ivedimas_isvedimas.h"
#include "rusiavimas.h"
#include "failu_generavimas.h"
#include "studentu_isskirstymas.h"


int main()
{
    for (int studentu_skaicius = 1000; studentu_skaicius <= 10000000; studentu_skaicius *= 10)
    {
        auto viso_matavimo_pradzia = high_resolution_clock::now();
        vector<studentas> vektorius_antras;
        int pazymiu_skaicius_antras;
        ivedimas_vector(vektorius_antras, "kursiokai" + to_string(studentu_skaicius) + ".txt", &pazymiu_skaicius_antras);
        if (vektorius_antras.size() == 0)
        {
            cout << "Pradiniu duomenu vektorius tuscias." << endl;
        }

        else
        {
            string vardas = "Vardas";
            string pavarde = "Pavarde";
            string galutinis_med = "Galutinis(Med.)";
            string galutinis_vid = "Galutinis(Vid.)";
            auto matavimo_pradzia = high_resolution_clock::now();

            vector<studentas> nelaimeliai_stud_vector_antras(vektorius_antras.size());
            remove_copy_if(vektorius_antras.begin(), vektorius_antras.end(), nelaimeliai_stud_vector_antras.begin(), nelaimeliu_suradimas);

            auto matavimo_pabaiga = high_resolution_clock::now();
            duration<double> skirtumas = matavimo_pabaiga - matavimo_pradzia;
            cout << "Studentu suskirstymas uztruko: " << skirtumas.count() << "s" << endl;

            auto viso_matavimo_pabaiga = high_resolution_clock::now();
            duration<double> viso_skirtumas = viso_matavimo_pabaiga - viso_matavimo_pradzia;
            cout << "Testas su " << studentu_skaicius << " studentu naudojant std::vector uztruko: " << viso_skirtumas.count() << "s" << endl;

            cout << endl << endl;
        }
        cout << endl;
    }
}
