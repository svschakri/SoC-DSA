#include<iostream>
#include<vector>
#include<stdexcept>


template <typename T>
class Stack{
    std::vector<T> v;
    public:
    Stack() =default;
    ~Stack()=default;
    Stack(std::initializer_list<T> v1){
        v=v1;
    }
    void push(const T &value){
        v.push_back(value);
    }
    void pop(){
        if(v.empty()) throw std::underflow_error("stack is empty");
        else {
            v.pop_back();
        }
    }
    T& top(){
        if(v.empty()) throw std::underflow_error("stack is empty");
        else return v.back();
    }
    const T& top() const {
        if(v.empty()) throw std::underflow_error("stack is empty");
        else return v.back();
    }
    bool empty() const{
        return v.empty();
    }
    std::size_t size() const{
        return v.size();
    }
    bool operator==(const Stack& s) const{
        return v==s.v;
    }
    bool operator!=(const Stack& s) const{
        return !(*this==s);
    }
    friend std::ostream& operator<<(std::ostream& os,const Stack<T>& s){
        os<<'[';
        for (auto i=s.v.size();i>0;i--){
            os<<s.v[i-1];
            if(i>1) os<<", ";
        }
        os<<']';
        return os;
    }
};



int main(){
    Stack<int> s;
    s.push(10);
    std::cout<<s<<"\n";
    s.push(20);
    std::cout<<s<<"\n";
    s.push(30);
    std::cout<<s<<"\n";
    s.pop();
    std::cout<<s<<"\n";
    s.push(40);
    std::cout<<s<<"\n";
    s.pop();
    std::cout<<s<<"\n";
}