#include <iostream>

using namespace std;

struct Data
{
  char a;
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


int main (int argc, char *argv[])
{
  List *u = nullptr; // указатель на начало будущего списка, пока список пуст, и указатель явно задан равным константе null
  // u это указатель

  u = new List; // выделяем память под элемент списка (адрес)
  u->d.a = (*argv[1]); // заполняем поля с данными (здесь всего одно поле)
  u->next = nullptr; // указатель на следующий элемент пуст

  List *x; // вспомогательная переменная-указатель для хранения последнего элемента списка
  x = u; // сейчас последний элемент списка совпадает с его началом

  for (int i = 2; i < argc; i++)
  {
    x->next = new List; // выделяем место в памяти для следующего элемента списка и перенаправляем указатель х на выделенную область памяти
    x = x->next;
    
    x->d.a = (*argv[i]); // затем определяем значение этого элемента списка
    x->next = nullptr;
  }

  Print(u);

  return 0;
}

