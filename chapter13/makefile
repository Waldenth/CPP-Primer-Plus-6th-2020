CC=g++
DIR= ./bin/
INDEX=1
OUTINDEX=2
all:usebrass$(OUTINDEX).exe
usebrass$(OUTINDEX).exe: usebrass$(OUTINDEX).o brass$(INDEX).o
	$(CC) $(DIR)usebrass$(OUTINDEX).o $(DIR)brass$(INDEX).o -o $(DIR)usebrass$(OUTINDEX).exe
usebrass$(OUTINDEX).o: usebrass$(OUTINDEX).cpp
	$(CC) -c usebrass$(OUTINDEX).cpp -o $(DIR)usebrass$(OUTINDEX).o
brass$(INDEX).o: brass$(INDEX).cpp
	$(CC) -c brass$(INDEX).cpp -o $(DIR)brass$(INDEX).o
clean:
	del *.o *.exe /q /s