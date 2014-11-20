#pragma once
#include "ChessPeice.h"

class Pawn : public ChessPeice
{
private:
	bool isMoved ;
	bool twoStepped ;
public:
	Pawn( char , char ) ;
	bool canMove( int , int , int , int ) ;
	~Pawn( void ) ;
} ;