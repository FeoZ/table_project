#ifndef __ETUDIANT_H
#define __ETUDIANT_H


class Etudiant{

private:
	unsigned int num;
	int age; 

public: 

	Etudiant(); 
	~Etudiant();

	bool operator==(const Etudiant a) const; 	

//	std::ostream &operator<<(std::ostream &flux, Etudiant const& etu) const;

	 
};






#endif