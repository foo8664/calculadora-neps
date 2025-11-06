CC = gcc
CFLAGS.common = -Wall -Werror -Wextra -Wconversion -std=c99 -pedantic\
	-mtune=native -Og -gdwarf-5 -fsanitize=address,leak,undefined

main : main.c
.PHONY : clean
clean :
	-rm main 2>/dev/null || true
