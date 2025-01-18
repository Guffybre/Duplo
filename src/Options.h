#ifndef _OPTIONS_H_
#define _OPTIONS_H_

#include <string>
#include <vector>

class Options {
    unsigned m_minChars;
    bool m_ignorePrepStuff;
    unsigned m_minBlockSize;
    unsigned m_blockPercentThreshold;
    unsigned m_filesToCheck;
    bool m_outputXml;
    bool m_ignoreSameFilename;
    bool m_recursiveSearch;
    std::vector<std::string> m_filteredExtensions;
    std::string m_listFilename;
    std::string m_outputFilename;
    
public:
    Options(
        unsigned minChars,
        bool ignorePrepStuff,
        unsigned minBlockSize,
        unsigned blockPercentThreshold,
        unsigned m_filesToCheck,
        bool outputXml,
        bool ignoreSameFilename,
        bool recursiveSearch,
        const std::vector<std::string>& filteredExtensions,
        const std::string& listFilename,
        const std::string& outputFilename
    );

    bool GetIgnoreSameFilename() const;
    const std::string& GetListFilename() const;
    const std::string& GetOutputFilename() const;
    const std::vector<std::string>& GetFilteredExtensions() const;
    bool GetRecursiveSearch() const;
    bool GetOutputXml() const;
    unsigned GetMinChars() const;
    bool GetIgnorePrepStuff() const;
    unsigned GetMinBlockSize() const;
    unsigned GetBlockPercentThreshold() const;
    size_t GetFilesToCheck() const;
};

#endif
