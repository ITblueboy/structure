#include<iostream>
#include<stack>
using namespace std;

template<typename T>

class myqueue
{
  public:
     myqueue(void)
    {

    }
     ~myqueue(void)
     {

     }
     void Pop();
     void Push(const T& data);
  private:
     stack<T> stack1;
     stack<T> stack2;
};

template<class T>
void myqueue<T>::Pop()
{
  T tmp=0;
  if(stack2.empty())
  {
    while(!stack1.empty())
    {
      tmp=stack1.top();
      stack2.push(tmp);
      stack1.pop();
    }
  }
  stack2.pop();
}

template<class T>
void myqueue<T>::Push(const T& data)
{
  stack1.push(data);
}
