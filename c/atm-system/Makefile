objects = src\main.o src\system.o src\auth.o

# Detect platform to adjust commands
ifeq ($(OS),Windows_NT)
    RM = del
    CC = gcc
else
    RM = rm -f
    CC = gcc
endif

atm : $(objects)
	$(CC) -o atm $(objects)

src/main.o : src/header.h
src/system.o : src/header.h
src/auth.o : src/header.h

clean :
	$(RM) $(objects) atm.exe

