build:
	gcc ./src/main.c ./src/printFucntions.c ./src/registerEditFunctions.c ./src/sortFunctions.c -o build 

clean:
	rm build