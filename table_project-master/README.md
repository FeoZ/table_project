# table_project

Projet de table de Hachage;

===============================
COMPILATION :

	option de compilation: 
		
		- make : compile simplement le programmme

		- make clear : supprime tout les fichiers objets 

		- make veryclean : supprime fichiers objets et exectuables		

		- make re : supprime tout les fichiers objets, executables et recompile	 

==============================
EXECUTION

	Depuis un terminal à la racine du projet :

executer :	./bin/prog




==============================
RESULTATS : 

	un fichier "perfomances.txt" se situe depuis la racine dans "./data/", il contient les résultats de vitesse d'insertion en fonction du nombre d'éléments insérés dans la table hachage par les types de gestion de collision.

	visualisation : pour visualiser sur un graphique les résultats taper dans le temrinal à la racine du projet : 


	gnuplot
	plot "./data/performances.txt" using 1:2 with lines


===========================================
Projet étudiant réalisé dans le cadre de l'UE LIFAP6 à l'université claude bernard Lyon 1

KACED Jayson 
LEPERCQ Yann
