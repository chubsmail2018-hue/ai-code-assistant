#!/usr/bin/env python3
"""
AI Code Assistant - Main Entry Point
Supports code generation in Python, C, C++, Java, JavaScript, and more.
"""

import os
import sys
from pathlib import Path
from typing import Optional
from assistant import AICodeAssistant

def main():
    """Main function to run the AI Code Assistant."""
    print("=" * 60)
    print("🤖 AI CODE ASSISTANT")
    print("=" * 60)
    print("\nSupported Languages: Python, C, C++, Java, JavaScript, Go, Rust")
    print("Supported Tasks: File creation, code generation, debugging, refactoring")
    print("\nCommands:")
    print("  'create' - Create a new code file")
    print("  'generate' - Generate code snippet")
    print("  'explain' - Explain existing code")
    print("  'debug' - Help debug code")
    print("  'refactor' - Refactor existing code")
    print("  'help' - Show help information")
    print("  'exit' - Exit the assistant")
    print("=" * 60 + "\n")
    
    assistant = AICodeAssistant()
    
    while True:
        try:
            user_input = input("\n🤖 Assistant> ").strip()
            
            if not user_input:
                continue
            
            if user_input.lower() == 'exit':
                print("\n👋 Goodbye! Happy coding!")
                break
            
            elif user_input.lower() == 'help':
                assistant.show_help()
            
            elif user_input.lower().startswith('create'):
                assistant.create_file_interactive()
            
            elif user_input.lower().startswith('generate'):
                assistant.generate_code_interactive()
            
            elif user_input.lower().startswith('explain'):
                assistant.explain_code_interactive()
            
            elif user_input.lower().startswith('debug'):
                assistant.debug_code_interactive()
            
            elif user_input.lower().startswith('refactor'):
                assistant.refactor_code_interactive()
            
            else:
                # Free-form request
                assistant.process_request(user_input)
        
        except KeyboardInterrupt:
            print("\n\n👋 Interrupted. Goodbye!")
            break
        except Exception as e:
            print(f"❌ Error: {str(e)}")
            print("Try again or type 'help' for assistance.")

if __name__ == "__main__":
    main()
