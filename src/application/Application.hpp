//
// Created by Anıl Orhun Demiroğlu on 19.12.25.
//

#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Entity.hpp"
#include "Renderer.hpp"


namespace random_walk {


    class Application {
    public:
        Application();

        void run();

    private:
        void process_events();

        void update(float dt);

        void render();

        static constexpr unsigned int WINDOW_WIDTH = 800;
        static constexpr unsigned int WINDOW_HEIGHT = 600;

        sf::RenderWindow m_window;
        sf::Clock m_clock;

        std::vector<entity::Entity> m_entities;
        std::vector<renderer::Renderer<sf::RectangleShape>> m_renderers;
    };
}

