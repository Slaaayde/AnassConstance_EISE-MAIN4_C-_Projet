#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Echiquier{

private: 
	int m_ligne;
	int m_colonne;
	int **m_couleur;  //pour savoir la couleur des pieces
	int **m_tab;	//Pour connaitre les pieces sur l'echiquier
	string **m_id; //pour l'affichage

public:
	Echiquier();
	//~Echiquier();
	friend ostream& operator<<(ostream& , Echiquier const& E);
	
	//--------get or set

	int get_ligne();
	int get_colonne();

	int get_value(int x,int y);
	int get_couleur(int x,int y);
	string get_id(int x,int y);

    void set_value(int val,int x,int y);
    void set_couleur(int coul,int x,int y);
    void set_id(string id,int x,int y);
//--------------------------------

    bool miam(int x,int y); //Le deplacement provoque une capture?

};


