midterm: main.o 
	g++ main.o -o midterm
main.o: main.cpp 
	g++ -c main.cpp -g
clean:
	rm *.o midterm