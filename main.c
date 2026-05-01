#include <raylib.h>
#include <stdlib.h>

#define WIDTH 16
#define HEIGHT 9
#define SCREEN_SCALE 50
#define VELOCITY_SCALE 10
#define BALL_SIZE SCREEN_SCALE * 1

int main(void) {

  int s_width = WIDTH * SCREEN_SCALE;
  int s_height = HEIGHT * SCREEN_SCALE;

  SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);

  InitWindow(s_width, s_height, "Simple bouncing ball");

  Vector2 ball = {(float)GetScreenWidth() / 2.0f,
                  (float)GetScreenHeight() / 2.0f};

  Vector2 velocity = {VELOCITY_SCALE, VELOCITY_SCALE};

  SetTargetFPS(60);

  while (!WindowShouldClose()) {

    s_width = GetScreenWidth();
    s_height = GetScreenHeight();

    // right
    if (ball.x + velocity.x >= s_width - BALL_SIZE) {
      ball.x = s_width - BALL_SIZE;
      velocity.x *= -1.0f;
      ball.x += velocity.x;
    } else {
      ball.x += velocity.x;
    }

    // left
    if (ball.x + velocity.x <= BALL_SIZE) {
      ball.x = BALL_SIZE;
      velocity.x *= -1.0f;
      ball.x += velocity.x;
    } else {
      ball.x += velocity.x;
    }

    // down
    if (ball.y + velocity.y >= s_height - BALL_SIZE) {
      ball.y = s_height - BALL_SIZE;
      velocity.y *= -1.0f;
      ball.y += velocity.y;
    } else {
      ball.y += velocity.y;
    }

    // up
    if (ball.y + velocity.y <= BALL_SIZE) {
      ball.y = BALL_SIZE;
      velocity.y *= -1.0f;
      ball.y += velocity.y;
    } else {
      ball.y += velocity.y;
    }

    BeginDrawing();

    ClearBackground(LIGHTGRAY);

    DrawCircleV(ball, BALL_SIZE, BLUE);

    EndDrawing();
  }

  return EXIT_SUCCESS;
}
