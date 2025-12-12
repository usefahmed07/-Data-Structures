
// Stack implemen on Array;
#include <iostream>
using namespace std;

#define SIZE 5; // This is const;

int stack[SIZE] , top = -1;
// كدا هو فاضي هنعمل فانكشن push علشان نضيف عناصر


void push(int value);
int pop(); // تشيل العنصر من TOP
int peek(int value);
void display();




int main()
{
  push(5);
  push(10);
  push(15);
  display();
  pop();
  display();
  peek();
  display();

    return 0;
}




void push(int value)
{
  if (top = SIZE-1)
  {
    cout <<"This Stack is Overflow"<<"\n";
  }
  else 
  {
    top++;
    stack[top] = value; // هنضيف اول عنصر الي STACK
  }
}




int pop()
{
   if (top == -1)
   {
    cout <<"This Stack is underflow<"<<"\n"
   }
   else
   {
     return stack[top--]; // هيبدأ يشوف التوب في STACK و بعدين ينقص واحد
   }
}



int peek()
{
 if (top == -1)
 {
    cout <<"Thiss Stack is underflow"<<"\n";
 }
 else
 {
    return stack[top];
 }
}





void display()
{
    if (top == -1)
    {
        cout <<"Stack underflow"<<"\n";
    }
    else
    {
        for (int i = top; i>=0; i--)
        {
           cout <<stack[i] <<"\n";
        }
    }
}


// Done Stack;
