#include "element.h"
#include "table.h"


using namespace std;


Table::Table()
{
	tab = new Elem[100];
}

Table::~Table()
{
	delete[] tab; 
}


