#pragma once
#include "include.h"

class ChessPeice
{
protected:
	int destX ;
	int destY ;
	char color ;
	char rank ;
public:
	ChessPeice( char , char ) ;
	char getColor( ) ;
	char getRank( ) ;
	void setYPos( int ) ;
	void setXPos( int ) ;
	int getDestXPos( ) ;
	int getDestYPos( ) ;
	bool canMove( int , int , int , int ) ;
	void move( std::vector<int> ) ;
	~ChessPeice( void ) ;
} ;