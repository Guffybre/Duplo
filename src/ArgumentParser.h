#ifndef _ARGUMENTPARSER_H_
#define _ARGUMENTPARSER_H_
#include <string>
#include <vector>
class ArgumentParser {
private:
    int argc;
    const char** argv;
    static constexpr char SEPARATOR = ',';

public:
    ArgumentParser(int m_argc, const char* m_argv[]);

    bool is(const char* s);
    const char* getStr(const char* s, const char* defaultValue = "");
    int getInt(const char* s, int defaultValue);
    float getFloat(const char* s, float defaultValue);
    std::vector<std::string> getVectStr(const char* s, std::vector<std::string> defaultValue = std::vector<std::string>()) const;
};

#endif
