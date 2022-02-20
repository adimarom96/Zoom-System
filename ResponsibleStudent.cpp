#include "ResponsibleStudent.h"

ResponsibleStudent::~ResponsibleStudent() {

}

void ResponsibleStudent::SendMessage(vector<Student *> students, string message) {
    vector<Student*>::iterator it;

    for(it = students.begin(); it != students.end(); it++){
        (*it)->getMessage(this->getName(), message);
    }
}
