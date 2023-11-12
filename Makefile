CC = gcc;
CFLAGS = -Wall -g -O2;
DEPS = findc.c findc.h;
OBJ = findc.o;

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<
findC: $(OBJ)
	gcc $(CFLAGS) -o $@ $^