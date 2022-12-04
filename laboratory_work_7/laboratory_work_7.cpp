#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define N 4

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

		//*workshopData[i].performerServiceNumber = getRandomStr(6);
		//performerServiceNumber = requestPerformerServiceNumber(i);
		performerServiceNumber = 1;
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
	cout << "Введите Таб. № испол. " << index << endl;
	cin >> performerServiceNumber;
	return performerServiceNumber;
}

std::string getRandomStr(int sizeStr)
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
		<< "|ID#|"
		<< "|№ наряда|"
		<< "|Таб. № испол.|"
		<< "|Код работы|"
		<< "|Ед. изм.|"
		<< "|Норма t (ч)|"
		<< "|Расценка (р/к)|"
		<< "|Кол. выпол. без брака Ед. изм.|"
		<< "|Стоимость работы (р/к)|"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout
			<< "  " << i << "\t"
			<< *workshopData[i].orderNumber << "\t\t"
			<< *workshopData[i].performerServiceNumber << "\t"
			<< *workshopData[i].jobСode << "\t   "
			<< *workshopData[i].unit << "\t"
			<< *workshopData[i].normOfTime << "\t\t"
			<< *workshopData[i].price << "\t\t"
			<< *workshopData[i].numberCompletedUnitsMeasure << "\t\t\t"
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
	     isPreviousSerialNumber;
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
					totalCostOfWork += dataOfSelectedPerformers[i].costWork;
				}
			}
			else
				printServiceNumberFieldsAndRecords(dataOfSelectedPerformers, i);
			totalCostOfWork += dataOfSelectedPerformers[i].costWork;
			timeOfExecutionOfListedWorks += *dataOfSelectedPerformers[i].normOfTime;
		}
	}
	printTimeOfExecutionOfListedWorks(timeOfExecutionOfListedWorks);
}

void printRecords(WorkInWorkshop dataOfSelectedPerformers[N], int serialNumber)
{
	cout
		<< "\n"
		<< serialNumber << "\t\t"
		<< left << *dataOfSelectedPerformers[serialNumber].orderNumber << "\t\t"
		<< *dataOfSelectedPerformers[serialNumber].jobСode << "\t\t"
		<< *dataOfSelectedPerformers[serialNumber].unit << "\t\t"
		<< *dataOfSelectedPerformers[serialNumber].normOfTime << "\t\t"
		<< *dataOfSelectedPerformers[serialNumber].price << "\t\t"
		<< *dataOfSelectedPerformers[serialNumber].numberCompletedUnitsMeasure << "\t\t"
		<< dataOfSelectedPerformers[serialNumber].costWork
		<< endl;
}

void printTotalCostOfWork(float totalCostOfWork)
{
	cout
		<< "Итого:"
		<< totalCostOfWork
		<< endl;
}

void printServiceNumberFieldsAndRecords(WorkInWorkshop dataOfSelectedPerformers[N], int serialNumber)
{
	printServiceNumberAndFields(dataOfSelectedPerformers, serialNumber);
	printRecords(dataOfSelectedPerformers, serialNumber);
}

void printServiceNumberAndFields(WorkInWorkshop dataOfSelectedPerformers[N], int serialNumber)
{
	string test;
	cout
		<< "\nСведения о прохождении нарядов для исполнителя с табельным номером "
		<< *dataOfSelectedPerformers[serialNumber].performerServiceNumber
		<< endl;
	cout
		<< "|ID# "
		<< left << "|№ наряда|"
		<< "|Код работы|"
		<< "|Ед. изм.|"
		<< "|Норма t (ч)|"
		<< "|Расценка (р/к)|"
		<< "|Кол. выпол. без брака Ед. изм.|"
		<< "|Стоимость работы (руб. коп.)|"
		<< endl;
}

void printTimeOfExecutionOfListedWorks(float timeOfExecutionOfListedWorks)
{
	cout << "Время выполнения перечисленных работ (час.): " << timeOfExecutionOfListedWorks << endl;
}
