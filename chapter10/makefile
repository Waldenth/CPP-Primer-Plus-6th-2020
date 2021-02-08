CC=g++
all:usestock0.exe 
usestock0.exe:usestock0.o stock00.o
	$(CC) usestock0.o stock00.o -o usestock0.exe
stock00.o:stock00.cpp
	$(CC) -c stock00.cpp -o stock00.o
usestock0.o:usestock0.cpp
	$(CC) -c usestock0.cpp -o usestock0.o
clean:
	del *.o *.exe