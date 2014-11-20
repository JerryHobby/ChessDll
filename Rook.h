#pragma once
#include "ChessPeice.h"

class Rook: public ChessPeice
{
private:
	bool isMoved ;
public:
	Rook( char , char ) ;
	bool canMove( int , int , int , int ) ;
	bool canCastle( ) ;
	~Rook( void ) ;
};

