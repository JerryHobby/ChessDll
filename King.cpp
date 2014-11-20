#include "StdAfx.h"
#include "include.h"

King::King( char r , char c ) : ChessPeice( r , c )
{
	castleAble = true ;
}

King::~King( void )
{
}

bool King::canMove( int sX , int sY , int eX , int eY )
{
	if( !ChessPeice::canMove( sX , sY , eX , eY ) )
		return false ;

	if( abs( sX - eX ) == 1 && abs( sY - eY ) == 1 )
	{
		destX = eX ;
		destY = eY ;
		return true ;
	}

	return false ;
}

bool King::canCastle( )
{
	return castleAble ;
}