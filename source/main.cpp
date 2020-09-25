#include <iostream>

#include "SemaforoAuto.h"
#include "SemaforoPeaton.h"
#include "Boton.h"

using namespace std;

int main() {
    SemaforoAuto semaforoAuto;
    SemaforoPeaton semaforoPeaton;
    Boton::oprimir(semaforoAuto, semaforoPeaton);
    return 0;
}
