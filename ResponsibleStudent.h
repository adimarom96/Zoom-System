#ifndef ZOOM_RESPONSIBLESTUDENT_H
#define ZOOM_RESPONSIBLESTUDENT_H

#include "Student.h"

class ResponsibleStudent: public Student{
public:
    ResponsibleStudent(string& first_name, string& last_name, string& id, float avg):Student(first_name, last_name,id, avg){}
    ~ResponsibleStudent();
    virtual void Cry()const{}
    virtual void Work()const{}
    virtual void SendMessage(vector<Student*> students, string message);
    void addMySelfToLazyRoom(Room* room){}
    void addMySelfToWorkingRoom(Room* room){}
};


#endif //ZOOM_RESPONSIBLESTUDENT_H
