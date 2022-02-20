
#ifndef ZOOM_WORKINGROOM_H
#define ZOOM_WORKINGROOM_H
#include "Room.h"


class WorkingRoom: public Room {
public:
    WorkingRoom();
    ~WorkingRoom();
    virtual void addLazyStudent(Student* student){}
    virtual void addWorkingStudent(Student* student);
};


#endif //ZOOM_WORKINGROOM_H
