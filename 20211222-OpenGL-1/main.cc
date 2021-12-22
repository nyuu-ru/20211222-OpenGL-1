#include <iostream>
#include <SDL2/SDL.h>

#include "MainWindow.h"

int main(int, char **)
{
	try {
		MainWindow w;

		w.main_loop();
	} catch (const std::exception &e) {
		std::cerr <<
				"Во время выполнения программы\n"
				"произошла следующая ошибка:\n" <<
				e.what() <<
				std::endl;
		return 1;
	}


	return 0;
}
