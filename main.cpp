#include <iostream>

using namespace std;

struct Data 
{
  int a;
};

struct List 
{
  Data d;
  List *next;
};

void Print(List *u) 
{
  List *p = u;
  while (p) 
  {
    cout << p->d.a << " -> ";
    p = p->next;
  }
  cout << "NULL" << endl;
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

  List *u = nullptr;  // указатель на начало будущего списка, пока список пуст,
                      // и указатель явно задан равным константе null
  // u это указатель

  u = new List;  // выделяем память под элемент списка (адрес)
  if (argc < 2)
  {
    cout << "The list is empty" << endl;
  }
  else
  {
    u->d.a = (*argv[1]);  // заполняем поля с данными (здесь всего одно поле)
    u->next = nullptr;  // указатель на следующий элемент пуст

    List *x;  // вспомогательная переменная-указатель для хранения последнего
            // элемента списка
    x = u;    // сейчас последний элемент списка совпадает с его началом

    for (int i = 2; i < argc; i++) 
    {
      x->next = new List;  // выделяем место в памяти для следующего элемента
                           // списка и перенаправляем указатель х на выделенную
                           // область памяти
      x = x->next;

      x->d.a = (*argv[i]);  // затем определяем значение этого элемента списка
      x->next = nullptr;
    }
 
    int op = 0;
    cin >> op;

    switch(op) 
    {
      case 1:
        Print(u);
        break;
      case 2:
        break;
    }
  } 
  return 0;
}

