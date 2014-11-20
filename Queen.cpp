#include "StdAfx.h"
#include "include.h"

Queen::Queen( char r , char c ) : ChessPeice( r , c )
{
}


Queen::~Queen( void )
{
}

bool Queen::canMove( int sX , int sY , int eX , int eY )
{
	if( !ChessPeice::canMove( sX , sY , eX , eY ) )
		return false ;
	
	if( ( abs( eX - sX ) == abs( sY - eY ) ) 
		|| ( sX == eX && sY != eY ) 
		|| ( sX != eX && sY == eY ) )
	{
		destX = eX ;
		destY = eY ;
		return true ;
    }

	return false ;
}