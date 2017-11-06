#include "etudiant.h"
#include "element.h"
#include "table.h"
#include "time.h"
#include "stdlib.h"
#include <string>
#include <math.h>


using namespace std;


Table::Table()
{
	tab = new Elem[Taille];
	demande();
}

Table::~Table()
{
	delete[] tab; 
}


void Table::demande()
{
	int choixFt, Gest;

	do{
	cout<<"Choisissez votre fonction de hachage"<<endl;
	cout<<"1 pour fonction de hachage pas modulo"<<endl;
	cout<<"2 pour fonction de hachage par addition ascii"<<endl; 
	cin>>choixFt;

	}while(choixFt < 1 or choixFt > 2);

	do{
	cout<<"Choisissez quelle gestion des collisions utiliser"<<endl;
	cout<<"1 pour gestion des collisions par liste"<<endl;
	cout<<"2 pour gestion des collisions par re-hachage linéaire"<<endl; 
	cout<<"3 pour gestion des collisions par re-hachage quadratique"<<endl;
	cout<<"4 pour gestion des collisions par double hachage"<<endl;
	cin>>Gest;

	}while(Gest < 1 or Gest > 4);

	fonctHach = listeFonctionsHachage[choixFt - 1];
	fonctReHach = listeFonctionsReHachage[Gest - 1];

}

unsigned int Table::ft_hach_1(Elem etu)
{
	unsigned int x = etu.getNum() % Taille;
	return x; 
}


unsigned int Table::ft_hach_2(Elem etu)
{
	unsigned int x = etu.getNum() % Taille;
	x = sqrt((Taille - x)* (Taille - x));  
	return x;
}


bool Table::recherche(const Elem& e) const // A AMELIORER, temps linéaire et non constant
{
	unsigned int cle = e.getNum(); 
	unsigned int i;

	Etudiant* temp;

	for(i = 0; i < Taille; i++)
	{
		if(tab[i].getOcc())
		{
			temp = tab[i].getSuiv();
			while(temp != NULL)
			{
				temp = temp->getSuiv(); 
				if(temp->getNum() == cle)
				{
					cout<<"L'etudiant existe deja!"<<endl;
					return true; 
				}
			}
			if(tab[i].getNum() == cle)
			{
				cout<<"L'etudiant existe deja!"<<endl;
				return true; 
			} 
		}

	}

	cout<<"L'etudiant n'existe pas"<<endl; 
	return false; 
} 	

void Table::ajoute(Elem &e) 
{
	if(!recherche(e))
	{
		(this->*fonctReHach)(e);	
	}
}

void Table::affiche_tab() const //A MODIFIER POUR AFF LA LISTE DERRIERE
{
	unsigned int i;
	Etudiant* temp;

	std::cout<<"========================================================"<<endl; 
	std::cout<<"			TABLEAU								"<<endl;
	std::cout<<"========================================================"<<endl;
	std::cout<<endl;

	for(i = 0; i < Taille; i++)
	{
		if(tab[i].getOcc())
		{
			std::cout << "Case " << i << " : "<< std::endl <<tab[i] << std::endl;
			temp = tab[i].getSuiv();
			while(temp != NULL)
			{
				std::cout<< *temp <<std::endl;
				temp = temp->getSuiv(); 
			}
			std::cout<<std::endl;
		}

	}

	std::cout<<"========================================================"<<endl; 
	std::cout<<"		    FIN TABLEAU							"<<endl;
	std::cout<<"========================================================"<<endl;
	std::cout<<endl; 
}


void Table::creeListes(Elem &e) ///// A MODIFIER EN UTILISANT POINTEUR SUR FT POUR HACHAGE + LISTES
{
	unsigned int i; 
	i = (this->*fonctHach)(e);

	if(tab[i].getOcc())
	{

		cout<<"rip"<<endl;  
		tab[i].setSuiv(e);  
	}
	else
	{
		tab[i] = e; 	
		cout<<tab[i]<<endl;	
	}

	std::cout << "done" << std::endl;

}

void Table::reHach_lin(Elem& e){
	unsigned int nb = 1;
	unsigned int i = (this->*fonctHach)(e);
	unsigned indice = i; 

	while(tab[indice].getOcc())
	{
		if(nb == Taille)
		{
			break;
		}
		nb++;
		indice = (indice + 1) % Taille;
	}

	if(nb != Taille)
	{
		tab[indice] = e;
		cout<<"ajout : OK"<<endl;
		e.setNbEssais(nb); 
	}

}

void Table::reHach_quad(Elem& e){
	unsigned int nb = 1;
	unsigned int i = (this->*fonctHach)(e);
	unsigned indice = i; 

	while(tab[indice].getOcc())
	{
		if(nb == Taille)
		{
			break;
		}
		nb++;
		indice = (i + (nb - 1)*(nb - 1)) % Taille;
	}

	if(nb < Taille)
	{
		tab[indice] = e;
		e.setNbEssais(nb); 
	}

}


void Table::doubleHach(Elem& e){
	unsigned int nb = 1;
	unsigned int i = (this->*fonctHach)(e);
	unsigned int j = ft_hach_2(e); 
	unsigned indice = i; 

	while(tab[indice].getOcc())
	{
		if(nb == Taille)
		{
			break;
		}
		nb++;
		indice = (i + j*(nb - 1)) % Taille;
	}

	if(nb < Taille)
	{
		tab[indice] = e;
		e.setNbEssais(nb); 
	}

} 


void Table::rempTab()
{
	srand(time(NULL));
	int i;
	Etudiant a (rand(), rand() % 30);  
	for(i = 0; i < 10; i++)
	{
		a.setNum(rand());
		a.setAge(rand() % 30);
		ajoute(a); 
	}
}


void Table::supprimer(Elem &e) {

	if(this->size() != 0) { // Si la table n'est pas vide, sinon inutile
		int num = e.getNum();
		unsigned int position = (this->*fonctHach)(e);

		if(tab[position].getNum() == num) {
			tab[position].setOcc(true);
		}
	}
}

bool Table::recherche2(const Elem &e) {

	if (this->size() != 0) { // Si la table n'est pas vide, sinon inutile
		int num = e.getNum();
		unsigned int position = (this->*fonctHach)(e);

		std::cout << "Position initiale de l'objet selon la fonction de hachage courante : " << position << std::endl;

		if (position == 0) {
			return false;
		}

		/* ReHachage Lineaire */
		if (fonctReHach == listeFonctionsReHachage[1]) {

			// Tant que les valeurs des elements ne sont pas identiques
			while (position <= this->size()) {
				if (tab[position].getNum() == num) {
					std::cout << "La case est trouvée, position : " << position << std::endl;
					return true;
				}
				if (tab[position].isEmpty()) {
					std::cout << "La case est vide, position : " << position << std::endl;
					return false;
				}
				if (tab[position].getOcc() == true) { // Si la case est libérée
					std::cout << "La case est libérée, position : " << position << std::endl;
				}
				position = (position + 1);
			}
			//std::cout << "L'élement se trouve à la position : " << position << std::endl;
		}

		/* ReHachage Quadratique */
		if(fonctReHach == listeFonctionsReHachage[2]){
			int nb = 1;
			while (tab[position].getNum() != num && position <= this->size())
				if(tab[position].getOcc() == true || tab[position].isEmpty()) {
					std::cout << "La case est vide, position : " << position << std::endl;
					return false;
				}
			nb++;
			position = (position + (nb - 1)*(nb - 1));
		}
		std::cout << "L'élement se trouve à la position : " << position << std::endl;
		return true;
	}
}


