#ifndef SISTEMA_SEMAFORO_SEMAFOROAUTO_H
#define SISTEMA_SEMAFORO_SEMAFOROAUTO_H

class SistemaSemaforo;

class SemaforoAuto {
private:
    bool luzRoja{};
    bool luzAmarilla{};
    bool luzVerde{};

public:
    SemaforoAuto();

    void mostrarLuzRoja();
    void mostrarLuzAmarilla();
    void mostrarLuzVerde();

    ~SemaforoAuto() = default;

    friend class SistemaSemaforo;
};

#endif //SISTEMA_SEMAFORO_SEMAFOROAUTO_H
