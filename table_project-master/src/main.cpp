#include <iostream>
#include "etudiant.h"
#include "element.h"
#include "table.h"

using namespace std;

int main(){


	Table a;

	Elem s(1, 47);
	a.ajoute(s);
	cout<<"yyo1"<<endl;
	a.rempTab(10, 12); //// Tu peux tester ça
	a.affiche_tab();
	Elem c(136192, 24);

	cout << "Test de la recherche" << endl;

	a.recherche2(c);
	a.recherche2(s);

	// creePerf();

	return 0;


	return 0;
}