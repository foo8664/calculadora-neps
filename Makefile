CC = cc
CFLAGS = -Wall -Wextra -Wconversion -std=c99 -pedantic\
	-mtune=native -march=native -O2

main : src/main.c
	$(CC) $(CFLAGS) src/main.c -o main
.PHONY : clean
clean :
	-rm main 2>/dev/null || true
