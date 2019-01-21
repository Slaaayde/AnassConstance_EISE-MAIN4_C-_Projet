#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "roi.hh"
//#include "pion.hh"
#include "Pionb.hh"
#include "fou.hh"
#include "tour.hh"
#include "cavalier.hh"
#include "dame.hh"

#include <chrono>
#include <thread>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

class Partie{

	private:
		list<Piece> m_blanc; //liste des pieces blanches
		list<Piece> m_noir;  //liste des pieces noires


	public:
		Partie();
		


};