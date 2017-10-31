#ifndef __TABLE_H
#define __TABLE_H

class Table{

private:
	unsigned int Taille = 100; 
	Elem* tab; 

public:


	Table();
	~Table();

	void affiche() const; //

	unsigned int ft_hach_1(Elem etu); //hachage par modulo

	Elem recherche(const Elem e) const;  // recherche dans la table un Element et indique sa position


	void affiche_tab() const; 


	void ajoute(Elem &e);  // doit pouvoir demander quelle fonction de hachage utiliser à l'utilisateur 

	void rempTab(); /// Met un grand nombre d'étudiant dans le tableau

};


#endif