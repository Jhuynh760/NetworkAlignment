run:
	g++ main.cpp create_graph.cpp -o main -std=c++17 -Wall
	./main "n10.txt"
	./main "n100.txt"
	./main "n10000.txt"
	./main "s1.txt"

debug:
	g++ main.cpp create_graph.cpp -o main -std=c++17 -Wall
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --track-origins=yes ./main "n10000.txt"