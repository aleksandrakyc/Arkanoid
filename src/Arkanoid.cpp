#include "pch.h"
#include <map>
#include <string>
#include <numbers>


int main() {

	Menu menu;

	//game loop
	
	while (menu.getWindowIsOpen()) {

		//update

		menu.update();


		//render

		menu.render();

	}

	//end

	return 0;
}