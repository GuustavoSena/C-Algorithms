CC=gcc
CFLAGS=-I include

.PHONY: all bfs clean

all: main

main:
	$(CC) $(CFLAGS) -o main src/main.c src/graph.c src/queue.c Graphs/BFS/src/bfs.c

clean:
	PowerShell -Command "Remove-Item main.exe -Force"
