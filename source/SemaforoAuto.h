#ifndef SISTEMA_SEMAFORO_SEMAFOROAUTO_H
#define SISTEMA_SEMAFORO_SEMAFOROAUTO_H

class SemaforoAuto {
private:
    bool luzRoja{};
    bool luzAmarilla{};
    bool luzVerde{};

public:
    SemaforoAuto();



    ~SemaforoAuto() = default;
};

#endif //SISTEMA_SEMAFORO_SEMAFOROAUTO_H
