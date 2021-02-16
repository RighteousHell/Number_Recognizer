#include "Driwer.h"

int8_t Driwer::preconfiguration_driwer()
{
    main_window.setVerticalSyncEnabled(false);
    main_window.setFramerateLimit(100);

    gues_window.setVerticalSyncEnabled(false);
    gues_window.setFramerateLimit(100);

    //set position of guesess main_window
    sf::Vector2i pos_gues_window(main_window.getPosition().x * 2 + 250, main_window.getPosition().y);
    gues_window.setPosition(pos_gues_window);

    canvas.create(main_window.getSize().x, main_window.getSize().y);
    canvas.clear(sf::Color::Black);

    sprite.setTexture(canvas.getTexture(), true);

    brush.setSize(sf::Vector2f(brush_size, brush_size));
    brush.setOrigin(sf::Vector2f(brush_size, brush_size));
    brush.setFillColor(color);

    gen_font.loadFromFile("20082.ttf");

    text_gues_inform.setString("I think it's: ");
    text_gues_inform.setFont(gen_font);
    text_gues_inform.setCharacterSize(25);
    text_gues_inform.setFillColor(sf::Color::Green);

    text_gues_attempt.setFont(gen_font);
    text_gues_attempt.setString("0/");
    text_gues_attempt.setCharacterSize(25);
    text_gues_attempt.setFillColor(sf::Color::Red);
    text_gues_attempt.setPosition(sf::Vector2f(text_gues_inform.getPosition().x + 150, text_gues_inform.getPosition().y));

    return 0;
}

int8_t Driwer::driwing_windows()
{
    while (main_window.isOpen()) {
        sf::Event event;
        while (main_window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                main_window.close();
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code) {
                case sf::Keyboard::C:
                 
                    canvas.clear(sf::Color::Black);
                    canvas.display();
                    break;
                }
                break;
            case sf::Event::MouseButtonPressed:
                
                if (event.mouseButton.button == sf::Mouse::Left) {
                    isDrawing = true;
                    
                    lastPos = main_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
                    brush.setPosition(lastPos);
                    canvas.draw(brush);
                    canvas.display();
                }
                break;
            case sf::Event::MouseButtonReleased:
                if (event.mouseButton.button == sf::Mouse::Left)
                    isDrawing = false;
                break;
            case sf::Event::MouseMoved:
                if (isDrawing)
                {
                    const sf::Vector2f newPos(main_window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y)));
                    brush.setPosition(newPos);
                    canvas.draw(brush);
                    canvas.display();
                    break;
                }
            }
        }

        gues_window.draw(text_gues_inform);
        gues_window.draw(text_gues_attempt);

        main_window.clear(sf::Color(64, 64, 64));

        main_window.draw(sprite);

        main_window.display();
        gues_window.display();
    }
    return 0;
}