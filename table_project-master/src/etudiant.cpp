#include <iostream>
#include "etudiant.h"

using namespace std; 

Etudiant::Etudiant()
{
	occ = false;
	num = 0; 
	age = 0; 
	// ad = NULL; 	
}

Etudiant::~Etudiant(){
	// if(ad != NULL)
	// {
	// 	Cell* temp = ad;
	// 	Cell* temp2; 

	// 	while(temp->suivant != NULL)
	// 	{
	// 		temp2 = temp->suivant;
	// 		delete temp;
	// 		temp = temp2; 
	// 	}

	// 	delete temp; 

	// }

	// delete Cell; 

}

Etudiant::Etudiant(const Etudiant& e)
{
	num = e.num;
	age = e.age;
}


bool operator==(const Etudiant& lhs, const Etudiant& rhs)
{
    return (lhs.num == rhs.num && lhs.age == rhs.age);
}

ostream& operator<<(ostream& out, Etudiant const& etu)
{
	return out <<"Etudiant : "<<endl << "numero etu : " << etu.num << endl <<"age : " << etu.age <<endl;
}

