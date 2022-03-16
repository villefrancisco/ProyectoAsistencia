
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Output.h"
#include "Alumno.h"

using namespace std;

int main() {
    vector<Alumno*> alumnos;
	string archivos = exec("dir /s/b \"Contenido del Curso\\2021-*.txt");
    fstream myFile;
	stringstream ss(archivos);
	string tt;
	while (getline(ss, tt, '\n')) {
        cout << endl << "*Revisando el archivo: " << endl;
		cout << "{" << tt << "}" << endl;
        myFile.open(tt, ios::in);
        if (myFile.is_open()) {
            string line; 
            while (getline(myFile, line)) {
                bool audio = true;
                string nombre;
                stringstream ss2(line);
                string nom;
                if (line[0] <= 57 && line[0] >= 48) {
                    cout << "I";
                }
                else if (line == "" || line.find("ASISTIERON") != string::npos || line.find("EXAMEN") != string::npos) {
                    cout << "I";
                }
                else {
                    int cont = 0;
                    while (getline(ss2, nom, ' ')) {
                        if (cont == 0) {
                            nombre = nom;
                        }
                        else if (nom == "NO_AUDIO") {
                            audio = false;
                        }
                        cont++;
                    }
                    cout << "[" << nombre << "]" << "[A]";
                    int found = -1;
                    for (int i = 0; i < alumnos.size(); i++) {
                        if (alumnos[i]->getNombre() == nombre) {
                            found = i;
                            cout << "F";
                            break;
                        }
                    }
                    if (found != -1) {
                        alumnos[found]->setAsistencia(alumnos[found]->getAsistencia() + 1);
                        cout << "U";
                    }
                    else {
                        cout << "N";
                        alumnos.push_back(new Alumno(nombre, 1, 0));
                        found = alumnos.size() - 1;
                        cout << "C";
                    }

                    if (audio) {
                        alumnos[found]->setCon_Audio(alumnos[found]->getCon_Audio() + 1);
                    }
                    else {
                        cout << "NA";
                    }
                    cout << ",";
                }
                cout << line << endl;
            }
            cout << endl;
            myFile.close();
        }

	}
    for (Alumno* alumno : alumnos) {
        cout << alumno->getNombre() << " " << alumno->getAsistencia() << " " << alumno->getCon_Audio() << endl;
    }
}
