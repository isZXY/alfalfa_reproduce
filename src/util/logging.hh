#ifndef LOGGINGRECEIVER_HH
#define LOGGINGRECEIVER_HH

#include <fstream>
#include <string>

class LoggingReceiver {
private:
    std::ofstream logfile;

public:
    uint64_t receive_timestamp{-1};
    uint32_t frame_no{-1};
    uint16_t fragment_no{-1};
    size_t required_next_frame_no{-1};
    uint32_t time_since_last{-1};
    uint32_t avg_EWMA_delay{-1};

    LoggingReceiver(const std::string& filePath);
    ~LoggingReceiver();

    void reset_value();
    void write_line();
};

#endif // LOGGINGRECEIVER_HH