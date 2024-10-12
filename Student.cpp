#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Student{
public:
    string name;
    int roll;
    float cgpa;
};
class data{
public:
    //bubble sort for student roll number
    void bubble(vector<Student>&students){
        int num=students.size();
        for(int i=0; i<num-1; i++){
            for(int j=0; j<num-1-i; j++)
            if(students[j].roll>students[j+1].roll){
                swap(students[j].roll,students[j+1].roll);
                swap(students[j].name,students[j+1].name);
                swap(students[j].cgpa,students[j+1].cgpa);
            }
        }
    }
    //arrange student by name
    void insertion(vector<Student>&students){
        int n=students.size();
        for(int i=1; i<n; i++){
            Student key=students[i];
            int j=i-1;
            while(j>=0 && key.name<students[j].name){
                students[j+1]=students[j];
                j=j-1;
            }
            students[j+1]=key;
        }
    }
    int partition(vector<Student>& students, int low, int high) {
        Student pivot = students[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            if (students[j].cgpa > pivot.cgpa) {
                i++;
                swap(students[i], students[j]);
            }
        }
        swap(students[i + 1], students[high]);
        return (i + 1);
    }

    void quick(vector<Student>&students,int low,int high){
        if(low<high){
            int pi=partition(students,low,high);
            quick(students,low,pi-1);
            quick(students,pi+1,high);
        }
    }
    //search by cgpa student
    void search(vector<Student>&students){
        cout<<"Enter CGPA : ";
        float cgpa;
        cin>>cgpa;
        for(int i=0; i<students.size(); i++){
            if(students[i].cgpa==cgpa){
                cout<<"Student Detils are :\n";
                cout<<"Name\tRoll\tCGPA\n";
                cout<<students[i].name<<"\t"<<students[i].roll<<"\t"<<students[i].cgpa;
            }
            cout<<endl;
        }
    }
    //search by name
    void bineary(vector<Student>&students){
        int low=0;
        int high=students.size();
        cout<<"Enter name : ";
        string name;
        cin>>name;
        while(low<=high){
            int mid=(low+high)/2;
            if(students[mid].name==name){
                cout<<"Name\tRoll\tCGPA\n";
                cout<<students[mid].name<<"\t"<<students[mid].roll<<"\t"<<students[mid].cgpa;
            }
            cout<<endl;
            if(students[mid].name>name){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
    }
    void display(vector<Student>&students){
        cout<<"Name\tRoll\tCGPA\n";
        for(int i=0; i<students.size(); i++){
            cout<<students[i].name<<"\t"<<students[i].roll<<"\t"<<students[i].cgpa<<endl;
        }
        cout<<endl;
    }
};
int main(){
    data st;
    vector<Student>students;
    cout<<"Enter Number of student data : ";
    int num;
    cin>>num;
    //taking input from user
    for(int i=0; i<num; i++){
        Student student;
        cout<<"Enter Roll No,Name,CGPA for student "<<i+1<<" : ";
        cin>>student.roll>>student.name>>student.cgpa;
        students.push_back(student);
    }
    cout<<"1.Bubble sort\n2.Inseration sort\n3.Quick sort\n4.Liner search\n5.Bineary search\n6.Display\n";
    int choice;
    do{
        cout<<"Enter choice : ";
        cin>>choice;
        cout<<endl;
        switch(choice){
            case 1:
            st.bubble(students);
            st.display(students);
            break;
            case 2:
            st.insertion(students);
            st.display(students);
            break;
            case 3:
            st.quick(students,0,students.size());
            cout<<"Enter Number to topper list : ";
            int n;
            cin>>n;
            cout<<"\nClass Topper"<<endl;
            cout<<"Name\tRoll\tCGPA\n";
            for(int i=0; i<n; i++){
                cout<<students[i].name<<"\t"<<students[i].roll<<"\t"<<students[i].cgpa<<endl;;
            }
            cout<<endl;
            break;
            case 4:
            st.search(students);
            break;
            case 5:
            st.insertion(students);
            st.bineary(students);
            break;
            case 6:
            st.display(students);
        }

    }while(choice<=6);
}