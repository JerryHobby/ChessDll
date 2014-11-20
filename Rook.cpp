#include "StdAfx.h"
#include "include.h"

Rook::Rook( char r , char c ) : ChessPeice( r , c )
{
	isMoved = false ;
}


Rook::~Rook( void )
{
}

bool Rook::canMove( int sX , int sY , int eX , int eY )
{
	if( !ChessPeice::canMove( sX, sY , eX , eY ) )
		return false ;
    
	if( ( sX == eX && sY != eY ) || ( sX != eX && sY == eY ) )
	{
		destX = eX ;
		destY = eY ;
		return true ;
	}

	return false ;
}

bool Rook::canCastle( )
{
	return !isMoved ;
}