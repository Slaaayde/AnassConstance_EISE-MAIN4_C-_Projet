#include "piece.hh"

class Pion: public Piece{
	
	public:
		Pion(int x,int y,int coul,string id,Echiquier E);
		bool validation(int x_vise,int y_vise,Echiquier E);
		void deplacement(int x_vise,int y_vise,Echiquier E);
        


};