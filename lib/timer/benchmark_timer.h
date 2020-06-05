
/*
 *
 * FILE NAME: benchmark_timer.h
 *
 *
 */

#include <chrono>
#include <cstdint>

/*
 * testing result using high_resolution_timer
 * run time duration still varies significantly: 0.02 - 0.04seconds
 */
struct high_resolution_timer
{
    high_resolution_timer() : start_time_(take_time_stamp()) {}

    void restart()
    {
        start_time_ = take_time_stamp();
    }

    double elapsed() const //return elapsed time in seconds
    {
        return double(take_time_stamp() - start_time_) * 1e-9;
    }

    std::uint64_t elapsed_nanoseconds() const
    {
        return take_time_stamp() - start_time_;
    }

protected:
    static std::uint64_t take_time_stamp()
    {
        return std::uint64_t(
            std::chrono::high_resolution_clock::now().time_since_epoch().count());
    }

private:
    std::uint64_t start_time_;
};


