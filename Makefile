#target: dependency list
#	rule to build targe from dependencies

knightsTour: knightsTour.c
	gcc -Wall -Werror -g knightsTour.c -o knightsTour

#cleaning
clean:
	rm -f knightsTour
