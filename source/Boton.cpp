#include "Boton.h"

void Boton::oprimir(SemaforoAuto &sAuto, SemaforoPeaton &sPeaton) {
    sf::RenderWindow window(sf::VideoMode(640, 480), "Semaforo");
    window.setFramerateLimit(2);
    float radio = 30;
    int contador = 0;

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
        }
        window.clear(sf::Color::Black);

        if (sAuto.luzRoja) window.draw(rojaAuto);
        if (sAuto.luzAmarilla) window.draw(amarillaAuto);
        if (sAuto.luzVerde) window.draw(verdeAuto);

        if (sPeaton.luzRoja) window.draw(rojaPeaton);
        if (sPeaton.luzVerde) window.draw(verdePeaton);

        window.display();

        if (contador == 4) {
            sAuto.mostrarLuzAmarilla();
            std::cout << "Muestra luz amarilla por un tiempo" << std::endl;
        }
        else if (contador == 8) {
            sAuto.mostrarLuzRoja();
            sPeaton.mostrarLuzVerde();
            std::cout << "Cierra para los carros y abre para los peatones" << std::endl;
        }
        else if (contador == 18) {
            std::cout << "Mantiene estado para que pasen los peatones" << std::endl;
            sPeaton.mostrarLuzRoja();
        }
        else if (contador == 19) {
            sPeaton.apagarLuzRoja();
        }
        else if (contador == 20) {
            sPeaton.mostrarLuzRoja();
        }
        else if (contador == 21) {
            sPeaton.apagarLuzRoja();
        }
        else if (contador == 22) {
            sPeaton.mostrarLuzRoja();
        }
        else if (contador == 23) {
            sPeaton.apagarLuzRoja();
        }
        else if (contador == 24) {
            sPeaton.mostrarLuzRoja();
            sAuto.mostrarLuzVerde();
            std::cout << "Se cierra para los peatones y se abre para los carros" << std::endl;
        }
        else if (contador == 26) {
            contador = 0;
        }
        //std::cout << "Mostrando" << std::endl;
        contador++;
    }

    // Espera unos segundos
    /*std::cout << "Espera unos segundos" << std::endl;
    sleep(2);

    // Muestra luz amarilla por un tiempo
    sAuto.mostrarLuzAmarilla();
    std::cout << "Muestra luz amarilla por un tiempo" << std::endl;
    sleep(2);

    // Cierra para los carros y abre para los peatones
    sAuto.mostrarLuzRoja();
    sPeaton.mostrarLuzVerde();
    std::cout << "Cierra para los carros y abre para los peatones" << std::endl;

    // Mantiene estado para que pasen los peatones
    std::cout << "Mantiene estado para que pasen los peatones" << std::endl;
    sleep(5);

    // Se activa luz roja intermitente para peatones
    std::cout << "Se activa luz roja intermitente para peatones" << std::endl;
    //sPeaton.mostrarLuzRojaIntermitente();

    // Se cierra para los peatones y se abre para los carros
    sPeaton.mostrarLuzRoja();
    sAuto.mostrarLuzVerde();
    std::cout << "Se cierra para los peatones y se abre para los carros" << std::endl;*/
}
