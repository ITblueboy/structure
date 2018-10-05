#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class mystack
{
  public:
  mystack(void)
  {

  }
  ~mystack(void)
  {

  }
  void Pop();
  void Push(const T& data);
  private:
  queue<T> queue1;
  queue<T> queue2;
};

template<class T>
void mystack<T>::Pop()
{
  if(queue1.size()==0&&queue2.size()!=0)
  {
    int i=queue2.size();
    while(i>1)
    {
      queue1.push(queue2.front());
      queue2.pop();
      i--;
    }
    queue2.pop();
  }
  else if(queue2.size()==0&&queue1.size()!=0)
  {
    int i=queue1.size();
    while(i>1)
    {
      queue2.push(queue1.front());
      queue1.pop();
      i--;
    }
    queue1.pop();
  }
}

template<class T>
void mystack<T>::Push(const T& data)
{
  if(!queue1.empty())
  {
    queue1.push(data);
  }
  else 
  {
    queue2.push(data);
  }
}
