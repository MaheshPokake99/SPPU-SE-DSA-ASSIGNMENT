#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Student {
public:
    int roll;
    string name;
    int division;
};

class StudentInfo {
public:
    fstream StudentData;
    Student student;
    // Create File
    void createFile() {
        StudentData.open("Data.txt", ios::out);
        if (StudentData.is_open()) {
            StudentData << "Roll NO.\tName\tDivision\n";
            StudentData.close();
            cout << "File created successfully." << endl;
        } else {
            cout << "Error creating file." << endl;
        }
    }

    // Clear File
    void clear() {
        StudentData.open("ldco.txt", ios::out | ios::trunc);
        StudentData.close();
        cout << "File cleared successfully." << endl;
    }

    // Insert Student Data in File
    void Insert() {
        StudentData.open("Data.txt", ios::app);
        if (StudentData.is_open()) {
            int number;
            cout << "Enter number of students : ";
            cin >> number;
            for (int i = 1; i <= number; i++) {
                cout << "Enter Student Roll, Name, Division for " << i << " : ";
                cin >> student.roll >> student.name >> student.division;
                StudentData << student.roll << "\t\t" << student.name << "\t\t" << student.division << "\n";
            }
            StudentData.close();
        } else {
            cout << "File is not open.." << endl;
        }
    }

    // Display Student Data
    void Display() {
        StudentData.open("ldco.txt", ios::in);
        if (StudentData.is_open()) {
            string data;
            while (getline(StudentData, data)) {
                cout << data << endl;
            }
            StudentData.close();
        } else {
            cout << "File is not opened.." << endl;
        }
    }

    // Search Data in File
    void search(int Roll) {
        StudentData.open("Data.txt", ios::in);
        if (StudentData.is_open()) {
            string data;
            bool found = false;
            while (getline(StudentData, data)) {
                stringstream input(data);  
                input >> student.roll >> student.name >> student.division;
                if (Roll == student.roll) {
                    cout << "Record found:\n" << data << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Record not found." << endl;
            }
            StudentData.close();
        } else {
            cout << "File is not open.." << endl;
        }
    }

    // Delete Record from File
    void Delete(int Roll) {
        fstream temp;
        StudentData.open("Data.txt", ios::in);
        temp.open("Delet.txt", ios::out);
        if (StudentData.is_open() && temp.is_open()) {
            string data;
            while (getline(StudentData, data)) {
                stringstream input(data);
                input >> student.roll >> student.name >> student.division;
                if (Roll != student.roll) {
                    temp << data << "\n";
                }
            }
            StudentData.close();
            temp.close();
            remove("Data.txt");
            rename("Delet.txt", "Data.txt");
            cout << "Record deleted successfully." << endl;
        } else {
            cout << "File is not open.." << endl;
        }
    }

    // Modify Record
    void modify(int number) {
        fstream temp;
        StudentData.open("Data.txt", ios::in);
        temp.open("temp.txt", ios::out);
        if (StudentData.is_open() && temp.is_open()) {
            string line;
            while (getline(StudentData, line)) {
                stringstream input(line);
                Student student;
                input >> student.roll >> student.name >> student.division;
                if (number == student.roll) {
                    cout << "Record found. Enter new data: " << endl;
                    cout << "Enter Roll NO, Name, Division: ";
                    cin >> student.roll >> student.name >> student.division;
                    temp << student.roll << "\t" << student.name << "\t" << student.division << "\n";
                } else {
                    temp << line << "\n";
                }
            }
            StudentData.close();
            temp.close();
            remove("Data.txt");
            rename("temp.txt", "Data.txt");
            cout << "Record modified successfully." << endl;
        } else {
            cout << "File is not open." << endl;
        }
    }

    // Delete File
    void deleteFile() {
        if (remove("Data.txt") == 0) {
            cout << "File deleted successfully." << endl;
        } else {
            cout << "Error deleting the file." << endl;
        }
    }
};

int main() {
    StudentInfo S;

    int choice, rollNumber;
    do {
        cout << "MENU:\n1) CREATE FILE\n2) CLEAR FILE\n3) INSERT\n4) DISPLAY\n5) SEARCH\n6) DELETE\n7) MODIFY\n8) EXIT" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                S.createFile();
                break;
            case 2:
                S.clear();
                break;
            case 3:
                S.Insert();
                break;
            case 4:
                S.Display();
                break;
            case 5:
                cout << "Enter Roll number to search: ";
                cin >> rollNumber;
                S.search(rollNumber);
                break;
            case 6:
                cout << "Enter Roll number to delete: ";
                cin >> rollNumber;
                S.Delete(rollNumber);
                break;
            case 7:
                cout << "Enter Roll number to modify: ";
                cin >> rollNumber;
                S.modify(rollNumber);
                break;
            case 8:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Enter valid choice" << endl;
                break;
        }
    } while (choice != 8);

    return 0;
}
