#pragma once
#include <iostream>
#include <string>
using namespace std;
class Alumno {
	string nombre;
	int asistencia, con_audio;
public:
	Alumno(string nombre, int asistencia, int con_audio);
	string getNombre();
	void setNombre(string nombre);
	int getAsistencia();
	void setAsistencia(int asistencia);
	int getCon_Audio();
	void setCon_Audio(int con_audio);
};
