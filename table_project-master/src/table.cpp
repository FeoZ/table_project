#include "etudiant.h"
#include "element.h"
#include "table.h"
#include "time.h"
#include "stdlib.h"


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
	cin>>choixFt;

	}while(choixFt < 1 or choixFt > 1);

	do{
	cout<<"Choisissez quelle gestion des collisions utiliser"<<endl;
	cout<<"1 pour destion des collisions par liste"<<endl;
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


Elem Table::recherche(const Elem e) const
{
	return e; 
} 	

void Table::affiche_tab() const //A MODIFIER POUR AFF LA LISTE DERRIERE
{
	unsigned int i;

	std::cout<<"========================================================"<<endl; 
	std::cout<<"			TABLEAU								"<<endl;
	std::cout<<"========================================================"<<endl;
	std::cout<<endl; 
	for(i = 0; i < Taille; i++)
	{
		if(tab[i].getOcc())
		{
			std::cout<<"Case : "<<i<<" :"<<std::endl<<tab[i]<<std::endl; 
			Etudiant* temp = tab[i].getSuiv();
			while(temp != NULL)
			{
				std::cout<<*temp<<std::endl;
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

		cout<<"rip"<<endl;   /////// ici que ça bug, j'ai essayé de faire une liste chainée assez bizarre 
		tab[i].setSuiv(e);  /////// nsm, on verra plus tard
	}
	else
	{
		tab[i] = e; 	
		cout<<tab[i]<<endl;	
	}

	std::cout<<"done"<<std::endl; 



}

void Table::reHach_lin(Elem& e){

}

void Table::reHach_quad(Elem& e){

}

void Table::doubleHach(Elem& e){

} 





void Table::rempTab()
{
	srand(time(NULL));
	int i;
	Etudiant a (rand(), rand() % 30);  
	for(i = 0; i < 100; i++)
	{
		a.setNum(rand());
		a.setAge(rand() % 30);
		(this->*fonctReHach)(a);
	}	
}