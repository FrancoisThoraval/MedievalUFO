#include <stdlib.h>
#include "Game/game.hpp"
int main()
{
	srand (time(NULL));
	sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("./music/Power_Rangers_FULL_THEME_mp3cut.wav"))
        return -1;
	else
		std::cout << "playing" << '\n';
	sf::Sound sound;
	sf::Music music;
	sound.setBuffer(buffer);
	sound.play();


	music.openFromFile("./music/Power_Rangers_FULL_THEME_mp3cut.wav");
	music.play();
	Game g(800,600);
	g.start();
	// for (int i = 0; i < 99999; i++) {
	// 	for (int j = 0; j < 9999; j++) {
	// 		/* code */
	// 	}
	// }
     return 0;
}
