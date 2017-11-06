#ifndef __ETUDIANT_H
#define __ETUDIANT_H

#include <iostream>

class Etudiant{

private:

	unsigned int num;
	int age;

	bool occ; //booleen pour la verification de la disponibilité d'une cellule du tableau
	unsigned int nbEssais;

	Etudiant* suiv;

public: 

	/* Constructeurs & Destructeurs */
	Etudiant(); 
	~Etudiant();

	Etudiant(const Etudiant& e);  // consturteur par copie 

	Etudiant(unsigned int a, unsigned int b);

	/* Operateurs */

	friend bool operator==(Etudiant const& lhs,Etudiant const& rhs); 	

	Etudiant& operator=(const Etudiant& etu);

	friend std::ostream &operator<<(std::ostream &flux, Etudiant const& etu);

	/* Fonctions diverses */

	void remp_etu();

	bool isEmpty() const { return (0 == num && 0 == age && nbEssais == 0); }

	/* Getteurs & Setteurs */

	Etudiant* getSuiv() const;

	unsigned int getNbEssai() const;

	void setNbEssais(unsigned int i); 

	void setSuiv(Etudiant etu);

	void setNum(unsigned int i);   
	
	void setAge(unsigned int i);

	void setOcc(bool b);

	unsigned int getNum() const;

	unsigned int getAge() const;

	bool getOcc() const;
};
#endif