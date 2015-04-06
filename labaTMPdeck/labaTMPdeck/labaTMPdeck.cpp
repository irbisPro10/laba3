// labaTMPdeck.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
class deck
{public:
	int nU, nD, max;
	int **d;
	/*deck(){
	n = 0;
	}*/
	//�����������
	deck(){
		int i;
		d = new int*[100000];
		for (i = 0; i < 100000; i++) d[i] = 0x00;//�������� ��� ���������
		max = 100000;
		nU = 0;//������� �������
		nD = 0;//������ �������
	}
	//�������� �� ���� �� ���
	bool isEmpty(){
		if (nU == nD) return 1;
		else return 0;
	}
	//�������� ������� ������
	int push(int *ptr){
		if (nU != max){
			d[nU] = ptr;
			nU++;

			return 0;
		}
		else return 1;
	}
	//���������� ������� �����
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
	cout << endl<<"+ - ��������"<<endl<<"- - �������"<<endl<<"p - ������"<<endl<<"0 - �����\n";
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

			if (d.push(ptr) == 0) cout << "���������"<<endl;
			else cout << "�� ������� ��������!"<<endl;
		}
		if (c == '-'){
			if (d.pop() == 0) cout << "�������"<<endl;
			else cout << "> ��� ����"<<endl;
		}
	}

	return 0;
}

