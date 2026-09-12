#include "language_parser.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

LanguageParser::LanguageParser(const string& lang) : language(lang) {
    initializeKeywords();
}

void LanguageParser::initializeKeywords() {
    if (language == "c" || language == "cpp") {
        keywords["int"] = "keyword";
        keywords["void"] = "keyword";
        keywords["char"] = "keyword";
        keywords["if"] = "keyword";
        keywords["else"] = "keyword";
        keywords["for"] = "keyword";
        keywords["while"] = "keyword";
        keywords["return"] = "keyword";
    }
    else if (language == "python") {
        keywords["def"] = "keyword";
        keywords["class"] = "keyword";
        keywords["if"] = "keyword";
        keywords["else"] = "keyword";
        keywords["for"] = "keyword";
        keywords["while"] = "keyword";
        keywords["return"] = "keyword";
    }
    else if (language == "javascript") {
        keywords["function"] = "keyword";
        keywords["var"] = "keyword";
        keywords["let"] = "keyword";
        keywords["const"] = "keyword";
        keywords["if"] = "keyword";
        keywords["else"] = "keyword";
        keywords["for"] = "keyword";
        keywords["while"] = "keyword";
        keywords["return"] = "keyword";
    }
}

vector<LanguageParser::Token> LanguageParser::tokenize(const string& code) {
    vector<Token> tokens;
    stringstream ss(code);
    string line;
    int lineNum = 0;
    
    while (getline(ss, line)) {
        lineNum++;
        istringstream iss(line);
        string word;
        int col = 0;
        
        while (iss >> word) {
            Token token;
            token.line = lineNum;
            token.column = col;
            token.value = word;
            
            if (keywords.find(word) != keywords.end()) {
                token.type = "keyword";
            } else {
                token.type = "identifier";
            }
            
            tokens.push_back(token);
            col += word.length() + 1;
        }
    }
    
    return tokens;
}

LanguageParser::ParsedCode LanguageParser::parse(const string& code) {
    ParsedCode result;
    result.tokens = tokenize(code);
    result.complexity = result.tokens.size() / 10; // Simplified complexity calculation
    
    return result;
}

bool LanguageParser::validateSyntax(const string& code) {
    int openBraces = 0;
    int closeBraces = 0;
    
    for (char c : code) {
        if (c == '{') openBraces++;
        if (c == '}') closeBraces++;
        if (c == '(') openBraces++;
        if (c == ')') closeBraces++;
    }
    
    return openBraces == closeBraces;
}

vector<string> LanguageParser::detectErrors(const string& code) {
    vector<string> errors;
    
    if (!validateSyntax(code)) {
        errors.push_back("Mismatched braces or parentheses");
    }
    
    if (code.find("NULL") != string::npos && 
        code.find("nullptr") == string::npos &&
        language == "cpp") {
        errors.push_back("Use 'nullptr' instead of 'NULL' in C++");
    }
    
    return errors;
}

string LanguageParser::refactor(const string& code) {
    string refactored = code;
    
    // Replace old style NULL with nullptr for C++
    if (language == "cpp") {
        size_t pos = 0;
        while ((pos = refactored.find("NULL", pos)) != string::npos) {
            refactored.replace(pos, 4, "nullptr");
            pos += 7;
        }
    }
    
    return refactored;
}
