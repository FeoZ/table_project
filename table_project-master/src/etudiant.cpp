#include <iostream>
#include "etudiant.h"

using namespace std; 

Etudiant::Etudiant()
{
	occ = false;
	num = 0; 
	age = 0; 
	// ad = NULL; 	
	suiv = NULL;
	nbEssais = 0; 
}

Etudiant::~Etudiant(){

	if(suiv != NULL)
		{
			Etudiant* temp = suiv;
			Etudiant* temp2;

			while(temp->suiv != NULL)
			{
				temp2 = temp->suiv; 
				delete temp; 
				temp = temp2;
			}
			delete temp;
		}

}

Etudiant::Etudiant(const Etudiant& e)
{
	num = e.num;
	age = e.age;
	occ = true; 
	suiv = NULL;
	nbEssais = e.nbEssais;  
}

Etudiant::Etudiant(unsigned int a, unsigned int b)
{
	num = a; 
	age = b;
	occ = true;
	suiv = NULL; 
	nbEssais = 0; 
}


bool operator==(const Etudiant& lhs, const Etudiant& rhs)
{
    return (lhs.num == rhs.num && lhs.age == rhs.age);
}

ostream& operator<<(ostream& out, Etudiant const& etu)
{
	return out <<"Etudiant : "<<endl << "numero etu : " << etu.num << endl <<"age : " << etu.age <<endl << "Nb Essais avant insertion : " << etu.nbEssais<<endl;;
}

unsigned int Etudiant::getNum() const 
{
	return num;
}

bool Etudiant::getOcc() const
{
	return occ;
}

unsigned int Etudiant::getNbEssai() const
{
	return nbEssais;
}


unsigned int Etudiant::getAge() const 
{
	return age;
}

Etudiant* Etudiant::getSuiv() const
{
	return suiv;
}

void Etudiant::setNbEssais(unsigned int i)
{
	nbEssais = i; 
}

void Etudiant::remp_etu()
{
	std::cout<<"Saisir numero etudiant :"<<std::endl; 
	cin>>(*this).num; 
	std::cout<<"Saisir age :"<<std::endl;
	cin>>(*this).age;
	occ = true;
}


Etudiant& Etudiant::operator=(const Etudiant& etu)
{
	num = etu.getNum();
	age = etu.getAge();
	occ = true; 
	suiv = NULL; 
	nbEssais = etu.getNbEssai();

	return (*this);

}

void Etudiant::setSuiv(Etudiant etu)
{
	if(suiv == NULL)
	{
		suiv = new Etudiant (etu.getNum(), etu.getAge());		
	}
	else
	{
		Etudiant* temp = suiv; 

		while(temp->suiv != NULL)
		{
			temp = temp->suiv;
		}

		temp->suiv = new Etudiant (etu.getNum(), etu.getAge());

	}
}

void Etudiant::setAge(unsigned int i)
{
	age = i; 
}


void Etudiant::setNum(unsigned int i)
{
	num = i; 
}


void Etudiant::setOcc(bool b)
{
	occ = b; 
}
