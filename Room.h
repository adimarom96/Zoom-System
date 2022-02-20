#ifndef ZOOM_ROOM_H
#define ZOOM_ROOM_H
#include <iostream>
#include <cstring>
#include "Student.h"
class Student;

using namespace std;


class Room {
private:
    static int num_of_rooms;
    int room_id;
protected:
    vector<Student*> students;
    int num_of_students;
    bool isSplited;
    Room* father_room;
    Room* room_son_left;
    Room* room_son_right;
public:
    Room();
    virtual void addStudent(Student *student);
    virtual bool removeStudent(string id);
    virtual void deleteRoom();
    virtual void splitBySize();
    virtual void splitByChar();
    virtual void addLazyStudent(Student* student)=0;
    virtual void addWorkingStudent(Student* student)=0;
    void printRoom() const;
    virtual ~Room();
    int getRoomId() const{return room_id;}
    Room* getLeftChild(){return room_son_left;}
    void setLeftChild(Room* room);
    Room* getRightChild(){return room_son_right;}
    void setRightChild(Room* room);
    bool checkIsSplited()const{ return isSplited;}
    vector<Student*> getStudents(){return students;}
};


#endif //ZOOM_ROOM_H
