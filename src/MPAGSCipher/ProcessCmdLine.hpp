#ifndef MPAGSCIPHER_PROCESSCMDLINE_HPP
#define MPAGSCIPHER_PROCESSCMDLINE_HPP

#include <string>
#include <vector>

bool processCommandLine(const std::vector<std::string>& args, bool& helpRequested, bool& versionRequested, 
std::string& inputFileName, std::string& outFileName, std::string& key, bool& encrypt);

#endif