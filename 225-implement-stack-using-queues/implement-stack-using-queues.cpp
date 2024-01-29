/*
If using 2 queues:
1) push to q2
2) transfer all els from q1 to q2(topwise)
3) now swap q2 with q1
basically idea is to implement lifo(stack) through a queue, therefore pushed element goes to front of queue(last in) and will be removed first(first out)

If using 1 queue:
1)push to q. now el is at rear, we have to somehow get el to front of q
2) trasnfer all els from i =0 to i<q.size()-1 that is if 3 els then 2 will be pushed to q and popped>> push the (front) of the queue,pop and then increment i
3) now el is at front at rest els are at rear
*/

class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i =0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
       // ***wrong q.pop() doesn't return anything int x = q.pop();
       int x = q.front();
       q.pop();
       return x;
    }
    
    int top() {
        return q.front();
        
    }
    
    bool empty() {
        return q.empty();
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */