#include "piece.hh"

class Roi: public Piece{
	
	public:
		Roi(int x,int y,int coul,string id,Echiquier E);
		bool validation(int x_vise,int y_vise,Echiquier E);
		void deplacement(int x_vise,int y_vise,Echiquier E);
        //bool echec(Echequier E);
        //bool mat(Echequier E);


};