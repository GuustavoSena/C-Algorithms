CC=gcc
CFLAGS=-I./Graphs/BFS/include

.PHONY: all bfs clean

all: bfs

bfs:
	$(CC) $(CFLAGS) -o ./Graphs/BFS/bfs ./Graphs/BFS/src/main.c ./Graphs/BFS/src/bfs.c ./Graphs/BFS/src/graph.c ./Graphs/BFS/src/queue.c

clean:
	PowerShell -Command "Remove-Item ./Graphs/BFS/* -Include *.exe, *.o -Force"
