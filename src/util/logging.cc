# include<iostream>
# include<fstream>
# include<string>
# include <cstdlib>

class LoggingReceiver{
    private:
        std::ofstream logfile;
    public:
        uint64_t receive_timestamp;
        uint32_t frame_no;
        uint16_t fragment_no;
        size_t required_next_frame_no;
        uint32_t time_since_last;
        uint32_t avg_EWMA_delay;

        LoggingReceiver(const std::string& filePath) {
            logfile.open(filePath, std::ios::out | std::ios::trunc);
            logfile << "包接收时间戳,帧(Frame)序号,片(Fragment)序号,当前待解码帧序号,包处理时延,EWMA时延\n";
        }

        ~LoggingReceiver() {
            if (logfile.is_open())
                logfile.close();
        }

        void reset_value() {
            receive_timestamp = -1;
            frame_no =-1;
            fragment_no =-1;
            required_next_frame_no=-1;
            time_since_last=-1;
            avg_EWMA_delay=-1;
        }

        void write_line(){
            logfile << receive_timestamp << "," <<frame_no << "," <<fragment_no << "," <<required_next_frame_no<< "," <<time_since_last<<","<<avg_EWMA_delay <<"\n";
        }
};