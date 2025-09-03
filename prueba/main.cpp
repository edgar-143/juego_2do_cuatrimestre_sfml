#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

int main()
{
    sf::RenderWindow ventana(sf::VideoMode(800, 600), "Scrolling con limites");

    // ===== Fondo =====
    sf::Texture textura_fondo;
    if (!textura_fondo.loadFromFile("background/fondo_juego.png"))
        return EXIT_FAILURE;

    sf::Sprite sprite_fondo(textura_fondo);
    sprite_fondo.setScale(0.75f, 0.75f);
    sprite_fondo.setPosition(0, -1250);   // ⬅️ como vos lo pusiste

    // ===== Personaje =====
    sf::Texture textura_personaje;
    if (!textura_personaje.loadFromFile("jack3.png"))
        return EXIT_FAILURE;

    sf::Sprite sprite_pj(textura_personaje);
    sprite_pj.setScale(0.15f, 0.15f);
    sprite_pj.setPosition(100, 460);         // ⬅️ como vos lo pusiste



    float velocidad = 1;


    while (ventana.isOpen())
    {
        sf::Event evento;
        while (ventana.pollEvent(evento))
        {
            if (evento.type == sf::Event::Closed)
                ventana.close();
        }

       if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
           sprite_fondo.move(-velocidad,0);//MOVIMIENTO DEL FONDO PARA DERECHA
            sprite_pj.move(velocidad,0);//MOVIMIENTO DEL FONDO PARA IZQUIERDA
       }
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)or sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
         sprite_fondo.move(velocidad,0);//MOVIMIENTO DEL FONDO PARA IZQUIERDA
          sprite_pj.move(-velocidad,0);//MOVIMIENTO DEL FONDO PARA DERECHA
       }
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)or sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            sprite_fondo.move(0,velocidad);//MOVIMIENTO DEL FONDO PARA ABAJO
             sprite_pj.move(0,-velocidad);//MOVIMIENTO DEL FONDO PARA ARRIBA

       }
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)or sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ){
          sprite_fondo.move(0,-velocidad);//MOVIMIENTO DEL FONDO PARA ARRIBA
           sprite_pj.move(0,velocidad);//MOVIMIENTO DEL PJ PARA ABAJO
       }

        // ===== Dibujar =====
        ventana.clear();

        ventana.draw(sprite_fondo);
        ventana.draw(sprite_pj);
        ventana.display();
    }

    return 0;
}
