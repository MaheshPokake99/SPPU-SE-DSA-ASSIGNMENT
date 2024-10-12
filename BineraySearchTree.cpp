#include<iostream>
using namespace std;
class node{
public:
    node*left;
    node*right;
    int val;
    node(int val){
        this->left=NULL;
        this->right=NULL;
        this->val=val;
    }
};
class Tree{
public:
    node*head;
    Tree(){
        this->head=NULL;
    }
    //Insert element in tree
    node*Insert(node*root,int val){
        if(root==NULL){
            root=new node(val);
        }
        else{
            if(val<root->val){
                root->left=Insert(root->left,val);
            }
            if(val>root->val){
                root->right=Insert(root->right,val);
            }
        }
        return root;

    }
    //inorder traversal
    void inorder(node*root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }

    //delet element
    node*findmin(node*root){
        while(root->left!=NULL){
            root=root->left;
        }
        return root;
    }
    node*Delete(node*root,int val){
        if(root==NULL){
            return NULL;
        }
        if(val<root->val){
            root->left=Delete(root->left,val);
        }
        else if(val>root->val){
            root->right=Delete(root->right,val);
        }
        else{
            if(root->left==NULL){
                node*temp=root->right;
                delete root;
                return temp;
            }
            else if(root->right==NULL){
                node*temp=root->left;
                delete root;
                return temp;
            }
            node*temp=findmin(root->right);
            root->val=temp->val;
            root->right=Delete(root->right,temp->val);
        }
        return root;
    }

    //searching element in tree
    void search(node*root,int val){
        if(root==NULL) return;
        if(root->val==val){
            cout<<"Value is present"<<endl;
            return;
        }
        if(root->val>val){
            search(root->left,val);
        }
        else{
            search(root->right,val);
        }
    }

    //depth of tree
    int TreeDepth(node*root){
        if(root==NULL){
            return 0;
        }
        else{
            int leftDepth=TreeDepth(root->left);
            int rightDepth=TreeDepth(root->right);
            return max(leftDepth,rightDepth)+1;
        }
    }
    //mirror image
    node*Mirror(node*root){
        if(root==NULL) return NULL;
        swap(root->left,root->right);
        Mirror(root->left);
        Mirror(root->right);
        return root;
    }

    //create copy of tree
    node*COPY(node*root){
        if(root=NULL) return NULL;
        node*temp=new node(root->val);
        temp->left=COPY(root->left);
        temp->right=COPY(root->right);
        return root;
    }
    //leaf node
    void Leaf(node*root){
        if(root->left==NULL && root->right==NULL){
            cout<<root->val<<" ";
            return;
        }
        Leaf(root->left);
        Leaf(root->right);
    }
};
int main(){
    Tree tree;
    node*root=NULL;
    cout<<"Enter len : ";
    int len;
    cin>>len;
    int ele;
    cout<<"Enter element : ";
    for(int i=1; i<=len; i++){
        cin>>ele;
        root=tree.Insert(root,ele);
    }
    tree.inorder(root);
    cout<<endl;
    int value;
    cout<<"Enter value : ";
    cin>>value;
    tree.search(root,value);
    cout<<endl;
    root=tree.Delete(root,value);
    tree.inorder(root);
    cout<<"Depth : "<<tree.TreeDepth(root)<<endl;
    root=tree.Mirror(root);
    tree.inorder(root);
    cout<<endl;
    cout<<"Leaf : ";
    tree.Leaf(root);

}