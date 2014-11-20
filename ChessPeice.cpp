#include "StdAfx.h"
#include "include.h"

ChessPeice::ChessPeice( char name , char clr )
{
	color = clr ;
	rank = name ;
}

bool ChessPeice::canMove( int sX , int sY , int eX , int eY )
{
	if( sX == eX && sY == eY )
	{
		return false ;
    }

	if( eX < 0 || eX > 7 || eY < 0 || eY > 7 ) 
	{
		return false ;
	}

	return true;
}

ChessPeice::~ChessPeice( void )
{
}

char ChessPeice::getRank( )
{
	return rank ;
}

char ChessPeice::getColor( )
{
	return color ;
}

int ChessPeice::getDestXPos( ) 
{
	return destX ;
}

int ChessPeice::getDestYPos( ) 
{
	return destY ;
}