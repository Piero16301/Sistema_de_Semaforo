#ifndef SISTEMA_SEMAFORO_SEMAFOROPEATON_H
#define SISTEMA_SEMAFORO_SEMAFOROPEATON_H

#include <zconf.h>

class SistemaSemaforo;

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

    friend class SistemaSemaforo;
};

#endif //SISTEMA_SEMAFORO_SEMAFOROPEATON_H
