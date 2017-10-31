#include <iostream>
#include "etudiant.h"
#include "element.h"
#include "table.h"

using namespace std;

int main(){

	// Etudiant a (1231, 12);
	// Etudiant b (1331, 12);

	// a.setSuiv(b);

	// cout<<*a.getSuiv()<<endl;  



	Table a; 
	a.rempTab();
	a.affiche_tab(); 

	return 0;
}