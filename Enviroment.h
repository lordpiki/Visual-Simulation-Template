#pragma once
#include <mutex>
#include <condition_variable>
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <cmath>
#include <ctime>

class Enviroment
{
public:
    Enviroment(float timeStamp = 0.1f);
    ~Enviroment();

    void resume();
    void stop();

protected:
    bool _isPaused;
    float _timeStamp;

    std::mutex _runningMutex;
    std::condition_variable _cv;

    void run();
    void update();

	GLFWwindow* _window;
};
