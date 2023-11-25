# include<iostream>
# include<fstream>
# include<string>
# include <cstdlib>
# include "logging.hh"


LoggingReceiver::LoggingReceiver(const std::string &filePath) : logfile(filePath, std::ios::out | std::ios::trunc) {
    logfile << "包接收时间戳,帧(Frame)序号,片(Fragment)序号,当前待解码帧序号,包处理时延,EWMA时延\n";
}

LoggingReceiver::~LoggingReceiver() {
    if (logfile.is_open())
        logfile.close();
}

void LoggingReceiver::reset_value() {
    receive_timestamp = 0;
    frame_no = 0;
    fragment_no = 0;
    required_next_frame_no = 0;
    time_since_last = 0;
    avg_EWMA_delay = 0;
}

void LoggingReceiver::write_line() {
    logfile << receive_timestamp << "," << frame_no << "," << fragment_no << "," << required_next_frame_no << ","
            << time_since_last << "," << avg_EWMA_delay << "\n";
}