#include <iostream>
#include <cstring>
using namespace std;

#define MAX_SUBJECTS 10
#define MAX_STUDENTS 100

struct Subject {
    char code[10];
    char name[30];
    int credits;
    float score;
};

struct Student {
    char code[12];
    char name[50];
    char dob[11];
    Subject subjects[MAX_SUBJECTS];
    int numSubjects;
};

void readStudents(Student students[], int& n) {
    cout << "So Luong Sinh Vien: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "MaSV: ";
        cin.getline(students[i].code, 12);
        cout << "HoTen: ";
        cin.getline(students[i].name, 50);
        cout << "NgaySinh: ";
        cin.getline(students[i].dob, 11);
        cout << "SoMonHoc: ";
        cin >> students[i].numSubjects;

        for (int j = 0; j < students[i].numSubjects; j++) {
            cout << "MaMon: ";
            cin >> students[i].subjects[j].code;
            cout << "TenMon: ";
            cin.ignore();
            cin.getline(students[i].subjects[j].name, 30);
            cout << "SoTinChi: ";
            cin >> students[i].subjects[j].credits;
            cout << "Diem: ";
            cin >> students[i].subjects[j].score;
        }
    }
}

void updateStudentName(Student students[], int n, const char* studentCode, const char* newName) {
    for (int i = 0; i < n; i++) {
        if (strcmp(students[i].code, studentCode) == 0) {
            strcpy_s(students[i].name, newName);
            cout << "Doi ten Sinh Vien: " << newName << endl;
            return;
        }
    }
    cout << "Ma Sinh Vien " << studentCode << " khong tim thay." << endl;
}

void sortStudentsByNameDescending(Student students[], int n) {
    for (int i = 1; i < n; i++) {
        Student key = students[i];
        int j = i - 1;
        while (j >= 0 && strcmp(students[j].name, key.name) < 0) {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
    }
    cout << "Ten Sinh Vien duoc sap xep." << endl;
}

void deleteStudentByLastName(Student students[], int& n, const char* lastName) {
    sortStudentsByNameDescending(students, n);

    for (int i = 0; i < n; i++) {
        char* studentLastName = strrchr(students[i].name, ' ') + 1;
        if (strcmp(studentLastName, lastName) == 0) {
            for (int j = i; j < n - 1; j++) {
                students[j] = students[j + 1];
            }
            n--;
            cout << "Xoa Sinh Vien Ho: " << lastName << endl;
            return;
        }
    }
    cout << "Sinh Vien Ho " << lastName << " khong tim thay." << endl;
}

void sortStudentsByAverageScore(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            float avg1 = 0, avg2 = 0;
            for (int k = 0; k < students[minIndex].numSubjects; k++) {
                avg1 += students[minIndex].subjects[k].score;
            }
            avg1 /= students[minIndex].numSubjects;

            for (int k = 0; k < students[j].numSubjects; k++) {
                avg2 += students[j].subjects[k].score;
            }
            avg2 /= students[j].numSubjects;

            if (avg2 < avg1) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            Student temp = students[i];
            students[i] = students[minIndex];
            students[minIndex] = temp;
        }
    }
    cout << "Ten Sinh Vien duoc sap xep diem trung binh tang dan." << endl;
}

void listScholarshipStudents(Student students[], int n) {
    cout << "Sinh Vien dc hoc bong:" << endl;
    for (int i = 0; i < n; i++) {
        float avgScore = 0;
        bool eligible = true;
        for (int j = 0; j < students[i].numSubjects; j++) {
            avgScore += students[i].subjects[j].score;
            if (students[i].subjects[j].score < 5) {
                eligible = false;
                break;
            }
        }
        avgScore /= students[i].numSubjects;

        if (eligible && avgScore >= 7.0) {
            cout << students[i].name << endl;
        }
    }
}

void sortStudentsByYearOfBirth(Student students[], int n) {
    cout << "Sinh Vien duoc sap xep theo nam sinh (Placeholder for QuickSort implementation)." << endl;
}

void printStudents(const Student students[], int n) {
    cout << "Danh Sach Sinh Vien:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "MaSV: " << students[i].code << endl
            << ", HoTen: " << students[i].name
            << ", NgaySinh: " << students[i].dob
            << ", SoMonHoc: " << students[i].numSubjects << endl << endl;
        for (int j = 0; j < students[i].numSubjects; j++) {
            cout << "    MaMon: " << students[i].subjects[j].code
                << ", TenMon: " << students[i].subjects[j].name
                << ", SoTinChi: " << students[i].subjects[j].credits
                << ", Diem: " << students[i].subjects[j].score << endl; << endl;
        }
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int n = 0;
    readStudents(students, n);
    updateStudentName(students, n, "S123456789", "New Name");
    sortStudentsByNameDescending(students, n);
    deleteStudentByLastName(students, n, "Doe");
    sortStudentsByAverageScore(students, n);
    listScholarshipStudents(students, n);
    sortStudentsByYearOfBirth(students, n);
    printStudents(students, n);
    return 0;
}
