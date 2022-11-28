#include <clocale>
#include <stdio.h>
#include <conio.h>
#include <string.h>
# define N 2


struct workInWorkshop
{
	int orderNumber;
	char performerServiceNumber;
	char jobСode;
	char unit;
	float normOfTime;
	float price;
	int numberCompletedUnitsMeasure;
};
informationAboutPassageOrdersForPerformerWithAPersonnelNumber
struct workInWorkshop
{
	int orderNumber;
	char performerServiceNumber;
	char jobСode;
	char unit;
	float normOfTime;
	float price;
	int numberCompletedUnitsMeasure;
};

void main()
{
	setlocale(LC_ALL, "ru");
	int TN;
	char FIO[15];
	float NZP;
	float SUD;
	float VNR;
	char ROSP[20] = "                   "; //Такое присваивание возможно только при
	//объявлении строки!
	ZAP Tab[N]; //Tab – массив структур int i;
	float Itog1, Itog2, Itog3;
	for (int i = 0; i < N; i++)
	{
		printf("TN=");
		scanf_s("%d", &TN);
		//gets(FIO); // считывает строку
		printf("Начислено ");
		scanf_s("%f", &NZP);
		printf("Удержано ");
		scanf_s("%f", &SUD);
		printf("ФИО ");
		scanf_s("%s", &FIO);
		Tab[i].TN = TN;

		strcpy_s(Tab[i].FIO, FIO);
		//Tab[i].NZP = NZP;
		//Tab[i].SUD = SUD;
		//Tab[i].VNR = NZP - SUD;
		//strcpy_s(Tab[i].ROSP, ROSP); // Присваивать значение одной строки другой можно
		//// только функцией strcpy_s ()!
	}
	Itog1 = Itog2 = Itog3 = 0;
	printf("        	ВЕДОМОСТЬ ЗАРПЛАТЫ \n");
	for (int i = 0; i < N; i++)
	{
		printf("%d %15s %7.2f %7.2f %7.2f %s \n", Tab[i].TN, Tab[i].FIO, Tab[i].NZP, Tab[i].SUD, Tab[i].VNR,
		       Tab[i].ROSP);
		Itog1 += Tab[i].NZP; // . - доступ к полю структуры
		Itog2 += Tab[i].SUD;
		Itog3 += Tab[i].VNR;
	}

	printf("===========================================\n");
	printf("              	%8.2f%8.2f %8.2f \n", Itog1, Itog2, Itog3);
}
