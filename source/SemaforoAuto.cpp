#include "SemaforoAuto.h"

SemaforoAuto::SemaforoAuto() {
    this->luzRoja = false;
    this->luzAmarilla = false;
    this->luzVerde = true;
}

void SemaforoAuto::mostrarLuzRoja() {
    this->luzRoja = true;
    this->luzAmarilla = false;
    this->luzVerde = false;
}

void SemaforoAuto::mostrarLuzAmarilla() {
    this->luzRoja = false;
    this->luzAmarilla = true;
    this->luzVerde = false;
}

void SemaforoAuto::mostrarLuzVerde() {
    this->luzRoja = false;
    this->luzAmarilla = false;
    this->luzVerde = true;
}
