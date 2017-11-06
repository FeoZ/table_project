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

	Etudiant* suiv; 

	unsigned int nbEssais;

public: 

	Etudiant(); 
	~Etudiant();

	Etudiant(const Etudiant& e);  // consturteur par copie 

	Etudiant(unsigned int a, unsigned int b);

	friend bool operator==(Etudiant const& lhs,Etudiant const& rhs); 	

	Etudiant& operator=(const Etudiant& etu);

	friend std::ostream &operator<<(std::ostream &flux, Etudiant const& etu);

	unsigned int getNum() const;

	bool isEmpty() const { return (0 == num && 0 == age && nbEssais == 0); };

	unsigned int getAge() const;

	bool getOcc() const;

	Etudiant* getSuiv() const;

	unsigned int getNbEssai() const;

	void setNbEssais(unsigned int i); 

	void setSuiv(Etudiant etu);

	void setNum(unsigned int i);   
	
	void setAge(unsigned int i);

	void setOcc(bool b);

	void remp_etu();
};






#endif