CXX?=g++

PROGRAM=tester
SRC=src
BLD=build
INC=include
OBJS=$(BLD)/*.o

INSTALLBIN=/usr/bin

liblex:
	mkdir -p $(BLD)
	$(CXX) -fPIC -g -ggdb -c -Wall -std=c++11 -I$(INC)/ -o$(BLD)/testfinder.o $(SRC)/testfinder.cc
	$(CXX) -fPIC -g -ggdb -c -Wall -std=c++11 -I$(INC)/ -o$(BLD)/testexecutor.o $(SRC)/testexecutor.cc
	$(CXX) -fPIC -g -ggdb -c -Wall -std=c++11 -I$(INC)/ -o$(BLD)/testparser.o $(SRC)/testparser.cc
	$(CXX) -fPIC -g -ggdb -c -Wall -std=c++11 -I$(INC)/ -o$(BLD)/main.o $(SRC)/main.cc

	$(CXX) -o$(PROGRAM) $(OBJS)

clean:
	rm -rf $(PROGRAM) $(BLD)/*.o

install:
	$(CXX) -o$(INSTALLBIN)/$(PROGRAM) $(SRC)/main.cc
