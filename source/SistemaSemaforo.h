#ifndef SISTEMA_SEMAFORO_SISTEMASEMAFORO_H
#define SISTEMA_SEMAFORO_SISTEMASEMAFORO_H

#include <zconf.h>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "SemaforoAuto.h"
#include "SemaforoPeaton.h"

class SistemaSemaforo {
private:
    int hora{};
    int minuto{};

protected:
    static void oprimirBoton(SemaforoAuto &sAuto, SemaforoPeaton &sPeaton, int &contadorFases);

public:
    SistemaSemaforo();

    static void iniciarSistema();

    ~SistemaSemaforo() = default;
};

#endif //SISTEMA_SEMAFORO_SISTEMASEMAFORO_H
