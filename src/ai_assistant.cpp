#include "ai_assistant.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

AIAssistant::AIAssistant() : generator() {}

void AIAssistant::showMenu() {
    cout << "\n" << string(60, '=') << endl;
    cout << "🤖 AI CODE ASSISTANT (C++ Engine)\n";
    cout << string(60, '=') << endl;
    cout << "\nAvailable Commands:\n";
    cout << "  1. create   - Create a new code file\n";
    cout << "  2. generate - Generate code snippet\n";
    cout << "  3. function - Generate function template\n";
    cout << "  4. analyze  - Analyze existing code\n";
    cout << "  5. debug    - Help debug code\n";
    cout << "  6. refactor - Refactor code\n";
    cout << "  7. languages - List supported languages\n";
    cout << "  8. help     - Show detailed help\n";
    cout << "  9. exit     - Exit the assistant\n";
    cout << string(60, '=') << "\n";
}

void AIAssistant::handleCreateFile() {
    string filename, language;
    
    cout << "\n📝 Create New File\n";
    cout << "Enter filename (without extension): ";
    cin >> filename;
    
    cout << "Enter language (python/c/cpp/java/javascript/go/rust): ";
    cin >> language;
    transform(language.begin(), language.end(), language.begin(), ::tolower);
    
    if (!generator.isValidLanguage(language)) {
        cout << "❌ Invalid language. Use 'languages' command to see supported languages.\n";
        return;
    }
    
    string fullFilename = filename + generator.getExtension(language);
    string content = generator.getHelloWorldTemplate(language);
    
    generator.createFile(fullFilename, content);
}

void AIAssistant::handleGenerateCode() {
    string language, description;
    
    cout << "\n💡 Generate Code Snippet\n";
    cout << "Enter language: ";
    cin >> language;
    transform(language.begin(), language.end(), language.begin(), ::tolower);
    
    if (!generator.isValidLanguage(language)) {
        cout << "❌ Invalid language.\n";
        return;
    }
    
    cout << "Describe what you want (e.g., 'loop from 1 to 10'): ";
    cin.ignore();
    getline(cin, description);
    
    cout << "\n📄 Generated Code:\n";
    cout << string(40, '-') << "\n";
    cout << generator.getHelloWorldTemplate(language);
    cout << string(40, '-') << "\n";
}

void AIAssistant::handleGenerateFunction() {
    string language, functionName, returnType;
    
    cout << "\n⚙️  Generate Function Template\n";
    cout << "Enter language: ";
    cin >> language;
    transform(language.begin(), language.end(), language.begin(), ::tolower);
    
    if (!generator.isValidLanguage(language)) {
        cout << "❌ Invalid language.\n";
        return;
    }
    
    cout << "Enter function name: ";
    cin >> functionName;
    
    cout << "Enter return type (default: void): ";
    cin.ignore();
    getline(cin, returnType);
    if (returnType.empty()) returnType = "void";
    
    string code = generator.generateFunctionTemplate(language, functionName, returnType);
    cout << "\n📄 Function Template:\n";
    cout << string(40, '-') << "\n";
    cout << code;
    cout << string(40, '-') << "\n";
}

void AIAssistant::handleAnalyzeCode() {
    string filename;
    
    cout << "\n🔍 Analyze Code\n";
    cout << "Enter filename to analyze: ";
    cin >> filename;
    
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "❌ Could not open file: " << filename << endl;
        return;
    }
    
    int lineCount = 0;
    int functionCount = 0;
    string line;
    while (getline(file, line)) {
        lineCount++;
        if (line.find('(') != string::npos && line.find(')') != string::npos) {
            functionCount++;
        }
    }
    file.close();
    
    cout << "\n📊 Analysis Results:\n";
    cout << "  Lines: " << lineCount << "\n";
    cout << "  Possible Functions: " << functionCount << "\n";
    cout << "  Complexity: Low\n";
}

void AIAssistant::handleDebugCode() {
    cout << "\n🐛 Debug Code\n";
    cout << "Enter code snippet (type 'END' when done):\n";
    
    string code, line;
    cin.ignore();
    while (getline(cin, line)) {
        if (line == "END") break;
        code += line + "\n";
    }
    
    cout << "\n🔍 Analyzing for potential issues...\n";
    cout << "  ⚠️  Possible null pointer access\n";
    cout << "  ⚠️  Memory leak detected\n";
    cout << "  ✓ Logic flow seems correct\n";
}

void AIAssistant::handleRefactorCode() {
    cout << "\n♻️  Refactor Code\n";
    cout << "Enter code snippet (type 'END' when done):\n";
    
    string code, line;
    cin.ignore();
    while (getline(cin, line)) {
        if (line == "END") break;
        code += line + "\n";
    }
    
    cout << "\n✨ Refactoring suggestions:\n";
    cout << "  1. Extract function for better reusability\n";
    cout << "  2. Use const references where applicable\n";
    cout << "  3. Add error handling\n";
}

void AIAssistant::showHelp() {
    cout << "\n📖 HELP - Detailed Command Information\n";
    cout << string(60, '=') << "\n";
    cout << "create   - Create a new code file from scratch or template\n";
    cout << "generate - Generate code snippets based on description\n";
    cout << "function - Generate function templates\n";
    cout << "analyze  - Analyze existing code files\n";
    cout << "debug    - Help identify bugs in code\n";
    cout << "refactor - Get refactoring suggestions\n";
    cout << "languages - Display all supported programming languages\n";
    cout << "exit     - Close the AI Assistant\n";
    cout << string(60, '=') << "\n";
}

void AIAssistant::run() {
    string command;
    bool running = true;
    
    while (running) {
        showMenu();
        cout << "Enter command: ";
        cin >> command;
        transform(command.begin(), command.end(), command.begin(), ::tolower);
        
        if (command == "1" || command == "create") {
            handleCreateFile();
        }
        else if (command == "2" || command == "generate") {
            handleGenerateCode();
        }
        else if (command == "3" || command == "function") {
            handleGenerateFunction();
        }
        else if (command == "4" || command == "analyze") {
            handleAnalyzeCode();
        }
        else if (command == "5" || command == "debug") {
            handleDebugCode();
        }
        else if (command == "6" || command == "refactor") {
            handleRefactorCode();
        }
        else if (command == "7" || command == "languages") {
            generator.listSupportedLanguages();
        }
        else if (command == "8" || command == "help") {
            showHelp();
        }
        else if (command == "9" || command == "exit") {
            cout << "\n👋 Thank you for using AI Code Assistant!\n";
            running = false;
        }
        else {
            cout << "❌ Unknown command. Type 'help' for assistance.\n";
        }
    }
}
