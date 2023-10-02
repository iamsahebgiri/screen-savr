#include <SFML/Graphics.hpp>

int main() {
    // sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Magenta);

    // while (window.isOpen()) {
    //     sf::Event event;
    //     while (window.pollEvent(event)) {
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //     }

    //     window.clear();
    //     window.draw(shape);
    //     window.display();
    // }

    auto window = sf::RenderWindow{{800U, 800U}, "The book of shaders", sf::Style::Fullscreen};
    window.setFramerateLimit(144);
    window.setMouseCursorVisible(false);

    auto clock = sf::Clock{};
    auto shape = sf::RectangleShape{sf::Vector2f{window.getSize()}};

    auto shader = sf::Shader{};
    if (!shader.loadFromFile("shader.frag", sf::Shader::Fragment)) {
        fprintf(stderr, "Couldn't load fragment shader");
        return -1;
    }

    auto mouse_position = sf::Vector2f{};

    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed) {
                window.close();
            } else if (event.type == sf::Event::MouseMoved) {
                mouse_position = window.mapPixelToCoords({event.mouseMove.x,
                                                          event.mouseMove.y});
            }
        }

        shader.setUniform("u_resolution", sf::Glsl::Vec2{window.getSize()});
        shader.setUniform("u_mouse", sf::Glsl::Vec2{mouse_position});
        shader.setUniform("u_time", clock.getElapsedTime().asSeconds());

        window.clear();
        window.draw(shape, &shader);
        window.display();
    }

    return 0;
}