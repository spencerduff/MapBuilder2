#include "Symbol.h"

Symbol::Symbol(char s, int x, int y, int f, int b){
	symbol = s;
	posX = x;
	posY = y;
	colorForeground = f;
	setColor(f, b);
}

void Symbol::setColor(int foreground, int background){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), foreground | background);
}

ostream& operator<<(ostream& os, Symbol& s)
{
	s.setColor(s.colorForeground);
	os << s.symbol;
	return os;
}