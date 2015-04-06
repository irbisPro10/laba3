// labaTPMlist.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

class list{
	list *l = 0x00, *first = 0x00;//переменные
	int i;//для перемещения
public:
	list *lN, *lP;
	int inf;
	list(){
		lN = lP = 0x00;
	}
	list(list *prev, list *next){
		lP = prev;
		lN = next;
	}
	int addUp(int inf){//Добавить вверх
		l = first;
		i = 0;
		while (l != 0x00 && l->lN != 0x00){
			i++;
			l = l->lN;
		}
		if (l != 0x00){
			l->lN = new list();
			l->lN->lP = l;
			l->lN->inf = inf;
		}
		else{
			first = l = new list();
			l->inf = inf;
		}
		return 0;
	}
	int addIn(int n, int inf){//Добавить в определённое место
		l = first;
		i = 0;
		while (l != 0x00 && l->lN != 0x00 && i<n){
			i++;
			l = l->lN;
		}
		if (i < n) addUp(inf);
		else{
			if (l != 0x00){
				l = new list(l->lP, l);
				if (l->lP != 0x00){
					l->lP->lN = l;
				}
				else first = l;
				if (l->lN != 0x00) l->lN->lP = l;
				l->inf = inf;
			}
			else{
				first = l = new list();
				l->inf = inf;
			}
		}
		return 0;
	}
	int addDown(int inf){//Добавить вниз
		l = first;
		if (l != 0x00){
			first = l->lP = new list();
			first->lN = l;
			first->inf = inf;
		}
		else{
			first = l = new list();
			l->inf = inf;
		}
		return 0;
	}
	int delUp(){//Удалить сверху
		l = first;
		i = 0;
		while (l != 0x00 && l->lN != 0x00){
			i++;
			l = l->lN;
		}
		if (l != 0x00){
			if (l->lP == 0x00) first = 0x00;
			else l->lP->lN = 0x00;
			delete(l);
		}
		else{
			return 2;
		}
		return 0;
	}
	int delIn(int n){//Удалить из определённого места
		l = first;
		i = 0;
		while (l != 0x00 && l->lN != 0x00 && i<n){
			i++;
			l = l->lN;
		}
		if (l != 0x00){
			if (l->lP == 0x00 && l->lN == 0x00) first = 0x00;
			if (l->lP != 0x00 && l->lN != 0x00){ l->lP->lN = l->lN; l->lN->lP = l->lP; }
			if (l->lP != 0x00 && l->lN == 0x00){ l->lP->lN = l->lN; }
			if (l->lP == 0x00 && l->lN != 0x00){ l->lN->lP = l->lP; }

			delete(l);
		}
		else{
			return 2;
		}
		return 0;
	}
	int delDown(){//Удалить снизу
		l = first;
		if (l != 0x00){
			if (l->lN == 0x00) first = 0x00;
			else{
				first = l->lN;
				l->lN->lP = 0x00;
			}
			delete(l);
		}
		else{
			return 2;
		}
		return 0;
	}
	void print(){
		l = first;
		i = 0;
		if (l != 0x00){
			while (l != 0x00){
				cout << l->inf << endl;
				i++;
				l = l->lN;
			}
		}
		else{
			cout << "> Список пуст!\n";
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int inf, n;
	char c;
	setlocale(LC_ALL,"Rus");
	list l;

			cout << endl<<"+ - добавить вверх"<<endl<<"* - добавить вниз"<<endl<<"- - удалить сверху"<<endl<<"/ - удалить снизу"<<endl<<"= - добавить определённое место"<<endl<<"_ - удалить с определённого места"<<endl<<"p - печать"<<endl<<"0 - выход"<<endl;

			while (1){

				cout << ">> ";
				
				cin >> c;
				if (c == 'p'){
					l.print();
				}
				if (c == '0') break;
				if (c == '+'){
					cout << "> ";
					cin >> inf;

					if (l.addUp(inf) == 0) cout << "Добавлено"<<endl;
					else cout << "Ошибка" << endl;
				}
				if (c == '*'){
					cout << "> ";
					cin >> inf;

					if (l.addDown(inf) == 0) cout << "Добавлено"<<endl;
					else cout << "Ошибка"<<endl;
				}
				if (c == '='){
					cout << "> место для добавления>";
					cin >> n;

					cout << "> ";
					cin >> inf;

					if (l.addIn(n, inf) == 0) cout << "Добавлено"<<endl;
					else cout << "Ошибка" << endl;
				}
				if (c == '-'){
					if (l.delUp() == 0) cout << "Удалено"<<endl;
					else cout << "Ошибка" << endl;
				}
				if (c == '/'){
					if (l.delDown() == 0) cout << "Удалено"<<endl;
					else cout << "Ошибка" << endl;
				}
				if (c == '_'){
					cout << "место для удаления";
					cin >> n;
					if (l.delIn(n) == 0) cout << "Удалено";
					else cout << "Список пуст"<<endl;
				}
			}
		
	return 0;
}

