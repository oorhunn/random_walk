//
// Created by Anıl Orhun Demiroğlu on 19.12.25.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.hpp"

namespace random_walk::renderer {

    using namespace random_walk::entity;
    template<typename T>
    concept PositionableDrawable = requires(T t, sf::Vector2f p) {

        t.setPosition(p);
    };


    template<PositionableDrawable DrawableT>
    class Renderer {

    public:
        template<typename... Args>
        explicit Renderer(Args &&... args)
                : m_drawable(std::forward<Args>(args)...) {}

        auto draw(sf::RenderWindow &window, const Entity &entity) -> void {

            set_position(entity.position());
            window.draw(m_drawable);
        }

        DrawableT &drawable() {

            return m_drawable;
        }

        const DrawableT &drawable() const { return m_drawable; }

    private:

        auto set_position(const sf::Vector2f &pos) -> void {

            m_drawable.setPosition(pos);
        }

        DrawableT m_drawable{};
    };
}
