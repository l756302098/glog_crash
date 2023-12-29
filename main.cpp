/*
 * main.cpp
 *
 *  Created on: 12 01, 2021
 *      Author: liyanlong
 */
#include <iostream>
#include "glog/logging.h"

static const char* EXE_NAME = "glog_crash";

static void FailureHandle(const char* data,size_t size) {
    LOG(ERROR) << std::string(data, size);
}

void crash(){
    int* a = nullptr;
        *a = 0;
}

int main(int argc, char *argv[])
{
    std::cout << "Start crash demo!" << std::endl;
    std::string logDirPath = "/home/li/log";

    google::InitGoogleLogging(EXE_NAME);
    google::InstallFailureSignalHandler();
    google::InstallFailureWriter(FailureHandle);

    // If specified, logfiles are written into this directory instead of the
    // default logging directory.
    FLAGS_log_dir = logDirPath;
    // Messages logged at a lower level than this don't  actually get logged
    // anywhere
    FLAGS_minloglevel = google::INFO;  // [default: 0 or google::INFO]
    // log messages go to stderr instead of logfiles
    FLAGS_logtostderr = false;  // [default: false]
    // log messages at or above this level are copied to stderr in addition to
    // logfiles.
    FLAGS_stderrthreshold = google::INFO;  // [default: 0 or google::INFO]
    // color messages logged to stderr (if supported by terminal)
    FLAGS_colorlogtostderr = false;  // [default: false]
    // log messages go to stderr in addition to logfiles.
    FLAGS_alsologtostderr = false;  // [default: false]
    // Buffer log messages for at most this many seconds
    FLAGS_logbufsecs = 30;  // [default: 30 sec]
    // approx. maximum log file size (in MB). A value of 0 will be silently
    // overridden to 1.
    FLAGS_max_log_size = 500;  // [default: 1800 MB]
    // Stop attempting to log to disk if the disk is full
    FLAGS_stop_logging_if_full_disk = true;  // [default: false]
    // Log line format: [IWEF]mmdd hh:mm:ss.uuuuuu threadid file:line] msg
    FLAGS_log_prefix = true;  // [default: true]

    crash();
    LOG(INFO) << "test exit.";

    return 0;
}

