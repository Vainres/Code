// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void count(float n)
{
	n /= 2;
	int crit, critdmg;
	float dps = 1, atk;
	for (int i = 5;i < n;i++)
	{
		float S;
		float rate = i * 0.01;
		if (rate > 1) rate = 1;
		float atkk;
		for (int j = 25;j < n - i;j++)
		{

			atkk = (n - i - j) * 0.015;
			S = rate * (j * 0.02 + 1) * (1 + atkk) + (1 - rate) * (1 + atkk);

			if (S > dps)
			{
				crit = i; critdmg = (j) * 2;dps = S; atk = atkk;

			}
			//cout << "crit :" << rate * 100 << endl << "critdmg :" << (j) * 2 << endl << "%ATK :" << atkk << endl << "dmg :" << S << endl;
		}

	}
	cout << "Toi uu :" << endl << "crit :" << crit << endl << "critdmg :" << critdmg << endl << "ATK BONUS : " << atk << endl << "dps :" << dps << endl;
}
void count2(float n,float base)
{
	n /= 2;
	int crit, critdmg;
	float dps = 1, atk;
	for (int i = 5;i < n;i++)
	{
		float S;
		float rate = i * 0.01;
		if (rate > 1) rate = 1;
		float atkk;
		for (int j = 25;j < n - i;j++)
		{

			atkk = (n - i - j) * 0.015;
			S = rate * (j * 0.02 + 1) * (1 + atkk) + (1 - rate) * (1 + atkk);

			if (S > dps)
			{
				crit = i; critdmg = (j) * 2;dps = S; atk = atkk;

			}
			//cout << "crit :" << rate * 100 << endl << "critdmg :" << (j) * 2 << endl << "%ATK :" << atkk << endl << "dmg :" << S << endl;
		}

	}
	cout << "Toi uu :" << endl << "crit :" << crit << endl << "critdmg :" << critdmg << endl << "ATK :" << base * (atk + 1) << endl << "ATK BONUS : " << atk << endl << "dps :" << base * dps << endl;
	cout << "Diem : " << n*2<<endl;
}
int main()
{
	float n,base,allatk,pcrit,pcritdmg;
	int l;
	cout << "Nhap 1.diem,2.stat (1,2): ";
	cin >> l;
	if (l == 2) {

		cout << "Nhap ATK : ";
		cin >> allatk;
		cout << "Nhap base ATK: ";
		cin >> base;
		cout << "Nhap crit rate: ";
		cin >> pcrit;
		cout << "Nhap crit dmg: ";
		cin >> pcritdmg;
		float c = allatk * pcrit * 0.01 * (1 + pcritdmg * 0.01) + allatk * (1 - pcrit * 0.01);
		cout << "dps hien tai : " << c << endl;
		n = (allatk - base) / base * 400 / 3;
		n += pcrit * 2 + pcritdmg;
		count2(n,base);
	}
	else if(l==1){
		cout << "Nhap diem : ";
		cin >> n;
		count(n);
	}
	system("pause");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
