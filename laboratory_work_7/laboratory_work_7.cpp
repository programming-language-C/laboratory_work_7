#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
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
string requestPerformerServiceNumberForCreateWorkshopData(int index);
string getRandomStr(int sizeStr);
void printWorkInWorkshop(WorkInWorkshop workshopData[N]);
void requestPerformerServiceNumber(WorkInWorkshop workshopData[N],
                                   WorkInWorkshop dataOfSelectedPerformers[N]);
void findCopyAndPrintSelectedArtist(WorkInWorkshop workshopData[N],
                                    WorkInWorkshop dataOfSelectedPerformers[N],
                                    string requestedServiceNumber);
void copySelectedArtist(WorkInWorkshop* workshopData,
                        WorkInWorkshop* dataOfSelectedPerformers,
                        int numberOfLoopExecution,
                        int i);
void printSelectedArtist(WorkInWorkshop dataOfSelectedPerformers[N],
                         string previousPerformerServiceNumber,
                         int index);
void printRecords(WorkInWorkshop dataOfSelectedPerformers[N], int serialNumber);
void printTotalCostOfWork(float totalCostOfWork);
void printServiceNumberFieldsAndRecords(WorkInWorkshop dataOfSelectedPerformers[N], int serialNumber);
void printServiceNumberAndFields(WorkInWorkshop dataOfSelectedPerformers[N], int serialNumber);
void printTimeOfExecutionOfListedWorks(float timeOfExecutionOfListedWorks);

int main()
{
	WorkInWorkshop workshopData[N], dataOfSelectedPerformers[N];

	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	createWorkInWorkshop(workshopData);
	printWorkInWorkshop(workshopData);
	requestPerformerServiceNumber(workshopData, dataOfSelectedPerformers);

	system("PAUSE");
	return 0;
}

void createWorkInWorkshop(WorkInWorkshop workshopData[N])
{
	string performerServiceNumber;

	for (int i = 0; i < N; i++)
	{
		*workshopData[i].orderNumber = rand() % 9999;

		performerServiceNumber = requestPerformerServiceNumberForCreateWorkshopData(i);
		*workshopData[i].performerServiceNumber = performerServiceNumber;

		*workshopData[i].jobСode = rand() % 999;
		*workshopData[i].unit = getRandomStr(5);
		*workshopData[i].normOfTime = (float)(rand()) / ((float)(RAND_MAX / 9));
		*workshopData[i].price = (float)(rand()) / ((float)(RAND_MAX / 9));
		*workshopData[i].numberCompletedUnitsMeasure = rand() % 999;
		workshopData[i].costWork = *workshopData[i].price * *workshopData[i].numberCompletedUnitsMeasure;
	}
}

string requestPerformerServiceNumberForCreateWorkshopData(int index)
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

void requestPerformerServiceNumber(WorkInWorkshop workshopData[N], WorkInWorkshop dataOfSelectedPerformers[N])
{
	string requestedServiceNumber;
	bool isEnd;

	cout << "\nВведите запрашиваемые табельные номера исполнителей через строчку. По завершению ввода введите end:\n";
	while (true)
	{
		cin >> requestedServiceNumber;
		isEnd = requestedServiceNumber == "end";
		if (isEnd) break;
		findCopyAndPrintSelectedArtist(workshopData,
		                               dataOfSelectedPerformers,
		                               requestedServiceNumber);
	}
}

void copySelectedArtist(WorkInWorkshop workshopData[N],
                        WorkInWorkshop dataOfSelectedPerformers[N],
                        int numberOfLoopExecution,
                        int i)
{
	*dataOfSelectedPerformers[numberOfLoopExecution].orderNumber = *workshopData[i].orderNumber;
	*dataOfSelectedPerformers[numberOfLoopExecution].performerServiceNumber = *workshopData[i].
		performerServiceNumber;
	*dataOfSelectedPerformers[numberOfLoopExecution].jobСode = *workshopData[i].jobСode;
	*dataOfSelectedPerformers[numberOfLoopExecution].unit = *workshopData[i].unit;
	*dataOfSelectedPerformers[numberOfLoopExecution].normOfTime = *workshopData[i].normOfTime;
	*dataOfSelectedPerformers[numberOfLoopExecution].price = *workshopData[i].price;
	*dataOfSelectedPerformers[numberOfLoopExecution].numberCompletedUnitsMeasure =
		*workshopData[i].numberCompletedUnitsMeasure;
	dataOfSelectedPerformers[numberOfLoopExecution].costWork = workshopData[i].costWork;
}

void findCopyAndPrintSelectedArtist(WorkInWorkshop workshopData[N],
                                    WorkInWorkshop dataOfSelectedPerformers[N],
                                    string requestedServiceNumber)
{
	bool isFoundPerformerServiceNumber;
	string performerServiceNumber,
	       previousPerformerServiceNumber;
	int numberOfLoopExecution = 0;
	float totalCostOfWork = 0,
	      timeOfExecutionOfListedWorks = 0;

	for (int i = 0; i < N; i++)
	{
		performerServiceNumber = *workshopData[i].performerServiceNumber;
		isFoundPerformerServiceNumber = requestedServiceNumber == performerServiceNumber;
		if (isFoundPerformerServiceNumber)
		{
			copySelectedArtist(workshopData, dataOfSelectedPerformers, numberOfLoopExecution, i);
			printSelectedArtist(dataOfSelectedPerformers, previousPerformerServiceNumber, numberOfLoopExecution);
			totalCostOfWork += workshopData[i].costWork;
			timeOfExecutionOfListedWorks += *workshopData[i].normOfTime;
			previousPerformerServiceNumber = performerServiceNumber;
			numberOfLoopExecution++;
		}
	}

	if (!numberOfLoopExecution)
	{
		cout << "Такого табельного номера исполнителя не существует\n";
		return;
	}
	printTotalCostOfWork(totalCostOfWork);
	printTimeOfExecutionOfListedWorks(timeOfExecutionOfListedWorks);
}

void printSelectedArtist(WorkInWorkshop dataOfSelectedPerformers[N],
                         string previousPerformerServiceNumber,
                         int index)
{
	string currentPerformerServiceNumber;
	bool isSameServiceNumber;

	currentPerformerServiceNumber = *dataOfSelectedPerformers[index].performerServiceNumber;
	isSameServiceNumber = currentPerformerServiceNumber == previousPerformerServiceNumber;
	if (isSameServiceNumber)
		printRecords(dataOfSelectedPerformers, index);
	else
		printServiceNumberFieldsAndRecords(dataOfSelectedPerformers, index);
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
