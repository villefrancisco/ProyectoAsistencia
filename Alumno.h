#pragma once
#include <iostream>
#include <string>
class Alumno {
	string nombre;
	int asistencia, con_audio;
public:
	Alumno(string, int, int);
	string getNombre();
	void setNombre(string);
	int getAsistencia();
	void setAsistencia(int);
	int getCon_Audio();
	void setCon_Audio(int);
};
