//
// Created by Vahe Aleksanyan on 13.02.23.
//

#include <array>
#include "iostream"
#include "vector"
#include "fstream"
#include "thread"
#include "mutex"

namespace Logs {

    // for interacting with files
    class FileSync {
    public:
        FileSync(const std::string &filename, std::size_t bufferSize = 4096u) : buffer(bufferSize), output(filename),
                                                                                offset(0u) {

            //check if file was not open
            if (!output.is_open()) {
                throw std::runtime_error("file was not created");
            }
        }

        void write(const std::string &data) {
            // when one thred thread tries to write something, in some cases, it does not uordate the offset size,
            // and when other thread tries to do its job, undefined behavior is expected, so us this lock_guard.
            // On construction, the mutex object is locked by the calling thread, and on destruction, the mutex is unlocked.
            // - in other words we synchronize the logging process on the file
            const std::size_t dataSize = data.size();
            std::lock_guard<std::mutex> lock(mutex);
            // if we don`t have enough space in buffer, write in the file
            if (dataSize + offset >= buffer.size()) {
                flush();
            }

            // else copy on buffer
            std::copy(begin(data), end(data), begin(buffer) + offset);
            offset += dataSize; // update the beginning of the data cursor
        }

        // create also a destructor
        ~FileSync() {
            // when the buffer is half filled, and when FileSync dies, we can loose data, we flush data before FileSYnc dies
            flush();
        }

    private:
        // this method will write on drive
        void flush() {
            // if buffer is not empty, just write
            if (offset != 0u) {
                output.write(buffer.data(), offset);
                offset = 0u;
            }
        }

    private:
        // buffer to hold data
        std::vector<char> buffer;
        std::fstream output;
        std::size_t offset;
        std::mutex mutex;
    };

    // will send data to FileSync, will do the log job
    class Console {
    public:

        // we have 6 level of logging, so we can understand at which level the current job is happening or the issue.
        enum Level {
            TRACE_LEVEL,
            DEBUG_LEVEL,
            INFO_LEVEL,
            WARN_LEVEL,
            ERROR_LEVEL,
            FATAL_LEVEL
        };
    public:

        // array of the different levels strings
        static inline std::array<std::string, Level::FATAL_LEVEL + 1u> LevelStr = {"TRACE", "DEBUG", "INFO", "WARN",
                                                                                   "ERROR", "FATAL"};

        // constructor
        Console(const std::string &fileName) : sync(fileName) {}

        // this will enable the user to change the format of logging
        void log(Level level, const char *source, const std::string &message) {
            // here define the structure for the formating message
            const std::string format_message = "[" + LevelStr[level] + "]" + source + " - " + message + "\n";
            // and send to the sync
            sync.write(format_message);
        };

    private:
        FileSync sync;
    };

}

inline Logs::Console &getGlobalConsole() {
    static Logs::Console console("/Users/vahealeksanyan/Desktop/projects/CPP_ACA/homeworks/homework7 feb11/Logger/logs/data.log");
    return console;
}

// macros - preprocessor directive, before compilation the preprocessor replaces the name with actual code
// advantage - make names shorter, avoid runtime overhead


#define STR_(x) #x  // The macro #define str(x) #x replaces the symbol 'str(x)' with 'x'.
#define STR(x) STR_(x)


#define LOG_TRACE(message) getGlobalConsole().log(Logs::Console::Level::TRACE_LEVEL, __FILE__ ":" STR(__LINE__), (message))
#define LOG_DEBUG(message) getGlobalConsole().log(Logs::Console::Level::DEBUG_LEVEL, __FILE__ ":" STR(__LINE__), (message))
#define LOG_INFO(message) getGlobalConsole().log(Logs::Console::Level::INFO_LEVEL, __FILE__ ":" STR(__LINE__), (message))
#define LOG_WARN(message) getGlobalConsole().log(Logs::Console::Level::WARN_LEVEL, __FILE__ ":" STR(__LINE__), (message))
#define LOG_ERROR(message) getGlobalConsole().log(Logs::Console::Level::ERROR_LEVEL, __FILE__ ":" STR(__LINE__), (message))
#define LOG_FATAl(message) getGlobalConsole().log(Logs::Console::Level::FATAL_LEVEL, __FILE__ ":" STR(__LINE__), (message))

int main(int arg, const char *argv[]) {

    std::thread worker([] {
        for (std::size_t i = 0; i < 100u; ++i) {
            LOG_DEBUG("Hello from other thread");
        }
    });

    for (std::size_t i = 0; i < 100u; ++i) {
        LOG_DEBUG("Hello from main thread");
    }

    worker.join();
    return 0;
}