#include "WorkingRoom.h"


// constructor
WorkingRoom::WorkingRoom(): Room() {}

// destructor
WorkingRoom::~WorkingRoom() {}

void WorkingRoom::addWorkingStudent(Student* student) {
     student->addMySelfToWorkingRoom(this);

}


