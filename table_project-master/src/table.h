#ifndef __TABLE_H
#define __TABLE_H

class Table{

private:
	unsigned int Taille = 100; 
	Elem* tab;

	unsigned int (Table::*fonctHach)(Elem);
	void (Table::*fonctReHach)(Elem&);

public:

	Table();
	~Table();

	void affiche() const; //

	void demande();

	int size() { return Taille; }

//============== fonctionalités

	bool recherche(const Elem& e) const;  // recherche dans la table un Element et indique s'il existe

	bool recherche2(const Elem& e);  // Indique si un élément existe et à quelle position

	void affiche_tab() const;

	void ajoute(Elem &e); // doit pouvoir demander quelle fonction de hachage utiliser à l'utilisateur

	void supprimer(Elem &e);  // doit pouvoir demander quelle fonction de hachage utiliser à l'utilisateur

//========== ft(s) hachage

	unsigned int ft_hach_1(Elem etu); //hachage par modulo

	unsigned int ft_hach_2(Elem etu); //hachage par addition ASCII

//=================== gestion collision

	void reHach_lin(Elem& e);

	void reHach_quad(Elem& e);

	void doubleHach(Elem& e); 

	void creeListes(Elem& e);

//===================== fonction(s) test

	void rempTab(); /// Met un grand nombre d'étudiant dans le tableau


//	===================== ptr sur ft

	unsigned int (Table::*listeFonctionsHachage[2])(Elem) = {&Table::ft_hach_1, &Table::ft_hach_2};
	void (Table::*listeFonctionsReHachage[4])(Elem&) = {&Table::creeListes, &Table::reHach_lin, &Table::reHach_quad, &Table::doubleHach};


};


#endif