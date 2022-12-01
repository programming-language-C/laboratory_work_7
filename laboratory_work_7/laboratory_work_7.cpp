#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
#define N 5

struct workInWorkShop
{
	int orderNumber[4];
	std::string performerServiceNumber[6];
	int jobСode[3];
	std::string unit[5];
	float normOfTime[3];
	float price[3];
	int numberCompletedUnitsMeasure[3];
	float costWork;
};

void createWorkInWorkShop(workInWorkShop arrStructures[N]);
std::string getRandomChar(int sizeChar);
void entryWorkInWorkShop(workInWorkShop arrStructures[N]);
vector<int> requestListPerformerServiceNumber();

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	workInWorkShop workInWorkShop[N];
	createWorkInWorkShop(workInWorkShop);
	entryWorkInWorkShop(workInWorkShop);
	entryWorkInWorkShop(workInWorkShop);
	//sort(workInWorkShop, workInWorkShop + N, compareTwoStudents);
	//entryWorkInWorkShop(workInWorkShop);
	vector<int> listPerformerServiceNumber = requestListPerformerServiceNumber();
}

void createWorkInWorkShop(workInWorkShop arrStructures[N])
{
	for (int i = 0; i < N; i++)
	{
		*arrStructures[i].orderNumber = rand() % 9999;
		*arrStructures[i].performerServiceNumber = getRandomChar(6);
		*arrStructures[i].jobСode = rand() % 999;
		*arrStructures[i].unit = getRandomChar(5);
		*arrStructures[i].normOfTime = (float)(rand()) / ((float)(RAND_MAX / 9));
		*arrStructures[i].price = (float)(rand()) / ((float)(RAND_MAX / 9));
		*arrStructures[i].numberCompletedUnitsMeasure = rand() % 999;
		arrStructures[i].costWork = *arrStructures[i].price * *arrStructures[i].numberCompletedUnitsMeasure;
	}
}

std::string getRandomChar(int sizeChar)
{
	const char POOL[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"0123456789";
	std::string randomChar = "";
	int poolSize = sizeof(POOL) - 1;

	for (int i = 0; i < sizeChar; i++)
		randomChar += POOL[rand() % poolSize];

	return randomChar;
}

void entryWorkInWorkShop(workInWorkShop arrStructures[N])
{
	cout
		<< "|ID# "
		<< setw(4) << left << "|Номер наряда|"
		<< setw(6) << "|Табельный номер исполнителя|"
		<< setw(3) << "|Код работы|"
		<< setw(5) << "|Единица измерения|"
		<< setw(3) << "|Норма времени (час.)|"
		<< setw(3) << "|Расценка (руб. коп.)|"
		<< setw(3) << "|Количество выполненных без брака Единиц измерения|"
		<< setw(7) << "|Стоимость работы (руб. коп.)|"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout
			<< i << "\t\t"
			<< right << *arrStructures[i].orderNumber << "\t\t"
			<< *arrStructures[i].performerServiceNumber << "\t\t"
			<< *arrStructures[i].jobСode << "\t\t"
			<< *arrStructures[i].unit << "\t\t"
			<< *arrStructures[i].normOfTime << "\t\t"
			<< *arrStructures[i].price << "\t\t"
			<< *arrStructures[i].numberCompletedUnitsMeasure << "\t\t"
			<< arrStructures[i].costWork
			<< endl;
		//cout
		//	<< i << "\t\t"
		//	<< setw(4) << right << *arrStructures[i].orderNumber << "\t\t"
		//	<< setw(6) << *arrStructures[i].performerServiceNumber << "\t\t"
		//	<< setw(3) << *arrStructures[i].jobСode << "\t\t"
		//	<< setw(5) << *arrStructures[i].unit << "\t\t"
		//	<< setw(3) << *arrStructures[i].normOfTime << "\t\t"
		//	<< setw(3) << *arrStructures[i].price << "\t\t"
		//	<< setw(3) << *arrStructures[i].numberCompletedUnitsMeasure << "\t\t"
		//	<< setw(6) << arrStructures[i].costWork
		//	<< endl;
		/*	cout << *arrStructures[i].orderNumber << "\n";
			cout << *arrStructures[i].performerServiceNumber << "\n";
			cout << *arrStructures[i].jobСode << "\n";
			cout << *arrStructures[i].unit << "\n";
			cout << *arrStructures[i].normOfTime << "\n";
			cout << *arrStructures[i].price << "\n";
			cout << *arrStructures[i].numberCompletedUnitsMeasure << "\n";
			cout << arrStructures[i].costWork << "\n";*/
	}
}


vector<int> requestListPerformerServiceNumber()
{
	vector<int> listPerformerServiceNumber;
	char charPerformerServiceNumber;
	int performerServiceNumber;
	bool isEnd;

	cout << "Введите запрашиваемые табельные номера исполнителей через строчку. По завершению ввода введите end:\n";
	while (true)
	{
		cin >> charPerformerServiceNumber;
		isEnd = charPerformerServiceNumber == (char)"end";
		cout << isEnd;
		if (isEnd) break;
		performerServiceNumber = (int)charPerformerServiceNumber;
		listPerformerServiceNumber.push_back(performerServiceNumber);
	}
	return listPerformerServiceNumber;
}
