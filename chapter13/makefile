CC=g++
DIR= ./bin/
INDEX=1
all:usebrass$(INDEX).exe
usebrass$(INDEX).exe: usebrass$(INDEX).o brass$(INDEX).o
	$(CC) $(DIR)usebrass$(INDEX).o $(DIR)brass$(INDEX).o -o $(DIR)usebrass$(INDEX).exe
usebrass$(INDEX).o: usebrass$(INDEX).cpp
	$(CC) -c usebrass$(INDEX).cpp -o $(DIR)usebrass$(INDEX).o
brass$(INDEX).o: brass$(INDEX).cpp
	$(CC) -c brass$(INDEX).cpp -o $(DIR)brass$(INDEX).o
clean:
	del *.o *.exe /q /s