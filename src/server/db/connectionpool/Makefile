CC = g++
CFLAGS = -std=c++11 -Wall
LDFLAGS = -lmysqlclient

SRCS = main.cpp Connection.cpp ConnectionPool.cpp
EXEC = main

all: $(EXEC)

$(EXEC): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(EXEC) $(LDFLAGS)

clean:
	rm -f $(EXEC)
