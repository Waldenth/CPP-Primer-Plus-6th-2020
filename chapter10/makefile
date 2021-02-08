CC=g++
all:usestock0.exe usestock1.exe
usestock0.exe:usestock0.o stock00.o
	$(CC) usestock0.o stock00.o -o usestock0.exe
usestock1.exe:usestock1.o stock10.o
	$(CC) usestock1.o stock10.o -o usestock1.exe
stock00.o:stock00.cpp
	$(CC) -c stock00.cpp -o stock00.o
usestock0.o:usestock0.cpp
	$(CC) -c usestock0.cpp -o usestock0.o
stock10.o:stock10.cpp
	$(CC) -c stock10.cpp -o stock10.o
usestock1.o:usestock1.cpp
	$(CC) -c usestock1.cpp -o usestock1.o
clean:
	del *.o *.exe