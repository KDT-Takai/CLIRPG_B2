#!/bin/bash
set -euo pipefail

CONFIG=${CONFIG:-"Debug"}
BUILD_DIR="x64/$CONFIG"

echo "=========================================="
echo "Building CLIRPG_B2 ($CONFIG)"
echo "Build directory: $BUILD_DIR"
echo "Working dir: $(pwd)"
echo "=========================================="

mkdir -p "$BUILD_DIR"

VERSION=$(git describe --tags --always 2>/dev/null || echo "dev")
export VSOPTIONS="/p:Version=$VERSION /p:Configuration=$CONFIG /m:4"

msbuild CLIRPG_B2.sln $VSOPTIONS

if [ -f "$BUILD_DIR/CLIRPG_B2.exe" ]; then
  echo "✅ Build successful!"
  ls -lh "$BUILD_DIR/CLIRPG_B2.exe"
else
  echo "❌ Executable not found at $BUILD_DIR/CLIRPG_B2.exe"
  exit 1
fi

echo "=========================================="
