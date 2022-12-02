#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define N 10

struct WorkInWorkshop
{
	int orderNumber[4];
	string performerServiceNumber[6];
	int jobСode[3];
	string unit[5];
	float normOfTime[3];
	float price[3];
	int numberCompletedUnitsMeasure[3];
	float costWork;
};

void createWorkInWorkshop(WorkInWorkshop workshopData[N]);
string getRandomChar(int sizeChar);
void outputWorkInWorkshop(WorkInWorkshop workshopData[N]);
vector<string> requestListPerformerServiceNumber(WorkInWorkshop workshopData[N]);
bool isPerformerServiceNumberInWorkInWorkshop(WorkInWorkshop workshopData[N], string performerServiceNumber);
void createSelectedPerformers(WorkInWorkshop workshopData[N], WorkInWorkshop dataOfPerformerServiceNumber[N],
                              vector<string> listPerformerServiceNumber);
void outputSelectedPerformersAndTotalExecutionTime(WorkInWorkshop dataOfPerformerServiceNumber[N]);

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	WorkInWorkshop workshopData[N], dataOfPerformerServiceNumber[N];
	createWorkInWorkshop(workshopData);
	outputWorkInWorkshop(workshopData);
	vector<string> listPerformerServiceNumber = requestListPerformerServiceNumber(workshopData);
	createSelectedPerformers(workshopData,
	                         dataOfPerformerServiceNumber,
	                         listPerformerServiceNumber);
	outputSelectedPerformersAndTotalExecutionTime(dataOfPerformerServiceNumber);

	system("PAUSE");
	return 0;
}

void createWorkInWorkshop(WorkInWorkshop workshopData[N])
{
	for (int i = 0; i < N; i++)
	{
		*workshopData[i].orderNumber = rand() % 9999;
		*workshopData[i].performerServiceNumber = getRandomChar(6);
		*workshopData[i].jobСode = rand() % 999;
		*workshopData[i].unit = getRandomChar(5);
		*workshopData[i].normOfTime = (float)(rand()) / ((float)(RAND_MAX / 9));
		*workshopData[i].price = (float)(rand()) / ((float)(RAND_MAX / 9));
		*workshopData[i].numberCompletedUnitsMeasure = rand() % 999;
		workshopData[i].costWork = *workshopData[i].price * *workshopData[i].numberCompletedUnitsMeasure;
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

void outputWorkInWorkshop(WorkInWorkshop workshopData[N])
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
			<< left << *workshopData[i].orderNumber << "\t\t"
			<< *workshopData[i].performerServiceNumber << "\t\t"
			<< *workshopData[i].jobСode << "\t\t"
			<< *workshopData[i].unit << "\t\t"
			<< *workshopData[i].normOfTime << "\t\t"
			<< *workshopData[i].price << "\t\t"
			<< *workshopData[i].numberCompletedUnitsMeasure << "\t\t"
			<< workshopData[i].costWork
			<< endl;
		//cout
		//	<< i << "\t\t"
		//	<< setw(4) << left << *workshopData[i].orderNumber << "\t\t"
		//	<< setw(6) << *workshopData[i].performerServiceNumber << "\t\t"
		//	<< setw(3) << *workshopData[i].jobСode << "\t\t"
		//	<< setw(5) << *workshopData[i].unit << "\t\t"
		//	<< setw(3) << *workshopData[i].normOfTime << "\t\t"
		//	<< setw(3) << *workshopData[i].price << "\t\t"
		//	<< setw(3) << *workshopData[i].numberCompletedUnitsMeasure << "\t\t"
		//	<< setw(6) << workshopData[i].costWork
		//	<< endl;
		/*	cout << *workshopData[i].orderNumber << "\n";
			cout << *workshopData[i].performerServiceNumber << "\n";
			cout << *workshopData[i].jobСode << "\n";
			cout << *workshopData[i].unit << "\n";
			cout << *workshopData[i].normOfTime << "\n";
			cout << *workshopData[i].price << "\n";
			cout << *workshopData[i].numberCompletedUnitsMeasure << "\n";
			cout << workshopData[i].costWork << "\n";*/
	}
}

vector<string> requestListPerformerServiceNumber(WorkInWorkshop workshopData[N])
{
	vector<string> listPerformerServiceNumber;
	string performerServiceNumber;
	bool isEnd, isPerformerServiceNumber;

	cout << "Введите запрашиваемые табельные номера исполнителей через строчку. По завершению ввода введите end:\n";
	while (true)
	{
		cin >> performerServiceNumber;
		isEnd = performerServiceNumber == "end";
		if (isEnd) break;

		isPerformerServiceNumber = isPerformerServiceNumberInWorkInWorkshop(workshopData, performerServiceNumber);
		if (isPerformerServiceNumber)
			listPerformerServiceNumber.push_back(performerServiceNumber);
		else
			cout << "Такого табельного номера исполнителя не существует\n";
	}
	return listPerformerServiceNumber;
}

bool isPerformerServiceNumberInWorkInWorkshop(WorkInWorkshop workshopData[N], string performerServiceNumber)
{
	for (int i = 0; i < N; i++)
		if (*workshopData[i].performerServiceNumber == performerServiceNumber)
			return true;
	return false;
}

void createSelectedPerformers(WorkInWorkshop workshopData[N],
                              WorkInWorkshop dataOfPerformerServiceNumber[N],
                              vector<string> listPerformerServiceNumber)
{
	int countPerformerServiceNumber = listPerformerServiceNumber.size();
	bool isFoundPerformerServiceNumber;
	string performerServiceNumber;

	for (int i = 0; i < countPerformerServiceNumber; i++)
		for (int j = 0; j < N; j++)
		{
			performerServiceNumber = *workshopData[j].performerServiceNumber;
			isFoundPerformerServiceNumber = listPerformerServiceNumber[i] == performerServiceNumber;

			if (isFoundPerformerServiceNumber)
			{
				*dataOfPerformerServiceNumber[j].orderNumber = *workshopData[j].orderNumber;
				*dataOfPerformerServiceNumber[j].performerServiceNumber = *workshopData[j].performerServiceNumber;
				*dataOfPerformerServiceNumber[j].jobСode = *workshopData[j].jobСode;
				*dataOfPerformerServiceNumber[j].unit = *workshopData[j].unit;
				*dataOfPerformerServiceNumber[j].normOfTime = *workshopData[j].normOfTime;
				*dataOfPerformerServiceNumber[j].price = *workshopData[j].price;
				*dataOfPerformerServiceNumber[j].numberCompletedUnitsMeasure =
					*workshopData[j].numberCompletedUnitsMeasure;
				dataOfPerformerServiceNumber[j].costWork = workshopData[j].costWork;
				break;
			}
		}
}

void outputSelectedPerformersAndTotalExecutionTime(WorkInWorkshop dataOfPerformerServiceNumber[N])
{
	//outputSelectedPerformers();
	cout
		<< "|ID# "
		<< setw(4) << left << "|Номер наряда|"
		<< setw(3) << "|Код работы|"
		<< setw(5) << "|Единица измерения|"
		<< setw(3) << "|Норма времени (час.)|"
		<< setw(3) << "|Расценка (руб. коп.)|"
		<< setw(3) << "|Количество выполненных без брака Единиц измерения|"
		<< setw(7) << "|Стоимость работы (руб. коп.)|"
		<< endl;
	string currentPerformerServiceNumber,
	       nextPerformerServiceNumber;
	bool isCurrentPerformerServiceNumber;
	for (int i = 0; i < N; i++)
	{
		currentPerformerServiceNumber = *dataOfPerformerServiceNumber[i].performerServiceNumber;
		nextPerformerServiceNumber = *dataOfPerformerServiceNumber[i + 1].performerServiceNumber;

		isCurrentPerformerServiceNumber = currentPerformerServiceNumber == nextPerformerServiceNumber;
		if (isCurrentPerformerServiceNumber)
		{
			cout
				<< i << "\t\t"
				<< left << *dataOfPerformerServiceNumber[i].orderNumber << "\t\t"
				<< *dataOfPerformerServiceNumber[i].jobСode << "\t\t"
				<< *dataOfPerformerServiceNumber[i].unit << "\t\t"
				<< *dataOfPerformerServiceNumber[i].normOfTime << "\t\t"
				<< *dataOfPerformerServiceNumber[i].price << "\t\t"
				<< *dataOfPerformerServiceNumber[i].numberCompletedUnitsMeasure << "\t\t"
				<< dataOfPerformerServiceNumber[i].costWork
				<< endl;

			cout << "Время выполнения перечисленных работ (час.): " << "";
		}
	}
}
