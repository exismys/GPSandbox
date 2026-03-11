#include "raylib.h"
#include "raymath.h"

struct Arrow {
  Vector2 pos1;
  Vector2 pos2;

  void drawArrow() {
    DrawLineV(pos1, pos2, LIGHTGRAY);

    Vector2 tip = pos2;
    Vector2 direction = Vector2Normalize(Vector2Subtract(pos2, pos1));
    Vector2 perpendicular = {-direction.y, direction.x};

    float arrowHeadLength = 20.0f;
    float arrowHeadWidth = 10.0f;

    Vector2 left = Vector2Add(Vector2Subtract(tip, Vector2Scale(direction, arrowHeadLength)), Vector2Scale(perpendicular, arrowHeadWidth / 2.0f));
    Vector2 right = Vector2Add(Vector2Subtract(tip, Vector2Scale(direction, arrowHeadLength)), Vector2Scale(perpendicular, -arrowHeadWidth / 2.0f));

    DrawTriangle(left, tip, right, YELLOW);
  }
};
