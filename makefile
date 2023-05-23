CC = gcc
LD = gcc
RM = del

OBJS += edf.o
OBJS += main.o

all:
	edf

edf: $(OBJS)
	$(LD) -o obj

%.o: %.c
	$(CC) -o $@ -c $<

clean:
	-$(RM) *.o
	-$(RM) edf

.PHONY:
	all
	clean