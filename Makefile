CC = gcc
CFLAGS.common = -Wall -Werror -Wextra -Wconversion -std=c99 -pedantic\
	-mtune=native -march=native -O2

main : main.c
.PHONY : clean
clean :
	-rm main 2>/dev/null || true
