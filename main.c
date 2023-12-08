#include <raylib.h>
#include <stdio.h>
#include <string.h>

#define WINDOW_HEIGHT 500
#define WINDOW_WIDTH 500
#define ARRAY_LEN(x) sizeof(x)/sizeof(x[0])

__uint64_t __frames[1024] = {0};  // Frame size is 2*sample size
int numframes;                 

void callback(void* buffer, unsigned int frames)
{
    if(frames > ARRAY_LEN(__frames))
    {
        frames = ARRAY_LEN(__frames);
    }

    memcpy(__frames,buffer,frames*sizeof(__uint64_t));
    numframes = frames;

}




int main()
{
\


    InitWindow(WINDOW_HEIGHT,WINDOW_WIDTH,"Player");
    SetTargetFPS(120);
    InitAudioDevice();
    Music music = LoadMusicStream("chemtrails.mp3");
    PlayMusicStream(music);
   
   AttachAudioStreamProcessor(music.stream,callback);

   

    while(!WindowShouldClose())
    {
        UpdateMusicStream(music);
        if(IsKeyPressed(KEY_SPACE))
        {
            if(IsMusicStreamPlaying(music))
                {
                    PauseMusicStream(music);
                }
            else
                {
                    ResumeMusicStream(music);
                }

        }

      

        BeginDrawing();
    
        ClearBackground(BLACK);
        
        for(int i=0; i <ARRAY_LEN(__frames);i++)
        {
        __int32_t sample = *(__int32_t*) &__frames[i];
        printf("%d\n",sample);
        }
        
        EndDrawing();


    }

    return 0;
}