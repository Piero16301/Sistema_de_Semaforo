#include "SistemaSemaforo.h"

SistemaSemaforo::SistemaSemaforo() {
    this->hora = 6;
    this->minuto = 0;
}

void SistemaSemaforo::iniciarSistema() {
    SemaforoAuto semaforoAuto;
    SemaforoPeaton semaforoPeaton;
    sf::RenderWindow window(sf::VideoMode(640, 480), "Sistema de semaforo");
    window.setFramerateLimit(2);
    float radio = 30;
    int contadorFases = 0;
    bool botonOprimido = false;

    sf::CircleShape rojaAuto(radio);
    rojaAuto.setPosition(100, 100);
    rojaAuto.setFillColor(sf::Color::Red);

    sf::CircleShape amarillaAuto(radio);
    amarillaAuto.setPosition(100, 200);
    amarillaAuto.setFillColor(sf::Color::Yellow);

    sf::CircleShape verdeAuto(radio);
    verdeAuto.setPosition(100, 300);
    verdeAuto.setFillColor(sf::Color::Green);

    sf::CircleShape rojaPeaton(radio);
    rojaPeaton.setPosition(300, 100);
    rojaPeaton.setFillColor(sf::Color::Red);

    sf::CircleShape verdePeaton(radio);
    verdePeaton.setPosition(300, 200);
    verdePeaton.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Enter) {
                    std::cout << "Oprimiendo boton" << std::endl;
                    botonOprimido = true;
                }
            }
        }

        if (botonOprimido) {
            oprimirBoton(semaforoAuto, semaforoPeaton, contadorFases);
            contadorFases++;
        }
        if (contadorFases == 0) {
            botonOprimido = false;
        }

        window.clear(sf::Color::Black);

        if (semaforoAuto.luzRoja) window.draw(rojaAuto);
        if (semaforoAuto.luzAmarilla) window.draw(amarillaAuto);
        if (semaforoAuto.luzVerde) window.draw(verdeAuto);

        if (semaforoPeaton.luzRoja) window.draw(rojaPeaton);
        if (semaforoPeaton.luzVerde) window.draw(verdePeaton);

        window.display();
    }
}

void SistemaSemaforo::oprimirBoton(SemaforoAuto &sAuto, SemaforoPeaton &sPeaton, int &contadorFases) {
    switch (contadorFases) {
        case 4: {
            sAuto.mostrarLuzAmarilla();
            std::cout << "Muestra luz amarilla por un tiempo" << std::endl;
            break;
        }
        case 8: {
            sAuto.mostrarLuzRoja();
            sPeaton.mostrarLuzVerde();
            std::cout << "Cierra para los carros y abre para los peatones" << std::endl;
            break;
        }
        case 18: {
            std::cout << "Mantiene estado para que pasen los peatones" << std::endl;
            sPeaton.mostrarLuzRoja();
            break;
        }
        case 19: {
            sPeaton.apagarLuzRoja();
            break;
        }
        case 20: {
            sPeaton.mostrarLuzRoja();
            break;
        }
        case 21: {
            sPeaton.apagarLuzRoja();
            break;
        }
        case 22: {
            sPeaton.mostrarLuzRoja();
            break;
        }
        case 23: {
            sPeaton.apagarLuzRoja();
            break;
        }
        case 24: {
            sPeaton.mostrarLuzRoja();
            sAuto.mostrarLuzVerde();
            std::cout << "Se cierra para los peatones y se abre para los carros" << std::endl;
            break;
        }
        case 26: {
            contadorFases = -1;
            break;
        }
        default: {}
    }
}
