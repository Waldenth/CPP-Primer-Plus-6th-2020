CC=g++
all:usetime0.exe
usetime0.exe: usetime0.o mytime0.o
	$(CC) usetime0.o mytime0.o -o usetime0.exe
usetime0.o: usetime0.cpp
	$(CC) -c usetime0.cpp -o usetime0.o
mytime0.o: mytime0.cpp
	$(CC) -c mytime0.cpp -o mytime0.o
clean:
	del *.o *.exe