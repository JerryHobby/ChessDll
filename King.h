#pragma once
#include "ChessPeice.h"

class King : public ChessPeice
{
private:
	bool castleAble ;
public:
	King( char , char ) ;
	bool canMove( int , int , int , int ) ;
	bool canCastle( ) ;
	~King( void ) ;
} ;

