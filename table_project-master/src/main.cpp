#include <iostream>
#include "etudiant.h"
#include "element.h"
#include "table.h"

using namespace std;

int main(){

	Etudiant v (111100, 23); 

	Etudiant b (111100, 43); 

	Table a;

	a.ajoute(v);
	a.ajoute(b);

	// a.rempTab(); //// Tu peux tester ça 

	a.affiche_tab();






	return 0;
}