// Enviroment.cpp
#include "Enviroment.h"
#include <iostream>
#include <thread>


Enviroment::Enviroment(float timeStamp) : _timeStamp(timeStamp), _isPaused(false)
{

    srand(time(NULL));

    if (!glfwInit())
        exit(EXIT_FAILURE);


    int windowWidth = 1000, windowHeight = 750;

    _window = glfwCreateWindow(windowWidth, windowHeight, "Point Simulation", NULL, NULL);

    if (!_window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(_window);


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

    while (true && !glfwWindowShouldClose(_window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        std::unique_lock<std::mutex> lock(_runningMutex);
        _cv.wait(lock, [this]() { return !_isPaused; });
        if (!_isPaused)
            update();

        glfwSwapBuffers(_window);
        glfwPollEvents();
    }
}

void Enviroment::update()
{
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