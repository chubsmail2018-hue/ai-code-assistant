#ifndef LANGUAGE_PARSER_H
#define LANGUAGE_PARSER_H

#include <string>
#include <vector>
#include <map>

class LanguageParser {
public:
    struct Token {
        std::string type;
        std::string value;
        int line;
        int column;
    };

    struct ParsedCode {
        std::vector<Token> tokens;
        std::vector<std::string> functions;
        std::vector<std::string> variables;
        int complexity;
    };

    LanguageParser(const std::string& language);
    
    ParsedCode parse(const std::string& code);
    bool validateSyntax(const std::string& code);
    std::vector<std::string> detectErrors(const std::string& code);
    std::string refactor(const std::string& code);

private:
    std::string language;
    std::map<std::string, std::string> keywords;
    
    void initializeKeywords();
    std::vector<Token> tokenize(const std::string& code);
};

#endif
