#ifndef ZOOM_STUDENT_H
#define ZOOM_STUDENT_H

#include <iostream>
#include <cstring>
#include "vector"
#include "Room.h"
class Room;
#include "Exepctions.h"
using namespace std;


class Student {
private:
    string first_name;
    string last_name;
    string id;
    float avg;
    int room_num;
    vector < pair<string, string> > messages;
public:
    Student(string& first_name, string& last_name, string& id, float avg);
    void printStudent() const;
    virtual ~Student();
    int getRoomNum() const {return room_num;};
    void setRoomNum(int room);
    string getName() const {return first_name + " " + last_name;}
    string getId() const {return id;}
    virtual void Cry()const =0;
    virtual void Work() const =0;
    virtual void SendMessage(vector<Student*> students, string message)=0;
    void getMessage(string from, string message);
    void printMessages();
    virtual void addMySelfToLazyRoom(Room* room)=0;
    virtual void addMySelfToWorkingRoom(Room* room)=0;
};



#endif //ZOOM_STUDENT_H
