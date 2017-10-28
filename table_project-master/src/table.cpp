#include "etudiant.h"
#include "element.h"
#include "table.h"


using namespace std;


Table::Table()
{
	tab = new Elem[Taille];
}

Table::~Table()
{
	delete[] tab; 
}


