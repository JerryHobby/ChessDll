#include "StdAfx.h"
#include "include.h"

Pawn::Pawn( char r , char c ) : ChessPeice( r , c )
{
	isMoved = false ;
	twoStepped = false ;
}

bool Pawn::canMove( int sX , int sY , int eX , int eY )
{
	if( !ChessPeice::canMove( sX , sY , eX , eY ) )
	{
		return false ;
	}

	if( !isMoved && color == WHITE )
	{
		if( sX + 2 == eX && sY == eY )
		{
			destX = eX ;
			destY = eY ;
			return true ;
		}
	}

	if( !isMoved && color == BLACK )
	{
		if( sX - 2 == eX && sY == eY )
		{
			destX = eX ;
			destY = eY ;
			return true ;
		}
	}

	if( color == WHITE )
	{
		if( sX + 1 == eX && sY == eY )
		{
			destX = eX ;
			destY = eY ;
			return true ;
		}
	}

	if( color == BLACK )
	{
		if( sX - 1 == eX && sY == eY )
		{
			destX = eX ;
			destY = eY ;
			return true ;
		}
	}

	return false ;
}

bool Pawn::canCapture( int sX , int sY , int eX , int eY )
{
	if( color == WHITE )
	{
		if( ( sX + 1 == eX && sY + 1 == eY )
			|| ( sX + 1 == eX && sY - 1 == eY ) )
		{
			destX = eX ;
			destY = eY ;
			return true ;
		}
	}

	if( color == BLACK )
	{
		if( sX - 1 == eX && sY + 1 == eY 
			|| ( sX - 1 == eX && sY - 1 == eY ) )
		{
			destX = eX ;
			destY = eY ;
			return true ;
		}
	}

	return false ;
}

Pawn::~Pawn( void )
{
}