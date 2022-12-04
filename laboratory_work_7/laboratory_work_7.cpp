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
string requestPerformerServiceNumber(int index);
string getRandomStr(int sizeStr);
void printWorkInWorkshop(WorkInWorkshop workshopData[N]);
vector<string> requestListPerformerServiceNumber(WorkInWorkshop workshopData[N]);
bool isPerformerServiceNumberInWorkInWorkshop(WorkInWorkshop workshopData[N], string performerServiceNumber);
void createSelectedPerformers(WorkInWorkshop workshopData[N], WorkInWorkshop dataOfSelectedPerformers[N],
                              vector<string> listPerformerServiceNumber);
void printSelectedPerformersTotalExecutionTimeAndCostOfWork(WorkInWorkshop dataOfSelectedPerformers[N]);
void printRecords(WorkInWorkshop dataOfSelectedPerformers[N], int serialNumber);
void printTotalCostOfWork(float totalCostOfWork);
void printServiceNumberFieldsAndRecords(WorkInWorkshop dataOfSelectedPerformers[N], int serialNumber);
void printServiceNumberAndFields(WorkInWorkshop dataOfSelectedPerformers[N], int serialNumber);
void printTimeOfExecutionOfListedWorks(float timeOfExecutionOfListedWorks);

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	WorkInWorkshop workshopData[N], dataOfSelectedPerformers[N];
	createWorkInWorkshop(workshopData);
	printWorkInWorkshop(workshopData);
	vector<string> listPerformerServiceNumber = requestListPerformerServiceNumber(workshopData);
	createSelectedPerformers(workshopData,
	                         dataOfSelectedPerformers,
	                         listPerformerServiceNumber);
	printSelectedPerformersTotalExecutionTimeAndCostOfWork(dataOfSelectedPerformers);

	system("PAUSE");
	return 0;
}

void createWorkInWorkshop(WorkInWorkshop workshopData[N])
{
	string performerServiceNumber;

	for (int i = 0; i < N; i++)
	{
		*workshopData[i].orderNumber = rand() % 9999;

		performerServiceNumber = requestPerformerServiceNumber(i);
		*workshopData[i].performerServiceNumber = performerServiceNumber;

		*workshopData[i].jobСode = rand() % 999;
		*workshopData[i].unit = getRandomStr(5);
		*workshopData[i].normOfTime = (float)(rand()) / ((float)(RAND_MAX / 9));
		*workshopData[i].price = (float)(rand()) / ((float)(RAND_MAX / 9));
		*workshopData[i].numberCompletedUnitsMeasure = rand() % 999;
		workshopData[i].costWork = *workshopData[i].price * *workshopData[i].numberCompletedUnitsMeasure;
	}
}

string requestPerformerServiceNumber(int index)
{
	string performerServiceNumber;
	cout << "Введите Таб. № испол. " << index + 1 << endl;
	cin >> performerServiceNumber;
	return performerServiceNumber;
}

string getRandomStr(int sizeStr)
{
	const char POOL[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"0123456789";
	std::string randomStr = "";
	int poolSize = sizeof(POOL) - 1;

	for (int i = 0; i < sizeStr; i++)
		randomStr += POOL[rand() % poolSize];

	return randomStr;
}

void printWorkInWorkshop(WorkInWorkshop workshopData[N])
{
	cout
		<< "\n"
		<< left
		<< setw(4) << "|ID#"
		<< setw(10) << "|№ наряда|"
		<< setw(15) << "|Таб. № испол.|"
		<< setw(12) << "|Код работы|"
		<< setw(10) << "|Ед. изм.|"
		<< setw(13) << "|Норма t (ч)|"
		<< setw(16) << "|Расценка (р/к)|"
		<< setw(32) << "|Кол. выпол. без брака Ед. изм.|"
		<< setw(34) << "|Стоимость работы (р/к)|"
		<< endl;

	for (int i = 0; i < N; i++)
	{
		cout
			<< setw(4) << i + 1
			<< setw(10) << *workshopData[i].orderNumber
			<< setw(15) << *workshopData[i].performerServiceNumber
			<< setw(12) << *workshopData[i].jobСode
			<< setw(10) << *workshopData[i].unit
			<< setw(13) << *workshopData[i].normOfTime
			<< setw(16) << *workshopData[i].price
			<< setw(32) << *workshopData[i].numberCompletedUnitsMeasure
			<< setw(34) << workshopData[i].costWork
			<< endl;
	}
}

vector<string> requestListPerformerServiceNumber(WorkInWorkshop workshopData[N])
{
	vector<string> listPerformerServiceNumber;
	string performerServiceNumber;
	bool isEnd, isPerformerServiceNumber;

	cout << "\nВведите запрашиваемые табельные номера исполнителей через строчку. По завершению ввода введите end:\n";
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
                              WorkInWorkshop dataOfSelectedPerformers[N],
                              vector<string> listPerformerServiceNumber)
{
	int countPerformerServiceNumber = listPerformerServiceNumber.size(),
	    numberOfLoopExecution = 0;
	bool isFoundPerformerServiceNumber;
	string performerServiceNumber;

	for (int i = 0; i < countPerformerServiceNumber; i++)
		for (int j = 0; j < N; j++)
		{
			performerServiceNumber = *workshopData[j].performerServiceNumber;

			isFoundPerformerServiceNumber = listPerformerServiceNumber[i] == performerServiceNumber;
			if (isFoundPerformerServiceNumber)
			{
				*dataOfSelectedPerformers[numberOfLoopExecution].orderNumber = *workshopData[j].orderNumber;
				*dataOfSelectedPerformers[numberOfLoopExecution].performerServiceNumber = *workshopData[j].
					performerServiceNumber;
				*dataOfSelectedPerformers[numberOfLoopExecution].jobСode = *workshopData[j].jobСode;
				*dataOfSelectedPerformers[numberOfLoopExecution].unit = *workshopData[j].unit;
				*dataOfSelectedPerformers[numberOfLoopExecution].normOfTime = *workshopData[j].normOfTime;
				*dataOfSelectedPerformers[numberOfLoopExecution].price = *workshopData[j].price;
				*dataOfSelectedPerformers[numberOfLoopExecution].numberCompletedUnitsMeasure =
					*workshopData[j].numberCompletedUnitsMeasure;
				dataOfSelectedPerformers[numberOfLoopExecution].costWork = workshopData[j].costWork;
				numberOfLoopExecution++;
			}
		}
}

void printSelectedPerformersTotalExecutionTimeAndCostOfWork(WorkInWorkshop dataOfSelectedPerformers[N])
{
	bool isMemoryFull,
	     isCurrentPerformerServiceNumber,
	     isPreviousSerialNumber,
	     isLastSerialNumber;
	int numberOfLoopExecution = 0;
	float totalCostOfWork = 0,
	      timeOfExecutionOfListedWorks = 0;
	string currentPerformerServiceNumber,
	       previousPerformerServiceNumber;

	for (int i = 0; i < N; i++)
	{
		isMemoryFull = *dataOfSelectedPerformers[i].orderNumber > 0;
		if (isMemoryFull)
		{
			isPreviousSerialNumber = i - 1 >= 0;
			if (isPreviousSerialNumber)
			{
				currentPerformerServiceNumber = *dataOfSelectedPerformers[i].performerServiceNumber;
				previousPerformerServiceNumber = *dataOfSelectedPerformers[i - 1].performerServiceNumber;

				isCurrentPerformerServiceNumber = currentPerformerServiceNumber == previousPerformerServiceNumber;
				if (isCurrentPerformerServiceNumber)
					printRecords(dataOfSelectedPerformers, i);
				else
				{
					printTotalCostOfWork(totalCostOfWork);
					totalCostOfWork = 0;
					printServiceNumberFieldsAndRecords(dataOfSelectedPerformers, i);
				}
			}
			else
				printServiceNumberFieldsAndRecords(dataOfSelectedPerformers, i);
			totalCostOfWork += dataOfSelectedPerformers[i].costWork;
			timeOfExecutionOfListedWorks += *dataOfSelectedPerformers[i].normOfTime;
			numberOfLoopExecution++;
		}
	}
	printTotalCostOfWork(totalCostOfWork);
	printTimeOfExecutionOfListedWorks(timeOfExecutionOfListedWorks);
}

void printRecords(WorkInWorkshop dataOfSelectedPerformers[N], int serialNumber)
{
	cout
		<< "\n"
		<< left
		<< setw(4) << serialNumber + 1
		<< setw(10) << *dataOfSelectedPerformers[serialNumber].orderNumber
		<< setw(12) << *dataOfSelectedPerformers[serialNumber].jobСode
		<< setw(10) << *dataOfSelectedPerformers[serialNumber].unit
		<< setw(13) << *dataOfSelectedPerformers[serialNumber].normOfTime
		<< setw(16) << *dataOfSelectedPerformers[serialNumber].price
		<< setw(32) << *dataOfSelectedPerformers[serialNumber].numberCompletedUnitsMeasure
		<< setw(34) << dataOfSelectedPerformers[serialNumber].costWork
		<< endl;
}

void printTotalCostOfWork(float totalCostOfWork)
{
	cout
		<< "\n"
		<< left
		<< setw(4 + 10 + 12 + 10 + 13 + 16 + 32) << "Итого:"
		<< setw(34) << totalCostOfWork
		<< endl;
}

void printServiceNumberFieldsAndRecords(WorkInWorkshop dataOfSelectedPerformers[N], int serialNumber)
{
	printServiceNumberAndFields(dataOfSelectedPerformers, serialNumber);
	printRecords(dataOfSelectedPerformers, serialNumber);
}

void printServiceNumberAndFields(WorkInWorkshop dataOfSelectedPerformers[N], int serialNumber)
{
	cout
		<< "\nСведения о прохождении нарядов для исполнителя с табельным номером "
		<< *dataOfSelectedPerformers[serialNumber].performerServiceNumber
		<< endl;
	cout
		<< left
		<< setw(4) << "|ID#"
		<< setw(10) << "|№ наряда|"
		<< setw(12) << "|Код работы|"
		<< setw(10) << "|Ед. изм.|"
		<< setw(13) << "|Норма t (ч)|"
		<< setw(16) << "|Расценка (р/к)|"
		<< setw(32) << "|Кол. выпол. без брака Ед. изм.|"
		<< setw(34) << "|Стоимость работы (р/к)|"
		<< endl;
}

void printTimeOfExecutionOfListedWorks(float timeOfExecutionOfListedWorks)
{
	cout << "\nВремя выполнения перечисленных работ (час.): " << timeOfExecutionOfListedWorks << endl;
}
