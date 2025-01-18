#include "ArgumentParser.h"

#include <cstdlib>
#include <cstring>
#include <sstream>

ArgumentParser::ArgumentParser(int m_argc, const char* m_argv[]) {
    argc = m_argc;
    argv = m_argv;
}

bool ArgumentParser::is(const char* s) {
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], s) == 0) {
            return true;
        }
    }
    return false;
}

std::vector<std::string> ArgumentParser::getVectStr(const char* s, std::vector<std::string> defaultValue) const {
    std::vector<std::string> arguments;
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], s) == 0 && argc > i + 1) {
            std::string buffer = argv[i + 1];
            std::istringstream ss(buffer);
            std::string token;
            while (std::getline(ss, token, SEPARATOR)) {
                arguments.push_back(token);
            }
            return arguments;
        }
    }
    return defaultValue;
}

const char* ArgumentParser::getStr(const char* s, const char* defaultValue) {
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], s) == 0 && argc > i + 1) {
            return argv[i + 1];
        }
    }

    return defaultValue;
}

int ArgumentParser::getInt(const char* s, int defaultValue) {
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], s) == 0 && argc > i + 1) {
            return atoi(argv[i + 1]);
        }
    }

    return defaultValue;
}

float ArgumentParser::getFloat(const char* s, float defaultValue) {
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], s) == 0 && argc > i + 1) {
            return (float)atof(argv[i + 1]);
        }
    }

    return defaultValue;
}
