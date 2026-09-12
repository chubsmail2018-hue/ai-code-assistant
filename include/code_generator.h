#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

#include <string>
#include <vector>
#include <map>

class CodeGenerator {
private:
    std::map<std::string, std::string> languageExtensions;
    std::map<std::string, std::string> languageComments;
    std::map<std::string, std::string> codeTemplates;

public:
    CodeGenerator();
    
    void initializeLanguages();
    void initializeTemplates();
    
    bool isValidLanguage(const std::string& language);
    std::string getExtension(const std::string& language);
    std::string getHelloWorldTemplate(const std::string& language);
    
    bool createFile(const std::string& filename, const std::string& content);
    std::string generateFunctionTemplate(const std::string& language, 
                                         const std::string& functionName, 
                                         const std::string& returnType = "void");
    
    void listSupportedLanguages();
};

#endif
