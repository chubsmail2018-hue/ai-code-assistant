#include "code_generator.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

CodeGenerator::CodeGenerator() {
    initializeLanguages();
    initializeTemplates();
}

void CodeGenerator::initializeLanguages() {
    languageExtensions["python"] = ".py";
    languageExtensions["c"] = ".c";
    languageExtensions["cpp"] = ".cpp";
    languageExtensions["java"] = ".java";
    languageExtensions["javascript"] = ".js";
    languageExtensions["go"] = ".go";
    languageExtensions["rust"] = ".rs";

    languageComments["python"] = "#";
    languageComments["c"] = "//";
    languageComments["cpp"] = "//";
    languageComments["java"] = "//";
    languageComments["javascript"] = "//";
    languageComments["go"] = "//";
    languageComments["rust"] = "//";
}

void CodeGenerator::initializeTemplates() {
    codeTemplates["python_hello"] = 
        "#!/usr/bin/env python3\nprint(\"Hello, World!\")\n";

    codeTemplates["c_hello"] = 
        "#include <stdio.h>\n\n"
        "int main() {\n"
        "    printf(\"Hello, World!\\n\");\n"
        "    return 0;\n"
        "}\n";

    codeTemplates["cpp_hello"] = 
        "#include <iostream>\n\n"
        "int main() {\n"
        "    std::cout << \"Hello, World!\" << std::endl;\n"
        "    return 0;\n"
        "}\n";

    codeTemplates["java_hello"] = 
        "public class HelloWorld {\n"
        "    public static void main(String[] args) {\n"
        "        System.out.println(\"Hello, World!\");\n"
        "    }\n"
        "}\n";

    codeTemplates["javascript_hello"] = 
        "console.log(\"Hello, World!\");\n";

    codeTemplates["go_hello"] = 
        "package main\n\n"
        "import \"fmt\"\n\n"
        "func main() {\n"
        "    fmt.Println(\"Hello, World!\")\n"
        "}\n";

    codeTemplates["rust_hello"] = 
        "fn main() {\n"
        "    println!(\"Hello, World!\");\n"
        "}\n";
}

bool CodeGenerator::isValidLanguage(const string& language) {
    return languageExtensions.find(language) != languageExtensions.end();
}

string CodeGenerator::getExtension(const string& language) {
    return languageExtensions[language];
}

string CodeGenerator::getHelloWorldTemplate(const string& language) {
    string key = language + "_hello";
    if (codeTemplates.find(key) != codeTemplates.end()) {
        return codeTemplates[key];
    }
    return "// Template not found\n";
}

bool CodeGenerator::createFile(const string& filename, const string& content) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not create file " << filename << endl;
        return false;
    }
    file << content;
    file.close();
    cout << "✅ File created: " << filename << endl;
    return true;
}

string CodeGenerator::generateFunctionTemplate(const string& language, 
                                              const string& functionName, 
                                              const string& returnType) {
    stringstream ss;
    
    if (language == "python") {
        ss << "def " << functionName << "(param1, param2):\n"
           << "    \"\"\"Function description\"\"\"\n"
           << "    pass\n";
    }
    else if (language == "c" || language == "cpp") {
        ss << returnType << " " << functionName << "(int param1, int param2) {\n"
           << "    // Implementation\n"
           << "    return 0;\n"
           << "}\n";
    }
    else if (language == "java") {
        ss << "public static " << returnType << " " << functionName << "(int param1, int param2) {\n"
           << "    // Implementation\n"
           << "    return 0;\n"
           << "}\n";
    }
    else if (language == "javascript") {
        ss << "function " << functionName << "(param1, param2) {\n"
           << "    // Implementation\n"
           << "    return 0;\n"
           << "}\n";
    }
    else if (language == "go") {
        ss << "func " << functionName << "(param1, param2 int) int {\n"
           << "    // Implementation\n"
           << "    return 0\n"
           << "}\n";
    }
    else if (language == "rust") {
        ss << "fn " << functionName << "(param1: i32, param2: i32) -> i32 {\n"
           << "    // Implementation\n"
           << "    0\n"
           << "}\n";
    }
    
    return ss.str();
}

void CodeGenerator::listSupportedLanguages() {
    cout << "\n📚 Supported Languages:\n";
    cout << "  • Python (.py)\n";
    cout << "  • C (.c)\n";
    cout << "  • C++ (.cpp)\n";
    cout << "  • Java (.java)\n";
    cout << "  • JavaScript (.js)\n";
    cout << "  • Go (.go)\n";
    cout << "  • Rust (.rs)\n\n";
}
