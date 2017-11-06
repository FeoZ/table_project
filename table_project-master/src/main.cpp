#include <iostream>
#include "etudiant.h"
#include "element.h"
#include "table.h"

using namespace std;

int main(){


	Table a;

	a.rempTab(); //// Tu peux tester ça
	a.affiche_tab();
	Elem c(1360325192, 24);
	Elem s(1144433223, 47);
	cout << "Test de la recherche" << endl;

	a.recherche2(c);
	a.recherche2(s);

	return 0;
}