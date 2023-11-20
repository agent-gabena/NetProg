PHONY: all rl

SOURCE = Server_TCP.cpp
FL = -Wall
EXEC = client

all: rl

rl: $(EXEC)

$(EXEC): $(SOURCE)
	g++ $(FL) $(SOURCE) -o $(EXEC)

