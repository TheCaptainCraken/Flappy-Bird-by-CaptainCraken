#include <SFML/Graphics.hpp>
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main(){
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Flappy Bird by Captain Craken");
    while (window.isOpen()){//game loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}