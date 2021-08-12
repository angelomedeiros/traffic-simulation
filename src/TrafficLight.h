#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H
#include "TrafficObject.h"
#include <thread>
#include <chrono>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

enum class TrafficLightPhase{
    red,
    green
};

class TrafficLight: public TrafficObject
{
private:
    void cycleThroughPhases();
    void InvertLight();
    TrafficLightPhase _currentPhase { TrafficLightPhase::red }; /* arbitrary choose */
    int _currentCycleTimeSec;
    static constexpr int CYCLE_TIME_TOP_LIMIT = 6; //no need to define this in runtime, put the constexpr to define in compile time
    static constexpr int CYCLE_TIME_FLOOR_LIMIT = 4; //no need to define this in runtime, put the constexpr to define in compile time

public:
    TrafficLight();
    ~TrafficLight();

    void generateCurrentCycleTime();
    void waitForGreen();
    void simulate();
    TrafficLightPhase getCurrentPhase() const;
};

#endif