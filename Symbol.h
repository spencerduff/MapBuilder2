#ifndef SYMBOL_H
#define SYMBOL_H

#include <Windows.h>
#include <iostream>

using namespace std;

// Symbols make up everything that is shown to the UI. Items, the MapTiles, etc. Has a color and char.
class Symbol{
public:
	Symbol(char s, int f = 7, int b = 0);

	// Setter
	void setColor(int foreground, int background = 0);

	// For cout-ing
	friend void operator<<(ostream& os, Symbol& s);

	// Getter
	char getSymbol(){ return symbol; }
	// Prints the Symbol in its color.
	void printSymbol();

private:
	char symbol;
	int colorForeground, colorBackground;
};


#endif