#include "../../E2DE/src/Engine/core.h"
#include "../../E2DE/src/Scene/Entity.h"
#include <iostream>

int main(){
    // Here we are creating the engine with a title, width, height, and a window flag
    e2e::Engine game("Simple Demo Game", 800, 800, SHOWN);

    // Get a pointer to the event instance so we don't have to call this function every time
    auto* inputHandler = game.GetEventInstance();

    // Set up some inputs with custom values on custom maps
    inputHandler->NewMap("Horizontal");
    inputHandler->BindKey("Horizontal", e2e::KEYS::KEY_A, -1.0f);
    inputHandler->BindKey("Horizontal", e2e::KEYS::KEY_D, 1.0f);

    inputHandler->NewMap("Vertical");
    inputHandler->BindKey("Vertical", e2e::KEYS::KEY_W, -1.0f);
    inputHandler->BindKey("Vertical", e2e::KEYS::KEY_S, 1.0f);

    // Create a player entity, all entities has a transform component
    auto player = game.GetScene().CreateEntity();
    player.AddComponent<e2e::SpriteRendererComponent>(e2e::Vector4(100, 120, 60, 255)); // This can not render sprites yet, but can render a rectangle with a rgba value

    // Gets a reference to the transform component so we don't have to use so many function calls
    auto& transform = player.GetComponent<e2e::TransformComponent>();

    // Here we simply set a position and scale of the player transform
    transform.Position = e2e::Vector(400, 400);
    transform.Scale = e2e::Vector(50, 50);

    // The direction will be used for simple player movement
    e2e::Vector direction;

    // This while loop will run as long as we are not meant to terminate the game
    while (!game.Terminate()){
        // Here we are getting the value of all pressed keys on spicified maps
        direction.x = inputHandler->GetValue("Horizontal");
        direction.y = inputHandler->GetValue("Vertical");

        // We are normalizing our direction for a consistent movement
        direction.Normalize();

        // This is our movement code
        transform.Position += direction * 0.5f * game.GetDeltaTime();

        // game.update() is what keeps quite a large pile of the engine running
        game.update();
        // game.Render() is here to render all SpriteRendererComponents
        game.Render();
    }

    // When we are done with the event instance we can just point to nothing
    inputHandler = nullptr;

    return 0;
}