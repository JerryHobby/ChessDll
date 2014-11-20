#include "StdAfx.h"
#include "include.h"

Bishop::Bishop( char r , char c ) : ChessPeice( r , c )
{
}


Bishop::~Bishop( void )
{
}

bool Bishop::canMove( int sX , int sY , int eX , int eY )
{
	if( !ChessPeice::canMove( sX , sY , eX , eY ) )
		return false ;
	
	if( abs( eX - sX ) == abs( sY - eY ) )
	{
		destX = eX ;
		destY = eY ;
		return true ;
    }

    return false ;
}