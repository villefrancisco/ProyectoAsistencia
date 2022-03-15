#include <iostream>
#include <string>
#include "Output.h"

using namespace std;

int main() {
	string archivos = exec("dir /s/b \"Contenido del Curso\\2021-*.txt");
	cout << archivos << endl;
}
