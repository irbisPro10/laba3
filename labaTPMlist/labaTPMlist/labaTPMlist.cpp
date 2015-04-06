// labaTPMlist.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

class list{
	list *l = 0x00, *first = 0x00;//����������
	int i;//��� �����������
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
	int addUp(int inf){//�������� �����
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
	int addIn(int n, int inf){//�������� � ����������� �����
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
	int addDown(int inf){//�������� ����
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
	int delUp(){//������� ������
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
	int delIn(int n){//������� �� ������������ �����
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
	int delDown(){//������� �����
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
			cout << "> ������ ����!\n";
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int inf, n;
	char c;
	setlocale(LC_ALL,"Rus");
	list l;

			cout << endl<<"+ - �������� �����"<<endl<<"* - �������� ����"<<endl<<"- - ������� ������"<<endl<<"/ - ������� �����"<<endl<<"= - �������� ����������� �����"<<endl<<"_ - ������� � ������������ �����"<<endl<<"p - ������"<<endl<<"0 - �����"<<endl;

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

					if (l.addUp(inf) == 0) cout << "���������"<<endl;
					else cout << "������" << endl;
				}
				if (c == '*'){
					cout << "> ";
					cin >> inf;

					if (l.addDown(inf) == 0) cout << "���������"<<endl;
					else cout << "������"<<endl;
				}
				if (c == '='){
					cout << "> ����� ��� ����������>";
					cin >> n;

					cout << "> ";
					cin >> inf;

					if (l.addIn(n, inf) == 0) cout << "���������"<<endl;
					else cout << "������" << endl;
				}
				if (c == '-'){
					if (l.delUp() == 0) cout << "�������"<<endl;
					else cout << "������" << endl;
				}
				if (c == '/'){
					if (l.delDown() == 0) cout << "�������"<<endl;
					else cout << "������" << endl;
				}
				if (c == '_'){
					cout << "����� ��� ��������";
					cin >> n;
					if (l.delIn(n) == 0) cout << "�������";
					else cout << "������ ����"<<endl;
				}
			}
		
	return 0;
}

