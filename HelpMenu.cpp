#include "HelpMenu.h"

HelpMenu::HelpMenu(){
	system("CLS");
	printMainScreen();

}

HelpMenu::~HelpMenu(){


}

void HelpMenu::printMainScreen(){
	std::cout << "This is the Help Menu's main screen, what would you like to know?" << std::endl;
}