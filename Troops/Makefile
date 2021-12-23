vpath %.hpp ../Unit
vpath %.cpp ../Unit
vpath %.o ../Unit

all: main.o unit/Unit.o unit/Soldier.o
	g++ main.o Unit/Unit.o Unit/Soldier.o -o troops

main.o: main.cpp
	g++ main.cpp -c

Unit.o: Unit.o
	g++ Unit/Unit.cpp -c

Soldier.o: Soldier.o
	g++ Unit/Soldier.cpp -c

clean:
	rm -rf *.o troops
