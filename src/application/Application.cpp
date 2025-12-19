//
// Created by Anıl Orhun Demiroğlu on 19.12.25.
//

#include "Application.hpp"

#include <random>

namespace random_walk {

    Application::Application()
            : m_window(
            sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
            "Random Walk - Multiple Squares"
    ) {
        constexpr std::size_t object_count = 555;
        constexpr float square_size = 5.f;

        m_entities.reserve(object_count);
        m_renderers.reserve(object_count);

        std::mt19937 rng{std::random_device{}()};
        std::uniform_real_distribution<float> vel(-200.f, 200.f);

        for (std::size_t i = 0; i < object_count; ++i) {

            m_entities.emplace_back(
//                    sf::Vector2f{pos_x(rng), pos_y(rng)},
                    sf::Vector2f{WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2}
            );

            m_renderers.emplace_back(sf::Vector2f{square_size, square_size});
            m_renderers.back().drawable().setFillColor(sf::Color::Magenta);
        }
    }

    void Application::run() {

        while (m_window.isOpen()) {

            const float dt = m_clock.restart().asSeconds();

            process_events();
            update(dt);
            render();
        }
    }

    void Application::process_events() {

        while (auto event = m_window.pollEvent()) {

            if (event->is<sf::Event::Closed>()) {

                m_window.close();
            }
        }
    }

    void Application::update(float dt) {

        for (auto &entity: m_entities) {

            entity.update(dt);
        }
    }

    void Application::render() {

        m_window.clear(sf::Color::Black);

        for (std::size_t i = 0; i < m_entities.size(); ++i) {

            m_renderers[i].draw(m_window, m_entities[i]);
        }

        m_window.display();
    }

} // namespace random_walk