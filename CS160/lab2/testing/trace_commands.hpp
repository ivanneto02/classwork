#ifndef TRACE_COMMANDS
#define TRACE_COMMANDS

#include <iostream>
#include <string>

/* 
trace_command - Creates a command to create an output from the ./tsh executable

traceFile: exact file name for the trace we need
*/
std::string trace_command(const std::string& traceFile) {
    std::string command = "";
    command += "./sdriver.pl -t "
            + traceFile
            + " -s ./tsh -a \"-p\"";
    return command;
}

/*
trace_command - Creates a command to create an output from the ./tshref executable

traceFile: exact file name for the trace we need
*/
std::string rtrace_command(const std::string& traceFile) {
    std::string command = "";
    command += "./sdriver.pl -t "
            + traceFile
            + " -s ./tshref -a \"-p\"";
    return command;
}

#endif