#pragma once
#include "ChessPeice.h"

class Knight : public ChessPeice
{
public:
	Knight( char , char ) ;
	bool canMove( int, int , int , int ) ;
	~Knight( void ) ;
} ;

