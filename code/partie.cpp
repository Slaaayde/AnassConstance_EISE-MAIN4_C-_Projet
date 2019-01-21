#include "partie.hh"



int inlist(string courant,list<Piece> liste)//vérifie que l'id donné par le joeuur est dans la liste
{
	list<Piece>::iterator iter;

 	for (iter=liste.begin();iter!=liste.end();++iter)
	{
		//cout<<iter->get_id()<<endl;
		if (courant == iter->get_id())
				return 1;
				
	}
	return 0;
}

int get_ligne() //Demande la ligne au joeur
{
	int l;
	cout<<"Donnez la ligne de la case ou jouer"<<endl;
 		cin>>l;			

 		return l;

}

int get_colonne() //demande la colonne au joueur
{
	int c;
	cout<<"Donnez la colonne de la case ou jouer"<<endl;
 		cin>>c;

 		return c;
}


string mouvement(Piece & courant,Echiquier& E,list<Piece> &liste,int l,int c,SDL_Rect inutile) //fonction qui permet le mouvement
{
	int flag=0;
	 	Piece flag2;
 	string ret;
    cout<<courant<<endl;
 	
 	while(flag==0) //On verifie que la case est jouavble
 	{
 		
 		
 		if(courant.validation(l,c,E))
 			flag++;
 		else
 			cout<<"case injouable"<<endl;
 	}
 	cout<<E<<endl;



 	if(E.miam(l,c))  //si le mouvemennt entraine une capture, il faut baisser la vie de la piece capturé avant de faire le deplacement
 	{
 		cout<<E.get_value(l,c)<<endl;

 		list<Piece>::iterator iter;

 	for (iter=liste.begin();iter!=liste.end();++iter)
	{
		cout<<iter->get_num()<<"test"<<endl;
		cout<<E.get_value(l,c)<<"true"<<endl;
		if (E.get_value(l,c)== iter->get_num())
				{
					cout<<iter->get_id()<<"bon"<<endl;
					courant.deplacement(l,c,E);
 					cout<<courant<<endl;
 					cout<<" Le coup a été pris en compte "<<endl;
 					cout<<E<<endl;
					 return iter->get_id();
					 
				}
		}

 	}
	
 	

 	//le mouvement n'entraine pas de capture
 	courant.deplacement(l,c,E);
 	cout<<courant<<endl;
 	cout<<" Le coup a été pris en compte "<<endl;
 	cout<<E<<endl;
 	return "";

}

SDL_Rect change(int l,int c) // les positions des cases
{
	SDL_Rect position;
	switch(c)
 	{
 		case 0:
 			position.x=40;
 			break;
 		case 1:
 			position.x=106;
 			break;
 		case 2:
 			position.x=172;
 			break;

 		case 3:
 			position.x=238;
 			break;
 		case 4:
 			position.x=304;
 			break;

 		case 5:
 			position.x=370;
 			break;
 		case 6:
 			position.x=436;
 			break;
 		case 7:
 			position.x=502;
 			break;		
 		default:
 			cout<<"error"<<endl;

 	}

 	switch(l)
 	{
 		case 0:
 			position.y=44;
 			break;
 		case 1:
 			position.y=110;
 			break;
 		case 2:
 			position.y=175;
 			break;

 		case 3:
 			position.y=240;
 			break;
 		case 4:
 			position.y=304;
 			break;

 		case 5:
 			position.y=368;
 			break;
 		case 6:
 			position.y=432;
 			break;
 		case 7:
 			position.y=598;
 			break;		
 		default:
 			cout<<"error"<<endl;

 	}
 	position.w=65;
 	position.h=65;

 	return position;
}


Partie::Partie()
{


 int numb=0; //incremente à chaque tour de jeu

int l; //ligne
int c;  //colonne
int i; //incrementation

using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds
    
string flag;//si une piece est capturé,flag prend son id
int flag2=0; //entier à incrementer
string courant;//l'id de la piece bougée par le joueur
 Echiquier E;

 

    
        // Création de la fenêtre 
        SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);

        SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED); // Création d'un SDL_Renderer utilisant l'accélération matérielle
 
 //----------------Les blancs-------------------------
  
 Pion P0B(1,0,0,"P0B",E);   m_blanc.push_back(P0B);
 Pionb P1B(1,1,0,"P1B",E);   m_blanc.push_back(P1B);
 Pion P2B(1,2,0,"P2B",E);   m_blanc.push_back(P2B);
 Pionb P3B(1,3,0,"P3B",E);   m_blanc.push_back(P3B);
 Pion P4B(1,4,0,"P4B",E);   m_blanc.push_back(P4B);
 Pionb P5B(1,5,0,"P5B",E);   m_blanc.push_back(P5B);
 Pion P6B(1,6,0,"P6B",E);   m_blanc.push_back(P6B);
 Pionb P7B(1,7,0,"P7B",E);   m_blanc.push_back(P7B);

 Tour T0B(0,0,0,"T0B",E);   	 m_blanc.push_back(T0B);
 Cavalier C0B(0,1,0,"C0B",E);    m_blanc.push_back(C0B);
 Fou F0B(0,2,0,"F0B",E);    	 m_blanc.push_back(F0B);
 Roi RB(0,3,0,"R0B",E);     		 m_blanc.push_back(RB);
 Dame DB(0,4,0,"D0B",E);    		 m_blanc.push_back(DB);
 Fou F1B(0,5,0,"F1B",E);    	 m_blanc.push_back(F1B);
 Cavalier C1B(0,6,0,"C1B",E);    m_blanc.push_back(C1B);
 Tour T1B(0,7,0,"T1B",E);   	 m_blanc.push_back(T1B);

 
 
 
 

//------------------Les noirs------------------------------
 Pion P0N(6,0,1,"P0N",E);  m_noir.push_back(P0N);
 Pionb P1N(6,1,1,"P1N",E);  m_noir.push_back(P1N);
 Pion P2N(6,2,1,"P2N",E);  m_noir.push_back(P2N);
 Pionb P3N(6,3,1,"P3N",E);  m_noir.push_back(P3N);
 Pion P4N(6,4,1,"P4N",E);  m_noir.push_back(P4N);
 Pionb P5N(6,5,1,"P5N",E);  m_noir.push_back(P5N);
 Pion P6N(6,6,1,"P6N",E);  m_noir.push_back(P6N);
 Pionb P7N(6,7,1,"P7N",E);  m_noir.push_back(P7N);

 Tour T0N(7,0,1,"T0N",E);   	 m_noir.push_back(T0N);
 Cavalier C0N(7,1,1,"C0N",E);    m_noir.push_back(C0N);
 Fou F0N(7,2,1,"F0N",E);   		 m_noir.push_back(F0N);
 Roi RN(7,3,1,"R0N",E);    		 m_noir.push_back(RN);
 Dame DN(7,4,1,"D0N",E);   		 m_noir.push_back(DN);
 Fou F1N(7,5,1,"F1N",E);  		 m_noir.push_back(F1N);
 Cavalier C1N(7,6,1,"C1N",E);    m_noir.push_back(C1N);
 Tour T1N(7,7,1,"T1N",E);  		 m_noir.push_back(T1N);

cout<<E<<endl;

 if ( pRenderer )
{
	//-------on charge les images
    SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

    SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
    SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png");                 
    SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 

    SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
    SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
    SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 

    


    //-On prepare l'emplacement des images

    SDL_Rect texr; texr.x = 0; texr.y = 0; texr.w = 600; texr.h = 600; 
	
	SDL_Rect tab[32];

	SDL_Rect dPB0 = {40,110, 65, 65};   tab[0]= dPB0;
	SDL_Rect dPB1 = {106,110, 65, 65};	tab[1]= dPB1;
	SDL_Rect dPB2 = {172,110, 65, 65};	tab[2]= dPB2;
	SDL_Rect dPB3 = {238,110, 65, 65};	tab[3]= dPB3;
	SDL_Rect dPB4 = {304,110, 65, 65};	tab[4]= dPB4;
	SDL_Rect dPB5 = {370,110, 65, 65};	tab[5]= dPB5;
	SDL_Rect dPB6 = {436,110, 65, 65};	tab[6]= dPB6;
	SDL_Rect dPB7 = {502,110, 65, 65};	tab[7]= dPB7;

	SDL_Rect dTB0 = {40,44, 65, 65};	tab[8]= dTB0;
	SDL_Rect dCB0 = {106,44, 65, 65};	tab[9]= dCB0;
	SDL_Rect dFB0 = {172,44, 65, 65};	tab[10]= dFB0;
	SDL_Rect dRB = {238,44, 65, 65};	tab[11]= dRB;
	SDL_Rect dDB = {304,44, 65, 65};	tab[12]= dDB;
	SDL_Rect dFB1 = {370,44, 65, 65};	tab[13]= dFB1;
	SDL_Rect dCB1 = {436,44, 65, 65};	tab[14]= dCB1;
	SDL_Rect dTB1 = {502,44, 65, 65};	tab[15]= dTB1;



	SDL_Rect dPN0 = {40,432, 65, 65};	tab[16]= dPN0;
	SDL_Rect dPN1 = {106,432, 65, 65};	tab[17]= dPN1;
	SDL_Rect dPN2 = {172,432, 65, 65};	tab[18]= dPN2;
	SDL_Rect dPN3 = {238,432, 65, 65};	tab[19]= dPN3;
	SDL_Rect dPN4 = {304,432, 65, 65};	tab[20]= dPN4;
	SDL_Rect dPN5 = {370,432, 65, 65};	tab[21]= dPN5;
	SDL_Rect dPN6 = {436,432, 65, 65};	tab[22]= dPN6;
	SDL_Rect dPN7 = {502,432, 65, 65};	tab[23]= dPN7;

	SDL_Rect dTN0 = {40,498, 65, 65};	tab[24]= dTN0;
	SDL_Rect dCN0 = {106,498, 65, 65};	tab[25]= dCN0;
	SDL_Rect dFN0 = {172,498, 65, 65};	tab[26]= dFN0;
	SDL_Rect dRN = {238,498, 65, 65};	tab[27]= dRN;
	SDL_Rect dDN = {304,498, 65, 65};	tab[28]= dDN;
	SDL_Rect dFN1 = {370,498, 65, 65};	tab[29]= dFN1;
	SDL_Rect dCN1 = {436,498, 65, 65};	tab[30]= dCN1;
	SDL_Rect dTN1 = {502,498, 65, 65};	tab[31]= dTN1;
        
        if ( pTexture )
        {

       //On place les images

            SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
			SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
			SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
			SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
			SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
			SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
			SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
			SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
			SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
			SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
			SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);


            SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
			SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
			SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
			SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
			SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
			SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
			SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);

            SDL_RenderPresent(pRenderer); // Affichage
            
            while(1)
 {
 	

 	if(numb%2==0)
 	{
 		cout<<"C'est le tour des Minions"<<endl;
 		cout<<"Donnez l'id de la piece à bouger"<<endl;
 		
 		cin>>courant;
 		

			while(1)
			{
			if(courant=="P0B")
			{
 				if(P0B.get_life()==1)//La piece est-elle dispo?
 					{	
 						

 						//le depladement est-il autorisé?

 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(P0B.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 						//le deplacement est donc autorisé
 						flag =mouvement(P0B,E,m_noir,l,c,tab[0]);

 						//-------On actualise l'affichage----------
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 	SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dPB0=change(l,c);
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 

    					
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);


            			SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);

            			SDL_RenderPresent(pRenderer); // Affichage
                   //----------------------------------------------------------------

 						break;

 						//dispo=0;
 					}

 				else //la piece n'est pas dispo,il faut en prendre une autre
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}
 			}
 			//On refait la même chose pour toutes les pieces

 			if(courant=="P1B")
 				{
 				if(P1B.get_life()==1)
 						{

 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(P1B.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;

 						flag =mouvement(P1B,E,m_noir,l,c,tab[1]);
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 						SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dPB1=change(l,c);
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						

            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);

            			SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}

 			}
 				

 			if(courant=="P2B")
 				{
 				if(P2B.get_life()==1)
 						{
 						
 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(P2B.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 						
 						flag =mouvement(P2B,E,m_noir,l,c,tab[2]);
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 	
 						SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dPB2=change(l,c);
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);

            			SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}

 			}
 				

 			if(courant=="P3B")
 				{
 				if(P3B.get_life()==1)
 						{
 						
 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(P3B.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 						
 						flag =mouvement(P3B,E,m_noir,l,c,tab[3]);
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 						SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dPB3=change(l,c);
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");
						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);


            			SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}
 			}
 				
 			if(courant== "P4B")
 				{
 				if(P4B.get_life()==1)
 						{
 						
 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(P4B.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 						
 						flag =mouvement(P4B,E,m_noir,l,c,tab[4]);
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 						SDL_DestroyWindow(pWindow);
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dPB4=change(l,c);
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);


            			SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}
 			}
 				
 			if(courant== "P5B")
 				{
 				if(P5B.get_life()==1)
 						{
 						
 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(P5B.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 						
 						flag =mouvement(P5B,E,m_noir,l,c,tab[5]);
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 						SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dPB5=change(l,c);
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);


            			SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}
 			}
 				
 			if(courant== "P6B")
 				{
 				if(P6B.get_life()==1)
 						{
 						
 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(P6B.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 						
 						flag =mouvement(P6B,E,m_noir,l,c,tab[6]);
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 						SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dPB6=change(l,c);
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);


            			SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}
 			}
 				
 			if(courant=="P7B")
 				{
 				if(P7B.get_life()==1)
 					{
 						
 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(P7B.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 						
 						flag =mouvement(P7B,E,m_noir,l,c,tab[7]);
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 						SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dPB7=change(l,c);
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);


            			SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}
 			}
 				
 			if(courant=="T0B")
 				{
 				if(T0B.get_life()==1)
 					{
 						
 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(T0B.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 						
 						flag =mouvement(T0B,E,m_noir,l,c,tab[8]);
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 						SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dTB0=change(l,c);
 						
 						cout<<dTB0.x<<endl;
 						cout<<dTB0.y<<endl;

 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);


            			SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}
 			}
 				
 			if(courant=="T1B")
 				{
 				if(T1B.get_life()==1)
 					{
 						
 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(T1B.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 						
 						flag =mouvement(T1B,E,m_noir,l,c,tab[9]);
 						
 						
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 						SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dTB1=change(l,c);
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png");  
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);

            			SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}
 			}
 				
 			if(courant=="C0B")
 				{
 				if(C0B.get_life()==1)
 					{
 						
 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(C0B.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 						
 						flag =mouvement(C0B,E,m_noir,l,c,tab[10]);
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 						SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dCB0=change(l,c);
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);


            			SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}
 			}
 				
 			if(courant=="C1B")
 				{
 				if(C1B.get_life()==1)
 					{
 						
 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(C1B.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 						
 						flag =mouvement(C1B,E,m_noir,l,c,tab[11]);
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 						SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dCB1=change(l,c);
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png");  
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);


            			SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}
 			}
 				
 			if(courant=="F0B")
 				{
 				if(F0B.get_life()==1)
 				{
 						
 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(F0B.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 						
 						flag =mouvement(F0B,E,m_noir,l,c,tab[12]);
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 						SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dFB0=change(l,c);
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);


            			SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}
 			}
 				
 			if(courant=="F1B")
 				{
 				if(F1B.get_life()==1)
 					{
 						
 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(F1B.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 						
 						flag =mouvement(F1B,E,m_noir,l,c,tab[13]);
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 						SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dFB1=change(l,c);
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);


            			SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}
 			}
 				
 			if(courant=="D0B")
 				{
 				if(DB.get_life()==1)
 					{
 						
 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(DB.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 						
 						flag =mouvement(DB,E,m_noir,l,c,tab[14]);
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 						SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dDB=change(l,c);
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);


            			SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}
 			}
 				
 			if(courant=="R0B")
 				{
 				if(RB.get_life()==1)
 					{
 						
 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(RB.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 						
 						flag =mouvement(RB,E,m_noir,l,c,tab[15]);
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 						SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dRB=change(l,c);
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);


            			SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}

 				
 			}
 				if(inlist(courant,m_blanc)==0) //Le cas ou l'id donné n'existe pas
 					{
 						cout<<"Cette piece n'est pas disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}	
 			}

 		}

 	else // Au tour des noirs, même protocole
 	{
 		cout<<"C'est le tour des Simpsons"<<endl;
 		cout<<"Donnez l'id de la piece à bouger"<<endl;
 		cin>>courant;

 		while(1)
 		{

 		if(courant=="P0N")
			{
 				if(P0N.get_life()==1)
 					{
 						
 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(P0N.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 						
 						flag =mouvement(P0N,E,m_blanc,l,c,tab[16]);
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 						SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dPN0=change(l,c);
 						
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}
 			}
 			
 			if(courant=="P1N")
 				{
 				if(P1N.get_life()==1)
 						{
 						
 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(P1N.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 							
 						flag =mouvement(P1N,E,m_blanc,l,c,tab[17]);
 						
 						SDL_DestroyTexture(pTexture);

 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 						SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dPN1=change(l,c);
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}

 			
 			}	

 			if(courant=="P2N")
 				{
 				if(P2N.get_life()==1)
 						{
 						
 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(P2N.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 						
 						flag =mouvement(P2N,E,m_blanc,l,c,tab[18]);
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 						SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dPN2=change(l,c);
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}

 			}
 				

 			if(courant=="P3N")
 				{
 				if(P3N.get_life()==1)
 						{
 						
 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(P3N.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 						
 						flag =mouvement(P3N,E,m_blanc,l,c,tab[19]);
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 						SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dPN3=change(l,c);
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}
 			}
 				
 			if(courant== "P4N")
 				{
 				if(P4N.get_life()==1)
 						{
 						
 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(P4N.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 						
 						flag =mouvement(P4N,E,m_blanc,l,c,tab[20]);
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 						SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dPN4=change(l,c);
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}
 			}
 				
 			if(courant== "P5N")
 				{
 				if(P5N.get_life()==1)
 						{
 						
 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(P5N.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 						
 						flag =mouvement(P5N,E,m_blanc,l,c,tab[21]);
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 						SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dPN5=change(l,c);
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}
 			}
 				
 			if(courant== "P6N")
 				{
 				if(P6N.get_life()==1)
 						{
 						
 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(P6N.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 							
 						flag =mouvement(P6N,E,m_blanc,l,c,tab[22]);
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 						SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dPN6=change(l,c);
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}
 			}
 				
 			if(courant=="P7N")
 				{
 				if(P7N.get_life()==1)
 					{
 						
 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(P7N.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 						
 						flag =mouvement(P7N,E,m_blanc,l,c,tab[23]);
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 						SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dPN7=change(l,c);
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}
 			}
 				
 			if(courant=="T0N")
 				{
 				if(T0N.get_life()==1)
 					{
 						
 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(T0N.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 						
 						flag =mouvement(T0N,E,m_blanc,l,c,tab[24]);
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 						SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dTN0=change(l,c);
 						
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}
 			}
 				
 			if(courant=="T1N")
 				{
 				if(T1N.get_life()==1)
 					{
 						
 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(T1N.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 						
 						flag =mouvement(T1N,E,m_blanc,l,c,tab[25]);
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 						SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dTN1=change(l,c);
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}
 			}
 				
 			if(courant=="C0N")
 				{
 				if(C0N.get_life()==1)
 					{
 						
 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(C0N.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 						
 						flag =mouvement(C0N,E,m_blanc,l,c,tab[26]);
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 						SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dCN0=change(l,c);
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}
 			}
 				
 			if(courant=="C1N")
 				{
 				if(C1N.get_life()==1)
 					{
 						
 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(C1N.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 						
 						flag =mouvement(C1N,E,m_blanc,l,c,tab[27]);
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 	 					SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dCN1=change(l,c);
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}
 			}
 				
 			if(courant=="F0N")
 				{
 				if(F0N.get_life()==1)
 				{
 						
 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(F0N.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 						
 						flag =mouvement(F0N,E,m_blanc,l,c,tab[28]);
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 						SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dFN0=change(l,c);
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}
 			}
 				
 			if(courant=="F1N")
 				{
 				if(F1N.get_life()==1)
 					{
 						
 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(F1N.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 						
 						flag =mouvement(F1N,E,m_blanc,l,c,tab[29]);
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 						SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dFN1=change(l,c);
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}
 			}
 				
 			if(courant=="D0N")
 				{
 				if(DN.get_life()==1)
 					{
 						
 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(DN.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 						
 						flag =mouvement(DN,E,m_blanc,l,c,tab[30]);
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 						SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dDN=change(l,c);
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}
 			}
 				
 			if(courant=="R0N")
 				{
 				if(RN.get_life()==1)
 					{
 						
 						while(flag2==0)
 						{
 						l=get_ligne();
 						c=get_colonne();
 		
 						if(RN.validation(l,c,E))
 						flag2++;
 						else
 						cout<<"case injouable"<<endl;
 						}
 						flag2=0;
 						
 						flag =mouvement(RN,E,m_blanc,l,c,tab[31]);
 						SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);
 	SDL_DestroyRenderer(pRenderer);
 						SDL_DestroyWindow(pWindow);
 						//sleep_for(seconds(1));
 						//SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  600,
                                                                  600,
                                                                  SDL_WINDOW_SHOWN);
 						SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
 						dRN=change(l,c);
 						


 						//image_renderer(pRenderer); // Copie du sprite grâce au SDL_Renderer
						SDL_Texture* pTexture = IMG_LoadTexture(pRenderer,"plateau.png");

   						SDL_Texture* pPN = IMG_LoadTexture(pRenderer,"PN.png");
   						SDL_Texture* pPNb = IMG_LoadTexture(pRenderer,"PNb.png");  
   						SDL_Texture* pTN = IMG_LoadTexture(pRenderer,"TN.png"); 
    					SDL_Texture* pCN = IMG_LoadTexture(pRenderer,"CN.png"); 
    					SDL_Texture* pFN = IMG_LoadTexture(pRenderer,"FN.png"); 
    					SDL_Texture* pDN = IMG_LoadTexture(pRenderer,"DN.png"); 
    					SDL_Texture* pRN = IMG_LoadTexture(pRenderer,"RN.png"); 


   						SDL_Texture* pPB = IMG_LoadTexture(pRenderer,"PB.png");
   						SDL_Texture* pPBb = IMG_LoadTexture(pRenderer,"PBb.png");
    					SDL_Texture* pTB = IMG_LoadTexture(pRenderer,"TB.png"); 
    					SDL_Texture* pCB = IMG_LoadTexture(pRenderer,"CB.png"); 
    					SDL_Texture* pFB = IMG_LoadTexture(pRenderer,"FB.png"); 
    					SDL_Texture* pDB = IMG_LoadTexture(pRenderer,"DB.png"); 
    					SDL_Texture* pRB = IMG_LoadTexture(pRenderer,"RB.png"); 
    
						//copie_renderer(&pRenderer);
						SDL_RenderCopy(pRenderer,pTexture,NULL,&texr); // Copie du sprite grâce au SDL_Renderer
			
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB0);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB1);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB2);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB3);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB4);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB5);
						SDL_RenderCopy(pRenderer,pPB,NULL,&dPB6);
						SDL_RenderCopy(pRenderer,pPBb,NULL,&dPB7);


						SDL_RenderCopy(pRenderer,pTB,NULL,&dTB0);
						SDL_RenderCopy(pRenderer,pCB,NULL,&dCB0);
						SDL_RenderCopy(pRenderer,pFB,NULL,&dFB0);
						SDL_RenderCopy(pRenderer,pRB,NULL,&dRB);
						SDL_RenderCopy(pRenderer,pDB,NULL,&dDB);
            			SDL_RenderCopy(pRenderer,pFB,NULL,&dFB1);
            			SDL_RenderCopy(pRenderer,pCB,NULL,&dCB1);
            			SDL_RenderCopy(pRenderer,pTB,NULL,&dTB1);


            			SDL_RenderCopy(pRenderer,pPN,NULL,&dPN0);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN1);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN2);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN3);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN4);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN5);
						SDL_RenderCopy(pRenderer,pPN,NULL,&dPN6);
						SDL_RenderCopy(pRenderer,pPNb,NULL,&dPN7);


						SDL_RenderCopy(pRenderer,pTN,NULL,&dTN0);
						SDL_RenderCopy(pRenderer,pCN,NULL,&dCN0);
						SDL_RenderCopy(pRenderer,pFN,NULL,&dFN0);
						SDL_RenderCopy(pRenderer,pRN,NULL,&dRN);
						SDL_RenderCopy(pRenderer,pDN,NULL,&dDN);
            			SDL_RenderCopy(pRenderer,pFN,NULL,&dFN1);
            			SDL_RenderCopy(pRenderer,pCN,NULL,&dCN1);
            			SDL_RenderCopy(pRenderer,pTN,NULL,&dTN1);

            			SDL_RenderPresent(pRenderer); // Affichage


 						break;
 						//dispo=0;
 					}

 				else
 					{
 					cout<<"Cette piece n'est plus disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}
 			}
		if(inlist(courant,m_noir)==0)
 					{
 						cout<<"Cette piece n'est pas disponible"<<endl;
 					cout<<"Donnez l'id de la piece à bouger"<<endl;
 					cin>>courant;
 					}	 		
 		}
 				
 	}

//------------Si une piece a été capturée, on lui retire son point de vie
	if(flag=="P0B")
		{
		P0B.set_life();
		dPB0.w=0;
		dPB0.h=0;
	}
	if(flag=="P1B")
		{
		P1B.set_life();
		dPB1.w=0;
		dPB1.h=0;
	}
	if(flag=="P2B")
		{
		P2B.set_life();
		dPB2.w=0;
		dPB2.h=0;
	}
	if(flag=="P3B")
		{
		P3B.set_life();
		dPB3.w=0;
		dPB3.h=0;
	}
	if(flag=="P4B")
		{
		P4B.set_life();
		dPB4.w=0;
		dPB4.h=0;
	}
	if(flag=="P5B")
		{
		P5B.set_life();
		dPB5.w=0;
		dPB5.h=0;
	}
	if(flag=="P6B")
		{
		P6B.set_life();
		dPB6.w=0;
		dPB6.h=0;
	}
	if(flag=="P7B")
		{
		P7B.set_life();
		dPB7.w=0;
		dPB7.h=0;
	}
	if(flag=="T0B")
		{
		T0B.set_life();
		dTB0.w=0;
		dTB0.h=0;
	}
	if(flag=="T1B")
		{
		T1B.set_life();
		dTB1.w=0;
		dTB1.h=0;
	}
	if(flag=="C0B")
		{
		C0B.set_life();
		dCB0.w=0;
		dCB0.h=0;
	}
	if(flag=="C1B")
		{
		C1B.set_life();
		dCB1.w=0;
		dCB1.h=0;
	}
	if(flag=="F0B")
		{
		F0B.set_life();
		dFB0.w=0;
		dFB0.h=0;
	}
	if(flag=="F1B")
		{
		F1B.set_life();
		dFB1.w=0;
		dFB1.h=0;
	}
	if(flag=="D0B")
		{
		DB.set_life();
		dDB.w=0;
		dDB.h=0;
	}
	if(flag=="R0B")
		{
		RB.set_life();
		dRB.w=0;
		dRB.h=0;
	}
	
	
	if(flag=="P0N")
		{
		P0N.set_life();
		dPN0.w=0;
		dPN0.h=0;
	}
	if(flag=="P1N")
		{
		P1N.set_life();
		dPN1.w=0;
		dPN1.h=0;
	}
	if(flag=="P2N")
		{
		P2N.set_life();
		dPN2.w=0;
		dPN2.h=0;
	}
	if(flag=="P3N")
		{
		P3N.set_life();
		dPN3.w=0;
		dPN3.h=0;
	}
	if(flag=="P4N")
		{
		P4N.set_life();
		dPN4.w=0;
		dPN4.h=0;
	}
	if(flag=="P5N")
		{
		P5N.set_life();
		dPN5.w=0;
		dPN5.h=0;
	}
	if(flag=="P6N")
		{
		P6N.set_life();
		dPN6.w=0;
		dPN6.h=0;
	}
	if(flag=="P7N")
		{
		P7N.set_life();
		dPN7.w=0;
		dPN7.h=0;
	}
	if(flag=="T0N")
		{
		T0N.set_life();
		dTN0.w=0;
		dTN0.h=0;
	}
	if(flag=="T1N")
		{
		T1N.set_life();
		dTN1.w=0;
		dTN1.h=0;
	}
	if(flag=="C0N")
		{
		C0N.set_life();
		dCN0.w=0;
		dCN0.h=0;
	}
	if(flag=="C1N")
		{
		C1N.set_life();
		dCN1.w=0;
		dCN1.h=0;
	}
	if(flag=="F0N")
		{
		F0N.set_life();
		dFN0.w=0;
		dFN0.h=0;
	}
	if(flag=="F1N")
		{
		F1N.set_life();
		dFN1.w=0;
		dFN1.h=0;
	}
	if(flag=="D0N")
	{
		DN.set_life();
		dDN.w=0;
		dDN.h=0;
	}
	if(flag=="R0N")
	{
		RN.set_life();
		dRN.w=0;
		dRN.h=0;
	}
//-----------------------

//----------Fin de Partie-----------------	
 if(RN.get_life()==0)
 {
 	cout<<"Victoire des blancs ! Bravo !"<<endl;
 	break;
 }

if(RB.get_life()==0)
 {
 	cout<<"Victoire des noirs ! Bravo !"<<endl;
 	break;
 }
 //------------------------------------	
    
 	numb++;// on passe au tour suivant


 }

           
            
            SDL_DestroyTexture(pTexture);
 						SDL_DestroyTexture(pPB);
 						SDL_DestroyTexture(pPBb);
    SDL_DestroyTexture(pTB);
    SDL_DestroyTexture(pCB);
    SDL_DestroyTexture(pFB);
    SDL_DestroyTexture(pDB);
    SDL_DestroyTexture(pRB);

    SDL_DestroyTexture(pPN);
    SDL_DestroyTexture(pPNb);
    SDL_DestroyTexture(pTN);
    SDL_DestroyTexture(pCN);
    SDL_DestroyTexture(pFN);
    SDL_DestroyTexture(pDN);
    SDL_DestroyTexture(pRN);// Libération de la mémoire associée à la texture
        }
        else
        {
            fprintf(stdout,"Échec de création de la texture (%s)\n",SDL_GetError());
        }

 


  SDL_DestroyRenderer(pRenderer); // Libération de la mémoire du SDL_Renderer
}
else
{
    fprintf(stdout,"Échec de création du renderer (%s)\n",SDL_GetError());
}


       
    

    SDL_DestroyWindow(pWindow);
    SDL_Quit();

 
 






}