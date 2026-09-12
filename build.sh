#!/bin/bash
# Build script for AI Code Assistant (Linux/macOS)

echo ""
echo "================================"
echo "🔨 AI Code Assistant - Build Script"
echo "================================"
echo ""

# Check if CMake is installed
if ! command -v cmake &> /dev/null; then
    echo "❌ CMake is not installed. Please install CMake first."
    exit 1
fi

# Create build directory
if [ ! -d "build" ]; then
    echo "📁 Creating build directory..."
    mkdir build
fi

# Change to build directory
cd build

# Run CMake
echo "🔧 Running CMake..."
cmake ..

# Build the project
echo "⚙️  Building project..."
cmake --build . --config Release

# Check if build was successful
if [ $? -eq 0 ]; then
    echo ""
    echo "✅ Build successful!"
    echo "📍 Executable location: ./ai_assistant"
    echo ""
    echo "Run with: ./ai_assistant"
else
    echo ""
    echo "❌ Build failed!"
    exit 1
fi
