LIBS	=	-lsfml-graphics -lsfml-window -lsfml-system

all: main
	rm *.o

./main: game.o menu.o splashScreen.o element.o map.o scenery.o unit.o zedd.o weapon.o player.o main.cpp
	g++ --std=c++11 -Wall -o programme zedd.o unit.o menu.o game.o weapon.o splashScreen.o element.o map.o scenery.o player.o main.cpp $(LIBS)

element.o: ./Element/element.cpp
	g++ --std=c++11 -Wall -c -o element.o ./Element/element.cpp $(LIBS)

map.o: ./Element/map.cpp
	g++ --std=c++11 -Wall -c -o map.o ./Element/map.cpp $(LIBS)

scenery.o: ./Scenery/scenery.cpp
	g++ --std=c++11 -Wall -c -o scenery.o ./Scenery/scenery.cpp $(LIBS)

unit.o: ./Unit/unit.cpp
	g++ --std=c++11 -Wall -c -o unit.o ./Unit/unit.cpp $(LIBS)

game.o: ./Game/game.cpp
	g++ --std=c++11 -Wall -c -o game.o ./Game/game.cpp $(LIBS)

splashScreen.o: ./Game/splashScreen.cpp
	g++ --std=c++11 -Wall -c -o splashScreen.o ./Game/splashScreen.cpp $(LIBS)

menu.o: ./Game/menu.cpp
	g++ --std=c++11 -Wall -c -o menu.o ./Game/menu.cpp $(LIBS)

zedd.o: ./Unit/zedd.cpp
	g++ --std=c++11 -Wall -c -o zedd.o ./Unit/zedd.cpp  $(LIBS)

weapon.o: ./Unit/weapon.cpp
	g++ --std=c++11 -Wall -c -o weapon.o ./Unit/weapon.cpp $(LIBS)

player.o: ./Player/player.cpp
	g++ --std=c++11 -Wall -c -o player.o ./Player/player.cpp $(LIBS)
