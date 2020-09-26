#ifndef SISTEMA_SEMAFORO_SISTEMASEMAFORO_H
#define SISTEMA_SEMAFORO_SISTEMASEMAFORO_H

#include <zconf.h>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "SemaforoAuto.h"
#include "SemaforoPeaton.h"

class SistemaSemaforo {
private:
    int hora{};
    int minuto{};

protected:
    static void oprimirBoton(SemaforoAuto &sAuto, SemaforoPeaton &sPeaton, int &contadorFases);
    static void parpadearRojoPeaton(SemaforoPeaton &sPeaton);
    static void parpadearAmarilloAuto(SemaforoAuto &sAuto);

public:
    SistemaSemaforo();

    void iniciarSistema();

    ~SistemaSemaforo() = default;
};

#endif //SISTEMA_SEMAFORO_SISTEMASEMAFORO_H
