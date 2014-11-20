#ifdef CHESSDLL_EXPORTS
#define CHESSDLL_API __declspec(dllexport) 
#else
#define CHESSDLL_API __declspec(dllimport) 
#endif

#include "include.h"
#include "Command.h"
#include "ChessPeice.h"

class CHESSDLL_API ChessBoard
{
private:
	std::vector <ChessPeice *> board ;
	char winner ;
	Command * command ;
	char currentPlayer ;
public:
	ChessBoard( ) ;
    bool isValid( std::string ) ;
	std::vector <char> getBoard( ) ;
	bool move ( std::string ) ;
	char getWinner( ) ;
	void setWinner( char ) ;
private:
	bool ChessBoard::obstacles( int , int , int , int ) ;
	int ChessBoard::tryToMove ( std::vector<ChessPeice *> , char , int , int a = -1 ) ;
	bool ChessBoard::checkPeice( ChessPeice * , int ) ;
	void ChessBoard::kingCastle( std::vector<ChessPeice*> ) ;
	void ChessBoard::queenCastle( std::vector<ChessPeice*> ) ;
	bool ChessBoard::canCastle( char ) ;
	bool ChessBoard::isChecked( std::vector<ChessPeice*> ) ;
	bool ChessBoard::checkMate( std::vector<ChessPeice*> ) ;
	bool ChessBoard::validCapture( std::vector<ChessPeice*> ) ;
	bool ChessBoard::execute( std::vector<ChessPeice*> &a ) ;
} ;