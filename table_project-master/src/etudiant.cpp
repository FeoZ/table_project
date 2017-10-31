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
}

Etudiant::Etudiant(unsigned int a, unsigned int b)
{
	num = a; 
	age = b;
	occ = true;
	suiv = NULL; 
}


bool operator==(const Etudiant& lhs, const Etudiant& rhs)
{
    return (lhs.num == rhs.num && lhs.age == rhs.age);
}

ostream& operator<<(ostream& out, Etudiant const& etu)
{
	return out <<"Etudiant : "<<endl << "numero etu : " << etu.num << endl <<"age : " << etu.age <<endl;
}

unsigned int Etudiant::getNum() const 
{
	return num;
}

bool Etudiant::getOcc() const
{
	return occ;
}


unsigned int Etudiant::getAge() const 
{
	return age;
}

Etudiant* Etudiant::getSuiv() const
{
	return suiv;
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

	return (*this);

}

void Etudiant::setSuiv(Etudiant etu)
{
	suiv = new Etudiant (etu.getNum(), etu.getAge());
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
