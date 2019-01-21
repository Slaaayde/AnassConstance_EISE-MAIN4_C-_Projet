#include "echiquier.hh"
#pragma once
class Piece{

	protected:
		string m_id; //nom de la piece
		int pos_x;   //colonne
		int pos_y;   //ligne
		int couleur;  //Blanc==0  Noir==1
        string val;   
        int life;   //disponible ou pas?
        int numero;  //chaque piece a un numero different
	public:
		Piece();
		Piece(int x,int y,int coul,string id,Echiquier E);
		virtual bool validation(int x_vise,int y_vise,Echiquier E) {return 0;}; //Le mouvement est-il possible?
		virtual void deplacement(int x_vise,int y_vise,Echiquier E){};  //Fais le deplacement
		friend ostream& operator<<(ostream& , Piece const& P);//affiche la localisation de la piece
		Piece& operator=(const Piece& P);
		
//--------------get or set
		int get_x();
		int get_y();
		int get_num();
		int get_life();
		void set_life();
		string get_id();
		
		void set_id(string id);
		




};
