//
// Created by Anıl Orhun Demiroğlu on 19.12.25.
//

#pragma once

#include <SFML/System/Vector2.hpp>

namespace random_walk::entity {

    class Entity {
    public:
        Entity() = delete;

        explicit Entity(const sf::Vector2f position)
                : m_position{position} {}

        auto update(const std::float_t dt) -> void {

            m_position += m_velocity * dt;
        }

        sf::Vector2f position() const {

            return m_position;
        }

    private:
        sf::Vector2f m_position{};
        sf::Vector2f m_velocity{};
    };
}