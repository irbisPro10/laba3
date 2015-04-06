// labaTMPstek.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
class stek{
public:
	int n, max;
	int **st;
	/*stek(){
	n = 0;
	}*/
	//�����������
	stek(){
		int i;
		st = new int*[100000];
		for (i = 0; i < 100000; i++) st[i] = 0x00;//�������� ��� ���������
		max = 100000;
		n = 0;//������� �������
	}
	//�������� �� ���� �� ����
	bool isEmpty(){
		if (st[0] == 0x00) return 1;
		else return 0;
	}
	//�������� ������� ������
	int push(int *ptr){
		if ((n) != max){
			st[n] = ptr;
			n++;

			return 0;
		}
		else return 1;
	}
	//���������� ������� ������
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

			cout << endl<<"+ - ��������"<<endl<<"- - �������"<<endl<<"p - ������"<<"0 - �����"<<endl;

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

					if (st.push(ptr) == 0) cout << "���������"<<endl;
					else cout << "������"<<endl;
				}
				if (c == '-'){
					if (st.pop() == 0) cout << "> �������"<<endl;
					else cout << "���� ����"<<endl;
				}
			}
	return 0;
}

