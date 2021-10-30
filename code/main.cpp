#include <SFML/Graphics.hpp>
#include <iostream>
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

class Background{
    private:
        sf::Texture day_texture;
        sf::Texture night_texture;
    public:
        sf::Sprite sprite;
    
    Background(sf::Texture day, sf::Texture night, int desired_width){
        day_texture = day;
        day_texture.setRepeated(true);
        night_texture = night;
        night_texture.setRepeated(true);

        sprite.setTexture(day_texture);
        sf::Rect desired_rect(0, 0, desired_width, (int) day_texture.getSize().y);
        sprite.setTextureRect(desired_rect);
    }

    void Draw(sf::RenderWindow *canvas){
        canvas -> draw(sprite);
    }
};

class Ground{
    private:
        sf::Texture ground_texture;
    public:
        sf::Sprite sprite;
    Ground(sf::Texture ground, int desired_width){
        ground_texture = ground;
        ground_texture.setRepeated(true);
        sprite.setTexture(ground_texture);
        sf::Rect desired_rect(0, 0, desired_width, (int) ground_texture.getSize().y);
        sprite.setTextureRect(desired_rect);
    }

    void Draw(sf::RenderWindow *canvas){
        canvas -> draw(sprite);
    }
};

bool create_icon(sf::RenderWindow*);
Background create_background();
Ground create_ground();

int main(){
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Flappy Bird by Captain Craken");
    if(!create_icon(&window)){return -1;}//try to load the icon and set it. If fails close app with an error.
    Background background = create_background();//create the background
    Ground ground = create_ground();//create the ground
    while (window.isOpen()){//game loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        background.Draw(&window);
        ground.Draw(&window);
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
    sf::Texture day_texture, night_texture;
    night_texture.loadFromFile("code/assets/sprites/background-night.png");
    day_texture.loadFromFile("code/assets/sprites/background-day.png");
    Background background(day_texture, night_texture, WINDOW_WIDTH);
    return background;
}

Ground create_ground(){
    sf::Texture ground_texture;
    ground_texture.loadFromFile("code/assets/sprites/base.png");
    Ground ground(ground_texture, WINDOW_WIDTH);
    ground.sprite.setPosition(0, 500);//put the ground under the background
    return ground;
}