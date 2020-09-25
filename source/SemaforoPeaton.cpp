#include "SemaforoPeaton.h"

SemaforoPeaton::SemaforoPeaton() {
    this->luzRoja = true;
    this->luzVerde = false;
}

void SemaforoPeaton::mostrarLuzRoja() {
    this->luzRoja = true;
    this->luzVerde = false;
}

void SemaforoPeaton::mostrarLuzVerde() {
    this->luzRoja = false;
    this->luzVerde = true;
}

void SemaforoPeaton::apagarLuzRoja() {
    this->luzRoja = false;
    this->luzVerde = false;
}

/*void SemaforoPeaton::mostrarLuzRojaIntermitente() {
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            this->luzRoja = true;
            this->luzVerde = false;
        } else {
            this->luzRoja = false;
            this->luzVerde = true;
        }
        usleep(500000);
    }
}*/
