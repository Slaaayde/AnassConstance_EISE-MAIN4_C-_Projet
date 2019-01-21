#include "piece.hh"

class Dame : public Piece{
	
	public:
		Dame(int x,int y,int coul,string id,Echiquier E);
		bool validation(int x_vise,int y_vise,Echiquier E);
		void deplacement(int x_vise,int y_vise,Echiquier E);


};