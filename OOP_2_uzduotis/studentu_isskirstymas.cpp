#include "build_lib.h"
#include "studentas.h"

bool nelaimeliu_suradimas(studentas stud)
{
	/*! 
	*	Funkcija randa, ar studento galutinis balas(skaiciuojant pagal vidurki) mazesnis nei 5.
	* 
	*	@param stud Studentas, su kuriuo atliekamas darbas.
	*/
	return (stud.paimti_galutini_vid() < 5.0);
}
