#include "States.h"

bool States::bPaused = false;


bool States::getPausedState()
{
    return bPaused;
}

void States::setPausedState(bool bPaused)
{
    States::bPaused = bPaused;
}
