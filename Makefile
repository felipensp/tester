CXX?=g++

PROGRAM=tester
SRC=src
BLD=build
INC=include
OBJS=$(BLD)/*.o

INSTALLBIN=/usr/bin

liblex:
	mkdir -p $(BLD)
#	$(CXX) -fPIC -g -c -Wall -I$(INC)/ -o$(BLD)/main.o $(SRC)/main.cc

	$(CXX) -o$(PROGRAM) -I$(INC)/ $(SRC)/main.cc -L$(LIB)/ -lpcre

clean:
	rm -rf $(PROGRAM) $(BLD)/*.o

install:
	$(CXX) -o$(INSTALLBIN)/$(PROGRAM) $(SRC)/main.cc -lpcre
