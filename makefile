LIBS	=	-lsfml-graphics -lsfml-window -lsfml-system

all: main
	rm *.o

./main: game menu splashScreen element map scenery main.cpp
	g++ -Wall -o programme menu.o game.o splashScreen.o element.o map.o scenery.o main.cpp $(LIBS)

element: ./Element/element.cpp
	g++ -Wall -c -o element.o ./Element/element.cpp $(LIBS)

map: ./Element/map.cpp
	g++ -Wall -c -o map.o ./Element/map.cpp $(LIBS)

scenery: ./Scenery/scenery.cpp
	g++ -Wall -c -o scenery.o ./Scenery/scenery.cpp $(LIBS)

# unit: ./Unit/unit.cpp
# 	g++ -Wall -c -o unit.o ./Unit/unit.cpp $(LIBS)

game: ./Game/game.cpp
	g++ -Wall -c -o game.o ./Game/game.cpp $(LIBS)

splashScreen: ./Game/splashScreen.cpp
	g++ -Wall -c -o splashScreen.o ./Game/splashScreen.cpp $(LIBS)

menu: ./Game/menu.cpp
	g++ -Wall -c -o menu.o ./Game/menu.cpp $(LIBS)
