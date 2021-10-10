CC=g++
DIR= ./bin/
INDEX=3
all:usetime$(INDEX).exe
usetime$(INDEX).exe: usetime$(INDEX).o mytime$(INDEX).o
	$(CC) $(DIR)usetime$(INDEX).o $(DIR)mytime$(INDEX).o -o $(DIR)usetime$(INDEX).exe
usetime$(INDEX).o: usetime$(INDEX).cpp
	$(CC) -c usetime$(INDEX).cpp -o $(DIR)usetime$(INDEX).o
mytime$(INDEX).o: mytime$(INDEX).cpp
	$(CC) -c mytime$(INDEX).cpp -o $(DIR)mytime$(INDEX).o
clean:
	del *.o *.exe /q /s