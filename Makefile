OBJS = MazeGame.o Game.o Floor.o Character.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)


prog: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o prog

MazeGame.o: MazeGame.cpp Game.h
	$(CC) $(CFLAGS) MazeGame.cpp

Game.o: Game.cpp Game.h Character.h
	$(CC) $(CFLAGS) Game.cpp

Character.o: Character.cpp Character.h Floor.h
	$(CC) $(CFLAGS) Character.cpp

Floor.o: Floor.cpp Floor.h
	$(CC) $(CFLAGS) Floor.cpp


clean:
	rm -f prog *.o
