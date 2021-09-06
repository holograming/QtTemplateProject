# QtTemplateProject
Qt 개발하면서, 임시적으로 테스트 목적으로 개발할 프로젝트들을 기록으로 남기기 위함.

[Document](https://devblogs.microsoft.com/cppblog/clear-functional-c-documentation-with-sphinx-breathe-doxygen-cmake/)   
[Mordern CMake](https://cliutils.gitlab.io/modern-cmake/)   
[Vcpkg](https://vcpkg.io/en/index.html)   
[SourceTree](https://github.com/michalbe/md-file-tree)

---
'''
\---Tools
    +---cmake-3.21.2
    +---vcpkg

\---Projects  
    +---Project1
    +---Project2
    +---..... 
'''

### Project quick start
---
Pre-build vcpkg and cmake support Windows 10(64-bit) with visual studio 2019 over. 

- Install vcpkg under Tools folder
```
> cd Tools
> git clone https://github.com/microsoft/vcpkg
> .\vcpkg\bootstrap-vcpkg.bat
```

- Downalod and install CMake under Tools folder
```
> git clone https://github.com/microsoft/vcpkg
> .\vcpkg\bootstrap-vcpkg.bat
```
    
- Install Qt libraries    
```
> .\vcpkg\vcpkg install Qt:x64-windows
```

- Integrate vcpkg with Visual Studio
```
> .\vcpkg\vcpkg integrate install
```
