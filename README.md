# KnightTravail

### **Assignment**

Find shortest path for chess *knight* from starting square to the destination square. For more details, see [here](https://www.theodinproject.com/paths/full-stack-ruby-on-rails/courses/ruby-programming/lessons/knights-travails).

### **Solution**

Assignment is solved in C++ with implementation of [BFS algorithm](https://en.wikipedia.org/wiki/Breadth-first_search).\
Square positions are represented with [chess notation](https://en.wikipedia.org/wiki/Algebraic_notation_(chess)).

### **Getting Started**

For project generation *Premake5* is used, it is done and tested in Visual studio 2019 enviroment, so Visual studio 2019 is recommended. Other development environments are untested.

#### **<ins>1. Downloading the repository</ins>**

Start by cloning the repository with `https://github.com/rperica/KnightTravail.git`

#### **<ins>2. Build Configuration</ins>**

Run ***GenerateProject.bat*** in order to build configuration.

#### **NOTE:** For other development environments it is needed to change *vs2019* argument in ***GenerateProject.bat***. Supported development environments and their arguments can be found at premake [documentations](https://premake.github.io/docs/Using-Premake).


#### **<ins>3. Compile and Run</ins>**
After configuration is built, open ***KnightTravail.sln*** to open Visual Studio solution. In Visual Studio build solution, it will generate bin folder in the solution folder. In bin folder there will be subdirectory called bin where can be found ***KnightTravail.exe*** for specific configuration. 