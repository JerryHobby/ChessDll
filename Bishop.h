#pragma once
#include "ChessPeice.h"

class Bishop:public ChessPeice
{
public:
	Bishop( char , char ) ;
	bool canMove( int , int , int , int ) ;
	~Bishop( void ) ;
} ;

