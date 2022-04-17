# leetcode
A repository to contain all my leetcode submissions

# Dependencies
* VS-Code
* VS-Code extensions
  * jeff-hykin.better-cpp-syntax
  * ms-vscode.cpptools-extension-pack
  * EditorConfig.EditorConfig

## Windows
* mingw-64

## mac-os
* Clang

# Build
* `mkdir build`
* `cd build`

## Windows
* `g++ \path\to\file.cc -o file.exe`
* `.\file.exe`

## mac-os
* `/usr/bin/clang++ -std=c++17 -stdlib=libc++ -g /path/to/file.cc -o file`
* `./file`

# Debug
* In VSCode
* Ensure that `build` directoy exists
* Select `Run and Debug`
* Open the required `cc` file from `problems` folder
* Select either `clang++ mac - Build and debug active file` or `gdb win - Build and debug current file`