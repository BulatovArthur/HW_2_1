#include <iostream>

using namespace std;

struct List 
{
  int d;
  List *next;
};

void Print(List *first, int argc) 
{
  if (argc != 1)
  {
  List *p = first;
  while (p) 
  {
    cout << p->d << " -> ";
    p = p->next;
  }
  cout << "NULL" << endl;
  }
  else
  {
    cout << "The list is empty" << endl;
  }
}

int main(int argc, char *argv[]) 
{
  cout << "Operation: " << endl;
  cout << "1. Print the list" << endl;
  cout << "2. Add items to the list" << endl;
  cout << "3. Delete the item" << endl;
  cout << "4. Find item positions" << endl;
  cout << "5. Replace the element with another one" << endl;
  cout << "6. Sort the list items" << endl;
  cout << "7. Quit the program" << endl;

  int *array=new int[argc-1];

  for(int i = 1; i < argc; i++)
  {
    array[i]=atoi(argv[i]);
  }

//  List *first = nullptr;  // указатель на начало будущего списка, пока список пуст,
                      // и указатель явно задан равным константе null
  // u = first это указатель
  List *first = new List;
//  first = new List;  // выделяем память под элемент списка (адрес)

  first->d = *(array + 1);  // заполняем поля с данными (здесь всего одно поле)
  first->next = nullptr;  // указатель на следующий элемент пуст

  List *last;  // вспомогательная переменная-указатель для хранения последнего
            // элемента списка 
  last = first;    // сейчас последний элемент списка совпадает с его началом

  for (int i = 2; i < argc; i++) 
  {
    
    last->next = new List;  // выделяем место в памяти для следующего элемента
                           // списка и перенаправляем указатель х на выделенную
                           // область памяти
    last = last->next;
    last->d = *(array + i);  // затем определяем значение этого элемента списка
    last->next = nullptr;
  }
 
  int op = 0;
  cin >> op;

  switch(op) 
  {
    case 1:
      Print(first, argc);
      break;
    case 2:
      break;
  }

  delete first; 
  delete [] array;  
  return 0;
}
