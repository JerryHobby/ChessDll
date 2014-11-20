// ChessDll.cpp : Defines the exported functions for the DLL application.
#include "stdafx.h"
#include "include.h"
#include "Chessdll.h"

///////////////////////////////////////////////////
#include <iostream>
///////////////////////////////////////////////////

ChessBoard::ChessBoard( )
{
	//board = new std::vector<ChessPeice*> ( 64 ) ;
	winner = EMPTY ;
	currentPlayer = WHITE ;
	board.push_back( new ChessPeice( ROOK , WHITE ) ) ;
	board.push_back( (ChessPeice *) new Knight( KNIGHT , WHITE ) ) ;
	board.push_back( (ChessPeice *) new Bishop( BISHOP , WHITE ) ) ;
	board.push_back( (ChessPeice *) new Queen( QUEEN , WHITE ) ) ;
	board.push_back( (ChessPeice *) new King( KING , WHITE ) ) ;
	board.push_back( (ChessPeice *) new Bishop( BISHOP , WHITE ) ) ;
	board.push_back( (ChessPeice *) new Knight( KNIGHT , WHITE ) ) ;
	board.push_back( (ChessPeice *) new Rook( ROOK , WHITE ) ) ;
	board.push_back( (ChessPeice *) new Pawn( PAWN , WHITE ) ) ;
	board.push_back( (ChessPeice *) new Pawn( PAWN , WHITE ) ) ;
	board.push_back( (ChessPeice *) new Pawn( PAWN , WHITE ) ) ;
	board.push_back( (ChessPeice *) new Pawn( PAWN , WHITE ) ) ;
	board.push_back( (ChessPeice *) new Pawn( PAWN , WHITE ) ) ;
	board.push_back( (ChessPeice *) new Pawn( PAWN , WHITE ) ) ;
	board.push_back( (ChessPeice *) new Pawn( PAWN , WHITE ) ) ;
	board.push_back( (ChessPeice *) new Pawn( PAWN , WHITE ) ) ;

	for( int j = 2 ; j < 6 ; j++ ) {
		for( int i = 0 ; i < 8 ; i ++ )
		{
			board.push_back( new ChessPeice( EMPTY , EMPTY ) ) ;
		}
	}

	board.push_back( (ChessPeice *) new Pawn( PAWN , BLACK ) ) ;
	board.push_back( (ChessPeice *) new Pawn( PAWN , BLACK ) ) ;
	board.push_back( (ChessPeice *) new Pawn( PAWN , BLACK ) ) ;
	board.push_back( (ChessPeice *) new Pawn( PAWN , BLACK ) ) ;
	board.push_back( (ChessPeice *) new Pawn( PAWN , BLACK ) ) ;
	board.push_back( (ChessPeice *) new Pawn( PAWN , BLACK ) ) ;
	board.push_back( (ChessPeice *) new Pawn( PAWN , BLACK ) ) ;
	board.push_back( (ChessPeice *) new Pawn( PAWN , BLACK ) ) ;
	board.push_back( (ChessPeice *) new Rook( ROOK , BLACK ) ) ;
	board.push_back( (ChessPeice *) new Knight( KNIGHT , BLACK ) ) ;
	board.push_back( (ChessPeice *) new Bishop( BISHOP , BLACK ) ) ;
	board.push_back( (ChessPeice *) new Queen( QUEEN , BLACK ) ) ;
	board.push_back( (ChessPeice *) new King( KING , BLACK ) ) ;
	board.push_back( (ChessPeice *) new Bishop( BISHOP , BLACK ) ) ;
	board.push_back( (ChessPeice *) new Knight( KNIGHT , BLACK ) ) ;
	board.push_back( (ChessPeice *) new Rook( ROOK , BLACK ) ) ;
}

/**
  * returns a vector of char containing the board state.
  * 64 characters.
  * uppercase for white.
  * lowercase for black.
  * 'E' for empty.
  */
std::vector<char> ChessBoard::getBoard( )
{
	std::vector<char> temp ;
	for(size_t i = 0 ; i < board.size( ) ; i++ )
	{
		if( board.at( i )->getColor( ) == WHITE ||
			board.at( i )->getColor( ) == EMPTY )
			temp.push_back( board.at( i )->getRank( ) ) ;
		else
			temp.push_back( tolower( board.at( i )->getRank( ) ) );
	}
	return temp;
}

/**
  * checks for the validity of a given command string.
  */
bool ChessBoard::isValid( std::string cmd )
{
	if ( winner != EMPTY )
	{
		return false ;
	}
	if( cmd.find ( '0' , 0 ) != std::string::npos )
	{
		return false ;
	}
	command = new Command ( cmd ) ;
	
	////////////////////////////////////////////////////////
	std::cout << "\n Command " << cmd << "\tResolved into\t: " << command->getSubject ( ) ;
	std::vector <int> t = command->getPoints ( ) ;
	for ( size_t i = 0 ; i < t.size ( ) ; i++ )
		std::cout << t.at ( i ) ;
	std::vector <char> t1 = command->getActions ( ) ;
	for( size_t i = 0 ; i < t1.size( ) ; i++ )
		std::cout << t1.at( i ) ;
	////////////////////////////////////////////////////////

	std::vector<ChessPeice *> temp = ( board ) ;
	return execute( temp ) ;
}

bool ChessBoard::execute( std::vector<ChessPeice*> &temp )
{
	std::vector<char> act = command->getActions( ) ;
	int cell = -1 ;
	int dest ;
	for( size_t i = 0 ; i < act.size( ) ; i++ )
	{
		switch( act.at( i ) )
		{
		case MOVE:
			if( command->getPoints( ).size( ) > 2 )
			{
				cell = tryToMove( temp , command->getSubject( ) , command->getPoints( ).at( 0 ) * 8 + command->getPoints( ).at( 1 )
					, command->getPoints( ).at( 2 ) * 8 + command->getPoints( ).at( 3 ) ) ;
			}
			else
			{
				cell = tryToMove( temp , command->getSubject( ) , command->getPoints( ).at( 0 ) * 8 + command->getPoints( ).at( 1 ) ) ;
			}
			if( cell != -1 ) 
			{
				dest = temp.at( cell )->getDestXPos( ) * 8 + temp.at( cell )->getDestYPos( ) ;
				if( !obstacles( cell / 8 , cell % 8 , dest / 8 , dest % 8 ) )
				{
					std::swap( temp.at( cell ) , temp.at( dest ) ) ;
					break;
				}
			}
			return false ;
		case KINGCASTLING:
			if ( !canCastle( KINGCASTLING ) )
			{
				return false ;
			}
			kingCastle( temp ) ;
			break ;
		case QUEENCASTLING:
			if ( !canCastle( QUEENCASTLING ) )
			{
				return false ;
			}
			queenCastle( temp ) ;
			break ;
		case CHECK:
			if( !isChecked( temp ) )
				return false;
			break ;
		case CAPTURE:
			if( validCapture( temp ) )
			{
				return false ;
			}
			break ;
		case CHECKMATE:
			if( !checkMate( temp ) )
			{
				return false ;
			}
		}
	}
	return true ;
}

bool ChessBoard::checkMate( std::vector<ChessPeice*> myBoard )
{
	for( size_t i = 0 ; i < myBoard.size( ) ; i++ )
	{
		if( myBoard.at( i )->getRank( ) == KING && myBoard.at( i )->getColor( ) != currentPlayer 
			&& isChecked( myBoard ) )
		{
			// try to move king
			int xPos = i / 8 ;
			int yPos = i % 8 ;
			for( int j = xPos - 1 ; j < xPos + 2 ; j++ )
			{
				for( int k = yPos - 1 ; k < yPos + 2 ; k++ )
				{
					if( myBoard.at( j * 8 + k )->getRank( ) == EMPTY )
					{
						std::swap( myBoard.at( i ) , myBoard.at( j * 8 + k ) ) ;
						if( !isChecked( myBoard ) )
						{
							std::swap( myBoard.at( i ) , myBoard.at( j * 8 + k ) ) ;
							return false ;
						}
					}
				}
			}

			// try to block checker

			// try to remove checker

		}
	}
	return true ;
}

bool ChessBoard::validCapture( std::vector<ChessPeice*> myBoard )
{
	for( size_t i = 0 ; i < myBoard.size( ) ; i++ )
	{
		if( myBoard.at( i )->getRank( ) == command->getSubject( )
			&& myBoard.at( i )->getColor( ) == currentPlayer
			&& tryToMove( myBoard , command->getSubject( ) , command->getPoints( ).at( 0 ) * 8 + command->getPoints( ).at( 1 ) )
			&& myBoard.at( command->getPoints( ).at( 0 ) * 8 + command->getPoints( ).at( 1 ) )->getColor( ) != currentPlayer )  
		{
			ChessPeice * temp = ( myBoard.at( command->getPoints( ).at( 0 ) * 8 + command->getPoints( ).at( 1 ) ) ) ;
			myBoard.at( command->getPoints( ).at( 0 ) * 8 + command->getPoints( ).at( 1 ) ) = new ChessPeice( EMPTY , EMPTY ) ;
			if( !obstacles( i / 8 , i % 8 , command->getPoints( ).at( 0 ) , command->getPoints( ).at( 0 ) ) )
			{
				myBoard.at( command->getPoints( ).at( 0 ) * 8 + command->getPoints( ).at( 1 ) ) = ( temp ) ;
				return true ;
			}
			myBoard.at( command->getPoints( ).at( 0 ) * 8 + command->getPoints( ).at( 1 ) ) = ( temp ) ;
		}
	}
	return false ;
}

bool ChessBoard::isChecked( std::vector<ChessPeice*> myBoard )
{
	for( size_t i = 0 ; i < myBoard.size( ) ; i++ )
	{
		if( myBoard.at( i )->getRank( ) == KING && myBoard.at( i )->getColor( ) != currentPlayer )
		{
			for( size_t j = 0 ; j < myBoard.size( ) ; j++ )
			{
				if( myBoard.at( j )->getColor( ) == currentPlayer 
					&& tryToMove( myBoard , currentPlayer , i , j ) 
					&& !obstacles( j / 8 , j % 8 , i / 8 , i % 8 ) )
				{
					return true ;
				}
			}
			break ;
		}
	}
	return false ;
}

void ChessBoard::kingCastle( std::vector<ChessPeice*> temp )
{
	if( currentPlayer == WHITE )
	{
		std::swap( temp.at( 7 ) , temp.at( 5 ) ) ;
		std::swap( temp.at( 4 ) , temp.at( 6 ) ) ;
	}
	else
	{
		std::swap( temp.at( 63 ) , temp.at( 61 ) ) ;
		std::swap( temp.at( 62 ) , temp.at( 60 ) ) ;
	}
}

void ChessBoard::queenCastle( std::vector<ChessPeice*> temp )
{
	if( currentPlayer == WHITE )
	{
		std::swap( temp.at( 7 ) , temp.at( 5 ) ) ;
		std::swap( temp.at( 4 ) , temp.at( 6 ) ) ;
	}
	else
	{
		std::swap( temp.at( 63 ) , temp.at( 61 ) ) ;
		std::swap( temp.at( 62 ) , temp.at( 60 ) ) ;
	}
}

/**
  * return whether there are pieces between two given locations.
  * checks free ways on all 8 directions.
  * exception to Knights
  */
bool ChessBoard::obstacles( int startX , int startY , int endX , int endY )
{
	if( board.at( startX * 8 + startY )->getRank( ) != KNIGHT )
	{
		int dirX = startX > endX ? -1 : 1 ;
		int dirY = startY > endY ? -1 : 1 ;
		dirX = startX == endX ? 0 : dirX ;
		dirY = startY == endY ? 0 : dirY ;
		for ( int i = 1 ; i < abs( startX - endX ) - 1 ; ++i ) 
		{
			if ( board.at( ( startX + ( i * dirX ) ) * 8 + ( startY + ( i * dirY ) ) )->getRank( ) != EMPTY )
			{
				return true ;
			}
		}
	}
	return false ;
}

/**
  * return false is failed.
  * actual movement of the peice is done by this
  */
bool ChessBoard::move ( std::string cmd )
{
	if( isValid( cmd ) )
	{
		execute( board ) ;
		return true ;
	}
    return false ;
}

/**
  * check whether a given move can be done or not.
  * uses a copy of the board.
  */
int ChessBoard::tryToMove ( std::vector<ChessPeice *> myBoard , char peice , int endPos , int startPos )
{
	if( startPos != -1 )
	{
		if( myBoard.at( startPos )->getRank( ) == peice &&
			checkPeice( myBoard.at( startPos ) , startPos ) )
		{
			return startPos ;
		}
	}
	else
	{
		for( size_t i =0 ; i < myBoard.size( ) ; i++ )
		{
			if( myBoard.at( i )->getRank( ) == peice &&
				checkPeice( myBoard.at( i ) , i ) )
			{	
					return i ;
			}
		}
	}
	return -1 ;
}

/**
  * get a peice and check whether it can move to a destination given with current command.
  */
bool ChessBoard::checkPeice( ChessPeice * chessPeice , int startPos )
{
	switch( chessPeice->getRank( ) )
	{
	case PAWN:
		if( static_cast<Pawn*> ( chessPeice )->canMove( startPos / 8 , startPos % 8 , 
			command->getPoints( ).at( 0 ) , command->getPoints( ).at( 1 ) ) )
			return true ;
		break ;
	case ROOK:
		if( static_cast<Rook*> ( chessPeice )->canMove( startPos / 8 , startPos % 8 , 
			command->getPoints( ).at( 0 ) , command->getPoints( ).at( 1 ) ) )
			return true ;
		break ;
	case KNIGHT:
		if( static_cast<Knight*> ( chessPeice )->canMove( startPos / 8 , startPos % 8 , 
			command->getPoints( ).at( 0 ) , command->getPoints( ).at( 1 ) ) )
			return true ;
		break ;
	case BISHOP:
		if( static_cast<Bishop*> ( chessPeice )->canMove( startPos / 8 , startPos % 8 ,
			command->getPoints( ).at( 0 ) , command->getPoints( ).at( 1 ) ) )
			return true ;
		break ;
	case QUEEN:
		if( static_cast<Queen*> ( chessPeice )->canMove( startPos / 8 , startPos % 8 ,
			command->getPoints( ).at( 0 ) , command->getPoints( ).at( 1 ) ) )
			return true ;
		break ;
	case KING:
		if( static_cast<King*> ( chessPeice )->canMove( startPos / 8 , startPos % 8 , 
			command->getPoints( ).at( 0 ) , command->getPoints( ).at( 1 ) ) )
			return true ;
		break ;
	}
	return false ;
}

char ChessBoard::getWinner( )
{
	return winner ;
}

void ChessBoard::setWinner( char Winner )
{
	winner = Winner ;
}

bool ChessBoard::canCastle( char type )
{
	// identify kings and rooks path
	int cells [ 16 ] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 56 , 57 , 58 , 59 , 60 , 61 , 62 , 63 } ;
	std::vector<int> path ;
	
	switch( currentPlayer )
	{
	case WHITE:
		if( !static_cast<King*> ( board.at( 4 ) )->canCastle( ) ) // king is moved before or checked
			return false ;
		if( type == KINGCASTLING )
		{
			if( !static_cast<Rook*> ( board.at( 7 ) )->canCastle( ) )	// rook is moved before
				return false ;
			path.insert ( path.begin( ) , cells + 4 , cells + 8 ) ;
		}
		else
		{
			if( !static_cast<Rook*> ( board.at( 0 ) )->canCastle( ) )
				return false ;
			path.insert ( path.begin( ) , cells + 12 , cells + 16 ) ;
		}
		break ;
	case BLACK:
		if( !static_cast<King*> ( board.at( 60 ) )->canCastle( ) )
			return false;
		if( type == KINGCASTLING )
		{
			if( !static_cast<Rook*> ( board.at( 63 ) )->canCastle( ) )
				return false ;
			path.insert ( path.begin( ) , cells , cells + 5 ) ;
		}
		else
		{
			if( !static_cast<Rook*> ( board.at( 56 ) )->canCastle( ) )
				return false ;
			path.insert ( path.begin( ) , cells + 8 , cells + 12 ) ;
		}
		break ;
	}

	if( !obstacles( path.at( 0 ) / 8 , path.at( 0 ) % 8 ,
		path.at( path.size( ) - 1 ) % 8 , path.at( path.size( ) - 1 ) % 8 ) ) 
		return false ;
	
	for( size_t i = 0 ; i < board.size( ) ; i++ )
	{
		if( currentPlayer != board.at( i )->getColor( ) && board.at( i )->getRank( ) != EMPTY )
		{
			for( size_t j = 0 ; j < path.size( ) ; j++ )
			{
				if( tryToMove( board , board.at( i )->getRank( ) , path.at( j ) , i ) != -1 
					&& !obstacles( i / 8 , i % 8 , path.at( j ) / 8 , path.at( j ) % 8 ) )
				{
					return false ;
				}
			}
		}
	}

	return true ;
}