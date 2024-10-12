#include<iostream>
#include<vector>
using namespace std;
class Queue{
public:
    int front_index;
    int rear_index;
    int size;
    int capacity;
    vector<int>arr;
    Queue(int c){
        front_index=0;
        rear_index=0;
        size=0;
        capacity=c;
        vector<int>v(c);
        arr=v;
    }

    //cheaking empty or not
    bool isEmpty(){
        if(size==0){
            return true;
        }
        return false;
    }

    //cheaking full or not
    bool isFull(){
        if(size==capacity){
            return true;
        }
        return false;
    }

    //enqueue element int queue
    void enqueue(){
        if(isFull()){
            cout<<"Queue is Full"<<endl;
            return;
        }
        cout<<"Enter value : ";
        int val;
        cin>>val;
        arr[rear_index]=val;
        rear_index=(rear_index+1)%capacity;
        size++;
    }

    //remove element from queue
    void dequeuefromfront(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        front_index=(front_index+1)%capacity;
        size--;
    }
    void dequeuefromrear(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        rear_index=(rear_index-1+capacity)%capacity;
        size--;
    }

    //front element
    int front(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        return arr[front_index];
    }

    //rear element
    int rear(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        if(rear_index==0){
            return arr[capacity-1];
        }
        return arr[rear_index-1];
    }

    //display queue
    void display(){
        int i=front_index;
        while(i!=rear_index){
            cout<<arr[i]<<" ";
            i=(i+1)%capacity;
        }
        cout<<endl;
    }
};
int main(){
    int n;
    cout<<"Enter size : ";
    cin>>n;
    Queue q(n);
    int choice;
    do{
        cout<<"1.enqueue\n2.dequeue\n3.display\n4.front\n5.rear\n";
        cout<<"Enter choice : ";
        cin>>choice;
        cout<<endl;
        switch(choice){
            case 1:
            q.enqueue();
            cout<<endl;
            break;
            case 2:
            q.dequeuefromfront();
            break;
            case 3:
            q.display();
            break;
            case 4:
            cout<<q.front()<<endl;
            break;
            case 5:
            cout<<q.rear()<<endl;
            break;
            case 6:
            q.dequeuefromrear();
            break;
        }

    }while(choice<=6);
}