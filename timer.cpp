#include <iostream>
#include <unistd.h>
using namespace std;


struct Crow
{
	char row[4];
};

ostream& operator<<(ostream& os, Crow C)
{
	os << C.row;
	return os;
}

//proto ===========
Crow Row(int num, int row);
void PrintTime(int time);
void incTime(int &t);
void decTime(int &t);


// == main ==================
int main(void)
{
	auto int tim;
	auto char usrChr;
	
	cout << "(s)tart timer, or (c)ountdown? ";
	cin >> usrChr;
	
	if ('s' == usrChr)
		{
		tim = 0;
		cout << "'ctrl + c' will stop timer.\n";
		while(1)
			{
			PrintTime(tim);
			incTime(tim);
			sleep(1);
			}
		}
	else if ('c' == usrChr)
		{
		cout << "Enter start time (ex: 2min. -> 200):  ";
		cin >> tim;
		bool zero = true;
		while(zero)
			{
			PrintTime(tim);
			decTime(tim);
			sleep(1);
			if (0 == tim) zero = false;
			}
		}
	
	else cout << "Nice try fool\n";
	
	cout << "Time's up!\n\a";
	return 0;
}



void incTime(int &t)
{
	if (t < 0 || t > 9958) t = 0;
	
	++t;
	if (60 == (t/100)) t+= 40;
}

void decTime(int &t)
{
	if (0 != t)
		{
		--t;
		if (99 == (t%100)) t -= 40;
		}
}



void PrintTime(int t)
{
	int t1, t2, t3, t4;
	t1 = (t/1000)%10;
	t2 = (t/100)%10;
	t3 = (t/10)%10;
	t4 = t%10;
	
	int lineCtr;
	for (lineCtr = 0; lineCtr < 3; lineCtr++)
		{
		cout << Row(t1, lineCtr) << " " << Row(t2, lineCtr);
		if (0 == lineCtr) cout << "   ";
		else cout << " . ";
		cout << Row(t3, lineCtr) << " " << Row(t4, lineCtr) << endl;
		}
	cout << endl;
}


Crow Row(int num, int row)
{
	Crow C;
	
switch(num)
{
case 0:
		 if (0 == row){ C.row[0] = ' '; C.row[1] = '_'; C.row[2] = ' ';}
	else if (1 == row){ C.row[0] = '|'; C.row[1] = ' '; C.row[2] = '|';}
	else if (2 == row){ C.row[0] = '|'; C.row[1] = '_'; C.row[2] = '|';}
	break;
case 1:
		 if (0 == row){ C.row[0] = ' '; C.row[1] = ' '; C.row[2] = ' ';}
	else if (1 == row){ C.row[0] = ' '; C.row[1] = ' '; C.row[2] = '|';}
	else if (2 == row){ C.row[0] = ' '; C.row[1] = ' '; C.row[2] = '|';}
	break;
case 2:
		 if (0 == row){ C.row[0] = ' '; C.row[1] = '_'; C.row[2] = ' ';}
	else if (1 == row){ C.row[0] = ' '; C.row[1] = '_'; C.row[2] = '|';}
	else if (2 == row){ C.row[0] = '|'; C.row[1] = '_'; C.row[2] = ' ';}
	break;
case 3:
		 if (0 == row){ C.row[0] = ' '; C.row[1] = '_'; C.row[2] = ' ';}
	else if (1 == row){ C.row[0] = ' '; C.row[1] = '_'; C.row[2] = '|';}
	else if (2 == row){ C.row[0] = ' '; C.row[1] = '_'; C.row[2] = '|';}
	break;
case 4:
		 if (0 == row){ C.row[0] = ' '; C.row[1] = ' '; C.row[2] = ' ';}
	else if (1 == row){ C.row[0] = '|'; C.row[1] = '_'; C.row[2] = '|';}
	else if (2 == row){ C.row[0] = ' '; C.row[1] = ' '; C.row[2] = '|';}
	break;
case 5:
		 if (0 == row){ C.row[0] = ' '; C.row[1] = '_'; C.row[2] = ' ';}
	else if (1 == row){ C.row[0] = '|'; C.row[1] = '_'; C.row[2] = ' ';}
	else if (2 == row){ C.row[0] = ' '; C.row[1] = '_'; C.row[2] = '|';}
	break;
case 6:
		 if (0 == row){ C.row[0] = ' '; C.row[1] = '_'; C.row[2] = ' ';}
	else if (1 == row){ C.row[0] = '|'; C.row[1] = '_'; C.row[2] = ' ';}
	else if (2 == row){ C.row[0] = '|'; C.row[1] = '_'; C.row[2] = '|';}
	break;
case 7:
		 if (0 == row){ C.row[0] = ' '; C.row[1] = '_'; C.row[2] = ' ';}
	else if (1 == row){ C.row[0] = ' '; C.row[1] = ' '; C.row[2] = '|';}
	else if (2 == row){ C.row[0] = ' '; C.row[1] = ' '; C.row[2] = '|';}
	break;
case 8:
		 if (0 == row){ C.row[0] = ' '; C.row[1] = '_'; C.row[2] = ' ';}
	else if (1 == row){ C.row[0] = '|'; C.row[1] = '_'; C.row[2] = '|';}
	else if (2 == row){ C.row[0] = '|'; C.row[1] = '_'; C.row[2] = '|';}
	break;
case 9:
		 if (0 == row){ C.row[0] = ' '; C.row[1] = '_'; C.row[2] = ' ';}
	else if (1 == row){ C.row[0] = '|'; C.row[1] = '_'; C.row[2] = '|';}
	else if (2 == row){ C.row[0] = ' '; C.row[1] = '_'; C.row[2] = '|';}
	break;
}

C.row[3] = 0;
return C;
}









