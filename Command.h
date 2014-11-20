#pragma once

class Command
{
private:
	char subject ;
	std::vector <int> points ;
	std::vector <char> actions ;
	bool validated ;
public:
	Command( ) ;
	Command( std::string ) ;
	char getSubject( ) ;
	std::vector <char> getActions( ) ;
	std::vector <int> getPoints( ) ;
	void validate( ) ;
	bool isValid( ) ;
	~Command( void ) ;
} ;