CC=g++
DIR= ./bin/
INDEX=1
all:usett$(INDEX).exe
usett$(INDEX).exe: usett$(INDEX).o tabtenn$(INDEX).o
	$(CC) $(DIR)usett$(INDEX).o $(DIR)tabtenn$(INDEX).o -o $(DIR)usett$(INDEX).exe
usett$(INDEX).o: usett$(INDEX).cpp
	$(CC) -c usett$(INDEX).cpp -o $(DIR)usett$(INDEX).o
tabtenn$(INDEX).o: tabtenn$(INDEX).cpp
	$(CC) -c tabtenn$(INDEX).cpp -o $(DIR)tabtenn$(INDEX).o
clean:
	del *.o *.exe /q /s