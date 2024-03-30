// Enviroment.cpp
#include "Enviroment.h"
#include <iostream>
#include <thread>

Enviroment::Enviroment(float timeStamp) : _timeStamp(timeStamp), _isPaused(false)
{
    std::thread t1(&Enviroment::run, this);
    t1.detach();
    stop();
}

Enviroment::~Enviroment()
{
    stop(); // Stop the thread before destroying the environment
}

void Enviroment::run()
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(_runningMutex);
        _cv.wait(lock, [this]() { return !_isPaused; });

        if (!_isPaused)
            update();
    }
}

void Enviroment::update()
{
    std::cout << "Enviroment update" << std::endl;
}

void Enviroment::resume()
{
    std::lock_guard<std::mutex> lock(_runningMutex);
    _isPaused = false;
    _cv.notify_one();
}

void Enviroment::stop()
{
    std::lock_guard<std::mutex> lock(_runningMutex);
    _isPaused = true;
    _cv.notify_one();
}