#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include<iostream>
using namespace std;
int main()
{
    sf::RenderWindow ventana(sf::VideoMode(800, 600), "Scrolling con limites");

    // ===== Fondo =====
    sf::Texture textura_fondo;
    if (!textura_fondo.loadFromFile("background/fondo_juego.png"))
        return EXIT_FAILURE;

    sf::Sprite sprite_fondo(textura_fondo);
    sprite_fondo.setScale(0.75f, 0.75f);
    sprite_fondo.setPosition(0, -1250);
    float ancho = sprite_fondo.getGlobalBounds().width;

// --- Obtener el último píxel en X ---
    float ultimoPixelX = sprite_fondo.getPosition().x + ancho;

// Mostrarlo por consola
    cout << "El último pixel en X está en: " << ultimoPixelX <<endl;

    // ===== Personaje =====
    sf::Texture textura_personaje;
    if (!textura_personaje.loadFromFile("jack3.png"))
        return EXIT_FAILURE;

    sf::Sprite sprite_pj(textura_personaje);
    sprite_pj.setScale(0.15f, 0.15f);
    sprite_pj.setPosition(300, 460);



    float velocidad = 0.5;


    while (ventana.isOpen())
    {
        sf::Event evento;
        while (ventana.pollEvent(evento))
        {
            if (evento.type == sf::Event::Closed)
                ventana.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            sprite_fondo.move(-velocidad,0);//MOVIMIENTO DEL FONDO PARA IZQUIERDA
            sprite_pj.move(velocidad,0);//MOVIMIENTO DEL PJ PARA DERECHA



        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)or sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            sprite_fondo.move(velocidad,0);//MOVIMIENTO DEL FONDO PARA DERECHA
            sprite_pj.move(-velocidad,0);//MOVIMIENTO DEL FONDO PARA IZQUIERDA

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)or sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            sprite_fondo.move(0,velocidad);//MOVIMIENTO DEL FONDO PARA ABAJO


        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)or sf::Keyboard::isKeyPressed(sf::Keyboard::Down) )
        {
            sprite_fondo.move(0,-velocidad);//MOVIMIENTO DEL FONDO PARA ARRIBA

        }
        if (sprite_fondo.getPosition().x > 0)
        {
            sprite_fondo.setPosition(0, sprite_fondo.getPosition().y);}

         if (sprite_fondo.getPosition().x <-2000 )
        {
            sprite_fondo.setPosition(-2000, sprite_fondo.getPosition().y);
        }
        if(sprite_pj.getPosition().x<100){
            sprite_pj.setPosition(100,sprite_pj.getPosition().y);
        }
        if(sprite_pj.getPosition().x>650){
            sprite_pj.setPosition(650,sprite_pj.getPosition().y);
        }



// Límite derecho (usando ancho del fondo)         //4079px    2468px




        // ===== Dibujar =====
        ventana.clear();

        ventana.draw(sprite_fondo);
        ventana.draw(sprite_pj);
        ventana.display();
    }

    return 0;
}
