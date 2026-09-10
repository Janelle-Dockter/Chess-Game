## Set up in Visual Studio Code

You only need 3 things installed to run this program straight from VSCode:
- Visual Studio Code, can be downloaded [here](https://code.visualstudio.com/)
- The C/C++ extension for Visual Studio Code
- Install MSYS2 and follow the instructions outlined on [this website](https://www.msys2.org/)

Once your installations are complete, ensure your PATH environment variable includes the UCRT bin, likely located at C:\msys64\ucrt64\bin.

In Visual Studio Code, open the local folder containing this repository. Open the chess.cpp file and locate the debug/run options in the top right of VSCode. Select *C/C++: g++.exe build and debug active file* as your debug configuration. Then, running or debugging this file should populate the VSCode terminal.
