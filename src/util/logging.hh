#ifndef LOGGINGRECEIVER_H
#define LOGGINGRECEIVER_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

class LoggingReceiver {
private:
    std::ofstream logfile;

public:
    uint64_t receive_timestamp;
    uint32_t frame_no;
    uint16_t fragment_no;
    size_t required_next_frame_no;
    uint32_t time_since_last;
    uint32_t avg_EWMA_delay;

    LoggingReceiver(const std::string& filePath);
    ~LoggingReceiver();
    void reset_value();
    void write_line();
};

#endif // LOGGINGRECEIVER_H