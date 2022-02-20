#include "Room.h"


int Room::num_of_rooms = 0;

Room::Room() {
    this->room_id = num_of_rooms;
    num_of_rooms++;
    this->num_of_students = 0;
    this->isSplited = false;
    father_room = nullptr;
    room_son_left = nullptr;
    room_son_right = nullptr;
}



void Room::printRoom() const {
    cout << "room id:" << this->room_id << ", students:" << num_of_students<<endl;
}

Room::~Room() {

}

void Room::deleteRoom() {
    if(room_son_left != nullptr) {
        room_son_left->deleteRoom();
    }
    if(room_son_right != nullptr) {
        room_son_right->deleteRoom();
    }

    // maybe need to pop students from vector?????????
    if(father_room == nullptr) {
        // go on every student and put -1 in there room id
        vector<Student*>::iterator it;

        for(it = students.begin(); it != students.end(); ++it){
            (*it)->setRoomNum(-1);
            (*it)->Cry();
        }

    }
    else{
        // add my students to my father room
        vector<Student*>::iterator it;

        for(it = students.begin(); it != students.end(); ++it){
            father_room->addStudent(*it);
            (*it)->Cry();
        }
        // set child of my father to null
        if(this == father_room->room_son_left)
            father_room->room_son_left = nullptr;
        else if(this == father_room->room_son_right)
            father_room->room_son_right = nullptr;
    }

    delete this;

}



void Room::addStudent(Student *new_student) {
    students.push_back(new_student);
    this->num_of_students++;
    new_student->setRoomNum(this->getRoomId());
}

bool Room::removeStudent(string id) {
    vector<Student*>::iterator it;

    for(it = students.begin(); it != students.end(); ++it){
        if((*it)->getId() == id){
            students.erase(it);
            this->num_of_students--;
            return true;
        }
    }
    return false;
}

void Room::splitBySize() {

    vector<Student*>::iterator it;
    int i;
    for(it = students.begin(), i = 0; i < num_of_students; i++, it++){
        if(i < num_of_students/2){
            this->room_son_left->addStudent(*it);
        }
        else{
            this->room_son_right->addStudent(*it);
        }

    }
    this->students.erase(students.begin(), students.end()); // remove all student from this room
    this->num_of_students = 0;

    room_son_left->father_room = this;
    room_son_right->father_room = this;

    this->isSplited = true;

}

void Room::splitByChar() {

    vector<Student*> id_to_remove;

    vector<Student*>::iterator it;
    for(it = students.begin(); it != students.end(); it++){
        room_son_left->addWorkingStudent(*it);
        room_son_right->addLazyStudent(*it);
    }

    id_to_remove = room_son_left->getStudents();

    vector<Student*>::iterator it2;
    for(it2 = id_to_remove.begin(); it2 != id_to_remove.end(); it2++) {
        removeStudent((*it2)->getId());
    }

    id_to_remove = room_son_right->getStudents();

    vector<Student*>::iterator it3;
    for(it3 = id_to_remove.begin(); it3 != id_to_remove.end(); it3++) {
        removeStudent((*it3)->getId());
    }

    this->isSplited = true;
}

void Room::setLeftChild(Room *room) {
    room_son_left = room;
    room_son_left->father_room = this;
}

void Room::setRightChild(Room *room) {
    room_son_right = room;
    room_son_right->father_room = this;
}


