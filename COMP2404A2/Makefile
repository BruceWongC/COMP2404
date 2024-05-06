A2:		main.o Control.o School.o Schedule.o CourseArray.o Course.o Time.o View.o
	g++ -o a2 main.o Control.o School.o Schedule.o CourseArray.o Course.o Time.o View.o

main.o: main.cc
	g++ -c main.cc

Control.o: Control.cc
	g++ -c Control.cc

School.o: School.cc
	g++ -c School.cc

Schedule.o: Schedule.cc
	g++ -c Schedule.cc

CourseArray.o: CourseArray.cc
	g++ -c CourseArray.cc

Course.o: Course.cc
	g++ -c Course.cc

Time.o: Time.cc
	g++ -c Time.cc

View.o: View.cc
	g++ -c View.cc
	
clean: 
	rm -f *.o a2
