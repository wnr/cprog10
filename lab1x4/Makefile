MOD = vector main hypercube

SRC = $(MOD:=.cpp)
HDR = $(MOD:=.h)
OBJ = $(MOD:=.o)

BACKUP = $(SRC) $(HDR)

FLDR = lab1x

CFLAG = -c -DDHYPER -Wall -ftemplate-depth-1337
LFLAG =

CTEST = -DCAL # recompiles main.cpp if Makefile is updated

all:
	make lab1x4

lab1x4 : $(OBJ) Makefile
	g++ $(OBJ) -o lab1x4

vector.o : vector.cpp vector.h Makefile
	g++ $(CFLAG) $(CTEST) vector.cpp

hypercube.o : hypercube.cpp hypercube.h Makefile
	g++ $(CFLAG) $(CTEST) hypercube.cpp

main.o : main.cpp Makefile
	g++ $(CFLAG) $(CTEST) main.cpp

clean:
	rm -f *.o lab1x4

run:
	./lab1x4

#backup: $(BACKUP)
#	cp -R $(BACKUP) backup/backup_$$(date +20\%y\%m\%d_\%H\%M\%S)
