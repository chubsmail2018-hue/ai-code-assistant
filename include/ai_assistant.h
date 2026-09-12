#ifndef AI_ASSISTANT_H
#define AI_ASSISTANT_H

#include "code_generator.h"
#include <string>

class AIAssistant {
private:
    CodeGenerator generator;

public:
    AIAssistant();
    
    void showMenu();
    void handleCreateFile();
    void handleGenerateCode();
    void handleGenerateFunction();
    void handleAnalyzeCode();
    void handleDebugCode();
    void handleRefactorCode();
    void showHelp();
    
    void run();
};

#endif
