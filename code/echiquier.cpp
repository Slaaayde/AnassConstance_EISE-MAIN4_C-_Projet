#include "echiquier.hh"
using namespace std;


Echiquier::Echiquier()
{
  m_ligne=8;
  m_colonne=8;
  m_tab=new int*[m_ligne];
  m_couleur=new int*[m_ligne];
  m_id=new string*[m_ligne];
  for(int i=0;i<m_ligne;++i)
  {
    m_tab[i]=new int[m_colonne];                  //Initialisation de l'echiquier : 3 tableaux 8x8
    m_couleur[i]=new int[m_colonne];
    m_id[i]=new string[m_colonne];
  }

  for (int i=0;i<m_ligne;++i)
	{
		for(int j=0;j<m_colonne;++j)
		{
			m_tab[i][j]=10;
      m_couleur[i][j]=2;
      m_id[i][j]="000";
		}
        }  

 
}

/*Echiquier::~Echiquier()
{
  for(int i=0;i<m_ligne;++i)
    {
    
        delete m_tab[i];
        delete m_couleur[i];
        delete m_id[i];

    }
   delete m_tab;
   delete m_couleur;
   delete m_id;
}*/


//----------------Get or Set functions-------------------------------
int Echiquier::get_ligne()
{
 return m_ligne;
}

int Echiquier::get_colonne()
{
 return m_colonne;
}

void Echiquier::set_value(int val,int x,int y)
{


  m_tab[x][y]=val;
}

void Echiquier::set_couleur(int coul,int x,int y)
{

  m_couleur[x][y]=coul;
}

void Echiquier::set_id(string id,int x,int y)
{

  m_id[x][y]=id;
}


int Echiquier::get_couleur(int x,int y)
{
  return m_couleur[x][y];

}

int Echiquier::get_value(int x,int y)
{
  return m_tab[x][y];

}

string Echiquier::get_id(int x,int y)
{
  return m_id[x][y];
}

//--------------------------------------------

bool Echiquier::miam(int x,int y)
{
  if(m_tab[x][y]==10)
    return false;                       //Le déplacement provoque la capture d'une pièce ou pas?
  else
    return true;
}


ostream & operator<<(ostream& os ,  Echiquier const & E)
{
	for (int i=0;i<E.m_ligne;++i)
	{
		for(int j=0;j<E.m_colonne;++j)
		{
			os<<E.m_id[i][j]<<"  ";                        //Surcharge pour afficher l'echiquier
		}
		cout<<endl;
	}
	return os;
}
