#ifndef ZOOM_LAZYROOM_H
#define ZOOM_LAZYROOM_H

#include "Room.h"


class LazyRoom: public Room {
public:
    LazyRoom();
    ~LazyRoom();
    virtual void addLazyStudent(Student* student);
    virtual void addWorkingStudent(Student* student){}
};


#endif //ZOOM_LAZYROOM_H
