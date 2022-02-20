
#ifndef ZOOM_EXEPCTIONS_H
#define ZOOM_EXEPCTIONS_H
#include <iostream>
using namespace std;

class IdException: public exception {
    virtual const char* what() const throw(){return "id doesn't exists";}
};

class Permission: public exception {
    virtual const char* what() const throw(){return "this student don't have permission";}
};

class SplitBefore: public exception {
    virtual const char* what() const throw(){return "This room was split before";}
};

class InvalidDetails: public exception {
    virtual const char* what() const throw(){return "Please enter valid details";}
};



#endif //ZOOM_EXEPCTIONS_H
