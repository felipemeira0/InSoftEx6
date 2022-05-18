FILE_NAMES=communication.c
COMPILER=gcc
FLAGS=-lpthread

bin:
	$(COMPILER) -o $@ $(FILE_NAMES) $(FLAGS)

.PHONY: run clean

run:
	./bin

clean:
	rm bin
