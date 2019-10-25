#include "pch.h"
#include <iostream>
#include <ctime> // для генеирования псевдо-случайных чисел в задании №9
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

	a = b;
	b = a;
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
	double x = g * t * t / 2; // в данном случае выражение делит на два только второ
	double x1 = (1.0 / 2.0) * g * t * t; // в данном случае выражение тоже неверно
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
	
	if (D < 0) {
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
		p = 0.5 * (a + b + c); //по формуле Герона
		S = sqrt(p * (p-a) * (p-b) * (p-c));
		std::cout << "S = " << S << std::endl;
		break;

	case 2:
		double x1, y1, x2, y2, x3, y3;
		std::cout << "Введите координаты вершин треугольника" << std::endl;
		std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		S = 0.5 * abs((x2-x1)*(y3-y1) - (x3-x1)*(y2-y1));
		std::cout << "S = " << S << std::endl;
		break;

	default:
		std::cout << "выберите число 1(расчет по длинам сторон) или 2(расчет по координатам вершин)" << std::endl;
		break;
	}

}

void task8() {
	double a, b, result;
	char op;

	std::cin >> a >> op >> b;
	
	switch (op) {
	case '+':
		result = a + b;
		std::cout << result << std::endl;
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
		result = a / b;
		std::cout << result << std::endl;
		break;

	default:
		std::cout << "Неверный оператор" << std::endl;
		break;
	}
}

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
	int n, p;
	std::cout << "Введите число и степень в которую нужно его ввести." << std::endl;
	std::cin >> n >> p;
	int res = n;
	for (int i = 0; i < p-1; i++) {
		res *= n;
	}
	std::cout << "Ответ: " << res << std::endl;
}

void task11() {
	int n;
	std::cout << "Введите число факториал которого нужно найти." << std::endl;
	std::cin >> n;
	int res = n;
	for (int i = 1; i < n; i++) {
		res *= i;
	}
	std::cout << res << std::endl;
}

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
//сдано

void task13() {
	int n;
	cout << "Введите число" << endl;
	cin >> n;
	int k = 0;
	for (int i = 1; i <= n; i *= 2)
		k++;
	cout << "Количество степеней двойки в введенном числе: \n" << k << endl;
}

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
	
	while (n % 2 == 0) {
		cout << 2 << "*";
		n = n / 2;
	}
	for (int i = 3; i < sqrt(n); i += 2) {
		while (n % i == 0) {
			cout << i << "*";
			n = n / i;
		}
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
	return(weight / ((height / 100)*(height / 100)));
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
	printBMI(BMI(weight, height));
}

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
	int *a = new int[n];
	int amt[10];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < 10; i++) amt[i] = 0;

	for (int i = 0; i < n; i++) {
		amt[a[i]]++;
	}

	for (int i = 0; i < 10; i++) {
		if (amt[i] > 0) {
			cout << i << ": " << amt[i] << endl;
		}
	}
	delete[] a;
}

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



int main()
{
	setlocale(LC_ALL, "Russian"); //решает проблему вывода текста на русском языке
	
	task1(); // Здесь обозначаем какое задание хотим запустить
	
	return 0;
}