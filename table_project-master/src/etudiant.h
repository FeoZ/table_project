#ifndef __ETUDIANT_H
#define __ETUDIANT_H

#include <iostream>


// struct Cell{
// 	Etudiant info; 
// 	Cell *suivant;
// };


class Etudiant{

private:
	unsigned int num;
	int age;

	bool occ; //booleen pour la férification de l'occupation du tableau

	// Cell *ad;

public: 

	Etudiant(); 
	~Etudiant();

	Etudiant(const Etudiant& e);  // consturteur par copie 


	friend bool operator==(Etudiant const& lhs,Etudiant const& rhs); 	


	friend std::ostream &operator<<(std::ostream &flux, Etudiant const& etu);

	 
};






#endif