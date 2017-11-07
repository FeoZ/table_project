#include "etudiant.h"
#include "element.h"
#include "table.h"
#include "time.h"
#include "stdlib.h"
#include <string>
#include <math.h>
#include <fstream>
#include <vector>
#include <chrono>
#include <ctime>



using namespace std;


Table::Table()
{
	tab = new Elem[Taille];
	demande();
}

Table::Table(int i){
	tab = new Elem[Taille];
	fonctHach = listeFonctionsHachage[0];
	fonctReHach = listeFonctionsReHachage[i];
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


bool Table::recherche(const Elem& e) 
{

		if (size() != 0) { // Si la table n'est pas vide, sinon inutile
		unsigned int num = e.getNum();
		unsigned int tampon = num; 
		unsigned int position = (this->*fonctHach)(e);

//		std::cout << "Position initiale de l'objet selon ltab[ia fonction de hachage courante : " << position << std::endl;
		if (fonctReHach == listeFonctionsReHachage[0]) {
			if(tab[position].getOcc())
			{ 
				if(tab[position].getNum() == num)
				{
					return true;
				}
				Elem* temp = tab[position].getSuiv();
				while(temp!= NULL)
				{
					if(temp->getNum() == num)
					{
						return true;
					}
					temp = temp->getSuiv();
				}
				return false;  
			}
			else
			{
				return false;
			}		
		}


		/* ReHachage Lineaire */
		if (fonctReHach == listeFonctionsReHachage[1]) {
			unsigned int nb = 1; 
			// Tant que les valeurs des elements ne sont pas identiques
			while (nb <= (unsigned int)this->size()) {
				if (tab[position].getNum() == num) {
		//			std::cout << "La case est trouvée, position : " << position << std::endl;
					return true;
				}
				if (tab[position].isEmpty()) {
		//			std::cout << "La case est vide, position : " << position << std::endl;
					return false;
				}
				if (tab[position].getOcc() == true) { // Si la case est libérée
		//			std::cout << "La case est libérée, position : " << position << std::endl;
				}
				position = (position + 1) % Taille;
				nb++;
			}
			//std::cout << "L'élement se trouve à la position : " << position << std::endl;
		}

		/* ReHachage Quadratique */
		if(fonctReHach == listeFonctionsReHachage[2]){
			unsigned int nb = 1;
			while (tab[position].getNum() != num && nb <= (unsigned int)this->size()){
				if(tab[position].isEmpty()) {
		//			std::cout << "La case est vide, position : " << position << std::endl;
					return false;
					}
			nb++;
			position = (tampon + (nb - 1)*(nb - 1)) %Taille;
			}
		}


		// Double hachage
		if(fonctReHach == listeFonctionsReHachage[3]){
			unsigned int nb = 1;
			unsigned int j;
			if(fonctHach == listeFonctionsHachage[0])
			{
				j = ft_hach_2(e); 
			}
			else
			{
			 	j = ft_hach_1(e);
			}

			while (tab[position].getNum() != num && nb <= (unsigned int)this->size()){
				if(tab[position].isEmpty()) {
					std::cout << "La case est vide, position : " << position << std::endl;
					return false;
				}
				nb++;
				position = (tampon + j*(nb - 1)) % Taille;
			}
			std::cout << "L'élement se trouve à la position : " << position << std::endl;
			return true;
		}
		//std::cout << "L'élement se trouve à la position : " << position << std::endl;
		}
	return false;
} 	

void Table::ajoute(Elem &e) 
{
	if(!recherche(e))
	{
		(this->*fonctReHach)(e);	
	}
}

void Table::modifie(const Elem& etu,const unsigned int age)
{
	Elem* etud = recherche2(etu);
	if(etud != NULL)
	{
		etud->setAge(age);
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
			std::cout<<"Case : "<<i<<" :"<<std::endl<<tab[i]<<std::endl; 
			temp = tab[i].getSuiv();
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


void Table::creeListes(Elem &e)
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

	std::cout<<"done"<<std::endl; 

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
	//	cout<<"yo 1"<<endl;
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
	unsigned int j;
	if(fonctHach == listeFonctionsHachage[0])
	{
		j = ft_hach_2(e); 
	}
	else
	{
 		j = ft_hach_1(e);
	}
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



void creePerf(){ /////////// NE MARCHE PAS POUR DES RAISONS INCONNUES

	chrono::time_point<chrono::system_clock> start, end;

	Table a(1);
	Table b(2);	
	Table c(3);

	float tim[12];

	vector<float> times;
	vector<int> nbs;

	nbs.push_back(1000);
	nbs.push_back(2000);
	nbs.push_back(3000);
	nbs.push_back(5000);
	//chrono 
	float temp;
	int it = 0;

	cout<<"fini partifafzazfaz"<<endl;
 	start = std::chrono::system_clock::now();
	a.rempTab(1000, 1000);
	cout<<"fini partie 1"<<endl;
	end = chrono::system_clock::now();
	temp = chrono::duration_cast<chrono::milliseconds> (end-start).count();

	a.affiche_tab();

	////times.push_back(temp);
	tim[it] = temp;
	it++;
 	start = std::chrono::system_clock::now();
	a.rempTab(2000, 2000);
	end = chrono::system_clock::now();
	temp = chrono::duration_cast<chrono::milliseconds> (end-start).count();
	//times.push_back(temp);
	tim[it] = temp;
	it++;

 	start = std::chrono::system_clock::now();
	a.rempTab(3000, 3000);
	end = chrono::system_clock::now();
	temp = chrono::duration_cast<chrono::milliseconds> (end-start).count();
	//times.push_back(temp);
	tim[it] = temp;
	it++;

 	start = std::chrono::system_clock::now();
	a.rempTab(5000, 5000);
	end = chrono::system_clock::now();
	temp = chrono::duration_cast<chrono::milliseconds> (end-start).count();
	//times.push_back(temp);
	tim[it] = temp;
	it++;


	start = std::chrono::system_clock::now();
	b.rempTab(1000, 1000);
	end = chrono::system_clock::now();
	temp = chrono::duration_cast<chrono::milliseconds> (end-start).count();
	//times.push_back(temp);
	tim[it] = temp;
	it++;

 	start = std::chrono::system_clock::now();
	b.rempTab(2000, 2000);
	end = chrono::system_clock::now();
	temp = chrono::duration_cast<chrono::milliseconds> (end-start).count();
	//times.push_back(temp);
	tim[it] = temp;
	it++;

 	start = std::chrono::system_clock::now();
	b.rempTab(3000, 3000);
	end = chrono::system_clock::now();
	temp = chrono::duration_cast<chrono::milliseconds> (end-start).count();
	//times.push_back(temp);
	tim[it] = temp;
	it++;

 	start = std::chrono::system_clock::now();
	b.rempTab(5000, 5000);
	end = chrono::system_clock::now();
	temp = chrono::duration_cast<chrono::milliseconds> (end-start).count();
	//times.push_back(temp);
	tim[it] = temp;
	it++;

	start = std::chrono::system_clock::now();
	c.rempTab(1000, 1000);
	end = chrono::system_clock::now();
	temp = chrono::duration_cast<chrono::milliseconds> (end-start).count();
	//times.push_back(temp);
	tim[it] = temp;
	it++;

 	start = std::chrono::system_clock::now();
	c.rempTab(2000, 2000);
	end = chrono::system_clock::now();
	temp = chrono::duration_cast<chrono::milliseconds> (end-start).count();
	//times.push_back(temp);
	tim[it] = temp;
	it++;

 	start = std::chrono::system_clock::now();
	c.rempTab(3000, 3000);
	end = chrono::system_clock::now();
	temp = chrono::duration_cast<chrono::milliseconds> (end-start).count();
	//times.push_back(temp);
	tim[it] = temp;
	it++;

 	start = std::chrono::system_clock::now();
	c.rempTab(5000, 5000);
	end = chrono::system_clock::now();
	temp = chrono::duration_cast<chrono::milliseconds> (end-start).count();
	//times.push_back(temp);
	tim[it] = temp;
	it++;




	ofstream fichier("./data/performances2.txt", ios::out | ios::trunc);


	if(fichier)
	{
		fichier << "# 'nb' 'temps' re-hachage linéaire"<< endl;

		for(int i = 0; i < 3; i++)
		{
			fichier << nbs[i] << " " << tim[i] <<endl;
		}


		fichier << endl << "# 'nb' 'temps' re-hachage quadratique"<< endl;
		for(int i = 0; i < 3; i++)
		{
			fichier << nbs[i+3] << " " << tim[i] <<endl;
		}

		fichier << endl << "# 'nb' 'temps' double hachage"<< endl;
		for(int i = 0; i < 3; i++)
		{
			fichier << nbs[i+6] << " " << tim[i] <<endl;
		}

		fichier.close();
	}

}


void Table::rempTab(int nb, unsigned int T)
{
	Taille = T; 
	srand(time(NULL));
	int i;
	Etudiant a (rand(), rand() % 30);  
	for(i = 0; i < nb; i++)
	{
		a.setNum(rand());
		a.setAge(rand() % 30);
		ajoute(a); 
	//	cout<<"ajouté"<<endl; 
	}	
}


Elem* Table::recherche2(const Elem &e) {

	Elem* etu;
	if (this->size() != 0) { // Si la table n'est pas vide, sinon inutile
		unsigned int num = e.getNum();
		unsigned int tampon = num;
		cout<<num<<endl;
		unsigned int position = (this->*fonctHach)(e);
		cout<<position<<endl;

		std::cout << "Position initiale de l'objet selon la fonction de hachage courante : " << position << std::endl;

		/* ReHachage Lineaire */
		if (fonctReHach == listeFonctionsReHachage[1]) {
			unsigned int nb = 1; 
			// Tant que les valeurs des elements ne sont pas identiques
			while (nb <= (unsigned int)this->size()) {
				if (tab[position].getNum() == num) {
					std::cout << "La case est trouvée, position : " << position << std::endl;
					etu = &tab[position];
					return etu;
				}
				if (tab[position].isEmpty()) {
					std::cout << "La case est vide, position : " << position << std::endl;
					etu = &tab[position];
					return etu;;
				}
				if (tab[position].getOcc() == true) { // Si la case est libérée
					std::cout << "La case est prise, position : " << position << std::endl;
				}
				nb++;
				position = (position + 1) % Taille;

			}
			//std::cout << "L'élement se trouve à la position : " << position << std::endl;
		}

		/* ReHachage Quadratique */
		if(fonctReHach == listeFonctionsReHachage[2]){
			unsigned int nb = 1;
			while (tab[position].getNum() != num && nb <= (unsigned int)this->size()){
				if(tab[position].isEmpty()) {
					std::cout << "La case est vide, position : " << position << std::endl;
					etu = &tab[position];
					return etu;
				}
				nb++;
				position = (tampon + (nb - 1)*(nb - 1)) %Taille;
			}
			std::cout << "L'élement se trouve à la position : " << position << std::endl;
			etu = &tab[position];
			return etu;
		}
	

		//DOUBLE HACHAGE
		if(fonctReHach == listeFonctionsReHachage[3]){
			unsigned int nb = 1;
				unsigned int j;
				if(fonctHach == listeFonctionsHachage[0])
				{
					j = ft_hach_2(e); 
				}
				else
				{
			 		j = ft_hach_1(e);
				}

			while (tab[position].getNum() != num && nb <= (unsigned int)this->size()){
				if(tab[position].isEmpty()) {
					std::cout << "La case est vide, position : " << position << std::endl;
					etu = &tab[position];
					return etu;;
				}
				nb++;
				position = (tampon + j*(nb - 1)) % Taille;
			}
			std::cout << "L'élement se trouve à la position : " << position << std::endl;
			etu = &tab[position];
			return etu;
		}
	}
	return NULL;
}
