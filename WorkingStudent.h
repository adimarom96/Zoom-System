#ifndef ZOOM_WORKINGSTUDENT_H
#define ZOOM_WORKINGSTUDENT_H

#include "Student.h"


class WorkingStudent: public Student {
public:
    WorkingStudent(string& first_name, string& last_name, string& id, float avg):Student(first_name, last_name,id, avg){}
    ~WorkingStudent();
    virtual void Cry() const {}
    virtual void Work() const{cout << this->getName() + " is working"<<endl;}
    virtual void SendMessage(vector<Student*> students, string message){throw Permission();};
    void addMySelfToLazyRoom(Room* room){}
    void addMySelfToWorkingRoom(Room* room){room->addStudent(this);}
};


#endif //ZOOM_WORKINGSTUDENT_H
