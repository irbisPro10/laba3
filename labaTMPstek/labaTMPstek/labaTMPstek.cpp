// labaTMPstek.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
class stek{
public:
	int n, max;
	int **st;
	/*stek(){
	n = 0;
	}*/
	//Конструктор
	stek(){
		int i;
		st = new int*[100000];
		for (i = 0; i < 100000; i++) st[i] = 0x00;//Обнуляем все указатели
		max = 100000;
		n = 0;//Верхний элемент
	}
	//Проверка не пуст ли стек
	bool isEmpty(){
		if (st[0] == 0x00) return 1;
		else return 0;
	}
	//Добавить элемент сверху
	int push(int *ptr){
		if ((n) != max){
			st[n] = ptr;
			n++;

			return 0;
		}
		else return 1;
	}
	//Вытолкнуть элемент сверху
	int pop(){
		if (!isEmpty()){

			n--;
			delete(st[n]);
			st[n] = 0x00;
			return 0;
		}
		else return 2;
	}
	void print(){
		int p = n - 1;
		if (p < 0) p = 0;
		cout << (st[p] == 0 ? 0 : *st[p]) << endl;
	}
	~stek(){
		delete(st);
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	char c;
	setlocale(LC_ALL, "Rus");
			stek st;

			cout << endl<<"+ - добавить"<<endl<<"- - удалить"<<endl<<"p - печать"<<"0 - выход"<<endl;

			while (1){

				cout << ">> ";
				cin >> c;
				

				if (c == 'p'){
					st.print();
				}
				if (c == '0') break;
				if (c == '+'){
					cout << "> ";
					int *ptr = new int;
					cin >> *ptr;

					if (st.push(ptr) == 0) cout << "Добавлено"<<endl;
					else cout << "Ошибка"<<endl;
				}
				if (c == '-'){
					if (st.pop() == 0) cout << "> Удалено"<<endl;
					else cout << "Стек пуст"<<endl;
				}
			}
	return 0;
}

