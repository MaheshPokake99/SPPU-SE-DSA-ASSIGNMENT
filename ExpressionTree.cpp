#include<iostream>
#include<string>
#include<stack>
using namespace std;
class node{
public:
    node*left;
    node*right;
    node*next;
    char data;
    node(char data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
        this->next=NULL;
    }
};
//Creting STACK
class Stack{
public:
    node*head;
    Stack(){
        this->head=NULL;
    }
    void push(node*Head){
        node*root=Head;
        root->next=head;
        head=root;
    }
    void pop(){
        if(!isEmpty()){
            node*temp=head;
            head=head->next;
            delete temp;
        }
    }
    node*top(){
        if(!isEmpty()){
            return head;
        }
    }
    bool isEmpty(){
        return head==NULL;
    }
};
class Tree{
public:
    Stack STACK;
    //cheaking is operator
    bool isOperator(char op){
        if(op=='*' || op=='/' || op=='+' || op=='-'){
            return true;
        }
        return false;
    }
    //Creating tree from postfix
    node*CreatrTreeFromPostfix(string&postfix){
        for(int i=0; i<postfix.length(); i++){
            if(isOperator(postfix[i])==false){
                node*root=new node(postfix[i]);
                STACK.push(root);
            }
            else{
                node*Tright=STACK.top();
                STACK.pop();
                node*Tleft=STACK.top();
                STACK.pop();
                node *root=new node(postfix[i]);
                root->right=Tright;
                root->left=Tleft;
                STACK.push(root);
            }
        }
        return STACK.top();
    }

    //creating tree from prefix
    node*CreateTreefromPrefix(string&prefix){
        for(int i=prefix.length()-1; i>=0; i--){
            if(isOperator(prefix[i])==false){
                node*root=new node(prefix[i]);
                STACK.push(root);
            }
            else{
                node*Tleft=STACK.top();
                STACK.pop();
                node*Tright=STACK.top();
                STACK.pop();
                node*root=new node(prefix[i]);
                root->left=Tleft;
                root->right=Tright;
                STACK.push(root);
            }
        }
        return STACK.top();
    }

    void nonpreorder(node*root){
        while(!STACK.isEmpty() || root!=NULL){
            while(root!=NULL){
                cout<<root->data<<" ";
                STACK.push(root);
                root=root->left;
            }
            root=STACK.top();
            STACK.pop();
            root=root->right;
        }
    }

    //NON RECURSIVE TRAVERSAL
    void noninorder(node* root) {
        while (!STACK.isEmpty() || root != NULL) {
            while (root != NULL) {
                STACK.push(root);
                root = root->left;
            }
            if (!STACK.isEmpty()) {
                root = STACK.top();
                STACK.pop();
                cout << root->data << " ";
                root = root->right;
            }
        }
    }

    // Non-Recursive Traversal - Postorder
    void nonpostorder(node* root) {
        Stack s1;
        stack<int>s2;

        while(root!=NULL){
            s1.push(root);
            s2.push(0);
            root=root->left;
        }
        while(!s1.isEmpty()){
            root=s1.top();
            if(s2.top()==1){
                s1.pop();
                s2.pop();
                cout<<root->data<<" ";
            }
            else{
                s2.top()=1;
                root=root->right;
                while(root!=NULL){
                    s1.push(root);
                    s2.push(0);
                    root=root->left;
                }
            }
        }
    }
    //RECURSIVE TRVERSAL
    void preorder(node*root){
        if(root==NULL) return;
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    void inorder(node*root){
        if(root==NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    void postorder(node*root){
        if(root==NULL) return;
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
};
int main(){
    Tree tree;
    node*root=NULL;
    cout<<"Enter postfix : ";
            string postfix;
            cin>>postfix;
            root=tree.CreatrTreeFromPostfix(postfix);
            // cout<<"Non recursive\n";
            // cout<<"Preorder : ";
            // tree.nonpreorder(root);
            cout<<endl;
            cout<<"inorder : ";
            tree.noninorder(root);
            cout<<endl;
            // cout<<"postorder : ";
            // tree.nonpostorder(root);
            // cout<<endl;
            // cout<<"Recursive\n";
            // cout<<"Preorder : ";
            // tree.preorder(root);
            // cout<<endl;
            // cout<<"inorder : ";
            // tree.inorder(root);
            // cout<<endl;
            // cout<<"postorder : ";
            // tree.postorder(root);
            // cout<<endl;
            // cout<<"Enter prefix : ";
            // string prefix;
            // cin>>prefix;
            // root=tree.CreateTreefromPrefix(prefix);
            cout<<"Non recursive\n";
            cout<<"Preorder : ";
            tree.nonpreorder(root);
            cout<<endl;
            cout<<"inorder : ";
            tree.noninorder(root);
            cout<<endl;
            cout<<"postorder : ";
            tree.nonpostorder(root);
            cout<<endl;
            // cout<<"Recursive\n";
            // cout<<"Preorder : ";
            // tree.preorder(root);
            // cout<<endl;
            // cout<<"inorder : ";
            // tree.inorder(root);
            // cout<<endl;
            // cout<<"postorder : ";
            // tree.postorder(root);
            // cout<<endl;
}