#include "raylib.h"

int main()
{
    const int screenWidth = 1800;
    const int screenHeight = 1000;
    SetConfigFlags(FLAG_MSAA_4X_HINT); // Enable Multi Sampling Anti Aliasing 4x (if available)

    InitWindow(screenWidth, screenHeight, "raylib rotation color size change");

    SetTargetFPS(120);

    const float rotation_speed = 0.5f;
    const float hue_change_speed = 0.9f;
    const int cube_size_shrink_speed = 1;
    
    const Color background_color = { 20, 25, 40, 255 };

    float current_hue = 0.0f;
    float rotation = 45.0f;
    int cube_size = 500;

    ClearBackground(background_color);
    while (!WindowShouldClose())
    {
        rotation += rotation_speed;
        current_hue += hue_change_speed;
        cube_size -= cube_size_shrink_speed;

        if (rotation > 360.0f) rotation = 0.0f;

        if (cube_size < 0) {
            WaitTime(2.0f);
            break;
        }

        Color cube_color = ColorFromHSV(current_hue, 1.0f, 1.0f);
        BeginDrawing();
            Rectangle rect = { screenWidth / 2, screenHeight / 2, cube_size, cube_size };
            Vector2 origin = { cube_size / 2, cube_size / 2 };
            DrawRectanglePro(rect, origin, rotation, cube_color);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
