#include "etudiant.h"
#include "element.h"
#include "table.h"
#include "time.h"
#include "stdlib.h"


using namespace std;


Table::Table()
{
	tab = new Elem[Taille];
}

Table::~Table()
{
	delete[] tab; 
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
			while(tab[i].getSuiv() != NULL)
			{
				std::cout<<tab[i].getSuiv()<<std::endl; 
			}
			std::cout<<std::endl;
		}

	}
	std::cout<<"========================================================"<<endl; 
	std::cout<<"		    FIN TABLEAU							"<<endl;
	std::cout<<"========================================================"<<endl;
	std::cout<<endl; 
}


void Table::ajoute(Elem &e) ///// A MODIFIER EN UTILISANT POINTEUR SUR FT POUR HACHAGE + LISTES
{
	unsigned int i; 
	i = ft_hach_1(e);

	if(tab[i].getOcc())
	{
		cout<<"rip"<<endl;   /////// ici que ça bug, j'ai essayé de faire une liste chainée assez bizarre 
		tab[i].setSuiv(e);  /////// nsm, on verra plus tard
	}
	else
	{
		tab[i] = e; 		
	}

	std::cout<<"done"<<std::endl; 
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
		ajoute(a);
	}	
}