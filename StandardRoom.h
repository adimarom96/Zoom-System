#ifndef ZOOM_STANDARDROOM_H
#define ZOOM_STANDARDROOM_H

#include "Room.h"

class StandardRoom: public Room {
public:
    StandardRoom();
    virtual ~StandardRoom();
    virtual void addLazyStudent(Student* student){}
    virtual void addWorkingStudent(Student* student){}
};


#endif //ZOOM_STANDARDROOM_H
