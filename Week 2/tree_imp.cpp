#include<iostream>
#include<queue>


struct  Node{
    int val;
    Node *left,*right;
    public:
    Node(){
        val=0;
        left=right=NULL;
    }
    Node(int x){
        val=x;
        left=right=NULL;
    }
};



class Tree{
    
    // this is an helper function  
    void preorder(Node* curr){
        if(curr == nullptr) return;
        
        std::cout << curr->val << ' ';
        preorder(curr->left);
        preorder(curr->right);
    }
    
    void postorder(Node* curr){
        if(curr == nullptr) return;
        
        postorder(curr->left);
        postorder(curr->right);
        std::cout << curr->val << ' ';
    }
    
    void inorder(Node* curr){
        if(curr == nullptr) return;
        
        inorder(curr->left);
        std::cout << curr->val << ' ';
        inorder(curr->right);
    }
    void levelOrder(Node* curr){
        if(curr==nullptr) return;
        std::queue<Node*> q;
        q.push(curr);
        while(!q.empty()){
            Node* n= q.front();
            q.pop();
            if(n->left) q.push(n->left);
            if(n->right) q.push(n->right);
            std::cout<<n->val<<' ';
        }
    }
    
    public:
    Node* root;
    Tree(){
        root=NULL;
    }
    Tree(int x){
        root=new Node(x);
    }
    ~Tree(){

    }
    void insert(){
        
    }
    void preorder(){
        preorder(root);
    }
    void postorder(){
        postorder(root);
    }
    void inorder(){
        inorder(root);
    }
    void levelOrder(){
        levelOrder(root);
    }
};

int main(){
    Tree t(1);
    t.root->left=new Node(2);
    t.root->right=new Node(3); 
    t.root->left->left=new Node(4);
    t.root->left->right=new Node(5);
    t.root->right->right=new Node(6);

    t.preorder();
    std::cout<<'\n';
    t.inorder();
    std::cout<<'\n';
    t.postorder();
    std::cout<<'\n';
    t.levelOrder();
    std::cout<<'\n';
}