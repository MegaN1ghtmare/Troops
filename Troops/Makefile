vpath %.hpp ../Unit
vpath %.cpp ../Unit
vpath %.o ../Unit

all: main.o unit/Unit.o unit/Soldier.o
	g++ main.o Unit/Unit.o Unit/Ability.o -o troops

main.o: main.cpp
	g++ main.cpp -c

Unit.o: Unit.o
	g++ Unit/Unit.cpp -c

Ability.o: Ability.o
	g++ Unit/Ability.cpp -c

clean:
	rm -rf *.o troops
