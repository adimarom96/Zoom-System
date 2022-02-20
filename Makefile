all: ex5 clean

ex5: main.o ZoomSys.o Student.o ResponsibleStudent.o WorkingStudent.o LazyStudent.o Room.o StandardRoom.o WorkingRoom.o LazyRoom.o Exepctions.o 
	g++ main.o ZoomSys.o Student.o ResponsibleStudent.o WorkingStudent.o LazyStudent.o Room.o StandardRoom.o WorkingRoom.o LazyRoom.o Exepctions.o -o ex5
	
main.o: ZoomSys.h Student.h ResponsibleStudent.h WorkingStudent.h LazyStudent.h Room.h StandardRoom.h WorkingRoom.h LazyRoom.h Exepctions.h main.cpp ZoomSys.cpp Student.cpp ResponsibleStudent.cpp WorkingStudent.cpp LazyStudent.cpp Room.cpp StandardRoom.cpp WorkingRoom.cpp LazyRoom.cpp Exepctions.cpp
	g++ -c main.cpp
	
ZoomSys.o: ZoomSys.h Student.h ResponsibleStudent.h WorkingStudent.h LazyStudent.h Room.h StandardRoom.h WorkingRoom.h LazyRoom.h Exepctions.h ZoomSys.cpp Student.cpp ResponsibleStudent.cpp WorkingStudent.cpp LazyStudent.cpp Room.cpp StandardRoom.cpp WorkingRoom.cpp LazyRoom.cpp Exepctions.cpp 
	g++ -c ZoomSys.cpp

Student.o: Student.h Room.h Exepctions.h Student.cpp Room.cpp Exepctions.cpp 
	g++ -c Student.cpp
	
LazyStudent.o: Student.h LazyStudent.h Room.h Exepctions.h Student.cpp LazyStudent.cpp Room.cpp Exepctions.cpp 
	g++ -c LazyStudent.cpp
	
WorkingStudent.o: Student.h WorkingStudent.h Room.h Exepctions.h Student.cpp WorkingStudent.cpp Room.cpp Exepctions.cpp 
	g++ -c WorkingStudent.cpp
	
ResponsibleStudent.o: Student.h ResponsibleStudent.h Room.h Exepctions.h Student.cpp ResponsibleStudent.cpp Room.cpp Exepctions.cpp 
	g++ -c ResponsibleStudent.cpp
	
Room.o: Student.h Room.h Exepctions.h Student.cpp Room.cpp Exepctions.cpp 
	g++ -c Room.cpp
	
StandardRoom.o: Student.h Room.h StandardRoom.h Exepctions.h Student.cpp Room.cpp Exepctions.cpp StandardRoom.cpp
	g++ -c StandardRoom.cpp

LazyRoom.o: Student.h Room.h LazyRoom.h Exepctions.h Student.cpp Room.cpp Exepctions.cpp LazyRoom.cpp
	g++ -c LazyRoom.cpp

WorkingRoom.o: Student.h Room.h WorkingRoom.h Exepctions.h Student.cpp Room.cpp Exepctions.cpp WorkingRoom.cpp
	g++ -c WorkingRoom.cpp
	
Exepctions.o: Exepctions.h Exepctions.cpp
	g++ -c Exepctions.cpp
	
clean:
	rm -f *.o

 
	



