#include "piece.hh"

static int flag=11;
Piece::Piece()
{
	
}

Piece::Piece(int x,int y,int coul,string id,Echiquier E)
{
	pos_x=x;
	pos_y=y;
	m_id=id;
	if (coul==0)
		val="TESTb";
	else
		val="TESTn";
	couleur=coul;
	E.set_value(numero,x,y);
	E.set_couleur(couleur,x,y);
	E.set_id(id,x,y);
	life=1;
	numero=flag;
	flag++;

}


Piece& Piece::operator=(const Piece& P)
{
    this->pos_x=P.pos_x;
    this->pos_y=P.pos_y;
    this->couleur=P.couleur;
    this->val=P.val;
    this->m_id=P.m_id;
    this->numero=P.numero;
    return *this;

}


//-------------get or set
string Piece::get_id()
{
	return m_id;
}


int Piece::get_x()
{
	return pos_x;
}

int Piece::get_y()
{
	return pos_y;
}

int Piece::get_life()
{
	return life;
}

void Piece::set_life()
{
	life=0;
}

int Piece::get_num()
{
	return numero;
}


void Piece::set_id(string id)
{
	m_id=id;
}

//---------------

ostream & operator<<(ostream& os ,  Piece const & P)
{
	
			os<<" La pièce "<< P.m_id<< " se trouve en ("<<P.pos_x<<","<<P.pos_y<<")"<<endl;;
		
	return os;
}