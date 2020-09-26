#include "SistemaSemaforo.h"

SistemaSemaforo::SistemaSemaforo() {
    this->hora = 14;
    this->minuto = 0;
}

void SistemaSemaforo::iniciarSistema() {
    SemaforoAuto semaforoAuto;
    SemaforoPeaton semaforoPeaton;
    sf::RenderWindow window(sf::VideoMode(700, 540), "Sistema de semaforo");
    window.setFramerateLimit(2);
    float radio = 40;
    int contadorFases = 0;
    bool botonOprimido = false;

    sf::RectangleShape bordeAuto(sf::Vector2f(160,360));
    bordeAuto.setFillColor(sf::Color::Black);
    bordeAuto.setPosition(60,130);

    sf::RectangleShape bordePeaton(sf::Vector2f(160,260));
    bordePeaton.setFillColor(sf::Color::Black);
    bordePeaton.setPosition(330,130);

    sf::Texture tAuto;
    tAuto.create(100, 100);
    tAuto.loadFromFile("../images/car_icon.png");
    sf::Sprite iconoAuto;
    iconoAuto.setTexture(tAuto);
    iconoAuto.setPosition(100, 30);
    iconoAuto.setScale(0.35, 0.35);

    sf::Texture tPeaton;
    tPeaton.create(100, 100);
    tPeaton.loadFromFile("../images/person_icon.png");
    sf::Sprite iconoPeaton;
    iconoPeaton.setTexture(tPeaton);
    iconoPeaton.setPosition(355, 10);
    iconoPeaton.setScale(0.09, 0.09);

    sf::Font font;
    font.loadFromFile("../fonts/SFDigitalReadout-Heavy.ttf");

    sf::Text text;
    text.setFont(font);
    text.setPosition(585, 5);
    text.setCharacterSize(50);
    text.setColor(sf::Color::Black);

    sf::CircleShape rojaAuto(radio);
    rojaAuto.setPosition(100, 170);
    rojaAuto.setFillColor(sf::Color::Red);

    sf::CircleShape amarillaAuto(radio);
    amarillaAuto.setPosition(100, 270);
    amarillaAuto.setFillColor(sf::Color::Yellow);

    sf::CircleShape verdeAuto(radio);
    verdeAuto.setPosition(100, 370);
    verdeAuto.setFillColor(sf::Color::Green);

    sf::CircleShape rojaPeaton(radio);
    rojaPeaton.setPosition(370, 170);
    rojaPeaton.setFillColor(sf::Color::Red);

    sf::CircleShape verdePeaton(radio);
    verdePeaton.setPosition(370, 270);
    verdePeaton.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        text.setString((hora<10?"0":"") + std::to_string(hora) + ":" + (minuto<10?"0":"") + std::to_string(minuto));
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Enter && (hora < 18 && hora >= 6)) {
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

        if (hora >= 18 || hora < 6) {
            botonOprimido = false;
            contadorFases = 0;
            parpadearRojoPeaton(semaforoPeaton);
            parpadearAmarilloAuto(semaforoAuto);
        } else {
            if (!botonOprimido) {
                semaforoPeaton.mostrarLuzRoja();
                semaforoAuto.mostrarLuzVerde();
            }
        }

        window.clear(sf::Color::White);

        window.draw(bordeAuto);
        window.draw(bordePeaton);

        window.draw(iconoPeaton);
        window.draw(iconoAuto);

        if (semaforoAuto.luzRoja)       window.draw(rojaAuto);
        if (semaforoAuto.luzAmarilla)   window.draw(amarillaAuto);
        if (semaforoAuto.luzVerde)      window.draw(verdeAuto);

        if (semaforoPeaton.luzRoja)     window.draw(rojaPeaton);
        if (semaforoPeaton.luzVerde)    window.draw(verdePeaton);

        window.draw(text);

        window.display();

        minuto += 15;
        if (minuto == 60) {
            hora++;
            minuto = 0;
        }
        if (hora == 24) {
            hora = 0;
        }
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
            std::cout << "Mantiene estado para que pasen los peatones" << std::endl;
            break;
        }
        case 18: {
            std::cout << "Parpadea luz roja de los peatones" << std::endl;
            sPeaton.mostrarLuzRoja();
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
    if (contadorFases > 18 && contadorFases < 24) {
        parpadearRojoPeaton(sPeaton);
    }
}

void SistemaSemaforo::parpadearRojoPeaton(SemaforoPeaton &sPeaton) {
    if (sPeaton.luzRoja) {
        sPeaton.apagarLuzRoja();
    } else {
        sPeaton.mostrarLuzRoja();
    }
}

void SistemaSemaforo::parpadearAmarilloAuto(SemaforoAuto &sAuto) {
    if (sAuto.luzAmarilla) {
        sAuto.apagarLuzAmarilla();
    } else {
        sAuto.mostrarLuzAmarilla();
    }
}
