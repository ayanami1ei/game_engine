#ifndef METRONOME_H
#define METRONOME_H

#include <chrono>
#include <thread>

class Metronome
{
private:
    std::chrono::system_clock::time_point start;
    std::chrono::duration<int,std::micro> duration;
    std::thread thread_obj;
    bool run_flag;

    static void time_work(Metronome* obj);
public:
    void time_start();

    std::chrono::microseconds get_duration();

    ~Metronome();
};

inline Metronome game_clock;

#endif