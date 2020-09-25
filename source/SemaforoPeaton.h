#ifndef SISTEMA_SEMAFORO_SEMAFOROPEATON_H
#define SISTEMA_SEMAFORO_SEMAFOROPEATON_H

#include <zconf.h>

class Boton;

class SemaforoPeaton {
private:
    bool luzRoja{};
    bool luzVerde{};

public:
    SemaforoPeaton();

    void mostrarLuzRoja();
    void mostrarLuzVerde();

    void apagarLuzRoja();

    ~SemaforoPeaton() = default;

    friend class Boton;
};

#endif //SISTEMA_SEMAFORO_SEMAFOROPEATON_H
