#pragma

#include <raylib.h>
#include <string>

#define MAIN_MENU 0
#define GAME 1 //starts gameThreadHandler
#define STOP 2

class engineThreadHandler {
    public:
        
        Camera2D mainMenuCam;
        void mainMenu(void);
        void saveSelect(std::string saveFilename);

        int state; //main menu, game etc
        void stopThread(void);
        void startThread(void);
        float deltaTime(void);
        void exitSafely(void); //stop the gameThread and save the state of the game
};
extern engineThreadHandler engineThread;