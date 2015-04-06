// labaTMPdeck.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
class deck
{public:
	int nU, nD, max;
	int **d;
	/*deck(){
	n = 0;
	}*/
	//Конструктор
	deck(){
		int i;
		d = new int*[100000];
		for (i = 0; i < 100000; i++) d[i] = 0x00;//Обнуляем все указатели
		max = 100000;
		nU = 0;//Верхний элемент
		nD = 0;//Нижний элемент
	}
	//Проверка не пуст ли дек
	bool isEmpty(){
		if (nU == nD) return 1;
		else return 0;
	}
	//Добавить элемент сверху
	int push(int *ptr){
		if (nU != max){
			d[nU] = ptr;
			nU++;

			return 0;
		}
		else return 1;
	}
	//Вытолкнуть элемент снизу
	int pop(){
		if (!isEmpty()){

			delete(d[nD]);
			d[nD] = 0x00;
			nD++;
			return 0;
		}
		else return 2;
	}
	void print(){
		int p = nD;
		if (p < 0) p = 0;
		cout << (d[p] == 0 ? 0 : *d[p]) << "\n";
	}
	~deck(){
		delete(d);
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	deck d;
	setlocale(LC_ALL, "Rus");
	cout << endl<<"+ - добавить"<<endl<<"- - удалить"<<endl<<"p - печать"<<endl<<"0 - выход\n";
	char c;
	
	while (1){

		cout << "> ";
		cin>>c;
		

		if (c == 'p'){
			d.print();
		}
		if (c == '0') break;
		if (c == '+'){
			cout << "> ";
			int *ptr = new int;
			cin >> *ptr;

			if (d.push(ptr) == 0) cout << "Добавлено"<<endl;
			else cout << "Не удалось добавить!"<<endl;
		}
		if (c == '-'){
			if (d.pop() == 0) cout << "Удалено"<<endl;
			else cout << "> Дек пуст"<<endl;
		}
	}

	return 0;
}

