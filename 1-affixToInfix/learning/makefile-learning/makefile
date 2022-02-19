

CC := gcc

helloworld: hello.o f1.o
	$(CC) hello.o f1.o -o helloworld 

hello.o: hello.c
	$(CC) -c hello.c -o hello.o

f1.o: f1.c
	$(CC) -c f1.c -o f1.o

.PHONY:
clean:
	rm -rf f1.o hello.o 
clean-all:
	rm -rf f1.o hello.o helloworld