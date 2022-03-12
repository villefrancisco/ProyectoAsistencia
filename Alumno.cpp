#include <iostream>
#include <string>
#include "Alumno.h"
#include <vector>

using namespace std;

Alumno::Alumno(string nombre, int asistencia, int con_audio) {
	this->nombre = nombre;
	this->asistencia = asistencia;
	this->con_audio = con_audio;
}
string Alumno::getNombre() {
	return nombre;
}
void Alumno::setNombre(string nomb) {
	nombre = nomb;
}
int Alumno::getAsistencia() {
	return asistencia;
}
void Alumno::setAsistencia(int asis) {
	asistencia = asis;
}
int Alumno::getCon_Audio() {
	return con_audio;
}
void Alumno::setCon_Audio(int conA) {
	con_audio = conA;
}

