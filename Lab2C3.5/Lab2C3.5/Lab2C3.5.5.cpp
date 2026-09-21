#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;


template <typename DataType>
struct Node {
    DataType _data;
    Node* _pNext;

    Node(DataType data) : _data(data), _pNext(nullptr) {}
};

struct Student {
    string code;           
    string name;            
    string className;       
    string dob;            
    float averageScore;    

    Student(string c, string n, string cls, string d, float score)
        : code(c), name(n), className(cls), dob(d), averageScore(score) {}
};

template <typename DataType>
class LinkedList {
private:
    Node<DataType>* _head;

public:
    LinkedList() : _head(nullptr) {}

    void append(DataType data) {
        Node<DataType>* newNode = new Node<DataType>(data);
        if (!_head) {
            _head = newNode;
        }
        else {
            Node<DataType>* temp = _head;
            while (temp->_pNext) {
                temp = temp->_pNext;
            }
            temp->_pNext = newNode;
        }
    }

    void print() const {
        Node<DataType>* temp = _head;
        while (temp) {
            cout << temp->_data.code << " - " << temp->_data.name << " - "
                << temp->_data.className << " - " << temp->_data.dob << " - "
                << temp->_data.averageScore << endl;
            temp = temp->_pNext;
        }
    }

    void printPassingStudents() const {
        Node<DataType>* temp = _head;
        cout << "Students with average score >= 5:" << endl;
        while (temp) {
            if (temp->_data.averageScore >= 5) {
                cout << temp->_data.name << " (" << temp->_data.code
                    << ") - Average Score: " << temp->_data.averageScore << endl;
            }
            temp = temp->_pNext;
        }
    }

    Student* searchStudentByCode(const string& code) {
        Node<DataType>* temp = _head;
        while (temp) {
            if (temp->_data.code == code) {
                return &temp->_data; 
            }
            temp = temp->_pNext;
        }
        return nullptr; 
    }

    void deleteStudentByCode(const string& code) {
        Node<DataType>* temp = _head;
        Node<DataType>* prev = nullptr;

        while (temp) {
            if (temp->_data.code == code) {
                if (prev) {
                    prev->_pNext = temp->_pNext;
                }
                else {
                    _head = temp->_pNext; 
                }
                delete temp;
                cout << "Student with code " << code << " deleted." << endl;
                return;
            }
            prev = temp;
            temp = temp->_pNext;
        }
        cout << "Student with code " << code << " not found." << endl;
    }

    void updateStudentScore(const string& code, float newScore) {
        Student* student = searchStudentByCode(code);
        if (student) {
            student->averageScore = newScore;
            cout << "Updated score for student " << code << " to " << newScore << endl;
        }
        else {
            cout << "Student with code " << code << " not found." << endl;
        }
    }

    ~LinkedList() {
        while (_head) {
            Node<DataType>* temp = _head;
            _head = _head->_pNext;
            delete temp;
        }
    }
};

int main() {
    LinkedList<Student> students; 

    string code, name, className, dob;
    float averageScore;
    char cont;

    do {
        cout << "Enter student code (11 characters): ";
        cin >> code;
        cin.ignore(); 
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter class: ";
        getline(cin, className);
        cout << "Enter date of birth (YYYY-MM-DD): ";
        getline(cin, dob);
        cout << "Enter average score (0 - 10): ";
        cin >> averageScore;

        students.append(Student(code, name, className, dob, averageScore));

        cout << "Do you want to add another student? (y/n): ";
        cin >> cont;
    } while (cont == 'y' || cont == 'Y');

    cout << "\nStudent List:\n";
    students.print();

    students.printPassingStudents();

    string codeToSearch;
    cout << "\nEnter student code to search: ";
    cin >> codeToSearch;
    Student* foundStudent = students.searchStudentByCode(codeToSearch);
    if (foundStudent) {
        cout << "Found student: " << foundStudent->name
            << " with average score: " << foundStudent->averageScore << endl;
    }
    else {
        cout << "Student not found." << endl;
    }

    string codeToDelete;
    cout << "\nEnter student code to delete: ";
    cin >> codeToDelete;
    students.deleteStudentByCode(codeToDelete);

    string codeToUpdate;
    float newScore;
    cout << "\nEnter student code to update score: ";
    cin >> codeToUpdate;
    cout << "Enter new score: ";
    cin >> newScore;
    students.updateStudentScore(codeToUpdate, newScore);

    cout << "\nFinal Student List:\n";
    students.print();

    return 0;
}
