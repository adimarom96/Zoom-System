#include "Student.h"

Student::Student(string& first_name, string& last_name, string& id, float avg) {
    this->first_name = first_name;
    this->last_name = last_name;
    this->id =id;
    this->avg = avg;
    this->room_num = -1; // for now

}

void Student::printStudent() const {
    cout << first_name << " " << last_name << " " << id << " " << avg << " " << room_num << endl;
}

Student::~Student() {

}

void Student::setRoomNum(int room) {
    this->room_num = room;
}

void Student::getMessage(string from, string message) {
    pair <string, string> new_message;
    new_message.first = from;
    new_message.second = message;
    this->messages.push_back(new_message);
}

void Student::printMessages(){
    vector<pair<string,string>>::iterator it;

    cout << "---Messages---" <<endl;
    for(it=messages.begin(); it!=messages.end();it++){
        cout << (*it).first <<":"<<(*it).second<<endl;
    }

}
