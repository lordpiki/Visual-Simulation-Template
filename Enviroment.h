#pragma once
#include <mutex>
#include <condition_variable>

class Enviroment
{
public:
    Enviroment(float timeStamp = 0.1f);
    ~Enviroment();

    void resume();
    void stop();

private:
    bool _isPaused;
    float _timeStamp;

    std::mutex _runningMutex;
    std::condition_variable _cv;

    void run();
    void update();
};
