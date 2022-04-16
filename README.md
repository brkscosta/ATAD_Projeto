# ATAD_Projeto
Algorithms and Abstract Data Project, Computer Engeneering 2018-2019
 
 This project loads CSV files and performs some calculation based on csv data. Basically it's a simulation of a medical data from some patients.
 This project have the implementatin of list, map and queue data sctructure and their usages do manage the data from the patients.
 
 To run this you must have gcc or g++ to compile the project. If you want to install you can find out this here https://www.msys2.org/
 
 Create a `task.json` and `lauch.json` on Visual Studio Code to compile and run the project.
 
 `task.json`
 ```json
{
  "tasks": [
    {
      "type": "cppbuild",
      "label": "Generate Main .exe",
      "command": "C:/msys64/mingw64/bin/g++.exe",
      "args": [
        "-g",
        "${fileDirname}\\Utils\\**.c",
        "${fileDirname}\\DataStructures\\**.c",
        "${fileDirname}\\PatientStruct\\**.c",
        "${file}",
        "-o",
        "${workspaceFolder}\\debug\\${fileBasenameNoExtension}.exe"
      ],
      "options": {
        "cwd": "${fileDirname}"
      },
      "problemMatcher": ["$gcc"],
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "detail": "compiler: C:/msys64/mingw64/bin/g++.exe"
    }
  ],
  "version": "2.0.0"
}
```
`launch.json`
```json
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "Debug",
      "type": "cppdbg",
      "request": "launch",
      "program": "${workspaceFolder}\\debug\\${fileBasenameNoExtension}.exe",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${fileDirname}",
      "environment": [],
      "externalConsole": true,
      "MIMode": "gdb",
      "miDebuggerPath": "C:\\msys64\\mingw64\\bin\\gdb.exe",
      "setupCommands": [
        {
          "description": "Enable pretty-printing for gdb",
          "text": "-enable-pretty-printing",
          "ignoreFailures": true
        }
      ],
      "preLaunchTask": "C/C++: g++.exe build active file"
    }
  ]
}
```
![image](https://user-images.githubusercontent.com/31209677/163683467-707a831a-bdd5-415b-b478-c33fecffb11a.png)
