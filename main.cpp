#include "raylib.h"
#include "visualization.cpp"
#include <vector>

struct Circle {
  Vector2 position;
  Vector2 velocity;
  float radius;
};

void updatePhysics(std::vector<Circle> &circles, float dt) {
  for (Circle& c : circles) {
    c.position.x += c.velocity.x * dt;
    c.position.y += c.velocity.y * dt;
  }
}

int main(void) {
  // Window configuration
  const int screenWidth = 800;
  const int screenHeight = 600;

  InitWindow(screenWidth, screenHeight, "Canvas of Emergence - v0");
  SetTargetFPS(60);

  std::vector<Circle> circles;
  circles.push_back({{200, 200}, {5, 5}, 10});
  Arrow arrow = {{100, 100}, {300, 300}};

  // Game loop
  while (!WindowShouldClose()) {
    float dt = GetFrameTime();
    updatePhysics(circles, dt);
    BeginDrawing();
    ClearBackground(BLACK);
    for (Circle& c: circles) {
      DrawCircleV(c.position, c.radius, RED);
    }
    arrow.drawArrow();
    EndDrawing();
  }

  CloseWindow();
  return 0;
}

