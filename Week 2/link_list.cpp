#include<iostream>

struct  Node{
    int val;
    Node* next;
    Node(int x){
        val=x;
        next=NULL;
    }
};

class LinkedList{
    Node* head;
    public:
    LinkedList(){
        head=NULL;
    }
    LinkedList(int x){
        head = new Node(x);
    }
    ~LinkedList(){
        Node* curr=head;
        while(curr){
            Node* temp=curr;
            curr=curr->next;
            delete temp;
        }
    }
    void insert(int x){
        Node* ans = new Node(x);

        if(head == NULL){
            head = ans;
            return;
        }

        Node* s = head;
        while(s->next) s = s->next;
        s->next = ans;
    }
    void traverse(){
        Node* s= head;
        while(s) {
            std::cout<<s->val<<" -> ";
            s=s->next;
        }
        std::cout<<"NULL\n";
    }
    int count(){
        int ans=0;
        Node* s= head;
        while(s) {
            s=s->next;
            ans++;
        }
        return ans;
    }

};


int main(){
    LinkedList l(5);
    l.insert(10);
    l.insert(15);
    l.insert(20);
    l.traverse();
    std::cout<<l.count()<<"\n";
}