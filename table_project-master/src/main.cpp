#include <iostream>
#include "etudiant.h"
#include "element.h"
#include "table.h"

using namespace std;

int main(){

	Etudiant v (111100, 23); 

	Etudiant b (1112300, 43); 

	Table a;

	a.ajoute(v);
	a.ajoute(b);

	a.affiche_tab();






	return 0;
}