#include "fou.hh"


Fou::Fou(int x,int y,int coul,string id,Echiquier E):Piece::Piece(x,y,coul,id,E)
{
	pos_x=x;
	pos_y=y;
	m_id=id;
	if (coul==0)
		val="Fb";
	else
		val="Fn";
	couleur=coul;
	E.set_value(numero,x,y);
	E.set_couleur(couleur,x,y);
	E.set_id(id,x,y);
	life=1;

}

bool Fou::validation(int x_vise,int y_vise,Echiquier E)
{
	
	vector<int> v;
	int a=0;
	int flag;
	
	
	int i=0;
	//----------On cherche les mouvements possibles qu'on stocke dans le vecteur
	while(pos_x+i<7 && pos_y+i<7)
	{
		i++;
	if (E.get_couleur(pos_x+i,pos_y+i)!=couleur && E.get_couleur(pos_x+i,pos_y+i)!=2)
		{flag=10*(pos_x+i)+pos_y+i;
		v.push_back(flag);
		break;}
	
	if (E.get_couleur(pos_x+i,pos_y+i)==2)
		{flag=10*(pos_x+i)+pos_y+i;
		v.push_back(flag);
		}

	if (E.get_couleur(pos_x+i,pos_y+i)==couleur)
		{break;}
	}
	

	i=0;
	while(pos_x+i<7 && pos_y-i>0)
	{
		i++;
	if (E.get_couleur(pos_x+i,pos_y-i)!=couleur && E.get_couleur(pos_x+i,pos_y-i)!=2)
		{flag=10*(pos_x+i)+pos_y-i;
		v.push_back(flag);
		break;}
	
	if (E.get_couleur(pos_x+i,pos_y-i)==2)
		{flag=10*(pos_x+i)+pos_y-i;
		v.push_back(flag);
		}

	if (E.get_couleur(pos_x+i,pos_y-i)==couleur)
		{break;}
	}



	i=0;
	while(pos_x-i>0 && pos_y+i<7)
	{
		//cout<<"test"<<endl;
		i++;
	if (E.get_couleur(pos_x-i,pos_y+i)!=couleur && E.get_couleur(pos_x-i,pos_y+i)!=2)
		{flag=10*(pos_x-i)+pos_y+i;
		v.push_back(flag);
		//cout<<"1"<<endl;
		break;}
	
	if (E.get_couleur(pos_x-i,pos_y+i)==2)
		{flag=10*(pos_x-i)+pos_y+i;
		v.push_back(flag);
		//cout<<"2"<<endl;
		}

	if (E.get_couleur(pos_x-i,pos_y+i)==couleur)
		{
			//cout<<"3"<<endl;
			break;}
	}

	i=0;
	while(pos_x-i>0 && pos_y-i>0)
	{
		i++;
	if (E.get_couleur(pos_x-i,pos_y-i)!=couleur && E.get_couleur(pos_x-i,pos_y-i)!=2)
		{flag=10*(pos_x-i)+pos_y-i;
		v.push_back(flag);
		break;}
	
	if (E.get_couleur(pos_x-i,pos_y-i)==2)
		{flag=10*(pos_x-i)+pos_y-i;
		v.push_back(flag);
		}

	if (E.get_couleur(pos_x-i,pos_y-i)==couleur)
		{break;}
	}
	//--------------------------------
    
	
	vector<int>::iterator iter;

	for (iter=v.begin();iter!=v.end();++iter)
	{
		cout<<*iter<<endl;
		if (10*x_vise+y_vise == *iter)
			{	cout<<"true"<<endl;						//Le deplacement voulu est-il dans le vecteur des mouvements possibles
				v.clear();
			return true;}
	}
	cout<<"false"<<endl;
	v.clear();
	return false;



}

void Fou::deplacement(int x_vise,int y_vise,Echiquier E)
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