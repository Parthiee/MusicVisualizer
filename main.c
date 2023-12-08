#include <raylib.h>
#include <stdio.h>
int main()
{
    Color set[] = {BLUE, GREEN, YELLOW, ORANGE, PINK, PURPLE, VIOLET};

    SetRandomSeed(100);

    InitWindow(400,400,"Player");
    SetTargetFPS(120);

    InitAudioDevice();
    Music music = LoadMusicStream("chemtrails.mp3");

    PlayMusicStream(music);
   

    while(!WindowShouldClose())
    {
        UpdateMusicStream(music);
        if(IsKeyPressed(KEY_SPACE))
        {
            if(IsMusicStreamPlaying(music))
                {
                    PauseMusicStream(music);
                    int val = GetRandomValue(0,7);
                    ClearBackground(set[val]);


                }
            else
                {
                    ResumeMusicStream(music);
                    int val = GetRandomValue(0,7);
                    ClearBackground(set[val]);
                }

        }

      

        BeginDrawing();
        
        //ClearBackground(BLUE);

        EndDrawing();


    }

    return 0;
}