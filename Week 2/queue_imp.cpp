#include<iostream>
#include<deque>
#include<stdexcept>


template <typename T>
class Queue{
    std::deque<T> v;
    public:
    Queue() =default;
    ~Queue()=default;

    void enqueue(const T &value){
        v.push_back(value);
    }
    void dequeue(){
        if(v.empty()) throw std::underflow_error("queue is empty");
        else v.pop_front();
    }
    T& front(){
        if(v.empty()) throw std::underflow_error("queue is empty");
        else return v.front();
    }
    const T& front() const {
        if(v.empty()) throw std::underflow_error("queue is empty");
        else return v.front();
    }
    T& back(){
        if(v.empty()) throw std::underflow_error("queue is empty");
        else return v.back();
    }
    const T& back() const {
        if(v.empty()) throw std::underflow_error("queue is empty");
        else return v.back();
    }
    bool empty() const{
        return v.empty();
    }
    std::size_t size() const{
        return v.size();
    }
    bool operator==(const Queue& s) const{
        return v==s.v;
    }
    bool operator!=(const Queue& s) const{
        return !(*this==s);
    }
    friend std::ostream& operator<<(std::ostream& os,const Queue<T>& s){
        os<<'[';
        for (auto i=1;i<s.v.size()+1;i++){
            os<<s.v[i-1];
            if(i<s.v.size()) os<<", ";
        }
        os<<']';
        return os;
    }
};


int main(){
    Queue<int> q;
    q.enqueue(10);
    std::cout<<q<<"\n";
    q.enqueue(20);
    std::cout<<q<<"\n";
    q.enqueue(30);
    std::cout<<q<<"\n";
    q.dequeue();
    std::cout<<q<<"\n";
    q.enqueue(40);
    std::cout<<q<<"\n";
    q.dequeue();
    std::cout<<q<<"\n";
}