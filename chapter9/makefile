CC=g++
all: file1.exe external.exe namessp.exe
file1.exe: file1.o file2.o
	$(CC) file1.o file2.o -o file1
external.exe: external.o support.o
	$(CC) external.o support.o -o external
namessp.exe: namessp.o namesp.o
	$(CC) namessp.o namesp.o -o namessp
namessp.o: namessp.cpp
	$(CC) -c namessp.cpp -o namessp.o
namesp.o: namesp.cpp
	$(CC) -c namesp.cpp -o namesp.o
file1.o: file1.cpp
	$(CC) -c file1.cpp -o file1.o
file2.o: file2.cpp
	$(CC) -c file2.cpp -o file2.o
external.o:external.cpp
	$(CC) -c external.cpp -o external.o
support.o:support.cpp
	$(CC) -c support.cpp -o support.o
clean:
	del *.o *.exe