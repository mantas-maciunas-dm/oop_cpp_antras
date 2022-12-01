#include "build_lib.h"
#include "studentas.h"
#include "rusiavimas.h"


bool palyginimas(studentas stud1, studentas stud2)
{
    if (stud1.paimti_varda().compare(stud2.paimti_varda()) == 0)
        return (stud1.paimti_pavarde().compare(stud2.paimti_pavarde()) < 0);

    return (stud1.paimti_varda().compare(stud2.paimti_varda()) < 0);
}
