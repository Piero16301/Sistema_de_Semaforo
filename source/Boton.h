#ifndef SISTEMA_SEMAFORO_BOTON_H
#define SISTEMA_SEMAFORO_BOTON_H

#include <zconf.h>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "SemaforoAuto.h"
#include "SemaforoPeaton.h"

class Boton {
public:
    static void oprimir(SemaforoAuto &sAuto, SemaforoPeaton &sPeaton);
};

#endif //SISTEMA_SEMAFORO_BOTON_H
