/*
* Alojamento.cpp
*
*  Created on: 01/04/2017
*      Author: David
*/
#include "Alojamento.h"
#include <vector>

using namespace std;

Alojamento::Alojamento() {
	this->nome = "";
}

Alojamento::Alojamento(string nome) {
	this->nome = nome;
}

void Alojamento::setEpocas(std::vector<Epoca*>epocas){
	this->epocas = epocas;
}

int Alojamento::getPreco(int dia, int mes) {

	Epoca *epoca = getEpoca(dia,mes);

	return epoca->getPreco();

}

Epoca* Alojamento::getEpoca(int dia, int mes) {

	vector<Epoca*>::iterator it;

	for (vector<Epoca*>::iterator it = epocas.begin(); it != epocas.end(); it++) {

		if (((*it)->getMesInicio() <= mes) && ((*it)->getMesFim() >= mes)) {
			if (((*it)->getMesInicio() < mes) && ((*it)->getMesFim() > mes))
			return (*it);

			if ((*it)->getMesInicio() == mes)
			if (dia >= (*it)->getDiaInicio())
			return (*it);

			if ((*it)->getMesFim() == mes)
			if (dia <= (*it)->getDiaFim())
			return (*it);

		}
	}

	return new Epoca();
}