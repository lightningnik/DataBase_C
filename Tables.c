/* Петкилев Никита Александрович ПКС-204
  Задание:
* Создание прототипа базы данных (количество хранимых объектов от 0 до 100), реализующий следующие функции:
• Добавление информации о новом объекте (в удобном интерфейсе, который нельзя испортить, каждое отдельное поле вводится либо в поле таблицы, либо в окошке)
• Удобный просмотр списка объектов (необходимо учесть, что их может быть больше 25)
  Интерфейс можно улучшать по сравнению с предложенным вариантом
• Удаление информации об объекте (необходимо предусмотреть удобный выбор объекта для удаления – с помощью выбора в таблице)
• Удаление информации об объекте по значению первого поля (значение вводится таким образом, чтобы нельзя было испортить интерфейс, в окошке)
• Изменение информации об объекте (необходимо предусмотреть удобный выбор объекта для изменения – с помощью выбора в таблице) и удобный ввод (прямо в таблице или в окошках – по одному окошку на поле)
• Изменение информации об объекте по значению первого поля (значение вводится таким образом, чтобы нельзя было испортить интерфейс, в окошке)
• Нахождение записи по значению первого поля
• Сортировка по значению одного из полей первой таблицы (выбираемому пользователем).
Таблица No1 (техники): название, модель, разработчик, предприятие, стоимость, тип.
Таблица No2 (разработчиков): ФИО, год рождения, пол. В случае реализации таблицы No2 в таблице No1 вместо ввода ФИО разработчика осуществляется его выбор из таблицы No2.
Таблица No3 (предприятий): название, место нахождения, количество работников, директор. В случае реализации таблицы No3 в таблице No1 вместо ввода названия предприятия осуществляется его выбор из таблицы No3.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

typedef struct tagVechicles
{
	char Model[12], Appelation[12], Developer[12], Enterprise[12], Type[12], Cost[12];
} Vechicles;

typedef struct tagPersons
{
	char Surname[12], Name[12], Patronymic[17], Gender[11], Year[5];
} Persons;

typedef struct tagCompany
{
	char CompanyName[12], Location[12], Director[12], NumberOfEmployees[12];
} Companies;

Vechicles Vechicle[999];
Persons Person[999];
Companies Company[999];

int NumberTable1, NumberTable2, NumberTable3, value, mul, i, j;
char FirstFieldCheck[12], IntValueCheck[12], ch;

int HintTable1() {
	system("cls");	//Очистка экрана
	printf("Подсказка:\nДля модели, названия, фамилии разработчика, названия предприятия и типа техники создано ограничение в 10 символов,\nДля стоимости техники создано ограничение в 1000000");
	printf("\nПример ввода:"
		"\nВведите модель техники       >> Т-34"
		"\nВведите название техники     >> Танк "
		"\nВведите фамилию разработчика >> Петкилев "
		"\nВведите название предприятия >> МГКИТ"
		"\nВведите тип техники          >> Военная"
		"\nВведите стоимость техники    >> 15000\n");
	return 0;
}
int HintTable2() {
	system("cls");
	printf("Подсказка: Для фамилии и имени создано ограничение в 12 символов, для пола в 8 символов, \nдля отчества в 16 символов, для даты рождения в 9999 лет");
	printf("\nПример ввода:"
		"\nВведите фамилию          >> Иванов"
		"\nВведите имя              >> Иван"
		"\nВведите отчество         >> Иванов "
		"\nВведите пол              >> Мужской"
		"\nВведите год  рождения    >> 2003\n");
	return 0;
}
int HintTable3() {
	system("cls");
	printf("Подсказка: Для названия компании, месположения(город) и количества сотрудников задано ограничение в 10 символов, \nдля фамилии директора в 15 символов");
	printf("\nПример ввода:"
		"\nВведите название компании             >> Яндекс"
		"\nВведите местположение компании(город) >> Москва"
		"\nВведите директора компании            >> Иванов"
		"\nВведите количество сотрудников        >> 155\n");
	return 0;
}

/*int PrintTable1() //Функция для вывода информации
{
	printf("|-----т--------------т-------------т-------------т-------------т-------------т---------------|\n");
	printf("|  N  |       Модель |    Название | Разработчик | Предприятие |         Тип |     Стоимость |\n");
	printf("|-----+--------------+-------------+-------------+-------------+-------------+---------------|\n");
	for (i = 0; i < NumberTable1; i++) {
		printf("%s %003i %s %12s %s %11s %s %11s %s %11s %s %11s %s %13s %s\n", "|", i + 1, "|", Vechicle[i].Model, "|", Vechicle[i].Appelation, "|", Vechicle[i].Developer, "|", Vechicle[i].Enterprise, "|", Vechicle[i].Type, "|", Vechicle[i].Cost, "|");
		printf("|-----+--------------+-------------+-------------+-------------+-------------+---------------|\n");
		}
	return 0;
}*/

void PrintTable1() {
	int i = 0, page = 10, ch = 0, a; //Setting the counter
	while (ch != 1) {
		printf("|-----т--------------т-------------т-------------т-------------т-------------т---------------|\n");
		printf("|   N |       Модель |    Название | Разработчик | Предприятие |         Тип |     Стоимость |\n");
		printf("|-----+--------------+-------------+-------------+-------------+-------------+---------------|\n");
		for (; i < page && i < NumberTable1; i++) { //Setting the "for" counter to output array elements by number
			printf("%s %003i %s %12s %s %11s %s %11s %s %11s %s %11s %s %13s %s\n", "|", i + 1, "|", Vechicle[i].Model, "|", Vechicle[i].Appelation, "|", Vechicle[i].Developer, "|", Vechicle[i].Enterprise, "|", Vechicle[i].Type, "|", Vechicle[i].Cost, "|");
			printf("|-----+--------------+-------------+-------------+-------------+-------------+---------------|\n");
		}
		printf("Last page - LEFT (<-) | Next page - RIGHT (->) | Exit - BACKSPACE\n");
		a = _getch();
		if (a == 72) {
			if (i > 11 && i != NumberTable1) {
				i -= 20;
				page -= 10;
				ch = 0;
			}
			else if (i == 10) {
				i = 0;
				page = 10;
				ch = 0;
			}
			else if (i >= NumberTable1) {
				page = i - (i%10);
				i = page - 10;
				ch = 0;
			}
			system("cls");
		}
		else if (a == 80) {
			if (i > NumberTable1) {
				i = 0;
				page = 10;
				ch = 0;
			}
			else {
				page += 10;
				ch = 0;
			}
			system("cls");
		}
		else if (a == 27) {
			ch = 1;
		}
	}
	a = _getch();
}
int PrintTable2()//Функция для вывода информации
{
	printf("|-----т--------------т--------------т------------------т----------т--------------|\n");
	printf("|  N  |      Фамилия |          Имя |         Отчество |      Пол | Год рождения |\n");
	printf("|-----+--------------+--------------+------------------+----------+--------------|\n");
	for (i = 0; i < NumberTable2; i++) {
	printf("%s %003i %s %12s %s %12s %s %16s %s %8s %s %04s %s\n", "|", i + 1, "|", Person[i].Surname, "|", Person[i].Name, "|", Person[i].Patronymic, "|", Person[i].Gender, "|        ", Person[i].Year, "|");
	printf("|-----+--------------+--------------+------------------+----------+--------------|\n");
	}
	return 0;
}
int PrintTable3()//Функция для вывода информации
{
	printf("|-----т-------------т----------------т----------------т----------------------|\n");
	printf("|  N  |    Название | Местоположение |       Директор |    Число сотрудников |\n");
	printf("|-----+-------------+----------------+----------------+----------------------|\n");
	for (i = 0; i < NumberTable3; i++) {
		printf("%s %003i %s %11s %s %11s %4s %14s %s %20s %s\n", "|", i + 1, "|", Company[i].CompanyName, "|", Company[i].Location, "|", Company[i].Director, "|", Company[i].NumberOfEmployees, "|");
	printf("|-----+-------------+----------------+----------------+----------------------|\n");
	}
	return 0;
}

int InsertTable1()
{
	if (NumberTable2 == 0 || NumberTable3 == 0) {
		printf("В Таблице №2/Таблице №3 отсутсвуют записи!!!\n");
		system("pause");
		return 0;
	}
	if (NumberTable1 == 100)
	{
		printf("Невозможно добавить еще один элемент\n");
		system("pause");
		return 0;
	}
	HintTable1();
	printf("\nВведите модель техники       >> "); fgets(Vechicle[NumberTable1].Model, 12, stdin); Vechicle[NumberTable1].Model[strlen(Vechicle[NumberTable1].Model) - 1] = 0;
	if (strlen(Vechicle[NumberTable1].Model) > 10 || strlen(Vechicle[NumberTable1].Model) == 0) {
		printf("Ошибка ввода поле было оставлено пустым, или превышенно допустимое количество символов\n");
		system("pause");
		return 0;
	}
	printf("Введите название техники     >> ");   fgets(Vechicle[NumberTable1].Appelation, 12, stdin); Vechicle[NumberTable1].Appelation[strlen(Vechicle[NumberTable1].Appelation) - 1] = 0;
	if (strlen(Vechicle[NumberTable1].Appelation) > 10 || strlen(Vechicle[NumberTable1].Appelation) == 0) {
		printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов\n");
		system("pause");
		return 0;
	}
	system("cls");
	PrintTable2();
	printf("Введите номер записи, откуда вы хотите выбрать фамилию!!!\n");
	i = 0;
	while ((ch = getchar()) != '\n')
		if (ch >= 48 && ch <= 57) {
			IntValueCheck[i] = ch;
			i++;
		}
	IntValueCheck[i] = '\0';
	i = 0;
	value = 0, mul = 1;
	for (size_t length = strlen(IntValueCheck) - 1; length != -1; length--) {
		value = IntValueCheck[length] - 48;
		i += value * mul;
		mul = mul * 10;
	}
	i--;
	if (i >= 0 && i < NumberTable2) {
		strcpy(Vechicle[NumberTable1].Developer, Person[i].Surname);
	}
	else { 
    i++;
	printf("Элемент с номером %i не существует\n",i); 
	system("pause");
	return 0;
	}

	HintTable1();
	printf("\nВведите модель техники       >> %s",Vechicle[NumberTable1].Model);
	printf("\nВведите название техники     >> %s", Vechicle[NumberTable1].Appelation);
	printf("\nВведите фамилию разработчика >> %s", Vechicle[NumberTable1].Developer);
	system("cls");
	PrintTable3();
	printf("Введите номер записи, откуда вы хотите выбрать название компании!!!\n");
	i = 0;
	while ((ch = getchar()) != '\n')
		if (ch >= 48 && ch <= 57) {
			IntValueCheck[i] = ch;
			i++;
		}
	IntValueCheck[i] = '\0';
	i = 0;
	value = 0,mul = 1;
	for (size_t length = strlen(IntValueCheck)-1; length !=-1; length--) {
		value = IntValueCheck[length] - 48;
		i += value * mul;
		mul = mul * 10;
	}
	i--;
	if (i >= 0 && i < NumberTable3) {
		strcpy(Vechicle[NumberTable1].Enterprise, Company[i].CompanyName);
	}
	else {
		i++;
		printf("Элемент с номером %i не существует\n",i);
		system("pause");
		return 0;
	}
	HintTable1();
	printf("\nВведите модель техники       >> %s", Vechicle[NumberTable1].Model);
	printf("\nВведите название техники     >> %s", Vechicle[NumberTable1].Appelation);
	printf("\nВведите фамилию разработчика >> %s", Vechicle[NumberTable1].Developer);
	printf("\nВведите название предприятия >> %s", Vechicle[NumberTable1].Enterprise);
	printf("\nВведите тип техники          >> ");   fgets(Vechicle[NumberTable1].Type, 12, stdin); Vechicle[NumberTable1].Type[strlen(Vechicle[NumberTable1].Type) - 1] = 0;
	if (strlen(Vechicle[NumberTable1].Type) > 10 || strlen(Vechicle[NumberTable1].Type) == 0) {
		printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов\n");
		system("pause");
		return 0;
	}
	printf("Введите стоимость техники    >> ");   
    i = 0;
	while ((ch = getchar()) != '\n')
		if (ch >= 48 && ch <= 57) {
			IntValueCheck[i] = ch;
			i++;
		}
	IntValueCheck[i] = '\0';
	if (strlen(IntValueCheck) == 0) {
		printf("Ошибка ввода, можно вводить только цифры!!!");
		system("pause");
		return 0;
	}
	strcpy(Vechicle[NumberTable1].Cost, IntValueCheck);
	NumberTable1++;
	return 0;
}
int InsertTable2()//Функция для ввода информации
{
	if (NumberTable2 == 100) //Если количество элементов превыщает 100
	{                 //То нас перебросит обратно в меню
		printf("Невозможно добавить еще один элемент\n");
		system("pause");
		return 1;
	}
	HintTable2();
	printf("\nВведите фамилию          >> "); fgets(Person[NumberTable2].Surname, 12, stdin); Person[NumberTable2].Surname[strlen(Person[NumberTable2].Surname) - 1] = 0;
	if (strlen(Person[NumberTable2].Surname) > 10 || strlen(Person[NumberTable2].Surname) == 0) {
		printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов\n");
		system("pause");
		return 0;
	}

	printf("Введите имя              >> "); fgets(Person[NumberTable2].Name, 12, stdin); Person[NumberTable2].Name[strlen(Person[NumberTable2].Name) - 1] = 0;
	if (strlen(Person[NumberTable2].Name) > 10 || strlen(Person[NumberTable2].Name) == 0) {
		printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов\n");
		system("pause");
		return 0;
	}

	printf("Введите отчество         >> "); fgets(Person[NumberTable2].Patronymic, 17, stdin); Person[NumberTable2].Patronymic[strlen(Person[NumberTable2].Patronymic) - 1] = 0;
	if (strlen(Person[NumberTable2].Patronymic) > 15 || strlen(Person[NumberTable2].Patronymic) == 0) {
		printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов\n");
		system("pause");
		return 0;
	}

	printf("Введите пол              >> "); fgets(Person[NumberTable2].Gender, 11, stdin); Person[NumberTable2].Gender[strlen(Person[NumberTable2].Gender) - 1] = 0;
	if (strlen(Person[NumberTable2].Gender) > 10 || strlen(Person[NumberTable2].Gender) == 0) {
		printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов\n");
		system("pause");
		return 0;
	}

	printf("Введите год рождения     >> ");   i = 0;
	while ((ch = getchar()) != '\n') {
		if (ch >= 48 && ch <= 57) {
			IntValueCheck[i] = ch;
			i++;
		}
	}
	IntValueCheck[i] = '\0';
	if (i > 4) {
		printf("Введено слишком много символов");
		return 0;
	}
	if (strlen(IntValueCheck) == 0) {
		printf("Ошибка ввода, можно вводить только цифры!!!");
		system("pause");
		return 0;
	}
		strcpy(Person[NumberTable2].Year, IntValueCheck); //записываем  строку, которую мы проверяли в строку стоимость
	NumberTable2++;

	return 0;
}
int InsertTable3()//Функция для ввода информации
{
	if (NumberTable3 == 100) //Если количество элементов превыщает 100
	{                 //То нас перебросит обратно в меню
		printf("Невозможно добавить еще один элемент\n");
		system("pause");
		return 1;
	}
	HintTable3();
	printf("\nВведите название компании             >> "); fgets(Company[NumberTable3].CompanyName, 12, stdin); Company[NumberTable3].CompanyName[strlen(Company[NumberTable3].CompanyName) - 1] = 0;
	if (strlen(Company[NumberTable3].CompanyName) > 10 || strlen(Company[NumberTable3].CompanyName) == 0) {
		printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов!!!");
		system("pause");
		return 0;
	}

	printf("Введите местположение компании(город) >> "); fgets(Company[NumberTable3].Location, 12, stdin); Company[NumberTable3].Location[strlen(Company[NumberTable3].Location) - 1] = 0;
	if (strlen(Company[NumberTable3].Location) > 10 || strlen(Company[NumberTable3].Location) == 0) {
		printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов!!!");
		system("pause");
		return 0;
	}

	printf("Введите фамилию директора компании    >> ");  fgets(Company[NumberTable3].Director, 12, stdin); Company[NumberTable3].Director[strlen(Company[NumberTable3].Director) - 1] = 0;
	if (strlen(Company[NumberTable3].Location) > 10 || strlen(Company[NumberTable3].Location) == 0) {
		printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов!!!");
		system("pause");
		return 0;
	}

	printf("Введите численность сотрудников       >> ");
	i=0;
	while ((ch = getchar()) != '\n') {
		if (ch >= 48 && ch <= 57) {
			IntValueCheck[i] = ch;
			i++;
		}
	}
	
	IntValueCheck[i] = '\0';
	if (strlen(IntValueCheck) == 0) {
		printf("Ошибка ввода, можно вводить только цифры!!!");
		system("pause");
		return 0;
	}
	strcpy(Company[NumberTable3].NumberOfEmployees, IntValueCheck);
	NumberTable3++;

	return 0;
}

int SearchTable1() {
	printf("Введите название модели   >> "); fgets(FirstFieldCheck, 12, stdin); FirstFieldCheck[strlen(FirstFieldCheck) - 1] = 0;
	if (strlen(FirstFieldCheck) > 10 || strlen(FirstFieldCheck) == 0)
	{
		printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов!!!\n");
		system("pause");
		return 0;
	}
	j = 0;
	printf("|-----т--------------т-------------т-------------т-------------т-------------т---------------|\n");;
	printf("|  N  |       Модель |    Название | Разработчик | Предприятие |         Тип |      Стоимость|\n");
	printf("|-----+--------------+-------------+-------------+-------------+-------------+---------------|\n");
	for (i = 0; i < NumberTable1; i++) {
		if (strcmp(Vechicle[i].Model, FirstFieldCheck) == 0) {
			printf("%s %003i %s %12s %s %11s %s %11s %s %11s %s %11s %s %13s %s\n", "|", i + 1, "|", Vechicle[i].Model, "|", Vechicle[i].Appelation, "|", Vechicle[i].Developer, "|", Vechicle[i].Enterprise, "|", Vechicle[i].Type, "|", Vechicle[i].Cost, "|");
			printf("|-----+--------------+-------------+-------------+-------------+-------------+---------------|\n");
			j++;
		}
	}
	return 0;
}
int SearchTable2() {
	printf("Введите фамилию: "); fgets(FirstFieldCheck, 12, stdin); FirstFieldCheck[strlen(FirstFieldCheck) - 1] = 0;
	if (strlen(FirstFieldCheck) > 10 || strlen(FirstFieldCheck) == 0) {
		printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов");
		system("pause");
		return 0;
	}
	j = 0;
	printf("|-----т--------------т--------------т------------------т----------т--------------|\n");
	printf("|  N  |      Фамилия |          Имя |         Отчество |      Пол | Год рождения |\n");
	printf("|-----+--------------+--------------+------------------+----------+--------------|\n");
	for (i = 0; i < NumberTable2; i++) {
		if (strcmp(Person[i].Surname, FirstFieldCheck) == 0) {
			printf("%s %003i %s %12s %s %12s %s %16s %s %8s %s %04s %s\n", "|", i + 1, "|", Person[i].Surname, "|", Person[i].Name, "|", Person[i].Patronymic, "|", Person[i].Gender, "|        ", Person[i].Year, "|");
			printf("|-----+--------------+--------------+------------------+----------+--------------|\n");
			j++;
		}
	}

	return 0;
}
int SearchTable3() {
	printf("Введите название компании   >> "); fgets(FirstFieldCheck, 12, stdin); FirstFieldCheck[strlen(FirstFieldCheck) - 1] = 0;
	if (strlen(FirstFieldCheck) > 10 || strlen(FirstFieldCheck) == 0)
	{
		printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов");
		system("pause");
		return 0;
	}
	j = 0;
	printf("|-----т-------------т----------------т----------------т----------------------|\n");
	printf("|  N  |    Название | Местоположение |       Директор |    Число сотрудников |\n");
	printf("|-----+-------------+----------------+----------------+----------------------|\n");
	for (i = 0; i < NumberTable3; i++) {
		if (strcmp(Company[i].CompanyName, FirstFieldCheck) == 0) {
			printf("%s %003i %s %11s %s %11s %4s %14s %s %20s %s\n", "|", i + 1, "|", Company[i].CompanyName, "|", Company[i].Location, "|", Company[i].Director, "|", Company[i].NumberOfEmployees, "|");
			printf("|-----+-------------+----------------+----------------+----------------------|\n");
			j++;
		}
	}

	return 0;
}

int RemoveNumberTable1()
{
	printf("|-----т--------------т-------------т-------------т-------------т-------------т---------------|\n");
	printf("|  N  |       Модель |    Название | Разработчик | Предприятие |         Тип |      Стоимость|\n");
	printf("|-----+--------------+-------------+-------------+-------------+-------------+---------------|\n");
	for (i = 0; i < NumberTable1; i++) {
		printf("%s %03i %s %12s %s %11s %s %11s %s %11s %s %11s %s %13s %s\n", "|", i + 1, "|", Vechicle[i].Model, "|", Vechicle[i].Appelation, "|", Vechicle[i].Developer, "|", Vechicle[i].Enterprise, "|", Vechicle[i].Type, "|", Vechicle[i].Cost, "|");
		if (i < NumberTable1 - 1)
			printf("|-----+--------------+-------------+-------------+-------------+-------------+---------------|\n");
		else
			printf("|-----|--------------|-------------|-------------|-------------|-------------|---------------|\n");
	}

	printf("Введите номер удаляемого элемента > ");

	i = 0;
	while ((ch = getchar()) != '\n')
		if (ch >= 48 && ch <= 57) {
			IntValueCheck[i] = ch;
			i++;
		}
	IntValueCheck[i] = '\0';
	i = 0;
	value = 0, mul = 1;
	for (size_t length = strlen(IntValueCheck) - 1; length != -1; length--) {
		value = IntValueCheck[length] - 48;
		i += value * mul;
		mul = mul * 10;
	}
		if (i < 1 || i > NumberTable1)//Если номер введеного элемента не существует
	{                       //То нас перебросит в меню
		printf("Данный элемент отсутствует");
		system("pause");
		return 0;
	}

	for (i--; i < NumberTable1 - 1; i++) //проходим список до тех пор, пока не дойдем до нужного номера
		Vechicle[i] = Vechicle[i + 1];

	NumberTable1--;
	
	return 0;
}
int RemoveNumberTable2() //Функция для удаления элементов
{
PrintTable2();

	printf("Введите номер удаляемого элемента > ");
	i = 0;
	while ((ch = getchar()) != '\n')
		if (ch >= 48 && ch <= 57) {
			IntValueCheck[i] = ch;
			i++;
		}
	IntValueCheck[i] = '\0';
	i = 0;
	value = 0, mul = 1;
	for (size_t length = strlen(IntValueCheck) - 1; length != -1; length--) {
		value = IntValueCheck[length] - 48;
		i += value * mul;
		mul = mul * 10;
	}
	if (i < 1 || i > NumberTable2)//Если номер введеного элемента не существует
	{                       //То нас перебросит в меню
		printf("Данный элемент отсутствует");
		system("pause");
		return 0;
	}

	for (i--; i < NumberTable2 - 1; i++)
		Person[i] = Person[i + 1];

	NumberTable2--;

	return 0;
}
int RemoveNumberTable3() //Функция для удаления элементов
{
	PrintTable3();

	printf("Введите номер удаляемого элемента > ");
	i = 0;
	while ((ch = getchar()) != '\n')
		if (ch >= 48 && ch <= 57) {
			IntValueCheck[i] = ch;
			i++;
		}
	IntValueCheck[i] = '\0';
	i = 0;
	value = 0, mul = 1;
	for (size_t length = strlen(IntValueCheck) - 1; length != -1; length--) {
		value = IntValueCheck[length] - 48;
		i += value * mul;
		mul = mul * 10;
	}
	if (i < 1 || i > NumberTable3)//Если номер введеного элемента не существует
	{                       //То нас перебросит в меню
		printf("Данный элемент отсутствует");
		system("pause");
		return 0;
	}

	for (i--; i < NumberTable3 - 1; i++)
		Company[i] = Company[i + 1];

	NumberTable3--;

	return 0;
}

int RemoveModelTable1() {
		SearchTable1(j);
		if (j == 0) {
			printf("Записей схожих с %s не найдено\n", FirstFieldCheck);
			system("pause");
			return 0;
		}
		printf("Введите номер удаляемого элемента > ");
		i = 0;
		while ((ch = getchar()) != '\n')
			if (ch >= 48 && ch <= 57) 
			{
				IntValueCheck[i] = ch;
				i++;
			}
		IntValueCheck[i] = '\0';
		i = 0;
		value = 0, mul = 1;
		for (size_t length = strlen(IntValueCheck) - 1; length != -1; length--) 
		{
			value = IntValueCheck[length] - 48;
			i += value * mul;
			mul = mul * 10;
		}
		if (i < 1 || i > NumberTable1 || strcmp(Vechicle[i].Model, FirstFieldCheck) == 0)//Если номер введеного элемента не существует
		{                       //То нас перебросит в меню
			printf("Данный элемент отсутствует\n");
			return 0;
		}
		for (i--; i < NumberTable1 - 1; i++)
			Vechicle[i] = Vechicle[i + 1];

		NumberTable1--;
	return 0;
}
int RemoveSurnameTable2() {
	SearchTable2(j);
	if (j == 0) {
		printf("Записей схожих с %s не найдено\n", FirstFieldCheck);
		system("pause");
		return 0;
	}
		printf("Введите номер удаляемого элемента > ");
		i = 0;
		while ((ch = getchar()) != '\n')
			if (ch >= 48 && ch <= 57) 
			{
				IntValueCheck[i] = ch;
				i++;
			}
		IntValueCheck[i] = '\0';
		i = 0;
		value = 0, mul = 1;
		for (size_t length = strlen(IntValueCheck) - 1; length != -1; length--) 
		{
			value = IntValueCheck[length] - 48;
			i += value * mul;
			mul = mul * 10;
		}
		if (i < 1 || i > NumberTable2 || strcmp(Person[i].Surname, FirstFieldCheck) == 0)//Если номер введеного элемента не существует
		{                       //То нас перебросит в меню
			printf("Данный элемент отсутствует/Выбран элемент, не представленный в списке");
			return 0;
		}

		for (i--; i < NumberTable2 - 1; i++)
			Person[i] = Person[i + 1];

		NumberTable2--;

	return 0;
}
int RemoveCompanyNameTable3() {
	SearchTable3(j); 
	if (j == 0) {
		printf("Записей схожих с %s не найдено\n", FirstFieldCheck);
		system("pause");
		return 0;
	}
	printf("Введите номер удаляемого элемента > ");
	i = 0;
	while ((ch = getchar()) != '\n')
		if (ch >= 48 && ch <= 57) 
		{
			IntValueCheck[i] = ch;
			i++;
		}
	IntValueCheck[i] = '\0';
	i = 0;
	value = 0, mul = 1;
	for (size_t length = strlen(IntValueCheck) - 1; length != -1; length--) 
	{
		value = IntValueCheck[length] - 48;
		i += value * mul;
		mul = mul * 10;
	}
	if (i < 1 || i > NumberTable3 || strcmp(Company[i].CompanyName, FirstFieldCheck) == 0)//Если номер введеного элемента не существует
		{                       //То нас перебросит в меню
			printf("Данный элемент отсутствует");
			system("pause");
			return 0;
		}

		for (i--; i < NumberTable3 - 1; i++)
			Company[i] = Company[i + 1];

		NumberTable3--;
	return 0;
}

int RemoveTable1() {
	int k = 0, Curr = 0;
	while (Curr >= 0 || Curr <= 2) {
		printf("|-------------------------------------|\n");
		(Curr == 0) ? printf("|Выйти в меню                         |<<<\n") : printf("|Выйти в меню                         |\n");
		printf("|-------------------------------------|\n");
		(Curr == 1) ? printf("|Удаление по номеру элемента          |<<<\n") : printf("|Удаление по номеру элемента          |\n");
		printf("|-------------------------------------|\n");
		(Curr == 2) ? printf("|Удаление по значению первого поля    |<<<\n") : printf("|Удаление по значению первого поля    |\n");
		printf("|-------------------------------------|\n");
		k = _getch();
		system("cls");
		if (k == 80) {//Обарботка стрелки вверх
			if (Curr == 2) Curr = 0;
			else Curr++;
		}
		if (k == 72) {//Обработка стрелки вниз
			if (Curr == 0) Curr = 2;
			else Curr--;
		}

		if (k == 27) {//Обработка клавиши ESC
			return 0;
		}

		if (k == 13) {//Обработка клавиши Enter
			switch (Curr)
			{
			case 0:
				return 0;
				break;
			case 1:
				system("cls");
				RemoveNumberTable1();
				break;
			case 2:
				system("cls");
				RemoveModelTable1();
				break;
			}
		}
	}
	return Curr;
}
int RemoveTable2() {
	int k = 0, Curr = 0;
	while (Curr >= 0 || Curr <= 2) {
		printf("|-------------------------------------|\n");
		(Curr == 0) ? printf("|Выйти в меню                         |<<<\n") : printf("|Выйти в меню                         |\n");
		printf("|-------------------------------------|\n");
		(Curr == 1) ? printf("|Удаление по номеру элемента          |<<<\n") : printf("|Удаление по номеру элемента          |\n");
		printf("|-------------------------------------|\n");
		(Curr == 2) ? printf("|Удаление по значению первого поля    |<<<\n") : printf("|Удаление по значению первого поля    |\n");
		printf("|-------------------------------------|\n");
		k = _getch();
		system("cls");
		if (k == 80) {//Обарботка стрелки вверх
			if (Curr == 2) Curr = 0;
			else Curr++;
		}
		if (k == 72) {//Обработка стрелки вниз
			if (Curr == 0) Curr = 2;
			else Curr--;
		}

		if (k == 27) {//Обработка клавиши ESC
			return 0;
		}

		if (k == 13) {//Обработка клавиши Enter
			switch (Curr)
			{
			case 0:
				return 0;
				break;
			case 1:
				system("cls");
				RemoveNumberTable2();
				break;
			case 2:
				system("cls");
				RemoveSurnameTable2();
				break;
			}
		}
	}
	return Curr;
}
int RemoveTable3() {
	int k = 0, Curr = 0;
	while (Curr >= 0 || Curr <= 2) {
		printf("|-------------------------------------|\n");
		(Curr == 0) ? printf("|Выйти в меню                         |<<<\n") : printf("|Выйти в меню                         |\n");
		printf("|-------------------------------------|\n");
		(Curr == 1) ? printf("|Удаление по номеру элемента          |<<<\n") : printf("|Удаление по номеру элемента          |\n");
		printf("|-------------------------------------|\n");
		(Curr == 2) ? printf("|Удаление по значению первого поля    |<<<\n") : printf("|Удаление по значению первого поля    |\n");
		printf("|-------------------------------------|\n");
		k = _getch();
		system("cls");
		if (k == 80) {//Обарботка стрелки вверх
			if (Curr == 2) Curr = 0;
			else Curr++;
		}
		if (k == 72) {//Обработка стрелки вниз
			if (Curr == 0) Curr = 2;
			else Curr--;
		}

		if (k == 27) {//Обработка клавиши ESC
			return 0;
		}

		if (k == 13) {//Обработка клавиши Enter
			switch (Curr)
			{
			case 0:
				return 0;
				break;
			case 1:
				system("cls");
				RemoveNumberTable3();
				break;
			case 2:
				system("cls");
				RemoveCompanyNameTable3();
				break;
			}
		}
	}
	return Curr;
}

int ChangeNumberTable1()//Функция для изменения элемента
{
	PrintTable1();
	printf("Введите номер изменяемого элемента > ");
	i = 0;
	while ((ch = getchar()) != '\n')
		if (ch >= 48 && ch <= 57) {
			IntValueCheck[i] = ch;
			i++;
		}
	IntValueCheck[i] = '\0';
	i = 0;
	value = 0, mul = 1;
	for (size_t length = strlen(IntValueCheck) - 1; length != -1; length--) {
		value = IntValueCheck[length] - 48;
		i += value * mul;
		mul = mul * 10;
	}
	i--;
	if (i < 1 || i > NumberTable1)//Если номер введеного элемента не существует
	{                       //То нас перебросит в меню
		printf("Данный элемент отсутствует");
		return 1;
	}
	i--; //Нумерация начинается с 0
	HintTable1();
	system("cls");
	printf("|-----т--------------т-------------т-------------т-------------т-------------т---------------|\n");;
	printf("|  N  |       Модель |    Название | Разработчик | Предприятие |         Тип |      Стоимость|\n");
	printf("|-----+--------------+-------------+-------------+-------------+-------------+---------------|\n");
	printf("%s %003i %s %12s %s %11s %s %11s %s %11s %s %11s %s %13s %s\n", "|", i + 1, "|", Vechicle[i].Model, "|", Vechicle[i].Appelation, "|", Vechicle[i].Developer, "|", Vechicle[i].Enterprise, "|", Vechicle[i].Type, "|", Vechicle[i].Cost, "|");
	printf("|-----|--------------|-------------|-------------|-------------|-------------|---------------|\n");
	printf("\nВведите модель техники       >> "); fgets(Vechicle[i].Model, 12, stdin); Vechicle[i].Model[strlen(Vechicle[i].Model) - 1] = 0;
	//
	if (strlen(Vechicle[i].Model) > 10 || strlen(Vechicle[i].Model) == 0) {
		printf("Ошибка ввода\nполе было оставлено пустым, или превышенно допустимое количество символов");
		
		return 0;
	}
	printf("Введите название техники     >> ");   fgets(Vechicle[i].Appelation, 12, stdin); Vechicle[i].Appelation[strlen(Vechicle[i].Appelation) - 1] = 0;
	if (strlen(Vechicle[i].Appelation) > 10 || strlen(Vechicle[i].Appelation) == 0) {
		printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов");
		
		return 0;
	}
	printf("Введите фамилию разработчика >> ");   fgets(Vechicle[i].Developer, 12, stdin); Vechicle[i].Developer[strlen(Vechicle[i].Developer) - 1] = 0;
	if (strlen(Vechicle[i].Developer) > 10 || strlen(Vechicle[i].Developer) == 0) {
		printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов");
		
		return 0;
	}
	printf("Введите название предприятия >> ");   fgets(Vechicle[i].Enterprise, 12, stdin); Vechicle[i].Enterprise[strlen(Vechicle[i].Enterprise) - 1] = 0;
	if (strlen(Vechicle[i].Enterprise) > 10 || strlen(Vechicle[i].Enterprise) == 0) {
		printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов");
		
		return 0;
	}
	printf("Введите тип техники          >> ");   fgets(Vechicle[i].Type, 12, stdin); Vechicle[i].Type[strlen(Vechicle[i].Type) - 1] = 0;
	if (strlen(Vechicle[i].Type) > 10 || strlen(Vechicle[i].Type) == 0) {
		printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов");
		
		return 0;
	}
	printf("Введите стоимость техники    >> ");   fgets(IntValueCheck, 12, stdin); IntValueCheck[strlen(IntValueCheck) - 1] = 0;
	if (strlen(IntValueCheck) > 10 || strlen(IntValueCheck) == 0) {
		printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов");
		
		return 0;
	}
	int j = 0;
	while (j != strlen(IntValueCheck)) { // проверяем длину строки и состоит ли строка только из цифр
		if (IntValueCheck[i] >= '0' && IntValueCheck[i] <= '9') { //если символ являяется цифрой, то увеличиваем счетчик на 1
			j++;
		}
		else { // иначе повторяем попытку ввода, пока все символы не будут равны цифрам
			j = 0;
			printf("Ошибка ввода, могут быть введены только цифры!!!");
			
			return 0;
		}
		strcpy(Vechicle[i].Cost, IntValueCheck); //записываем  строку, которую мы проверяли в строку стоимость
	}
	
	return 0;
}
int ChangeNumberTable2()//Функция для изменения элемента
{
	PrintTable2();
	printf("Введите номер изменяемого элемента > ");
	i = 0;
	while ((ch = getchar()) != '\n')
		if (ch >= 48 && ch <= 57) {
			IntValueCheck[i] = ch;
			i++;
		}
	IntValueCheck[i] = '\0';
	i = 0;
	value = 0, mul = 1;
	for (size_t length = strlen(IntValueCheck) - 1; length != -1; length--) {
		value = IntValueCheck[length] - 48;
		i += value * mul;
		mul = mul * 10;
	}
	i--;
	if ((i < 1 || i > NumberTable2))//Если номер введеного элемента не существует
	{                       //То нас перебросит в меню
		printf("Данный элемент отсутствует");
		system("pause");
		return 0;
	}
	HintTable2();
	printf("|-----т--------------т--------------т------------------т----------т--------------|\n");
	printf("|  N  |      Фамилия |          Имя |         Отчество |      Пол | Год рождения |\n");
	printf("|-----+--------------+--------------+------------------+----------+--------------|\n");
	printf("%s %003i %s %12s %s %12s %s %16s %s %8s %s %04s %s\n", "|", i + 1, "|", Person[i].Surname, "|", Person[i].Name, "|", Person[i].Patronymic, "|", Person[i].Gender, "|        ", Person[i].Year, "|");
	printf("|-----+--------------+--------------+------------------+----------+--------------|\n");
	printf("\nВведите фамилию       >> "); fgets(Person[i].Surname, 12, stdin); Person[i].Surname[strlen(Person[i].Surname) - 1] = 0;
	if (strlen(Person[i].Surname) > 10 || strlen(Person[i].Surname) == 0) {
		printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов");

		return 0;
	}

	printf("Введите имя           >> "); fgets(Person[i].Name, 12, stdin); Person[i].Name[strlen(Person[i].Name) - 1] = 0;
	if (strlen(Person[i].Name) > 10 || strlen(Person[i].Name) == 0) {
		printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов");

		return 0;
	}

	printf("Введите отчество      >> "); fgets(Person[i].Patronymic, 17, stdin); Person[i].Patronymic[strlen(Person[i].Patronymic) - 1] = 0;
	if (strlen(Person[i].Patronymic) > 15 || strlen(Person[i].Patronymic) == 0) {
		printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов");

		return 0;
	}

	printf("Введите пол           >> "); fgets(Person[i].Gender, 11, stdin); Person[i].Gender[strlen(Person[i].Gender) - 1] = 0;
	if (strlen(Person[i].Gender) > 10 || strlen(Person[i].Gender) == 0) {
		printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов");

		return 0;
	}

	printf("Введите год рождения    >> ");   fgets(IntValueCheck, 12, stdin); IntValueCheck[strlen(IntValueCheck) - 1] = 0;
	if (strlen(IntValueCheck) > 10 || strlen(IntValueCheck) == 0) {
		printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов");

		return 0;
	}
	j = 0;
	while (j != strlen(IntValueCheck)) { // проверяем длину строки и состоит ли строка только из цифр
		if (IntValueCheck[i] >= '0' && IntValueCheck[i] <= '9') { //если символ являяется цифрой, то увеличиваем счетчик на 1
			j++;
		}
		else { // иначе повторяем попытку ввода, пока все символы не будут равны цифрам
			j = 0;
			printf("Ошибка ввода, могут быть введены только цифры!!!");

			return 0;
		}
		strcpy(Person[i].Year, IntValueCheck); //записываем  строку, которую мы проверяли в строку стоимость
	}

	system("cls");
	return 0;
}
int ChangeNumberTable3()//Функция для изменения элемента
{
	PrintTable3();
	printf("Введите номер изменяемого элемента > ");
	i = 0;
	while ((ch = getchar()) != '\n')
		if (ch >= 48 && ch <= 57) {
			IntValueCheck[i] = ch;
			i++;
		}
	IntValueCheck[i] = '\0';
	i = 0;
	value = 0, mul = 1;
	for (size_t length = strlen(IntValueCheck) - 1; length != -1; length--) {
		value = IntValueCheck[length] - 48;
		i += value * mul;
		mul = mul * 10;
	}
	i--;
	if ((i < 1 || i > NumberTable3))//Если номер введеного элемента не существует
	{                       //То нас перебросит в меню
		printf("Данный элемент отсутствует");
		system("pause");
		return 0;
	}
	HintTable3();
	printf(" ---------------------------------------------------------------------------\n");
	printf("|  N |    Название | Местоположение |       Директор |    Число сотрудников |\n");
	printf("|----|-------------|----------------|----------------|----------------------|\n");
	printf("%s %02i %s %11s %s %11s %4s %14s %s %20s %s\n", "|", i+1, "|", Company[i].CompanyName, "|", Company[i].Location, "|", Company[i].Director, "|", Company[i].NumberOfEmployees, "|");
	printf("|----|-------------|----------------|----------------|----------------------|\n");
	printf("\nВведите название компании             >> "); fgets(Company[i].CompanyName, 12, stdin); Company[i].CompanyName[strlen(Company[i].CompanyName) - 1] = 0;
	if (strlen(Company[i].CompanyName) > 10 || strlen(Company[i].CompanyName) == 0) {
		printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов!!!");

		return 0;
	}

	printf("Введите местположение компании(город) >> "); fgets(Company[i].Location, 12, stdin); Company[i].Location[strlen(Company[i].Location) - 1] = 0;
	if (strlen(Company[i].Location) > 10 || strlen(Company[i].Location) == 0) {
		printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов!!!");

		return 0;
	}

	printf("Введите фамилию директора компании    >> ");  fgets(Company[i].Director, 12, stdin); Company[i].Director[strlen(Company[i].Director) - 1] = 0;
	if (strlen(Company[i].Director) > 10 || strlen(Company[i].Director) == 0) {
		printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов!!!");

		return 0;
	}

	printf("Введите численность сотрудников       >> "); 
	j = 0;
	while ((ch = getchar()) != '\n' && j < 4)
		if (ch >= 48 && ch <= 57) {
			IntValueCheck[j] = ch;
			j++;
		}
	IntValueCheck[j] = '\0';
	strcpy(Company[i].NumberOfEmployees, IntValueCheck);
	return 0;
}

int ChangeModelTable1() {
	SearchTable1(j);
	if (j == 0) {
		printf("Записей схожих с %s не найдено\n", FirstFieldCheck);
		system("pause");
		return 0;
	}
	printf("Введите номер удаляемого элемента > ");
	i = 0;
	while ((ch = getchar()) != '\n')
		if (ch >= 48 && ch <= 57) {
			IntValueCheck[i] = ch;
			i++;
		}
	IntValueCheck[i] = '\0';
	i = 0;
	value = 0, mul = 1;
	for (size_t length = strlen(IntValueCheck) - 1; length != -1; length--) {
		value = IntValueCheck[length] - 48;
		i += value * mul;
		mul = mul * 10;
	}
	i--;
	if ((i < 1 || i > NumberTable1))//Если номер введеного элемента не существует
	{                       //То нас перебросит в меню
		printf("Данный элемент отсутствует");
		system("pause");
		return 0;
	}
	if (strcmp(Vechicle[i].Model, FirstFieldCheck) != 0) {
		printf("Введенный номер не соответствует ни одному элементу %s\n", FirstFieldCheck);
		system("pause");
		return 0;
	}
	printf("|-----т--------------т-------------т-------------т-------------т-------------т---------------|\n");
	printf("|  N  |       Модель |    Название | Разработчик | Предприятие |         Тип |     Стоимость |\n");
	printf("|-----+--------------+-------------+-------------+-------------+-------------+---------------|\n");
	printf("%s %003i %s %12s %s %11s %s %11s %s %11s %s %11s %s %13s %s\n", "|", i + 1, "|", Vechicle[i].Model, "|", Vechicle[i].Appelation, "|", Vechicle[i].Developer, "|", Vechicle[i].Enterprise, "|", Vechicle[i].Type, "|", Vechicle[i].Cost, "|");
	printf("|-----+--------------+-------------+-------------+-------------+-------------+---------------|\n");
		printf("\nВведите модель техники       >> "); fgets(Vechicle[i].Model, 12, stdin); Vechicle[i].Model[strlen(Vechicle[i].Model) - 1] = 0;
		if (strlen(Vechicle[i].Model) > 10 || strlen(Vechicle[i].Model) == 0) {
			printf("Ошибка ввода\nполе было оставлено пустым, или превышенно допустимое количество символов");
			
			return 0;
		}
		printf("Введите название техники       >> ");   fgets(Vechicle[i].Appelation, 12, stdin); Vechicle[i].Appelation[strlen(Vechicle[i].Appelation) - 1] = 0;
		if (strlen(Vechicle[i].Appelation) > 10 || strlen(Vechicle[i].Appelation) == 0) {
			printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов");
			
			return 0;
		}
		printf("Введите фамилию разработчика   >> ");   fgets(Vechicle[i].Developer, 12, stdin); Vechicle[i].Developer[strlen(Vechicle[i].Developer) - 1] = 0;
		if (strlen(Vechicle[i].Developer) > 10 || strlen(Vechicle[i].Developer) == 0) {
			printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов");
			
			return 0;
		}
		printf("Введите название предприятия   >> ");   fgets(Vechicle[i].Enterprise, 12, stdin); Vechicle[i].Enterprise[strlen(Vechicle[i].Enterprise) - 1] = 0;
		if (strlen(Vechicle[i].Enterprise) > 10 || strlen(Vechicle[i].Enterprise) == 0) {
			printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов");
			
			return 0;
		}
		printf("Введите тип техники            >> ");   fgets(Vechicle[i].Type, 12, stdin); Vechicle[i].Type[strlen(Vechicle[i].Type) - 1] = 0;
		if (strlen(Vechicle[i].Type) > 10 || strlen(Vechicle[i].Type) == 0) {
			printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов");
			
			return 0;
		}
		printf("Введите стоимость техники      >> ");   
		j = 0;
		while ((ch = getchar()) != '\n' && j < 4)
			if (ch >= 48 && ch <= 57) {
				IntValueCheck[j] = ch;
				j++;
			}
		IntValueCheck[j] = '\0';
			strcpy(Vechicle[i].Cost, IntValueCheck); //записываем  строку, которую мы проверяли в строку стоимость
	return 0;
}
int ChangeSurnameTable2() {
	SearchTable2(j);
	if (j == 0) {
		printf("Записей схожих с %s не найдено\n", FirstFieldCheck);
		system("pause");
		return 0;
	}
	printf("Введите номер удаляемого элемента > ");
	i = 0;
	while ((ch = getchar()) != '\n')
		if (ch >= 48 && ch <= 57) {
			IntValueCheck[i] = ch;
			i++;
		}
	IntValueCheck[i] = '\0';
	i = 0;
	value = 0, mul = 1;
	for (size_t length = strlen(IntValueCheck) - 1; length != -1; length--) {
		value = IntValueCheck[length] - 48;
		i += value * mul;
		mul = mul * 10;
	}
	i--;
	if ((i < 1 || i > NumberTable2))//Если номер введеного элемента не существует
	{                       //То нас перебросит в меню
		printf("Данный элемент отсутствует");
		system("pause");
		return 0;
	}
	if (strcmp(Person[i].Surname, FirstFieldCheck) != 0) {
		printf("Под номером %d записи с фамилией %s не существует\n", i+1, FirstFieldCheck);
		system("pause");
		return 0;
	}
		HintTable2();
		printf("|-----т--------------т-------------т-------------т-------------т-------------т---------------|\n");
		printf("|  N |      Фамилия |          Имя |         Отчество |      Пол |  Дата рождения |\n");
		printf("|----|--------------|--------------|------------------|----------|----------------|\n");
		printf("%s %002i %s %12s %s %12s %s %16s %s %8s %s %04s %11s\n", "|", i+1, "|", Person[i].Surname, "|", Person[i].Name, "|", Person[i].Patronymic, "|", Person[i].Gender, "|", Person[i].Year, "|");
		printf("|----|--------------|--------------|------------------|----------|----------------|\n");
		printf("\nВведите фамилию       >> "); fgets(Person[i].Surname, 12, stdin); Person[i].Surname[strlen(Person[i].Surname) - 1] = 0;
		if (strlen(Person[i].Surname) > 10 || strlen(Person[i].Surname) == 0) {
			printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов");

			return 0;
		}

		printf("Введите имя           >> "); fgets(Person[i].Name, 12, stdin); Person[i].Name[strlen(Person[i].Name) - 1] = 0;
		if (strlen(Person[i].Name) > 10 || strlen(Person[i].Name) == 0) {
			printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов");

			return 0;
		}

		printf("Введите отчество      >> "); fgets(Person[i].Patronymic, 17, stdin); Person[i].Patronymic[strlen(Person[i].Patronymic) - 1] = 0;
		if (strlen(Person[i].Patronymic) > 15 || strlen(Person[i].Patronymic) == 0) {
			printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов");

			return 0;
		}

		printf("Введите пол           >> "); fgets(Person[i].Gender, 11, stdin); Person[i].Gender[strlen(Person[i].Gender) - 1] = 0;
		if (strlen(Person[i].Gender) > 10 || strlen(Person[i].Gender) == 0) {
			printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов");

			return 0;
		}

		printf("Введите год рождения    >> ");   
		j = 0;
		while ((ch = getchar()) != '\n' && j < 4)
			if (ch >= 48 && ch <= 57) {
				IntValueCheck[j] = ch;
				j++;
			}
		IntValueCheck[j] = '\0';
			strcpy(Person[i].Year, IntValueCheck); //записываем  строку, которую мы проверяли в строку стоимость
		return 0;
}
int ChangeCompanyNameTable3() {
	SearchTable3(j);
	if (j == 0) {
		printf("Записей схожих с %s не найдено\n", FirstFieldCheck);
		system("pause");
		return 0;
	}
	printf("Введите номер удаляемого элемента > ");
	i = 0;
	while ((ch = getchar()) != '\n')
		if (ch >= 48 && ch <= 57) {
			IntValueCheck[i] = ch;
			i++;
		}
	IntValueCheck[i] = '\0';
	i = 0;
	value = 0, mul = 1;
	for (size_t length = strlen(IntValueCheck) - 1; length != -1; length--) {
		value = IntValueCheck[length] - 48;
		i += value * mul;
		mul = mul * 10;
	}
	i--;
	if ((i < 1 || i > NumberTable3))//Если номер введеного элемента не существует
	{                       //То нас перебросит в меню
		printf("Данный элемент отсутствует");
		system("pause");
		return 0;
	}
	if (strcmp(Company[i].CompanyName, FirstFieldCheck) != 0) {
		printf("Введенный номер не соответствует ни одному элементу %s\n", FirstFieldCheck);
		system("pause");
		return 0;
	}
		printf(" ---------------------------------------------------------------------------\n");
		printf("|  N |    Название | Местоположение |       Директор |    Число сотрудников |\n");
		printf("|----|-------------|----------------|----------------|----------------------|\n");
		printf("%s %02i %s %11s %s %11s %4s %14s %s %20s %s\n", "|", i+1, "|", Company[i].CompanyName, "|", Company[i].Location, "|", Company[i].Director, "|", Company[i].NumberOfEmployees, "|");
		printf("|----|-------------|----------------|----------------|----------------------|\n");
		printf("Введите название компании             >> "); fgets(Company[i].CompanyName, 12, stdin); Company[i].CompanyName[strlen(Company[i].CompanyName) - 1] = 0;
		if (strlen(Company[i].CompanyName) > 10 || strlen(Company[i].CompanyName) == 0) {
			printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов");

			return 0;
		}

		printf("Введите местоположение компании (город) >> "); fgets(Company[i].Location, 12, stdin); Company[i].Location[strlen(Company[i].Location) - 1] = 0;
		if (strlen(Company[i].Location) > 10 || strlen(Company[i].Location) == 0) {
			printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов");

			return 0;
		}

		printf("Введите фамилию директора               >> "); fgets(Company[i].Director, 12, stdin); Company[i].Director[strlen(Company[i].Director) - 1] = 0;
		if (strlen(Company[i].Director) > 15 || strlen(Company[i].Director) == 0) {
			printf("Ошибка ввода, поле было оставлено пустым, или превышенно допустимое количество символов");

			return 0;
		}

		printf("Введите численность сотрудников         >> ");   
		j = 0;
		while ((ch = getchar()) != '\n' && j < 4)
			if (ch >= 48 && ch <= 57) {
				IntValueCheck[j] = ch;
				j++;
			}
		IntValueCheck[j] = '\0';
		strcpy(Company[i].NumberOfEmployees, IntValueCheck);
	return 0;
}

int ChangeTable1() {
	int k = 0, Curr = 0;
	while (Curr >= 0 || Curr <= 2) {
		printf("\n|------------------------------|\n");
		(Curr == 0) ? printf("|Выйти в меню                  |<<<\n") : printf("|Выйти в меню                  |\n");
		printf("|------------------------------|\n");
		(Curr == 1) ? printf("|Изменение по номеру элемента  |<<<\n") : printf("|Изменение по номеру элемента  |\n");
		printf("|------------------------------|\n");
		(Curr == 2) ? printf("|Изменение по модели техники   |<<<\n") : printf("|Изменение по модели техники   |\n");
		printf("|------------------------------|\n");
		k = _getch();
		system("cls");
		if (k == 80) {//Обарботка стрелки вверх
			if (Curr == 2) Curr = 0;
			else Curr++;
		}
		if (k == 72) {//Обработка стрелки вниз
			if (Curr == 0) Curr = 2;
			else Curr--;
		}

		if (k == 27) {//Обработка клавиши ESC
			return 0;
		}

		if (k == 13) {//Обработка клавиши Enter
			switch (Curr)
			{
			case 0:
				return 0;
				break;
			case 1:
				system("cls");
				ChangeNumberTable1();
				system("cls");
				break;
			case 2:
				system("cls");
				ChangeModelTable1();
				system("cls");
				break;
			}
		}
	}
	return Curr;
}
int ChangeTable2() {
	int k = 0, Curr = 0;
	while (Curr >= 0 || Curr <= 2) {
		printf("\n|------------------------------|\n");
		(Curr == 0) ? printf("|Выйти в меню                  |<<<\n") : printf("|Выйти в меню                  |\n");
		printf("|------------------------------|\n");
		(Curr == 1) ? printf("|Изменение по номеру элемента  |<<<\n") : printf("|Изменение по номеру элемента  |\n");
		printf("|------------------------------|\n");
		(Curr == 2) ? printf("|Изменение по модели техники   |<<<\n") : printf("|Изменение по модели техники   |\n");
		printf("|------------------------------|\n");
		k = _getch();
		system("cls");
		if (k == 80) {//Обарботка стрелки вверх
			if (Curr == 2) Curr = 0;
			else Curr++;
		}
		if (k == 72) {//Обработка стрелки вниз
			if (Curr == 0) Curr = 2;
			else Curr--;
		}

		if (k == 27) {//Обработка клавиши ESC
			return 0;
		}

		if (k == 13) {//Обработка клавиши Enter
			switch (Curr)
			{
			case 0:
				return 0;
				break;
			case 1:
				system("cls");
				ChangeNumberTable2();
				system("cls");
				break;
			case 2:
				system("cls");
				ChangeSurnameTable2();
				system("cls");
				break;
			}
		}
	}
	return Curr;
}
int ChangeTable3() {
	int k = 0, Curr = 0;
	system("cls");
	while (Curr >= 0 || Curr <= 2) {
		printf("\n|------------------------------|\n");
		(Curr == 0) ? printf("|Выйти в меню                  |<<<\n") : printf("|Выйти в меню                  |\n");
		printf("|------------------------------|\n");
		(Curr == 1) ? printf("|Изменение по номеру элемента  |<<<\n") : printf("|Изменение по номеру элемента  |\n");
		printf("|------------------------------|\n");
		(Curr == 2) ? printf("|Изменение по модели техники   |<<<\n") : printf("|Изменение по модели техники   |\n");
		printf("|------------------------------|\n");
		k = _getch();
		system("cls");
		if (k == 80) {//Обарботка стрелки вверх
			if (Curr == 2) Curr = 0;
			else Curr++;
		}
		if (k == 72) {//Обработка стрелки вниз
			if (Curr == 0) Curr = 2;
			else Curr--;
		}

		if (k == 27) {//Обработка клавиши ESC
			return 0;
		}


		if (k == 13) {//Обработка клавиши Enter
			switch (Curr)
			{
			case 0:
				return 0;
				break;
			case 1:
				system("cls");
				ChangeNumberTable3();
				system("cls");
				break;
			case 2:
				system("cls");
				ChangeCompanyNameTable3();
				system("cls");
				break;
			}
		}
	}
	return Curr;
}

int RecordTable1()//Функция для записи в файл
{
	FILE* F;
	if ((F = fopen("test1", "wt")) == NULL)//Если не удалось открыть файл
	{                                         //нас переюросит в мею
		printf("Невозможно открыть для записи файл'\n");
		return 0;
	}
	fprintf(F, "%i\n", NumberTable1);
	for (i = 0; i < NumberTable1; i++)
		fprintf(F, "%s\t%s\t%s\t%s\t%s\t%s\n", Vechicle[i].Model, Vechicle[i].Appelation, Vechicle[i].Developer, Vechicle[i].Enterprise, Vechicle[i].Type, Vechicle[i].Cost);

	fclose(F);
	printf("Запись в файл выполена успешно\n");
	
	return 0;
}
int RecordTable2()//Функция для записи в файл
{
	FILE* F;
	if ((F = fopen("test2", "wt")) == NULL)//Если не удалось открыть файл
	{                                         //нас переюросит в мею
		printf("Невозможно открыть для записи файл\n");
		return 0;
	}
	fprintf(F, "%i\n", NumberTable2);
	for (i = 0; i < NumberTable2; i++)
		fprintf(F, "%s %s %s %s %04s", Person[i].Surname, Person[i].Name, Person[i].Patronymic, Person[i].Gender, Person[i].Year);
	fclose(F);
	printf("Запись в файл выполена успешно\n");

	return 0;
}
int RecordTable3()//Функция для записи в файл
{
	FILE* F;
	if ((F = fopen("test3", "wt")) == NULL)//Если не удалось открыть файл
	{                                         //нас переюросит в мею
		printf("Невозможно открыть для записи файл\n");
		return 0;
	}
	fprintf(F, "%i\n", NumberTable3);
	for (i = 0; i < NumberTable3; i++)
		fprintf(F, "%s\t%s\t%s\t%s\n", Company[i].CompanyName, Company[i].Location, Company[i].Director, Company[i].NumberOfEmployees);

	fclose(F);
	printf("Запись в файл выполена успешно\n");

	return 0;
}

int ReadTable1()//Функция для чтения из файла
{
	int NofScannedArguments = 0;
	FILE* F;
	if ((F = fopen("test1", "rt")) == NULL)//Если не удалось открыть файл
	{                                         //нас переюросит в мею
		printf("Невозможно открыть для чтения файл\n");
		return 1;
	}

	fscanf_s(F, "%i", &NumberTable1);
	for (i = 0; i < NumberTable1; i++) {
		NofScannedArguments = fscanf(F, "%s\t%s\t%s\t%s\t%s\t%s", Vechicle[i].Model, Vechicle[i].Appelation, Vechicle[i].Developer, Vechicle[i].Enterprise, Vechicle[i].Type, Vechicle[i].Cost);
		if (NofScannedArguments == 1) /* should be one number */
		{
			return 0; /* failure, assumptions of program are not met */
		}
	}
	fclose(F);
	printf("Чтение из файла выполено успешно\n");
	
	return 0;
}
int ReadTable2()//Функция для чтения из файла
{
	int NofScannedArguments = 0;
	FILE* F;
	if ((F = fopen("test2", "rt")) == NULL)//Если не удалось открыть файл
	{                                         //нас переюросит в мею
		printf("Невозможно открыть для чтения файл\n");
		return 0;
	}

	fscanf_s(F, "%i", &NumberTable2);
	for (i = 0; i < NumberTable2; i++) {
		NofScannedArguments = fscanf(F, "%s %s %s %s %04s", Person[i].Surname, Person[i].Name, Person[i].Patronymic, Person[i].Gender, Person[i].Year);
		if (NofScannedArguments == 1) /* should be one number */
		{
			return 0; /* failure, assumptions of program are not met */
		}
	}
	fclose(F);
	printf("Чтение из файла выполено успешно\n");

	return 0;
}
int ReadTable3()//Функция для чтения из файла
{
	int NofScannedArguments = 0;
	FILE* F;
	if ((F = fopen("test3", "rt")) == NULL)//Если не удалось открыть файл
	{                                         //нас переюросит в мею
		printf("Невозможно открыть для чтения файл\n");
		return 0;
	}

	fscanf_s(F, "%i", &NumberTable3);
	for (i = 0; i < NumberTable3; i++) {
		NofScannedArguments = fscanf(F, "%s\t%s\t%s\t%s", Company[i].CompanyName, Company[i].Location, Company[i].Director, Company[i].NumberOfEmployees);
		if (NofScannedArguments == 1) /* should be one number */
		{
			return 0; /* failure, assumptions of program are not met */
		}
	}
	fclose(F);
	printf("Чтение из файла выполено успешно\n");

	return 0;
}

int SortTable1() {
	Vechicles Temp;
	int k = 0, Curr = 0;
	while (Curr >= 0 || Curr <= 8) {
		              printf("\n|-----------------------------------|\n");
		(Curr == 0) ? printf("|Выход в главное меню               |<<<\n") : printf("|Выход в главное меню               |\n");
		              printf("|-----------------------------------|\n");
		(Curr == 1) ? printf("|Сортировка по модели               |<<<\n") : printf("|Сортировка по модели               |\n");
		              printf("|-----------------------------------|\n");
		(Curr == 2) ? printf("|Сортировка по названию             |<<<\n") : printf("|Сортировка по названию             |\n");
		              printf("|-----------------------------------|\n");
		(Curr == 3) ? printf("|Сортировка по фамилии разработчика |<<<\n") : printf("|Сортировка по фамилии разработчика |\n");
		              printf("|-----------------------------------|\n");
		(Curr == 4) ? printf("|Сортировка по предприятию          |<<<\n") : printf("|Сортировка по предприятию          |\n");
		              printf("|-----------------------------------|\n");
		(Curr == 5) ? printf("|Сортировка по типу техники         |<<<\n") : printf("|Сортировка по типу техники         |\n");
		              printf("|-----------------------------------|\n");
		(Curr == 6) ? printf("|Сортировка по стоимости            |<<<\n") : printf("|Сортировка по стоимости            |\n");
	                  printf("|-----------------------------------|\n");
		k = _getch();
		system("cls");
		if (k == 80) {//Обарботка стрелки вверх
			if (Curr == 8) Curr = 0;
			else Curr++;
		}
		if (k == 72) {//Обработка стрелки вниз
			if (Curr == 0) Curr = 8;
			else Curr--;
		}

		if (k == 27) {//Обработка клавиши ESC
			return 0;
		}

		if (k == 13) {//Обработка клавиши Enter
			switch (Curr)
			{
			case 0:
				return 0;
				break;
			case 1:
				system("cls");
				for (j = NumberTable1 - 1; j > 0; j--)
					for (i = 0; i < j; i++)
						if (strcmp(Vechicle[i].Model, Vechicle[i + 1].Model) > 0)
						{
							Temp = Vechicle[i];
							Vechicle[i] = Vechicle[i + 1];
							Vechicle[i + 1] = Temp;
						}
				PrintTable1();
				break;
			case 2:
				system("cls");
				for (j = NumberTable1 - 1; j > 0; j--)
					for (i = 0; i < j; i++)
						if (strcmp(Vechicle[i].Appelation, Vechicle[i + 1].Appelation) > 0)
						{
							Temp = Vechicle[i];
							Vechicle[i] = Vechicle[i + 1];
							Vechicle[i + 1] = Temp;
						}
				PrintTable1();
				break;
			case 3:
				system("cls");
				for (j = NumberTable1 - 1; j > 0; j--)
					for (i = 0; i < j; i++)
						if (strcmp(Vechicle[i].Developer, Vechicle[i + 1].Developer) > 0)
						{
							Temp = Vechicle[i];
							Vechicle[i] = Vechicle[i + 1];
							Vechicle[i + 1] = Temp;
						}
				PrintTable1();
				break;
			case 4:
				system("cls");
				for (j = NumberTable1 - 1; j > 0; j--)
					for (i = 0; i < j; i++)
						if (strcmp(Vechicle[i].Enterprise, Vechicle[i + 1].Enterprise) > 0)
						{
							Temp = Vechicle[i];
							Vechicle[i] = Vechicle[i + 1];
							Vechicle[i + 1] = Temp;
						}
				PrintTable1();
				break;
			case 5:
				system("cls");
				for (j = NumberTable1 - 1; j > 0; j--)
					for (i = 0; i < j; i++)
						if (strcmp(Vechicle[i].Type, Vechicle[i + 1].Type) > 0)
						{
							Temp = Vechicle[i];
							Vechicle[i] = Vechicle[i + 1];
							Vechicle[i + 1] = Temp;
						}
				PrintTable1();
				break;
			case 6:
				system("cls");
				for (j = NumberTable1 - 1; j > 0; j--)
					for (i = 0; i < j; i++)
						if (strcmp(Vechicle[i].Cost, Vechicle[i + 1].Cost) > 0)
						{
							Temp = Vechicle[i];
							Vechicle[i] = Vechicle[i + 1];
							Vechicle[i + 1] = Temp;
						}
				PrintTable1();
				break;
			}
			}
		}
	return Curr;
}
int SortTable2()
{
	
	Persons Temp;
	int k = 0, Curr = 0;
	while (Curr >= 0 || Curr <= 5) {
		              printf("\n|-----------------------------------|\n");
		(Curr == 0) ? printf("|Выход в главное меню               |<<<\n") : printf("|Выход в главное меню               |\n");
		              printf("|-----------------------------------|\n");
		(Curr == 1) ? printf("|Сортировка по фамилии              |<<<\n") : printf("|Сортировка по фамилии              |\n");
		              printf("|-----------------------------------|\n");
		(Curr == 2) ? printf("|Сортировка по имени                |<<<\n") : printf("|Сортировка по имени                |\n");
	                  printf("|-----------------------------------|\n");
		(Curr == 3) ? printf("|Сортировка по отчеству             |<<<\n") : printf("|Сортировка по отчеству             |\n");
		              printf("|-----------------------------------|\n");
		(Curr == 4) ? printf("|Сортировка по полу                 |<<<\n") : printf("|Сортировка по полу                 |\n");
		              printf("|-----------------------------------|\n");
		(Curr == 5) ? printf("|Сортировка по году рождения        |<<<\n") : printf("|Сортировка по году рождения        |\n");
		              printf("|-----------------------------------|\n");
		k = _getch();
		system("cls");
		if (k == 80) {//Обарботка стрелки вверх
			if (Curr == 5) Curr = 0;
			else Curr++;
		}
		if (k == 72) {//Обработка стрелки вниз
			if (Curr == 0) Curr = 5;
			else Curr--;
		}

		if (k == 27) {//Обработка клавиши ESC
			return 0;
		}

		if (k == 13) {//Обработка клавиши Enter
			switch (Curr)
			{
			case 0:
				return 0;
				break;
			case 1:
				system("cls");
				for (j = NumberTable2 - 1; j > 0; j--)
					for (i = 0; i < j; i++)
						if (strcmp(Person[i].Surname, Person[i + 1].Surname) > 0)
						{
							Temp = Person[i];
							Person[i] = Person[i + 1];
							Person[i + 1] = Temp;
						}
				PrintTable2();
				break;
			case 2:
				system("cls");
				for (j = NumberTable2 - 1; j > 0; j--)
					for (i = 0; i < j; i++)
						if (strcmp(Person[i].Name, Person[i + 1].Name) > 0)
						{
							Temp = Person[i];
							Person[i] = Person[i + 1];
							Person[i + 1] = Temp;
						}
				PrintTable2();
				break;
			case 3:
				system("cls");
				for (j = NumberTable2 - 1; j > 0; j--)
					for (i = 0; i < j; i++)
						if (strcmp(Person[i].Patronymic, Person[i + 1].Patronymic) > 0)
						{
							Temp = Person[i];
							Person[i] = Person[i + 1];
							Person[i + 1] = Temp;
						}
				PrintTable2();
				break;
			case 4:
				system("cls");
				for (j = NumberTable2 - 1; j > 0; j--)
					for (i = 0; i < j; i++)
						if (strcmp(Person[i].Gender, Person[i + 1].Gender) > 0)
						{
							Temp = Person[i];
							Person[i] = Person[i + 1];
							Person[i + 1] = Temp;
						}
				PrintTable2();
				break;
			case 5:
				system("cls");
				for (j = NumberTable2 - 1; j > 0; j--) {
					for (i = 0; i < j; i++) {
						if (strcmp(Person[i].Year, Person[i + 1].Year) > 0)
						{
							Temp = Person[i];
							Person[i] = Person[i + 1];
							Person[i + 1] = Temp;
						}
						if (strlen(Person[i].Year) > strlen(Person[i + 1].Year)) {
							Temp = Person[i];
							Person[i] = Person[i + 1];
							Person[i + 1] = Temp;
						}
					}
				}
				PrintTable2();
				break;
			}
		}
	}
	return Curr;
	}
int SortTable3() {
	Companies Temp;
	int k = 0, Curr = 0;
	while (Curr >= 0 || Curr <= 4) {
		              printf("\n|-----------------------------------|\n");
		(Curr == 0) ? printf("|Выход в главное меню               |<<<\n") : printf("|Выход в главное меню               |\n");
		              printf("|-----------------------------------|\n");
		(Curr == 1) ? printf("|Сортировка по названию компании    |<<<\n") : printf("|Сортировка по названию компании    |\n");
					  printf("|-----------------------------------|\n");
		(Curr == 2) ? printf("|Сортировка по местополжению        |<<<\n") : printf("|Сортировка по местополжению        |\n");
					  printf("|-----------------------------------|\n");
		(Curr == 3) ? printf("|Сортировка по фамилии директора    |<<<\n") : printf("|Сортировка по фамилии директора    |\n");
					  printf("|-----------------------------------|\n");
		(Curr == 4) ? printf("|Сортировка по числу сотрудников    |<<<\n") : printf("|Сортировка по числу сотрудников    |\n");
					  printf("|-----------------------------------|\n");
		k = _getch();
		system("cls");
		if (k == 80) {//Обарботка стрелки вверх
			if (Curr == 4) Curr = 0;
			else Curr++;
		}
		if (k == 72) {//Обработка стрелки вниз
			if (Curr == 0) Curr = 4;
			else Curr--;
		}

		if (k == 27) {//Обработка клавиши ESC
			return 0;
		}

		if (k == 13) {//Обработка клавиши Enter
			switch (Curr)
			{
			case 0:
				return 0;
				break;
			case 1:
				system("cls");
				for (j = NumberTable3 - 1; j > 0; j--)
					for (i = 0; i < j; i++)
						if (strcmp(Company[i].CompanyName, Company[i + 1].CompanyName) > 0)
						{
							Temp = Company[i];
							Company[i] = Company[i + 1];
							Company[i + 1] = Temp;
						}
				PrintTable3();
				break;
			case 2:
				system("cls");
				for (j = NumberTable3 - 1; j > 0; j--)
					for (i = 0; i < j; i++)
						if (strcmp(Company[i].Location, Company[i + 1].Location) > 0)
						{
							Temp = Company[i];
							Company[i] = Company[i + 1];
							Company[i + 1] = Temp;
						}
				PrintTable3();
				break;
			case 3:
				system("cls");
				for (j = NumberTable3 - 1; j > 0; j--)
					for (i = 0; i < j; i++)
						if (strcmp(Company[i].Director, Company[i + 1].Director) > 0)
						{
							Temp = Company[i];
							Company[i] = Company[i + 1];
							Company[i + 1] = Temp;
						}
				PrintTable3();
				break;
			case 4:
				system("cls");
				for (j = NumberTable3 - 1; j > 0; j--) {
					for (i = 0; i < j; i++) {
						if (strcmp(Company[i].NumberOfEmployees, Company[i + 1].NumberOfEmployees) > 0)
						{
							Temp = Company[i];
							Company[i] = Company[i + 1];
							Company[i + 1] = Temp;
						}
						if (strlen(Company[i].NumberOfEmployees) > strlen(Company[i + 1].NumberOfEmployees)) {
							Temp = Company[i];
							Company[i] = Company[i + 1];
							Company[i + 1] = Temp;
						}
					}
				}
				PrintTable3();
				break;
			}
			}
		}
	return Curr;
	}

int Table1()
{
	int k = 0, Curr = 0;
	while (Curr >= 0 || Curr <= 8) {
		printf("Таблица No1 (техники): название, модель, разработчик, предприятие, стоимость, тип.\n");
		printf("Перемещение по меню происходит с помощью стрелок клавиатуры\nВыбор пункта с помощью Enter, выход из программы ESC\n");
		printf("\n|------------------------------|\n");
		(Curr == 0) ? printf("|Выйти в главное меню          |<<<\n") : printf("|Выйти в главное меню          |\n");
		printf("|------------------------------|\n");
		(Curr == 1) ? printf("|Вывод информации              |<<<\n") : printf("|Вывод информации              |\n");
		printf("|------------------------------|\n");
		(Curr == 2) ? printf("|Ввод информации               |<<<\n") : printf("|Ввод информации               |\n");
		printf("|------------------------------|\n");
		(Curr == 3) ? printf("|Удаление информации           |<<<\n") : printf("|Удаление информации           |\n");
		printf("|------------------------------|\n");
		(Curr == 4) ? printf("|Изменение информации          |<<<\n") : printf("|Изменение информации          |\n");
		printf("|------------------------------|\n");
		(Curr == 5) ? printf("|Поиск информации              |<<<\n") : printf("|Поиск информации              |\n");
		printf("|------------------------------|\n");
		(Curr == 6) ? printf("|Запись информации в файл      |<<<\n") : printf("|Запись информации в файл      |\n");
		printf("|------------------------------|\n");
		(Curr == 7) ? printf("|Чтение информации из файла    |<<<\n") : printf("|Чтение информации из файла    |\n");
		printf("|------------------------------|\n");
		(Curr == 8) ? printf("|Сортировка информации         |<<<\n") : printf("|Сортировка информации         |\n");
		printf("|------------------------------|\n");
		k = _getch();
		system("cls");
		if (k == 80) {//Обарботка стрелки вверх
			if (Curr == 8) Curr = 0;
			else Curr++;
		}
		if (k == 72) {//Обработка стрелки вниз
			if (Curr == 0) Curr = 8;
			else Curr--;
		}

		if (k == 27) {//Обработка клавиши ESC
			return 0;
		}

		if (k == 13) {//Обработка клавиши Enter
			switch (Curr)
			{
			case 0:
				return 0;
				break;
			case 1:
				system("cls");
				PrintTable1();
				break;
			case 2:
				system("cls");
				InsertTable1();
				break;
			case 3:
				system("cls");
				RemoveTable1();
				break;
			case 4:
				system("cls");
				ChangeTable1();
				break;
			case 5:
				system("cls");
				SearchTable1();
				break;
			case 6:
				system("cls");
				RecordTable1();
				break;
			case 7:
				system("cls");
				ReadTable1();
				break;
			case 8:
				system("cls");
				SortTable1();
				break;
			}
		}
	}
	return Curr;
}
int Table2()//главная функция
{
	int k = 0, Curr = 0;
	while (Curr >= 0 || Curr <= 8) {
		printf("Таблица No2(разработчиков) : ФИО, год рождения, пол\n");
		printf("Перемещение по меню происходит с помощью стрелок клавиатуры\nВыбор пункта с помощью Enter, выход из программы ESC\n");
		printf("\n|------------------------------|\n");
		(Curr == 0) ? printf("|Выйти в главное меню          |<<<\n") : printf("|Выйти в главное меню          |\n");
		printf("|------------------------------|\n");
		(Curr == 1) ? printf("|Вывод информации              |<<<\n") : printf("|Вывод информации              |\n");
		printf("|------------------------------|\n");
		(Curr == 2) ? printf("|Ввод информации               |<<<\n") : printf("|Ввод информации               |\n");
		printf("|------------------------------|\n");
		(Curr == 3) ? printf("|Удаление информации           |<<<\n") : printf("|Удаление информации           |\n");
		printf("|------------------------------|\n");
		(Curr == 4) ? printf("|Изменение информации          |<<<\n") : printf("|Изменение информации          |\n");
		printf("|------------------------------|\n");
		(Curr == 5) ? printf("|Поиск информации              |<<<\n") : printf("|Поиск информации              |\n");
		printf("|------------------------------|\n");
		(Curr == 6) ? printf("|Запись информации в файл      |<<<\n") : printf("|Запись информации в файл      |\n");
		printf("|------------------------------|\n");
		(Curr == 7) ? printf("|Чтение информации из файла    |<<<\n") : printf("|Чтение информации из файла    |\n");
		printf("|------------------------------|\n");
		(Curr == 8) ? printf("|Сортировка информации         |<<<\n") : printf("|Сортировка информации         |\n");
		printf("|------------------------------|\n");
		k = _getch();
		system("cls");
		if (k == 80) {//Обарботка стрелки вверх
			if (Curr == 8) Curr = 0;
			else Curr++;
		}
		if (k == 72) {//Обработка стрелки вниз
			if (Curr == 0) Curr = 8;
			else Curr--;
		}

		if (k == 27) {//Обработка клавиши ESC
			return 0;
		}

		if (k == 13) {//Обработка клавиши Enter
			switch (Curr)
			{
			case 0:
				return 0;
				break;
			case 1:
				system("cls");
				PrintTable2();
				break;
			case 2:
				system("cls");
				InsertTable2();
				break;
			case 3:
				system("cls");
				RemoveTable2();
				break;
			case 4:
				system("cls");
				ChangeTable2();
				break;
			case 5:
				system("cls");
				SearchTable2();
				break;
			case 6:
				system("cls");
				RecordTable2();
				break;
			case 7:
				system("cls");
				ReadTable2();
				break;
			case 8:
				system("cls");
				SortTable2();
				break;
			}
		}
	}
	return Curr;
}
int Table3()
{
	printf("");
	int k = 0, Curr = 0;
	while (Curr >= 0 || Curr <= 8) {
		printf("Таблица No3(предприятий) : название, место нахождения, количество работников, директор.\n");
		printf("Перемещение по меню происходит с помощью стрелок клавиатуры\nВыбор пункта с помощью Enter, выход из программы ESC\n");
		              printf("\n|------------------------------|\n");
		(Curr == 0) ? printf("|Выйти в главное меню          |<<<\n") : printf("|Выйти в главное меню          |\n");
					  printf("|------------------------------|\n");
		(Curr == 1) ? printf("|Вывод информации              |<<<\n") : printf("|Вывод информации              |\n");
					  printf("|------------------------------|\n");
		(Curr == 2) ? printf("|Ввод информации               |<<<\n") : printf("|Ввод информации               |\n");
				      printf("|------------------------------|\n");
		(Curr == 3) ? printf("|Удаление информации           |<<<\n") : printf("|Удаление информации           |\n");
					  printf("|------------------------------|\n");
		(Curr == 4) ? printf("|Изменение информации          |<<<\n") : printf("|Изменение информации          |\n");
					  printf("|------------------------------|\n");
		(Curr == 5) ? printf("|Поиск информации              |<<<\n") : printf("|Поиск информации              |\n");
		              printf("|------------------------------|\n");
		(Curr == 6) ? printf("|Запись информации в файл      |<<<\n") : printf("|Запись информации в файл      |\n");
		              printf("|------------------------------|\n");
		(Curr == 7) ? printf("|Чтение информации из файла    |<<<\n") : printf("|Чтение информации из файла    |\n");
		              printf("|------------------------------|\n");
		(Curr == 8) ? printf("|Сортировка информации         |<<<\n") : printf("|Сортировка информации         |\n");
		              printf("|------------------------------|\n");
		k = _getch();
		system("cls");
		if (k == 80) {//Обарботка стрелки вверх
			if (Curr == 8) Curr = 0;
			else Curr++;
		}
		if (k == 72) {//Обработка стрелки вниз
			if (Curr == 0) Curr = 8;
			else Curr--;
		}

		if (k == 27) {//Обработка клавиши ESC
			return 0;
		}

		if (k == 13) {//Обработка клавиши Enter
			switch (Curr)
			{
			case 0:
				return 0;
				break;
			case 1:
				system("cls");
				PrintTable3();
				break;
			case 2:
				system("cls");
				InsertTable3();
				break;
			case 3:
				system("cls");
				RemoveTable3();
				break;
			case 4:
				system("cls");
				ChangeTable3();
				break;
			case 5:
				system("cls");
				SearchTable3();
				break;
			case 6:
				system("cls");
				RecordTable3();
				break;
			case 7:
				system("cls");
				ReadTable3();
				break;
			case 8:
				system("cls");
				SortTable3();
				break;
			}
			}
		}
	return Curr;
}

//Главное меню

int main() {
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int k = 0, Curr = 0;
	while (Curr >= 0 || Curr <= 3) {
		printf("Таблица No1 (техники): название, модель, разработчик, предприятие, стоимость, тип.\n");
		printf("Таблица No2(разработчиков) : ФИО, год рождения, пол\n");
		printf("Таблица No3(предприятий) : название, место нахождения, количество работников, директор.\n");
		printf("Перемещение по меню происходит с помощью стрелок клавиатуры\nВыбор пункта с помощью Enter, выход из программы ESC\n");
		              printf("\n|----------|\n");
		(Curr == 0) ? printf("|Выход     |<<<\n") : printf("|Выход     |\n");
					  printf("|----------|\n");
		(Curr == 1) ? printf("|Таблица 1 |<<<\n") : printf("|Таблица 1 |\n");
		              printf("|----------|\n");
		(Curr == 2) ? printf("|Таблица 2 |<<<\n") : printf("|Таблица 2 |\n");
		              printf("|----------|\n");
		(Curr == 3) ? printf("|Таблица 3 |<<<\n") : printf("|Таблица 3 |\n");
		              printf("|––––––––––|\n");
		k = _getch();
		system("cls");
		if (k == 80) {//Обарботка стрелки вверх
			if (Curr == 3) Curr = 0;
			else Curr++;
		}
		if (k == 72) {//Обработка стрелки вниз
			if (Curr == 0) Curr = 3;
			else Curr--;
		}
		if (k == 27) {//Обработка клавиши ESC
			printf("Досвидания :-)");
			return 0;
		}
		if (k == 13) {//Обработка клавиши Enter
			switch (Curr)
			{
			case 0:
				printf("Досвидания :-)");
				return 0;
				break;
			case 1:
				system("cls");
				Table1();
				break;
			case 2:
				system("cls");
				Table2();
				break;
			case 3:
				system("cls");
				Table3();
				break;
			}
		}
	}

	return Curr;
}