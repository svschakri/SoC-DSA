
template<typename T>

class CircularQueue{
    int capacity,first,last,count;
    T* arr;
    public:
    CircularQueue(int sz){
        capacity=sz;
        first=last=count=0;
        arr= new T[sz];
    }
    ~CircularQueue(){
        delete[] arr;
    }
    void enqueue(const T &value){
        if(count==capacity) throw std::overflow_error("queue is full");
        else {
            arr[last]=value;
            count++;
            last++;
            last%=capacity;
        }
    }
    void dequeue(){
        if(count==0) throw std::underflow_error("queue is empty");
        else {
            count--;
            if(first==capacity-1) first=0;
            else first++;
        }
    }
    T& front(){
        if(count==0) throw std::underflow_error("queue is empty");
        else return arr[first];
    }
    const T& front() const {
        if(count==0) throw std::underflow_error("queue is empty");
        else return arr[first];
    }
    T& back(){
        if(count==0) throw std::underflow_error("queue is empty");
        else return arr[(last-1+capacity)%capacity];
    }
    const T& back() const {
        if(count==0) throw std::underflow_error("queue is empty");
        else return arr[(last-1+capacity)%capacity];
    }
    bool empty() const{
        return count==0;
    }
    std::size_t size() const{
        return count;
    }
    bool operator==(const CircularQueue& s) const{
        if(count!=s.count) return false;
        for(int i=0;i<count;i++){
            if(arr[(first+i)%capacity]!=s.arr[(s.first+i)%s.capacity]) return false;
        }
        return true;

    }
    bool operator!=(const CircularQueue& s) const{
        return !(*this==s);
    }
    friend std::ostream& operator<<(std::ostream& os,const CircularQueue<T>& s){
        os<<'[';
        for (auto i=0;i<s.count;i++){
            os<<s.arr[(i+s.first)%s.capacity];
            if(i<s.count-1) os<<", ";
        }
        os<<']';
        return os;
    }
};