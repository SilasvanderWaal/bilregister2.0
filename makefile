build:
	gcc ./src/main.c ./src/printFucntions.c ./src/registerEditFunctions.c ./src/sortFunctions.c -o build 

clean:
	rm build

leak:
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./build