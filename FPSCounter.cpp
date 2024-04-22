// FPSCounter.cpp
#include "FPSCounter.h"
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>

FPSCounter::FPSCounter(GLFWwindow* window)
    : window(window), lastTime(glfwGetTime()), framesCounter(0) {
}

FPSCounter::~FPSCounter() {
}

void FPSCounter::update() {
	double currentTime = glfwGetTime();
	double elapsedTime = currentTime - lastTime;

	if (elapsedTime >= 1.0) {
		std::stringstream fpsStream;
		//fpsStream << std::setprecision(2) << std::fixed << framesCounter / elapsedTime << " FPS";

		fixedFPS = framesCounter / elapsedTime;

		lastTime = currentTime;
		framesCounter = 0;
	}

	framesCounter++;
}

void FPSCounter::render()
{
	std::string windowTitle = "My Simulator - FPS: " + std::to_string(fixedFPS);
	glfwSetWindowTitle(window, windowTitle.c_str());
}