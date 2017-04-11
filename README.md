# pleaseCompile
A rough attempt to get rid of complicated cross-compilers for C++.
Many beginners are overwhelmed by the details of modern build systems and for a good reason as they usually only need a small fraction of the functionality.
PleaseCompile tries to keep as much of the build procedure hidden from the user.
In the best case he/she only types "pleaseCompile" and pleaseCompile will produce the executable, using ninja internally.

PleaseCompile does a lot of things a good programmer wouldn't be proud of, like enforcing a certain project layout, binding basically all project folders as input and library folders, and some other stuff.

Please note that pleaseCompile is by far no complete build system! 
In its current state it does not support any of the fancy features of other more powerful build systems such as CMake, Meson, autotools, or others.

## Project structure
All pleaseCompile projects need to stick to a special folder layout which is described below:

    root
    -src
    --app
    ---"your first executable" 
    ---"your second executable"
    --- ...
    --lib
    ---"your first static library that gets linked into your executables"  
    ---"your second static library that gets linked into your executables"
    --- ...

root is your project folder which needs to contain a src folder.

## Installation
You need to install Qt5 before installing pleaseCompile.
Currently no installer for pleaseCompile is provided, so you need to download the source files and compile them calling

    qmake pleaseCompile.pro

Copy the resulting executable into one of your folders specified in the environment variable $PATH so you can call it from a terminal.

## Usage
Simply go to your projects root directory and type 

    pleaseCompile

That's all. In the best case you don't need to specify any dependencies, include directories or link directories.
PleaseCompile should create a build directory and place the executable in there.

In some ambiguous cases pleaseCompile might ask you to specify which library or header you want to use. This usually happens if the header or library is neither part of the project nor in the standard folders.

## Restrictions
To allow this simplistic usage some guidelines must be followed:
- You have to stick to the project structure listed above
- In the best case any external libraries and headers used are in the standard directories.
- Avoid namespace clutter, no two files with the same name are allowed.
- All libraries that get created are named after the folder their source code resides.
- There are probably a lot more, I will add them here as soon as I stumble across them.

Hope you enjoy using pleaseCompile!

Some code:
'''javascript
function fancyAlert(arg) {
  if(arg) {
    $.facebox({div:'#foo'})
  }
}
'''
