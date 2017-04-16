#include <stdlib.h>
#include "Game/game.hpp"
int main()
{
     // srand (time(NULL));
     // Game g(800,600);
     // g.start();
	sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("/home/tom/Documents/Projet_TechProg_L2/Tetris/Music&Sounds/batmanReversed.wav"))
        return -1;
	else
		std::cout << "playing" << '\n';

	sf::Sound sound;
	sf::Music music;
	sound.setBuffer(buffer);
	sound.play();


	music.openFromFile("/home/tom/Documents/Projet_TechProg_L2/Tetris/Music&Sounds/batman.wav");
	music.play();
	for (int i = 0; i < 99999; i++) {
		for (int j = 0; j < 9999; j++) {
			/* code */
		}
	}
     return 0;
}
