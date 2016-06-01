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

void operator<<(ostream& os, Symbol& s)
{
	if (s.colorBackground >= 0)
		s.setColor(s.colorForeground, s.colorBackground);
	else s.setColor(s.colorForeground);
	cout << s.symbol;
	s.setColor(7);
	return;
}

void Symbol::printSymbol(){
	cout << *this;
}