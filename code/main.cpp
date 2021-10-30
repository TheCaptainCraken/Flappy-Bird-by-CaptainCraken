#include <SFML/Graphics.hpp>
#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 720

class Background{
    private:
        sf::Texture day_background;
        sf::Texture night_background;
    public:
        sf::Sprite sprite;
    
    Background(sf::Texture day, sf::Texture night, int desired_width){
        day_background = day;
        day_background.setRepeated(true);
        night_background = night;
        night_background.setRepeated(true);

        sprite.setTexture(day_background);
        sf::Rect desired_rect(0, 0, desired_width, (int) day_background.getSize().y);
        sprite.setTextureRect(desired_rect);
    }

    void Draw(sf::RenderWindow *canvas){
        canvas -> draw(sprite);
    }
};

bool create_icon(sf::RenderWindow*);
Background create_background();

int main(){
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Flappy Bird by Captain Craken");
    if(!create_icon(&window)){return -1;}//try to load the icon and set it. If fails close app with an error.
    Background background = create_background();//create the background

    while (window.isOpen()){//game loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        background.Draw(&window);
        window.display();
    }

    return 0;
}

bool create_icon(sf::RenderWindow *w){
    sf::Image icon;
    if(!icon.loadFromFile("code/assets/favicon.png")){
        return false;//error has occurred
    }
    w -> setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    return true;
}

Background create_background(){
    sf::Texture day, night;
    night.loadFromFile("code/assets/sprites/background-night.png");
    day.loadFromFile("code/assets/sprites/background-day.png");
    
    return Background(day, night, WINDOW_WIDTH);
}