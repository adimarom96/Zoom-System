
#include "LazyRoom.h"

LazyRoom::LazyRoom():Room() {

}

LazyRoom::~LazyRoom() {

}

void LazyRoom::addLazyStudent(Student* student) {
    student->addMySelfToLazyRoom(this);
}
