#include <string>
#include <vector>
#include <iostream>

bool processCommandLine(const std::vector<std::string>& args, bool& helpRequested, bool& versionRequested, 
std::string& inputFileName, std::string& outFileName) {

    bool processStatus{true}; //Add flag to see if any problems were encountered
    
    const std::size_t nCmdLineArgs{args.size()};
    for (std::size_t i{1}; i < nCmdLineArgs; ++i) {
        if (args[i] == "-h" || args[i] == "--help") {
            helpRequested = true;
            break;
        } else if (args[i] == "--version") {
            versionRequested = true;
            break;
        } else if (args[i] == "-i") {
            // Handle input file option
            // Next element is filename unless "-i" is the last argument
            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -i requires a filename argument"
                          << std::endl;
                // exit main with non-zero return to indicate failure
                processStatus = false;
                break;
            } else {
                // Got filename, so assign value and advance past it
                inputFileName = args[i + 1];
                ++i;
            }
        } else if (args[i] == "-o") {
            // Handle output file option
            // Next element is filename unless "-o" is the last argument
            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -o requires a filename argument"
                          << std::endl;
                // exit main with non-zero return to indicate failure
                processStatus = false;
                break;
            } else {
                // Got filename, so assign value and advance past it
                outFileName = args[i + 1];
                ++i;
            }
        } else {
            // Have an unknown flag to output error message and return non-zero
            // exit status to indicate failure
            std::cerr << "[error] unknown argument '" << args[i]
                      << "'\n";
            processStatus = false;
            break;
        }
    }

    return processStatus;
}
