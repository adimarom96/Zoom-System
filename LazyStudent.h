
#ifndef ZOOM_LAZYSTUDENT_H
#define ZOOM_LAZYSTUDENT_H
#include "Student.h"

class LazyStudent: public Student {
public:
    LazyStudent(string& first_name, string& last_name, string& id, float avg):Student(first_name, last_name,id, avg){}
    ~LazyStudent();
    virtual void Cry()const {cout << this->getName() + " is crying"<<endl;}
    virtual void Work()const{}
    virtual void SendMessage(vector<Student*> students, string message){throw Permission();}
    void addMySelfToLazyRoom(Room* room){room->addStudent(this);}
    void addMySelfToWorkingRoom(Room* room){}
};


#endif //ZOOM_LAZYSTUDENT_H
