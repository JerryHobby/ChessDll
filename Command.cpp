#include "StdAfx.h"
#include "include.h"

Command::Command( )
{
}

Command::Command( std::string cmd )
{
	if( isupper( cmd.at( 0 ) ) )
	{
		if ( cmd.at( 0 ) == 'O' )
		{
			if( cmd.compare( "O-O") )
			{
				actions.push_back( KINGCASTLING ) ;
			} 
			else
			{
				actions.push_back( QUEENCASTLING ) ;
			}
			subject = EMPTY ;
		}
		else
		{
			subject = cmd.at( 0 ) ;
		}
	}
	else
		subject = PAWN ;

	if ( cmd.find( 'x' , 0 ) != std::string::npos )
		actions.push_back( CAPTURE ) ;
	else
		actions.push_back( MOVE ) ;
	
	if ( cmd.find( '+' , 0 ) != std::string::npos )
		actions.push_back( CHECK ) ;
	
	if ( cmd.find( '#' , 0 ) != std::string::npos )
		actions.push_back(CHECKMATE);
	
	for(int i = cmd.length( ) - 1 ; i > 0 ; i-- )
	{
		if( isdigit( cmd.at( i ) ) )
		{
			points.push_back( cmd.at( i ) - '1' ) ;
			points.push_back( cmd.at( i - 1 ) - 'a' ) ;
		}
	}
}

char Command::getSubject( )
{
	return subject ;
}

std::vector<char> Command::getActions( )
{
	return actions ;
}

std::vector<int> Command::getPoints( )
{
	return points ;
}

Command::~Command( void )
{
}

void Command::validate( )
{
	validated = true ;
}

bool Command::isValid( )
{
	return validated ;
}