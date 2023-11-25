#ifndef LOGGINGRECEIVER_HH
#define LOGGINGRECEIVER_HH

#include <fstream>
#include <string>

class LoggingReceiver {
private:
    std::ofstream logfile;

public:
    uint64_t receive_timestamp{0};
    uint32_t frame_no{0};
    uint16_t fragment_no{0};
    size_t required_next_frame_no{0};
    uint32_t time_since_last{0};
    uint32_t avg_EWMA_delay{0};

//    uint64_t receive_timestamp;
//    uint32_t frame_no;
//    uint16_t fragment_no;
//    size_t required_next_frame_no;
//    uint32_t time_since_last;
//    uint32_t avg_EWMA_delay;

    LoggingReceiver(const std::string& filePath);
    ~LoggingReceiver();

    void reset_value();
    void write_line();
};

#endif // LOGGINGRECEIVER_HH