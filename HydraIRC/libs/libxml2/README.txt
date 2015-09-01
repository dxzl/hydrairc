========================================================================
I pre-built the libraries for Windows and put them in lib so you don't
need to follow the steps below unless you need to rebuild them.
XML Library files: libxml2.lib, libxml2_a.lib and libxml2_a_dll.lib
========================================================================

To re-build the libraries:

get libxml2 "GNOME" version from github.com:

https://github.com/GNOME/libxml2

and put the "master" contents into this directory (the "master" zip worked). 

To build for VS 2015

Open visual studio console (if you open x32 console - it builds x32 library,
if x64 - it builds x64 library). Go to libxml2/win32 and enter:

cscript.exe configure.js iconv=no compiler=msvc cruntime=/MT debug=no prefix="..\build_x86_static_release_mt" static=yes
nmake Makefile.msvc libxml install
nmake clean
cscript.exe configure.js iconv=no compiler=msvc cruntime=/MTd debug=yes prefix="..\build_x86_static_release_mtd" static=yes
nmake Makefile.msvc libxml install

NOTE:

I just ended up creating a new folder "lib" then hand-copied libxml2_a.lib, libxml2.lib and libxml2_a_dll.lib

from:

C:\Users\MyName\Documents\Visual Studio 2015\Projects\HydraIRC\HydraIRC\libs\libxml2\win32\bin.msvc

to:

C:\Users\MyName\Documents\Visual Studio 2015\Projects\HydraIRC\HydraIRC\libs\libxml2\lib

Then add that path in in the project's "Additional Library Directories"

NOTE: Disable the libxml2 project in the Visual Studio GUI to keep it from building or being cleaned in the
normal HydraIRC build.

reference site that helped me figure this out...

http://hostagebrain.blogspot.com/2015/06/building-libxml2-without-dependencies.html

- dxzl
========================================================================
