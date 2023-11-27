#ifndef E2E_COMPONENTS_H_
#define E2E_COMPONENTS_H_

#include "../Math/Vector.h"
#include <SDL2/SDL_render.h>
#include <memory>

namespace e2e{
    struct TransformComponent{
        TransformComponent() = default;
        TransformComponent(const TransformComponent&) = default;
        TransformComponent(const Vector& position, const Vector& scale, const float& rotation) : Position(position), Scale(scale), Rotation(rotation) {}

        Vector Position{};
        Vector Scale{1, 1};
        float Rotation{0};
    };

    struct SpriteRendererComponent{
        SpriteRendererComponent() = default;
        SpriteRendererComponent(const SpriteRendererComponent&) = default;
        SpriteRendererComponent(const Color& c) : color(c) {}

        Vector4 color{1.0f, 1.0f, 1.0f, 1.0f};
        std::shared_ptr<SDL_Texture> texture;
    };

    struct AABBCollisionBox {
        AABBCollisionBox() = default;
        AABBCollisionBox(const AABBCollisionBox&) = default;
        AABBCollisionBox(const int& CollisionLayer, const Vector& Size) : collisionLayer(CollisionLayer), size(Size) {}

        int collisionLayer{0};
        bool didCollide{false};
        Vector size{};
    };
}

#endif