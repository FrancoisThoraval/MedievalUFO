LIBS	=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
VERSION =	--std=c++11

all: main
	rm *.o

main: game.o menu.o splashScreen.o element.o map.o scenery.o unit.o  weapon.o player.o ayayay.o main.cpp
	g++ $(VERSION) -Wall -o programme unit.o menu.o game.o weapon.o splashScreen.o element.o map.o scenery.o player.o ayayay.o main.cpp $(LIBS)

element.o: ./Element/element.cpp
	g++ $(VERSION) -Wall -c -o element.o ./Element/element.cpp $(LIBS)

map.o: ./Element/map.cpp
	g++ $(VERSION) -Wall -c -o map.o ./Element/map.cpp $(LIBS)

scenery.o: ./Scenery/scenery.cpp
	g++ $(VERSION) -Wall -c -o scenery.o ./Scenery/scenery.cpp $(LIBS)

unit.o: ./Unit/unit.cpp
	g++ $(VERSION) -Wall -c -o unit.o ./Unit/unit.cpp $(LIBS)

game.o: ./Game/game.cpp
	g++ $(VERSION) -Wall -c -o game.o ./Game/game.cpp $(LIBS)

splashScreen.o: ./Game/splashScreen.cpp
	g++ $(VERSION) -Wall -c -o splashScreen.o ./Game/splashScreen.cpp $(LIBS)

menu.o: ./Game/menu.cpp
	g++ $(VERSION) -Wall -c -o menu.o ./Game/menu.cpp $(LIBS)

weapon.o: ./Unit/weapon.cpp
	g++ $(VERSION) -Wall -c -o weapon.o ./Unit/weapon.cpp $(LIBS)

player.o: ./Player/player.cpp
	g++ $(VERSION) -Wall -c -o player.o ./Player/player.cpp $(LIBS)

ayayay.o : ./Unit/ayayay.cpp
	g++  $(VERSION) -Wall -c -o ayayay.o ./Unit/ayayay.cpp $(LIBS)
