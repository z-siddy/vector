#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include "main.h"

struct Timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<float> duration;
    void Timer::startClock() {
        start = std::chrono::high_resolution_clock::now();
    }

    void Timer::endClock(std::string opName) {
        end = std::chrono::high_resolution_clock::now();
        duration = end-start;
        cout << opName <<  " : " << duration.count() << " s" << std::endl;

    }
};

#endif