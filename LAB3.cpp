#include <iostream>
using namespace std;

int find_number(char* els, int n, char x) {
	for (int i = 0; i < n; i++) {
		if (els[i] == x)
			return i;
	}
}

bool assoc(char** v, char* els, int n) {
	int checker = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (v[find_number(els, n, v[i][j])][k] != v[i][find_number(els, n, v[j][k])])
					return false;
			}
		}
	}
	return true;
}

bool comm(char** v, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] != v[j][i])
				return false;
		}
	}
	return true;
}

bool idemp(char** v, char* els, int n) {
	for (int i = 0; i < n; i++) {
		if (v[i][i] != els[i])
			return false;
	}
	return true;
}

bool distr(char** v1, char** v2, char* els, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (v2[find_number(els, n, v1[i][j])][k] != v1[find_number(els, n, v2[i][k])][find_number(els, n, v2[j][k])] ||
					v1[find_number(els, n, v2[i][j])][k] != v2[find_number(els, n, v1[i][k])][find_number(els, n, v1[j][k])])
					return false;
			}
		}
	}
	return true;
}

void my_union(int** v1, int** v2, int n) {
	int** res;
	res = new int* [n];
	for (int i = 0; i < n; i++) {
		res[i] = new int[n];
		for (int j = 0; j < n; j++) {
			res[i][j] = v1[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v2[i][j])
				res[i][j] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << res[i][j] << ' ';
		cout << endl;
	}
}


void my_intersection(int** v1, int** v2, int n) {
	int** res;
	res = new int* [n];
	for (int i = 0; i < n; i++) {
		res[i] = new int[n];
		for (int j = 0; j < n; j++) {
			res[i][j] = v1[i][j] * v2[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << res[i][j] << ' ';
		cout << endl;
	}
}

void my_reverse(int** v, int n) {
	int** res;
	res = new int* [n];
	for (int i = 0; i < n; i++) {
		res[i] = new int[n];
		for (int j = 0; j < n; j++) {
			res[i][j] = v[j][i];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << res[i][j] << ' ';
		cout << endl;
	}
}


void my_addition(int** v, int n) {
	int** res;
	res = new int* [n];
	for (int i = 0; i < n; i++) {
		res[i] = new int[n];
		for (int j = 0; j < n; j++) {
			if (v[i][j])
				res[i][j] = 0;
			else
				res[i][j] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << res[i][j] << ' ';
		cout << endl;
	}

}


void my_multiplication(int** v1, int** v2, int n) {
	int** res;
	res = new int* [n];
	for (int i = 0; i < n; i++) {
		res[i] = new int[n];
		for (int j = 0; j < n; j++) {
			res[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int count = 0;
			for (int k = 0; k < n; k++) {
				count += v1[i][k] * v2[k][j];
			}
			if (count > 0)
				res[i][j] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << res[i][j] << ' ';
		cout << endl;
	}
}


int** modul_matr(int** v1, int n, int m, int num) {
	int** res;
	res = new int* [n];
	for (int i = 0; i < n; i++) {
		res[i] = new int[m];
		for (int j = 0; j < m; j++) {
			res[i][j] = v1[i][j] % num;
			if (res[i][j] < 0)
				res[i][j] += num;
		}
	}
	return res;
}


void my_multiplication_matr(int** v1, int** v2, int n, int l, int m, int num) {
	int** res;
	res = new int* [n];
	for (int i = 0; i < n; i++) {
		res[i] = new int[m];
		for (int j = 0; j < m; j++) {
			res[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < l; k++) {
				res[i][j] += v1[i][k] * v2[k][j];
			}
		}
	}

	res = modul_matr(res, n, m, num);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
}

void my_addition_matr(int** v1, int** v2, int n, int m, int num) {
	int** res;
	res = new int* [n];
	for (int i = 0; i < n; i++) {
		res[i] = new int[m];
		for (int j = 0; j < m; j++) {
			res[i][j] = v1[i][j] + v2[i][j];
		}
	}

	res = modul_matr(res, n, m, num);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << res[i][j] << ' ';
		cout << endl;
	}
}


void my_transp_matr(int** v, int n, int m, int num) {
	int** res;
	res = new int* [m];
	for (int i = 0; i < m; i++) {
		res[i] = new int[n];
		for (int j = 0; j < n; j++) {
			res[i][j] = v[j][i];
		}
	}

	res = modul_matr(res, m, n, num);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << res[i][j] << ' ';
		cout << endl;
	}
}


int** minus_stroka_stolbec(int** v, int n, int str, int stolb) {
	int my_i = 0, my_j = 0;
	int** res;
	res = new int* [n - 1];
	for (int i = 0; i < n; i++) {
		if (i != str) {
			res[my_i] = new int[n - 1];
			for (int j = 0; j < n; j++) {
				if (j != stolb) {
					res[my_i][my_j] = v[i][j];
					my_j++;
				}
			}
			my_i++;
		}
		my_j = 0;
	}
	return res;
}


int Det(int** v, int n) {
	int temp = 0;
	int k = 1;
	if (n == 1)
		temp = v[0][0];
	else if (n == 2)
		temp = v[0][0] * v[1][1] - v[1][0] * v[0][1];
	else {
		int** temp_matr = new int* [n - 1];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - 1; j++)
				temp_matr[j] = new int[n - 1];
			temp_matr = minus_stroka_stolbec(v, n, 0, i);
			temp += k * v[0][i] * Det(temp_matr, n - 1);
			k = -k;
		}
	}
	return temp;
}

int** my_transp_matr_for_obr(int** v, int n, int num) {
	int** res;
	res = new int* [n];
	for (int i = 0; i < n; i++) {
		res[i] = new int[n];
		for (int j = 0; j < n; j++) {
			res[i][j] = v[j][i];
		}
	}
	return res;
}


void my_obr_matr(int** v, int n, int num) {
	double** transp;
	int det = Det(v, n);
	det = det % num;
	if (det == 0)
		cout << endl << "Определитель равен нулю. Матрица вырожденная." << endl << endl;
	else {
		if (det < 0)
			det += num;
		int obr_det = 0;
		for (int i = 1; i <= num; i++)
			if ((i * det) % num == 1) {
				obr_det = i;
				break;
			}

		cout << endl << "1/|A| = " << obr_det << endl << endl;

		int** res1;
		res1 = new int* [n];
		for (int i = 0; i < n; i++) {
			res1[i] = new int[n];
			for (int j = 0; j < n; j++) {
				res1[i][j] = Det(minus_stroka_stolbec(v, n, i, j), n - 1);
				if ((i + j) % 2 == 1)
					res1[i][j] *= -1;
			}
		}

		res1 = modul_matr(res1, n, n, num);
		cout << "Матрица алгебраических дополнений:" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << res1[i][j] << ' ';
			cout << endl;
		}
		cout << endl;


		int** res2 = my_transp_matr_for_obr(res1, n, num);

		res2 = modul_matr(res2, n, n, num);
		cout << "Транспонированная матрица алгебраических дополнений:" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << res2[i][j] << ' ';
				res2[i][j] *= obr_det;
			}
			cout << endl;
		}
		cout << endl;

		res2 = modul_matr(res2, n, n, num);

		cout << "Обратная матрица:" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << res2[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;

		cout << "Проверка:" << endl;
		my_multiplication_matr(v, res2, n, n, n, num);
		cout << endl;
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int w = 999;
	while (w > 0) {
		cout << endl;
		cout << "1 - алгоритмы проверки свойств операций" << endl;
		cout << "2 - алгоритмы выполнения операции над бинарными отношениями" << endl;
		cout << "3 - алгоритмы выполнения операций над матрицами" << endl;
		cout << "0 - выход" << endl;
		cin >> w;
		if (w == 1) {
			int n;
			cout << "Введите количество элементов. n = ";
			cin >> n;
			char* els = new char[n];
			cout << "Введите элементы: ";
			for (int i = 0; i < n; i++)
				cin >> els[i];

			char** v1;
			v1 = new char* [n];
			cout << endl;
			cout << "Введите таблицу Кэли для пересечения:" << endl;
			for (int i = 0; i < n; i++) {
				v1[i] = new char[n];
				for (int j = 0; j < n; j++) {
					cin >> v1[i][j];
				}
			}

			char** v2;
			v2 = new char* [n];
			cout << "Введите таблицу Кэли для объединения:" << endl;
			for (int i = 0; i < n; i++) {
				v2[i] = new char[n];
				for (int j = 0; j < n; j++) {
					cin >> v2[i][j];
				}
			}

			if (assoc(v1, els, n)) cout << "Операция пересечения обладает свойством ассоциативности" << endl;
			else cout << "Операция пересечения НЕ обладает свойством ассоциативности" << endl;
			if (assoc(v2, els, n)) cout << "Операция объединения обладает свойством ассоциативности" << endl;
			else cout << "Операция объединения НЕ обладает свойством ассоциативности" << endl;
			cout << endl;
			if (comm(v1, n)) cout << "Операция пересечения обладает свойством коммутативности" << endl;
			else cout << "Операция пересечения НЕ обладает свойством коммутативности" << endl;
			if (comm(v2, n)) cout << "Операция объединения обладает свойством коммутативности" << endl;
			else cout << "Операция объединения НЕ обладает свойством коммутативности" << endl;
			cout << endl;
			if (idemp(v1, els, n)) cout << "Операция пересечения обладает свойством идемпотентности" << endl;
			else cout << "Операция пересечения НЕ обладает свойством идемпотентности" << endl;
			if (idemp(v2, els, n)) cout << "Операция объединения обладает свойством идемпотентности" << endl;
			else cout << "Операция объединения НЕ обладает свойством идемпотентности" << endl;
			cout << endl;
			if (distr(v1, v2, els, n)) cout << "Решётка является дистрибутивной" << endl;
			else cout << "Решётка НЕ является дистрибутивной" << endl;
			cout << endl;
		}

		if (w == 2) {
			int ch = 0;
			cout << "1 - объединение" << endl;
			cout << "2 - пересечение" << endl;
			cout << "3 - дополнение" << endl;
			cout << "4 - произведение" << endl;
			cout << "5 - нахождение обратного" << endl;
			cin >> ch;
			if (ch == 1 || ch == 2 || ch == 4) {
				int n;
				cout << "Введите количество элементов. n = ";
				cin >> n;

				int** v1;
				v1 = new int* [n];
				cout << "Введите матрицу бинарного отношения. А = " << endl;
				for (int i = 0; i < n; i++) {
					v1[i] = new int[n];
					for (int j = 0; j < n; j++) {
						cin >> v1[i][j];
					}
				}

				int** v2;
				v2 = new int* [n];
				cout << "Введите матрицу бинарного отношения. B = " << endl;
				for (int i = 0; i < n; i++) {
					v2[i] = new int[n];
					for (int j = 0; j < n; j++) {
						cin >> v2[i][j];
					}
				}
				cout << endl;

				if (ch == 1)
					my_union(v1, v2, n);
				if (ch == 2)
					my_intersection(v1, v2, n);
				if (ch == 4)
					my_multiplication(v1, v2, n);
			}

			else {
				int n;
				cout << "Введите количество элементов. n = ";
				cin >> n;

				int** v1;
				v1 = new int* [n];
				cout << "Введите матрицу бинарного отношения. А = " << endl;
				for (int i = 0; i < n; i++) {
					v1[i] = new int[n];
					for (int j = 0; j < n; j++) {
						cin >> v1[i][j];
					}
				}
				cout << endl;

				if (ch == 3)
					my_addition(v1, n);
				if (ch == 5)
					my_reverse(v1, n);
			}
			cout << endl;
		}
		if (w == 3) {
			int ch = 0;
			cout << "1 - сложение" << endl;
			cout << "2 - умножение" << endl;
			cout << "3 - транспонирование" << endl;
			cout << "4 - обращение" << endl;
			cin >> ch;

			if (ch == 1) {
				int n, m;
				cout << "Введите количество строк. n = ";
				cin >> n;
				cout << "Введите количество столбцов. m = ";
				cin >> m;

				int** v1;
				v1 = new int* [n];
				cout << "Введите матрицу. А = " << endl;
				for (int i = 0; i < n; i++) {
					v1[i] = new int[m];
					for (int j = 0; j < m; j++) {
						cin >> v1[i][j];
					}
				}

				int** v2;
				v2 = new int* [n];
				cout << "Введите матрицу. B = " << endl;
				for (int i = 0; i < n; i++) {
					v2[i] = new int[m];
					for (int j = 0; j < m; j++) {
						cin >> v2[i][j];
					}
				}
				cout << endl;
				double num;
				cout << "Введите число, по модулю которого будут выполняться операции: ";
				cin >> num;
				cout << endl;
				my_addition_matr(v1, v2, n, m, num);
			}

			if (ch == 2) {
				int n, k1, k2, m;
				cout << "Введите количество строк первой матрицы. n = ";
				cin >> n;
				cout << "Введите количество столбцов первой матрицы. k1 = ";
				cin >> k1;
				cout << "Введите количество строк второй матрицы. k2 = ";
				cin >> k2;
				cout << "Введите количество столбцов второй матрицы. m = ";
				cin >> m;

				if (k1 == k2) {

					int** v1;
					v1 = new int* [n];
					cout << "Введите матрицу. А = " << endl;
					for (int i = 0; i < n; i++) {
						v1[i] = new int[k1];
						for (int j = 0; j < k1; j++) {
							cin >> v1[i][j];
						}
					}

					int** v2;
					v2 = new int* [k1];
					cout << "Введите матрицу. B = " << endl;
					for (int i = 0; i < k1; i++) {
						v2[i] = new int[m];
						for (int j = 0; j < m; j++) {
							cin >> v2[i][j];
						}
					}

					int num;
					cout << "Введите число, по модулю которого будут выполняться операции: ";
					cin >> num;
					cout << endl;

					my_multiplication_matr(v1, v2, n, k1, m, num);
				}

				else
					cout << "Ошибка! Количество столбцов А должно быть равно количеству строк B" << endl;
			}

			if (ch == 3) {
				int n, m;
				cout << "Введите количество строк. n = ";
				cin >> n;
				cout << "Введите количество столбцов. m = ";
				cin >> m;

				int** v1;
				v1 = new int* [n];
				cout << "Введите матрицу. А = " << endl;
				for (int i = 0; i < n; i++) {
					v1[i] = new int[m];
					for (int j = 0; j < m; j++) {
						cin >> v1[i][j];
					}
				}
				int num;
				cout << "Введите число, по модулю которого будут выполняться операции: ";
				cin >> num;
				cout << endl;

				my_transp_matr(v1, n, m, num);

			}

			if (ch == 4) {
				int n;
				cout << "Введите количество строк. n = ";
				cin >> n;


				int** v1;
				v1 = new int* [n];
				cout << "Введите матрицу. А = " << endl;
				for (int i = 0; i < n; i++) {
					v1[i] = new int[n];
					for (int j = 0; j < n; j++) {
						cin >> v1[i][j];
					}
				}

				int num;
				cout << "Введите число, по модулю которого будут выполняться операции: ";
				cin >> num;
				cout << endl;

				my_obr_matr(v1, n, num);
			}
			cout << endl;
		}
	}
	return 0;
}