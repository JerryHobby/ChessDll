#pragma once
#include "ChessPeice.h"

class Queen: public ChessPeice
{
public:
	Queen( char , char ) ;
	bool canMove( int , int , int , int ) ;
	~Queen( void ) ;
};

