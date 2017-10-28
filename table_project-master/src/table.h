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

	void ajoute(Elem e);  // doit pouvoir demander quelle fonction de hachage utiliser à l'utilisateur 

	Elem recherche(Elem e) const;  // recherche dans la table un Element et indique sa position



};


#endif