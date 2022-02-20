#ifndef ZOOM_ZOOMSYS_H
#define ZOOM_ZOOMSYS_H
#include "Room.h"
#include "StandardRoom.h"
#include "LazyRoom.h"
#include "WorkingRoom.h"
#include <map>
#include "ResponsibleStudent.h"
#include "LazyStudent.h"
#include "WorkingStudent.h"
#include "Exepctions.h"

class ZoomSys {
private:
    vector<Student*> students;
    vector<Room*> rooms_vec;
    map<string, Student*> students_map;
    map<int, Room*> rooms;
    void remove_from_data_structures(Room* to_delete);
public:
    ZoomSys(string path);
    void addStudent();
    void removeStudent();
    void printStudents();
    void assignStudent();
    void addRoom();
    void printRooms();
    void splitRoom();
    void removeRoom();
    void printStudentDetails();
    void sendMessage();
    void work();
    ~ZoomSys();

};


#endif //ZOOM_ZOOMSYS_H
