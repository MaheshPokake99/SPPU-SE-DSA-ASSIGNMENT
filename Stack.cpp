#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class node{
public:
    char data;
    node*next;
    node(char data){
        this->data=data;
        this->next=NULL;
    }
};
class Stack{
public:
    node*head;
    int size;
    Stack(){
        head=NULL;
        size=0;
    }
    void Push(char val){
        node*temp=new node(val);
        temp->next=head;
        head=temp;
        size++;
    }
    void pop(){
        if(head==NULL){
            cout<<"stack is empty : "<<endl;
            return;
        }
        head=head->next;
        size--;
    }
    int top(){
        if(head==NULL){
            cout<<"stack is empty "<<endl;
            return -1;
        }
        return head->data;
    }
    int SIZE(){
        return size;
    }
};
class implementation{
public:
    Stack stack;
    //piority cheaking of element
    int piority(char op){
        if(op=='*' || op=='/') return 2;
        else if(op=='+' || op=='-') return 1;
        else return -1;
    }
    //cheaking is not number or number
    bool cheakChar(char c){
        if(c=='/' || c=='*' || c=='-' || c=='+' || c=='(' || c==')'){
            return false;
        }
        return true;
    }
    //evalution solving
    int solve(int val1,int val2,char op){
        if(op=='+') return val1+val2;
        if(op=='-') return val1-val2;
        if(op=='*') return val1*val2;
        if(op=='/') return val1/val2;
    }
    //infix to postfix
    string infixToPostfix(string&infix){
        string postfix="";
        for(int i=0; i<infix.length(); i++){
            if(cheakChar(infix[i])==true){
                postfix+=infix[i];
            }
            else if(infix[i]=='('){
                stack.Push(infix[i]);
            }
            else if(infix[i]==')'){
                while(stack.SIZE()!=0 && stack.top()!='('){
                    postfix+=stack.top();
                    stack.pop();
                }
                stack.pop(); //removing from stack (
            }
            else{
                while(stack.SIZE()!=0 && piority(infix[i])<=piority(stack.top())){
                    postfix+=stack.top();
                    stack.pop();
                }
                stack.Push(infix[i]);
            }
        }
        while(stack.SIZE()!=0){
            postfix+=stack.top();
            stack.pop();
        }
        return postfix;
    }

    //infix to prefix
    string InfixToPrefix(string&infix){
        //reverse string and change the backet
        for(int i=0; i<infix.size(); i++){
            if(infix[i]=='('){
                infix[i]=')';
            }
            else if(infix[i]==')'){
                infix[i]='(';
            }
        }
        string prefix="";
        reverse(infix.begin(),infix.end());
        for(int i=0; i<infix.length(); i++){
            if(cheakChar(infix[i])==true){
                prefix+=infix[i];
            }
            else if(infix[i]=='('){
                stack.Push(infix[i]);
            }
            else if(infix[i]==')'){
                while(stack.SIZE()!=0 && stack.top()!='('){
                    prefix+=stack.top();
                    stack.pop();
                }
                stack.pop();
            }
            else{
                while(stack.SIZE()!=0 && piority(infix[i])<=piority(stack.top())){
                    prefix+=stack.top();
                    stack.pop();
                }
                stack.Push(infix[i]);
            }
        }
        while (stack.SIZE()!=0){
            prefix+=stack.top();
            stack.pop();
        }
        //again reverse the stirng to right ans
        reverse(prefix.begin(),prefix.end());
        return prefix;
        
    }
    //postfix evalution
    int evaluatePostfix(string&postfix){
        for(int i=0; i<postfix.length(); i++){
            if(cheakChar(postfix[i])==true){
                stack.Push(postfix[i]-'0');
            }
            else{
                int val2=stack.top();
                stack.pop();
                int val1=stack.top();
                stack.pop();
                switch(postfix[i]){
                    case '+':
                    stack.Push(val1+val2);
                    break;
                    case '-':
                    stack.Push(val1-val2);
                    break;
                    case '*':
                    stack.Push(val1*val2);
                    break;
                    case '/':
                    stack.Push(val1/val2);
                    break;
                }
            }
        }
        return stack.top();
    }
    //evalution prefix
    int evaluteprefix(string&prefix){
        reverse(prefix.begin(),prefix.end());
        for(int i=0; i<prefix.length() ;i++){
            if(cheakChar(prefix[i])==true){
                stack.Push(prefix[i]-'0');
            }
            else{
                int val1=stack.top();
                stack.pop();
                int val2=stack.top();
                stack.pop();
                switch(prefix[i]){
                    case '+':
                    stack.Push(val1+val2);
                    break;
                    case '-':
                    stack.Push(val1-val2);
                    break;
                    case '*':
                    stack.Push(val1*val2);
                    break;
                    case '/':
                    stack.Push(val1/val2);
                    break;
                }
            }
        }
        return stack.top();
    }
};
int main(){
    implementation infix;
    cout<<"Enter infix : ";
    string expression;
    cin>>expression;
    string postfix=infix.infixToPostfix(expression);
    string prefix=infix.InfixToPrefix(expression);
    cout<<"Postfix expression : "<<postfix<<endl;
    cout<<"Prefix expression : "<<prefix<<endl;
    cout<<"postfix evalution : "<<infix.evaluatePostfix(postfix)<<endl;
    cout<<"Prefix evalution : "<<infix.evaluteprefix(prefix)<<endl;
}
