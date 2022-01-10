#include <iostream>
#include "raylib.h"
#include <sstream>
#include <linux/input.h>

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 800;

void OpenWindow() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Test Window");
}

int main(){
    OpenWindow();

    while (!WindowShouldClose()){
        const char * primaryMonitor = (GetMonitorName(1));

        /*double elapsedTimeDouble = GetTime();
        std::stringstream timeString;
        timeString << elapsedTimeDouble;
        const char * elapsedTime = timeString.str().c_str();*/

        Color mainColor[] = {RED, GREEN, BLUE, YELLOW, LIGHTGRAY, BLACK, PURPLE, MAGENTA, PINK};
        const int mainColorLength = sizeof(mainColor);
        int selectedColor = 0;

        BeginDrawing();
        ClearBackground(RAYWHITE);
        //DrawText(elapsedTime,20, 20, 40, RED);
        DrawText("Sample window for raylib testing project!", SCREEN_WIDTH/4, SCREEN_HEIGHT/2, 30, mainColor[selectedColor]);
        DrawText( "Your primary monitor is: ", SCREEN_WIDTH/4 - 30, SCREEN_HEIGHT/2 + 50, 20, BLACK);
        DrawText( primaryMonitor, SCREEN_WIDTH/4 + 220, SCREEN_HEIGHT/2 + 50, 20, GREEN);
        if (IsKeyDown(KEY_SPACE)){
            selectedColor += 1;

            if (selectedColor == mainColorLength - 1){
                selectedColor = 0;
            }
        }
        if (IsKeyPressed(KEY_T)){
            DrawText( "The T key is being held down.", SCREEN_WIDTH/4 - 30, SCREEN_HEIGHT/2 + 250, 20, BLACK);
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}