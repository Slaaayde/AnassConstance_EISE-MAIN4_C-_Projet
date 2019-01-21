#include "cavalier.hh"



Cavalier::Cavalier(int x,int y,int coul,string id,Echiquier E):Piece::Piece(x,y,coul,id,E)
{
	pos_x=x;
	pos_y=y;
	m_id=id;
	if (coul==0)
		val="Cb";
	else
		val="Cn";
	couleur=coul;
	E.set_value(numero,x,y);
	E.set_couleur(couleur,x,y);
	E.set_id(id,x,y);
	life=1;

}

bool Cavalier::validation(int x_vise,int y_vise,Echiquier E)
{
	if( y_vise<8 && x_vise<8 && y_vise>=0 && x_vise>=0)
	{
		
   	if((x_vise==pos_x-2 && y_vise==pos_y-1 && E.get_couleur(x_vise,y_vise)!=couleur)||(x_vise==pos_x-2 && y_vise==pos_y+1 && E.get_couleur(x_vise,y_vise)!=couleur)||(x_vise==pos_x-1 && y_vise==pos_y+2 && E.get_couleur(x_vise,y_vise)!=couleur)||(x_vise==pos_x+1 && y_vise==pos_y+2 && E.get_couleur(x_vise,y_vise)!=couleur)||(x_vise==pos_x+2 && y_vise==pos_y+1 && E.get_couleur(x_vise,y_vise)!=couleur)||(x_vise==pos_x+2 && y_vise==pos_y-1 && E.get_couleur(x_vise,y_vise)!=couleur)||(x_vise==pos_x+1 && y_vise==pos_y-2 && E.get_couleur(x_vise,y_vise)!=couleur)||(x_vise==pos_x-1 && y_vise==pos_y-2 && E.get_couleur(x_vise,y_vise)!=couleur))
   		{cout<<"true"<<endl;
   		return true;}
   	else
   		{cout<<"false"<<endl;
   		return false;}
 	}
 	return false;
}

void Cavalier::deplacement(int x_vise,int y_vise,Echiquier E)
{
    
	E.set_value(10,pos_x,pos_y);
	E.set_value(numero,x_vise,y_vise);
	E.set_id("000",pos_x,pos_y);
	E.set_id(m_id,x_vise,y_vise);
	E.set_couleur(2,pos_x,pos_y);
	E.set_couleur(couleur,x_vise,y_vise);
	pos_x=x_vise;
	pos_y=y_vise;

}
