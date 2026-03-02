#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Canvas of Emergence - v0");
    SetTargetFPS(60);

    // Particle state
    Vector2 position = { screenWidth / 2.0f, screenHeight / 2.0f };
    Vector2 velocity = { 120.0f, 80.0f }; // pixels per second

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        // Law of motion
        position.x += velocity.x * dt;
        position.y += velocity.y * dt;

        BeginDrawing();
        ClearBackground(BLACK);

        DrawCircleV(position, 5.0f, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

