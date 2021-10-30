#pragma once

#include "System.h"



int main(int argc, char* argv[]) {


	System game;
	game.init();
	
	while (game.get_BRunning()) {

		game.handleEvents();
		game.update();
		game.render();
	}

	game.clean();
	
	return 0;
}