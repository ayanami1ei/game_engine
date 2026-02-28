#include "metronome.h"

void Metronome::time_work(Metronome* obj)
{
    while (obj->run_flag)
    {
        std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
        obj->duration = std::chrono::duration_cast < std::chrono::duration<int>>(end - obj->start);
        obj->start = end;
    }
}

void Metronome::time_start()
{
    run_flag = true;
    start = std::chrono::system_clock::now();
    thread_obj = std::thread(time_work, this);
}

std::chrono::milliseconds Metronome::get_duration()
{
    return duration;
}

Metronome ::~Metronome()
{
    run_flag = false;
    thread_obj.join();
}