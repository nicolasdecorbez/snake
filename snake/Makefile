but:snake



OFILES = jeu.o initialisation.o serpent.o main.o

CC = gcc

CFLAGS = -ansi -lgraph

jeu.o : jeu.h

initialisation.o : initialisation.h jeu.h

serpent.o : serpent.h jeu.h

main.o : jeu.h serpent.h initialisation.h

snake : $(OFILES)
	$(CC) $(CFLAGS) -o snake $(OFILES)

run : $(OFILES)
	$(CC) $(CFLAGS) -o snake $(OFILES)
	./snake

clean :
	-rm -f $(OFILES) snake

.PHONY : but clean
