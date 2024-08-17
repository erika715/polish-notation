all: calculate_in_polish.o graph.o rendering_field.o transform_to_polish.o
	gcc -Wall -Wextra -Werror calculate_in_polish.o graph.o rendering_field.o transform_to_polish.o -o

calculate_in_polish.o: calculate_in_polish.c calculate_in_polish.h
	gcc -Wall -Wextra -Werror -c calculate_in_polish.c

graph.o: graph.c
	gcc -Wall -Wextra -Werror -c graph.c

rendering_field.o: rendering_field.c rendering_field.h
	gcc -Wall -Wextra -Werror -c rendering_field.c

transform_to_polish.o: transform_to_polish.c transform_to_polish.h
	gcc -Wall -Wextra -Werror -c transform_to_polish.c

clean: 
	rm -rf *.o

rebuild: clean all