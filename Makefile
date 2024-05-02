CC=gcc
CFLAGS=-I./include -I./Graphs/BFS/include

.PHONY: all clean

all: main

main:
	$(CC) $(CFLAGS) -o main src/graph.c src/queue.c src/main.c Graphs/BFS/src/bfs.c Graphs/BFS/src/maze_bfs.c

clean:
	PowerShell -Command "Remove-Item main.exe -Force"
