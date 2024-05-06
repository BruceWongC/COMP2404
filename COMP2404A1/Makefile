A1:		main.o Date.o Time.o Event.o Calendar.o
	g++ -o a1 main.o Date.o Time.o Event.o Calendar.o

main.o: main.cc
	g++ -c main.cc

Date.o: Date.cc
	g++ -c Date.cc

Time.o: Time.cc
	g++ -c Time.cc

Event.o: Event.cc
	g++ -c Event.cc

Calendar.o: Calendar.cc
	g++ -c Calendar.cc

clean:
	rm -f *.o a1
