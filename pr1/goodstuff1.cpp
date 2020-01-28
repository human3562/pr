#include "pch.h"
#include <iostream>
#include <ctime> // для генеирования псевдо-случайных чисел в задании №9
#include <string> // для 23
#include <vector> // для 28
//#include <math.h>

using namespace std;

void task1() {
	int a = 2+2*2;
	std::cout <<"Результат вычисления выражения 2+2*2 = " << a << std::endl;
}
//сдано

void task2() {
	int a = 3;
	int b = 3.994;

	double da = 3;
	double db = 3.14;

	std::cout << a << "\n" << b << "\n" << da << "\n" << db << "\n" << std::endl; // Результат обьясняется тем, что переменная типа int может принимать только целое значение
}
//сдано

void task3() {
	int a1, b1;
	std::cin >> a1 >> b1;
	std::cout << a1 + b1 << "\n" << a1 - b1 << "\n" << a1 * b1 << "\n" << a1 / b1 << "\n" << std::endl; //при делении выделяется только целая часть, т.к. переменная типа int может принимать только целые значения.
	
	double a2, b2;
	std::cin >> a2 >> b2;
	std::cout << a2 + b2 << "\n" << a2 - b2 << "\n" << a2 * b2 << "\n" << a2 / b2 << "\n" << std::endl;
	int a3; double b3;
	std::cin >> a3 >> b3;
	std::cout << a3 + b3 << "\n" << a3 - b3 << "\n" << a3 * b3 << "\n" << a3 / b3 << "\n" << std::endl;

	double a4; int b4;
	std::cin >> a4 >> b4;
	std::cout << a4 + b4 << "\n" << a4 - b4 << "\n" << a4 * b4 << "\n" << a4 / b4 << "\n" << std::endl;
	
}
//сдано

void task4() {
	int a, b;
	std::cin >> a >> b;
	
	//с использованием третьей переменной

	int t = a;
	a = b;
	b = t;
	std::cout << a << " " << b << std::endl;

	//без использования третьей переменной
	std::cin >> a >> b;
	a = a + b;
	b = a - b;
	a = a - b;
	std::cout << a << " " << b << std::endl;

}
//сдано

void task5() {
	double x0, v0, t;
	const double g = -9.8;
	std::cout << "Введите начальную высоту, начальную скорость, и время падения." << std::endl;
	std::cin >> x0 >> v0 >> t;
	double x = g * t * t / 2; 
	double x1 = (1.0 / 2.0) * g * t * t;
	double x2 = (g*t*t) / 2;
	//std::cout << "за время t = " << t << ", падая с начальной высоты x0 = " << x0 << "с c начальной скоростью v0 = " << v0 << " тело окажется на координате x = " << x << std::endl;
	std::cout << x << " " << x1 << " " << x2 << std::endl;
}
//сдано

void task6() {
	double a, b, c;
	std::cout << "Введите а, b, c" << std::endl;
	std::cin >> a >> b >> c;
	
	double D = b * b - 4 * a * c;

	if (a == 0 && b != 0) { cout << "x = -1"; }
	else if (D < 0) {
		std::cout << "Нет корней" << std::endl;
	} else if(D!=0){
		double x1 = (-b + sqrt(D)) / (2 * a);
		double x2 = (-b - sqrt(D)) / (2 * a);

		std::cout << "x1 = " << x1 << "\n" << "x2 = " << x2 << std::endl;
	}
	else {
		double x1 = (-b + sqrt(D)) / (2 * a);
		std::cout << "x1 = x2 = " << x1 << std::endl;
	}
}


void task7() {
	int option = 0;
	double S = 0;
	double p = 0;

	std::cout << "Введите метод решения (1 для вычисления по длинам сторон треугольника) (2 для вычисления по координатам вершин) " << std::endl;
	std::cin >>  option;

	switch (option) {

	case 1:
		double a, b, c;
		std::cout << "Введите через пробел длины сторон треугольника" << std::endl;
		std::cin >> a >> b >> c;

		if (a + b > c && b + c > a && c + a > b) {
			p = 0.5 * (a + b + c); //по формуле Герона
			S = sqrt(p * (p - a) * (p - b) * (p - c));
			std::cout << "S = " << S << std::endl;
		}
		else {
			cout << "Введенный треугольник не существует." << endl;
		}
		break;

	case 2:
		double x1, y1, x2, y2, x3, y3;
		std::cout << "Введите координаты вершин треугольника" << std::endl;
		std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		S = 0.5 * abs((x2-x1)*(y3-y1) - (x3-x1)*(y2-y1));
		std::cout << "S = " << S << std::endl;
		break;

	default:
		std::cout << "Выбран неверный метод решения." << std::endl;
		break;
	}

}
//сдано

void task8() {
	double a, b, result;
	char op;  //char хранит в себе один символ в определенной кодировке
	op = '#';
	std::cin >> a >> op >> b;
	
	switch (op) {
	case '+':
		result = a + b;
		std::cout << result << std::endl;
		break;

	default:
		std::cout << "Неверный оператор" << std::endl;
		break;

	case '-':
		result = a - b;
		std::cout << result << std::endl;
		break;

	case '*':
		result = a * b;
		std::cout << result << std::endl;
		break;

	case '/':
		if (b != 0) {
			result = a / b;
			std::cout << result << std::endl;
		}
		else cout << "Деление на ноль" << endl;
		break;


	}
}
//сдано

void task9() {
	int n;
	srand(unsigned(time(0)));

	bool end = false;

	while (!end) {

		n = (rand() % 101);

		int gn = 0;

		bool win = false;
		std::cout << "Угадай число." << std::endl;

		for(int i = 0; i<10; i++){

			std::cin >> gn;

			if (gn == n) {
				std::cout << "Угадал!" << std::endl;
				win = true;
				break;
			}
			if (gn > n) {
				std::cout << "Загаданное число меньше." << std::endl;
				continue;
			}
			if (gn < n) {
				std::cout << "Загаданное число больше." << std::endl;
			}

		}

		if (!win) {
			std::cout << "Вы проиграли. Было загадано: " << n << std::endl;
		}
		int c = 0;

		incorrect:
		std::cout << "Ещё раз? (1 - да; 2 - нет)" << std::endl;
		std::cin >> c;
		switch (c) {
		case 1:
			system("CLS");
			break;
		case 2:
			end = true;
			break;
		default:
			system("CLS");
			goto incorrect;
			break;
		}
	}
}
//сдано

void task10() {
	double n; int p;
	std::cout << "Введите число и степень в которую нужно его ввести." << std::endl;
	std::cin >> n >> p;
	double res = n;
	for (int i = 0; i < abs(p)-1; i++) {
		res *= n;
	}
	if (p < 0 && n == 0) cout << "Деление на ноль" << endl;
	else{
	if (p == 0) res = 1;
	if (p < 0) res = 1 / res;
	cout << "Ответ: " << res << endl;
	}
}
//сдано

void task11() {
	int n;
	std::cout << "Введите число факториал которого нужно найти." << std::endl;
	std::cin >> n;
	int res = n;
	for (int i = 1; i < n; i++) {
		res *= i;
	}
	if (n == 0) cout << "1"; 
	else
	std::cout << res << std::endl;
}
//сдано

void task12() {
	int n;

	cout << "Введите число" << endl;
	cin >> n;

	for (int i = 2; i <= (sqrt(n)); i++) {
		if (n%i == 0) {
			cout << "Введенное число составное" << endl;
			return;
		}
	}
	cout << "Введенное число простое." << endl;
	
}

void task13() {
	int n;
	cout << "Введите число" << endl;
	cin >> n;
	int k = 0;
	for (int i = 1; i <= n; i *= 2)
		k++;
	cout << "Количество степеней двойки в введенном числе: \n" << k << endl;
}
//сдано

void task14() {
	int s;
	int l1, l2, r1, r2;
	int x1 = 0, x2 = 0;

	bool found = false;
	cout << "Введите s, l1, r1, l2, r2" << endl;
	cin >> s >> l1 >> r1 >> l2 >> r2;

	//Сравниваем каждое число из промежутка l1-r1 с числами промежутка l2-r2, из всех найденых чисел берем минимальное x1 и выводим.

	for (int i = l1; i <= r1; i++) { 
		for (int j = l2; j <= r2; j++) {
			if (i + j == s) {
				//cout << i << " " << j << endl;
				x1 = i;
				x2 = j;
				found = true;
				break; //после нахождения пары не имеет смысла дальше сравнивать, так как дальше сумма будет только возрастать.
			}
		}
		if (found) break;
	}
	if (!found) {
		cout << -1 << endl;
	}
	else cout << x1 << " " << x2 << endl;
}
//сдано

void task15() {
	int n;
	cout << "Введите кол-во сигналов" << endl;
	cin >> n;
	
	int *a = new int[n]; 

	cout << "Введите все числа через пробел" << endl;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; i++) {
		int *b = new int[i];

		for (int j = 0; j < i; j++) { //заполняем массив b уже поступившими сигналами (i)
			b[j] = a[j];
			
		}
		
		for (int j = 0; j < i; j++) { //сортировка пузырьком
			for (int k = 0; k < i - j - 1; k++) {
				if (b[k] > b[k + 1]) {
					int t = b[k + 1];
					b[k + 1] = b[k];
					b[k] = t;
				}
			}
		}

		int s = i;
		if (s > 5) s = 5;
		for (int j = s-1; j >= 0; j--) {
			cout << b[j] << " ";
		}

		delete[] b;
		cout << endl;
	}

	delete[] a;
}
//сдано

//task 16
void factorization(int n) {
	int count1 = 0;
	while (n % 2 == 0) {
		//cout << 2 << "*";
		n = n / 2;
		count1++;
	}
	if (count1 > 1) cout << 2 << "^" << count1;
	else if(count1>0) cout << 2 << "*";
	for (int i = 3; i <= sqrt(n); i += 1) {
		int count2 = 0;
		int num2 = 0;
		while (n % i == 0) {
			//cout << i << "*";
			num2 = i;
			n = n / i;
			count2++;
		}
		if(num2 > 0 && count2 > 0) cout << num2 << "^" << count2 << "*";
	}
	if (n > 2) cout << n << " ";
}
void task16() {
	int x;
	cin >> x;
	factorization(x);
}

//task 17
double BMI(double weight, double height) {
	return(weight / ((height)*(height)));
}
void printBMI(double BMI) {
	//sqcout << BMI << endl;
	if (BMI < 18.5) {
		cout << "Underweight" << endl;
	}else if (BMI >= 18.5 && BMI < 25) {
		cout << "Normal" << endl;
	}else if (BMI >= 25 && BMI < 30) {
		cout << "Overweight" << endl;
	}else if (BMI >= 30) {
		cout << "Obesity" << endl;
	}
}
void task17() {
	double height, weight;
	cin >> weight >> height;
	printBMI(BMI(weight, height/100));
}
//сдано

void task18() {
	srand(unsigned(time(0)));
	int n[20];
	for (int i = 0; i < 20; i++) {
		n[i] = (rand() % 201) - 100;
		cout << n[i] << "; ";
	}
	cout << endl;
	int min = n[1];
	int max = n[1];
	for (int i = 1; i < 20; i++) {
		if (n[i] > max) max = n[i];
		if (n[i] < min) min = n[i];
	}
	cout << "min: " << min << endl;
	cout << "max: " << max << endl;
}

void task19() {
	int n;
	cin >> n;
	int amt[10] = {};
	
	

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		amt[a]++;
	}

	for (int i = 0; i < 10; i++) {
		if (amt[i] > 0) {
			cout << i << ": " << amt[i] << endl;
		}
	}
}
//сдано

//task 20 
void bubble(int *a, int len) {
	for (int i = 0; i < len; i++) { //сортировка пузырьком
		for (int j = 0; j < len - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				int t = a[j + 1];
				a[j + 1] = a[j];
				a[j] = t;
			}
		}
	}

	for (int i = 0; i < len; i++) {
		cout << a[i] << " ";
	}
}
void task20() {
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	bubble(a, n);
}

void task21() {
	srand(unsigned(time(0)));
	int M[10][8];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 8; j++) {
			M[i][j] = 0;
		}
	}
	int ri = rand() % 10;
	int rj = rand() % 8;

	M[ri][rj] = 1;

	bool win = false;
	int tries = 0;
	while (!win) {
		int gi, gj;
		cin >> gi >> gj;
		if (gi < 10 && gj < 8 && gi > 0 && gj > 0) {
			if (M[gi][gj] > 0) {
				cout << "Вы угадали!" << endl;
				win = true;
			}
			else if (M[gi][gj] < 0) {
				cout << "Этот уже проверяли." << endl;
			}
			else if (M[gi][gj] == 0) {
				cout << "Нет" << endl;
				M[gi][gj] = -1;
				tries++;
			}
			if (tries > 5) {
				cout << "GAME OVER.";
				break;
			}
		}
	}

}


//task22 //сдано
void swap(int*, int*);		//Прототипы требуемых функций
int msort(int*, int*, int*);
void info(const int*);
int* add(int*, const int*);
void task22() {
	int a = 5;
	int b = 2;
	cout << a << " " << b << endl;
	swap(&a, &b);
	cout << a << " " << b << endl;
}
//Сами функции
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
int msort(int* n1, int* n2, int* n3) {
	if (*n1 > *n2) swap(n1, n2);
	if (*n2 > *n3) swap(n2, n3);
	if (*n1 > *n2) swap(n1, n2);
	return *n3;
}
void info(const int* n) {
	cout << "Адрес: " << n << endl;
	cout << "Значение: " << *n << endl;
}
int* add(int* a, const int* b) {
	*a = *a + *b;
	return a;
}


//task23
bool check_palindrom(string word)
{
	if (!word.empty()) {
		int len = word.length();
		for (int i = 0; i < len / 2; ++i)
		{
			if (word[i] != word[len - i - 1])
			{
				return false;
			}
		}
		return true;
	}
	else return false;
}
void task23() {
	string str;
	string fex;
	cout << "Введите слово: ";
	getline(cin, str);
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 65 && str[i] <= 90) {
			str[i] = str[i] + 32;
		}
		if ((str[i] >= 48 && str[i] <= 57) || (str[i] >= 97 && str[i] <= 122)) {
			fex += str[i];
		}
	}
	if (check_palindrom(fex))
		cout << "Палиндром\n";
	else
		cout << "Не палиндром\n";
}


//task24
size_t mystrlen(const char* string) {
	int len = 0;
	int i = 0;
	while (string[i] != '\0') {
		len++;
		i++;
	}
	return len;
}

int mystrcmp(const char* string1, const char* string2) {
	int i = -1;
	while (string1[i] != '\0' && string2[i] != '\0')
	{
		i++;
		if (string1[i] > string2[i]) { cout << "Строка 1 больше строки 2" << endl; break; }
		if (string1[i] < string2[i]) { cout << "Строка 2 больше строки 1" << endl; break; }
		if (string1[i] == string2[i]) { cout << "Строки равны" << endl; break; }
	}
	return 0;
}

char* mystrstr(char* string1, const char* string2) {
	for (int i = 0; i < mystrlen(string1); i++)
	{
		int l = 0;
		if (string1[i] == string2[l])
		{
			int k = 1;
			l++;

			while ((string1[i + l] == string2[l]) && (l < mystrlen(string2))) {
				k++;
				l++;
			}
			if (k == mystrlen(string2)) {
				return &string1[i];
			}
		}
	}
	return nullptr;
}

char* mystrcat(char* destptr, const char* srcptr) {
	int len = mystrlen(destptr);
	for (int i = 0; i < mystrlen(srcptr); i++)
		destptr[len + i] = srcptr[i];
	destptr[len + mystrlen(srcptr)] = '\0';
	return destptr;
}

void task24()
{
	char input1[51];
	char input2[51];

	cin.getline(input1, 51, '\n');
	cin.getline(input2, 51, '\n');
	cout << mystrlen(input1) << " " << mystrlen(input2) << '\n';
	mystrcmp(input1, input2);

	int i = 0;
	if (mystrstr(input1, input2)) while (&input1[i] != mystrstr(input1, input2)) i++;
	else i = -1;
	cout << i << endl;

	cout << mystrcat(input1, input2);

}

//task25
struct Student {
	char name[100];
	int group;
	int sec[5];
};
void task25() {
	Student students[] = {
		{"Denisenko V.A.",2,{3,4,3,5,4}},
		{"Lagutkin A.A.",1,{1,1,2,1,3}},
		{"Fedorov A.A.",1,{2,1,2,3,3}},
		{"Evpak D.A.",1,{5,5,5,5,5}},
		{"Ivanov A.F.",2,{5,3,4,4,4}},
		{"Petrov S.A.",1,{3,3,3,2,5}},
		{"Lashuk F.F.",2,{5,4,3,3,3}},
		{"Filipenko D.I.",3,{4,5,4,5,3}},
		{"Moskalenko O.V.",1,{2,2,2,1,1}},
		{"Kuripko O.V.",3,{4,5,4,5,3}}
	};
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 5; j++) {
			if (students[i].sec[j] < 3) {

			}
		}
	}

}

//task 28 //сдано
enum Order {
	ASC,
	DESC
};
bool inOrder(int *m, int s, Order ord) { //проверка упорядоченности для обычного массива интов, а также для трех отдельных чисел

	if (ord == ASC) 
		for (int i = 1; i < s; i++) 
				if (m[i] <= m[i - 1]) return false;
	
	if (ord == DESC) 
		for (int i = 1; i < s; i++)
			if (m[i] >= m[i - 1]) return false;
	
	return true;
}
bool inOrder(std::vector<int> m, int s, Order ord) { //проверка упорядоченности для std::vector

	if (ord == ASC)
		for (int i = 1; i < s; i++)
			if (m[i] <= m[i - 1]) return false;

	if (ord == DESC)
		for (int i = 1; i < s; i++)
			if (m[i] >= m[i - 1]) return false;

	return true;
}
void BozoSort(int *m, int s, Order ord = ASC) { // Обычный массив интов
	while (!inOrder(m, s, ord)) {
		int s1 = rand() % s;
		int s2 = rand() % s;
		if (s1 == s2) s2 /= 2;

		int t = m[s2];
		m[s2] = m[s1];
		m[s1] = t;
	}
	for (int i = 0; i < s; i++) {
		cout << m[i] << " ";
	}
	cout << endl;
}
void BozoSort(std::vector<int> m, int s, Order ord = ASC) { // std::vector
	while (!inOrder(m, s, ord)) {
		int s1 = rand() % s;
		int s2 = rand() % s;
		if (s1 == s2) s2 /= 2;

		int t = m[s2];
		m[s2] = m[s1];
		m[s1] = t;
	}
	for (int i = 0; i < s; i++) {
		cout << m[i] << " ";
	}
	cout << endl;
}
void BozoSort(int a, int b, int c, Order ord = ASC) { // три отдельных числа
	int m[3] = { a,b,c };
	while (!inOrder(m, 3, ord)) {
		int s1 = rand() % 3;
		int s2 = rand() % 3;
		if (s1 == s2) s2 /= 2;

		int t = m[s2];
		m[s2] = m[s1];
		m[s1] = t;
	}
	for (int i = 0; i < 3; i++) {
		cout << m[i] << " ";
	}
	cout << endl;
}
void task28() {
	srand(unsigned(time(0)));
	int s;
	cin >> s;

	int *m = new int[s];
	std::vector<int> vm(s);

	for (int i = 0; i < s; i++) {
		cin >> m[i];
		vm[i] = m[i];
	}

	cout << endl;

	BozoSort(m, s);
	BozoSort(m, s, DESC);
	cout << endl;
	BozoSort(vm, s);
	BozoSort(vm, s, DESC);
	cout << endl;
	if (s == 3) {
		BozoSort(m[0], m[1], m[2]);
		BozoSort(m[0], m[1], m[2], DESC);
	}
}




int main()
{
	setlocale(LC_ALL, "Russian"); //решает проблему вывода текста на русском языке
	
	task28(); // Здесь обозначаем задание которое хотим запустить
	
	return 0;
}
