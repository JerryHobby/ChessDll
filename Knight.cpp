#include "StdAfx.h"
#include "include.h"

Knight::Knight( char r , char c ) : ChessPeice( r , c )
{
}

Knight::~Knight( void )
{
}

bool Knight::canMove(  int sX , int sY , int eX , int eY )
{	
	if( !ChessPeice::canMove( sX , sY , eX , eY ) )
		return false ;

	if( sX + 2 == eX && sY + 1 == eY )
	{
		destX = eX ;
		destY = eY ;
		return true ;
	}
	if( sX + 2 == eX && sY - 1 == eY )
	{
		destX = eX ;
		destY = eY ;
		return true ;
	}
	if( sX - 2 == eX && sY + 1 == eY )
	{
		destX = eX ;
		destY = eY ;
		return true ;
	}
	if( sX - 2 == eX && sY - 1 == eY )
	{
		destX = eX ;
		destY = eY ;
		return true ;
	}
	if( sX + 1 == eX && sY + 2 == eY )
	{
		destX = eX ;
		destY = eY ;
		return true ;
	}
	if( sX + 1 == eX && sY - 2 == eY )
	{
		destX = eX ;
		destY = eY ;
		return true ;
	}
	if( sX - 1 == eX && sY + 2 == eY )
	{
		destX = eX ;
		destY = eY ;
		return true ;
	}
	if( sX - 1 == eX && sY - 2 == eY )
	{
		destX = eX ;
		destY = eY ;
		return true ;
	}
	return false ;
}