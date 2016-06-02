#ifndef SYMBOL_H
#define SYMBOL_H

#include <Windows.h>
#include <iostream>

using namespace std;

class Symbol{
public:
	Symbol(char s, int f = 7, int b = 0);
	void setColor(int foreground, int background = 0);

	friend void operator<<(ostream& os, Symbol& s);

	char getSymbol(){ return symbol; }
	void printSymbol();

private:
	char symbol;
	int colorForeground, colorBackground;
};


#endif