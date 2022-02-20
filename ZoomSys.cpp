#include "ZoomSys.h"
#include <fstream>
#include <sstream>

vector<string> &split(string &s, char delim, vector<string> &words) {
    stringstream ss(s);
    string word;
    while (getline(ss, word, delim)) {
        words.push_back(word);
    }
    return words;
}

ZoomSys::ZoomSys(string path) {
    ifstream data_file(path);

    string line;


    while (getline(data_file, line)) {
        line = line.substr(0, line.size() - 1); // cut \r at the end of the string
        vector<string> splitedLine;
        splitedLine = split(line, '\t', splitedLine); // split

        string first_name = splitedLine[0];
        string last_name = splitedLine[1];
        string id = splitedLine[2];
        float avg = stof(splitedLine[3]);
        string type = splitedLine[4];

        if (type == "R") {
            ResponsibleStudent *student1 = new ResponsibleStudent(first_name, last_name, id, avg);
            this->students.push_back(student1);
            this->students_map[student1->getId()] = student1;
        } else if (type == "W") {
            WorkingStudent *student2 = new WorkingStudent(first_name, last_name, id, avg);
            this->students.push_back(student2);
            this->students_map[student2->getId()] = student2;
        } else {
            LazyStudent *student3 = new LazyStudent(first_name, last_name, id, avg);
            this->students.push_back(student3);
            this->students_map[student3->getId()] = student3;
        }
    }
}

void ZoomSys::addStudent() {
    string firstName, lastName, str_avg, id, type;
    int id_num;
    float avg;
    cout << "---Create Student---" << endl;
    cout << "First name:" << endl;
    cin >> firstName;
    cout << "Last name:" << endl;
    cin >> lastName;
    cout << "ID:" << endl;
    cin >> id;
    cout << "avg:" << endl;
    cin >> str_avg;
    cout << "Worker(W) or Lazy(L) or Responsible(R) Student?" << endl;
    cin >> type;

    // avg validation
    try {

        avg = stof(str_avg);
        if (!(0 <= avg && avg <= 100)) {
            throw InvalidDetails();
        }

        id_num = stoi(id);
        if (id_num <= 0) {
            throw InvalidDetails();
        }
        if (type != "W" && type != "L" && type != "R") {
            throw InvalidDetails();
        }
        // check if student exist
        if (!(this->students_map.find(id) == this->students_map.end())) {
            throw InvalidDetails();
        }

    }
    catch (exception &e) {
        cout << e.what() << endl;
        return;
    }


    // after all validations now we can create the new student
    if (type == "W") {
        WorkingStudent *to_add = new WorkingStudent(firstName, lastName, id, avg);
        this->students_map[id] = to_add;
        this->students.push_back(to_add);
    } else if (type == "R") {
        ResponsibleStudent *to_add = new ResponsibleStudent(firstName, lastName, id, avg);
        this->students_map[id] = to_add;
        this->students.push_back(to_add);
    } else {
        LazyStudent *to_add = new LazyStudent(firstName, lastName, id, avg);
        this->students_map[id] = to_add;
        this->students.push_back(to_add);
    }
}

void ZoomSys::removeStudent() {
    string id;
    int room_num = -1;
    Student *to_delete;
    cout << "---Remove Student---" << endl;
    cout << "Enter the id:" << endl;
    cin >> id;


    try {
        if ((this->students_map.find(id) == this->students_map.end())) {
            throw IdException();
        }
    }
    catch (exception &e) {
        cout << e.what() << endl;
        return;
    }


    vector<Student *>::iterator it;
    for (it = this->students.begin(); it != this->students.end(); it++) {
        if ((*it)->getId() == id) {
            room_num = (*it)->getRoomNum();
            this->students.erase(it);
            break;
        }
    }
    to_delete = this->students_map[id];
    this->students_map.erase(id); // remove from map

    if (room_num != -1)
        this->rooms[room_num]->removeStudent(id); // remove from room

    delete to_delete;
}

void ZoomSys::printStudents() {
    cout << "First name, Last Name, ID, Avg, Room ID" << endl;
    vector<Student *>::iterator it;
    for (it = this->students.begin(); it != this->students.end(); it++) {
        (*it)->printStudent();
    }
}

void ZoomSys::assignStudent() {
    string student_id, str_room_id;
    int room_id;
    int prev_room_id;

    cout << "---Assign Student---" << endl;
    cout << "Enter student id:" << endl;
    cin >> student_id;
    cout << "Enter room id:" << endl;
    cin >> str_room_id;

    room_id = stoi(str_room_id);
    try {
        if ((this->students_map.find(student_id) == this->students_map.end())) {
            throw IdException();
        }
        if ((this->rooms.find(room_id) == this->rooms.end())) {
            throw IdException();
        }

    }
    catch (exception &e) {
        cout << e.what() << endl;
        return;
    }


    prev_room_id = this->students_map[student_id]->getRoomNum();
    if (room_id == -1) {
        this->students_map[student_id]->setRoomNum(room_id);
    } else {
        this->students_map[student_id]->setRoomNum(room_id);
        this->rooms.find(room_id)->second->addStudent(this->students_map[student_id]);
    }

    if (prev_room_id != -1) {
        this->rooms.find(prev_room_id)->second->removeStudent(student_id);
    }

}


void ZoomSys::addRoom() {
    StandardRoom *new_room = new StandardRoom();
    this->rooms[new_room->getRoomId()] = new_room;
    this->rooms_vec.push_back(new_room);
    cout << "New room created" << endl;
}

void ZoomSys::printRooms() {
    vector<Room *>::iterator it;
    for (it = this->rooms_vec.begin(); it != this->rooms_vec.end(); it++) {
        (*it)->printRoom();
    }
}

void ZoomSys::splitRoom() {
    string str_room_id;
    int room_id;
    string choice;

    WorkingRoom* newRoomW;
    LazyRoom* newRoomL;
    StandardRoom* newRoomS1;
    StandardRoom* newRoomS2;

    cout << "---Split Room---" << endl;
    cout << "Room id:" << endl;
    cin >> str_room_id;

    try {
        room_id = stoi(str_room_id);
        if ((this->rooms.find(room_id)) == this->rooms.end()) {
            throw IdException();
        } else {
            if ((this->rooms[room_id]->checkIsSplited())) {
                throw SplitBefore();
            }
        }

        cout << "1.Character split" << endl;
        cout << "2.Size split" << endl;
        cin >> choice;

        if (choice > "2" || choice < "1") {
           throw InvalidDetails();
        }
    }
    catch (exception& e) {
        cout << e.what() << endl;
        return;
    }


    if (choice == "1") {
        newRoomW = new WorkingRoom();
        newRoomL = new LazyRoom();
        this->rooms[room_id]->setLeftChild(newRoomW);
        this->rooms[room_id]->setRightChild(newRoomL);
        this->rooms[room_id]->splitByChar();
    } else {
        newRoomS1 = new StandardRoom();
        newRoomS2 = new StandardRoom();
        this->rooms[room_id]->setLeftChild(newRoomS1);
        this->rooms[room_id]->setRightChild(newRoomS2);
        this->rooms[room_id]->splitBySize();
    }
    // add childs to map and vec
    this->rooms_vec.push_back(this->rooms[room_id]->getLeftChild());
    this->rooms_vec.push_back(this->rooms[room_id]->getRightChild());
    this->rooms[this->rooms[room_id]->getLeftChild()->getRoomId()] = this->rooms[room_id]->getLeftChild();
    this->rooms[this->rooms[room_id]->getRightChild()->getRoomId()] = this->rooms[room_id]->getRightChild();

}

void ZoomSys::removeRoom() {
    string str_room_id;
    int room_id;
    Room *to_delete;
    cout << "---Remove Room---" << endl;
    cout << "Enter room id:" << endl;
    cin >> str_room_id;

    try {
        room_id = stoi(str_room_id);
        if ((this->rooms.find(room_id)) == this->rooms.end()) {
            throw IdException();
        } else {
            to_delete = this->rooms[room_id];
            remove_from_data_structures(to_delete);

        }

        to_delete->deleteRoom();
    }
    catch (exception& e) {
        cout << e.what() << endl;
        return;
    }
}


void ZoomSys::remove_from_data_structures(Room *to_delete) {
    if (to_delete->getLeftChild())
        remove_from_data_structures(to_delete->getLeftChild());
    if (to_delete->getRightChild())
        remove_from_data_structures(to_delete->getRightChild());

    this->rooms.erase(to_delete->getRoomId());

    vector<Room *>::iterator it;
    for (it = rooms_vec.begin(); it != rooms_vec.end(); it++) {
        if ((*it)->getRoomId() == to_delete->getRoomId()) {
            this->rooms_vec.erase(it);
            break;
        }
    }
}

void ZoomSys::printStudentDetails() {
    string student_id;
    Student *to_print;
    cout << "Enter student id:" << endl;
    cin >> student_id;

    try {
        if ((this->students_map.find(student_id) == this->students_map.end())) {
            throw IdException();
        }
        to_print = this->students_map.find(student_id)->second;

        to_print->printStudent();
        to_print->printMessages();
    }
    catch (exception& e) {
        cout << e.what() << endl;
        return;
    }

}

void ZoomSys::sendMessage() {
    string student_id;
    string message;

    Student *sends;

    cout << "Enter the id:" << endl;
    cin >> student_id;

    try {
        if ((this->students_map.find(student_id) == this->students_map.end())) {
            throw IdException();
        }

        sends = this->students_map.find(student_id)->second;
        cout << "Enter the message:" << endl;
        cin.ignore();
        getline(cin, message);

        if (sends->getRoomNum() == -1)
            return;

        sends->SendMessage(rooms.find(sends->getRoomNum())->second->getStudents(), message);
    }
    catch (exception& e) {
        cout << e.what() << endl;
        return;
    }

}

void ZoomSys::work() {
    string str_room_id;
    int room_id;
    Room *room_work;
    vector<Student *> stud_inRoom;

    cout << "Enter the room you want to work:" << endl;
    cin >> str_room_id;

    try {
        room_id = stoi(str_room_id);
        if ((this->rooms.find(room_id)) == this->rooms.end()) {
            throw IdException();
        } else {
            room_work = (this->rooms.find(room_id))->second;
            vector<Student *>::iterator it;
            stud_inRoom = room_work->getStudents();

            for (it = stud_inRoom.begin(); it != stud_inRoom.end(); it++) {
                (*it)->Work();
            }
        }

    }
    catch (exception& e) {
        cout << e.what() << endl;
        return;
    }


}

ZoomSys::~ZoomSys() {
    vector<Student *>::iterator it_1;
    vector<Room *>::iterator it_2;

    for (it_1 = this->students.begin(); it_1 != this->students.end(); it_1++) {
        delete *it_1;
    }

    for (it_2 = this->rooms_vec.begin(); it_2 != this->rooms_vec.end(); it_2++) {
        delete *it_2;
    }

}

