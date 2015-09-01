---------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------
DISCLAIMER 8/31/2015: This is NOT a new distribution of HydraIRC or a "derivative
work" and there has been no modification of the original author's "limited-use"
source license (which dates back to 2006). The author released his project on GitHub,
probably with the intention of making it open-source, and may just have not gotten
around to changing the license-header in all of the source-files, but I had to make
a few changes and do one bug-fix so the HydraIRC chat-client would work with my own
program, YahCoLoRiZe. And in doing that, I had to upgrade the project to work
with current software tools and libraries (a significant amount of work on my part).
So, for the time-being, this repository is NOT for distribution without permission
from Dominic Clifton (aka Hydra). I also wrote my own plugin for HydraIRC which is
included in my GitHub branch of a fork off the original HydraIRC project. My own work
on HydraIRC is freely-distributable and is "open-source". My fork of HydraIRC is a
work-in-progress. If there are any questions regarding my improvements and bug-fixes
to HydraIRC, please contact me: dxzl@live.com (Scott).
---------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------

Before you load HydraIRC into Visual Studio 2015 you should read below!

Get and install Visual Studio 2015 Community Edition and put hydrairc in your
Documents\Visual Studio 2015\Projects folder. BUT DON'T TRY TO LOAD THE PROJECT YET!

Read the README files in:

hydrairc\HydraIRC\atlmfc
hydrairc\HydraIRC\ATLServer
hydrairc\HydraIRC\wtl
hydrairc\HydraIRC\libs\libxml2
hydrairc\Installer

follow the directions...

Then load the solution file (HydraIRC.sln) into Visual Studio 2015,
let it get all the header-files parsed... then select Build->Build Solution

After building (of course there will be no errors or warnings :-)

The post-build will automatically copy all output files to the Distribution folder.

To build the installer .exe file read hydrairc\Installer\README.txt

- cheers, dxzl

---------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------

WHAT I'VE CHANGED:

1) compiles with Visual Studio 2015 Community edition using newer ATL/WTL
libraries

2) rebuilt the libxml libraries with the latest version and included the binaries

3) includes my own plugin that works with YahCoLoRiZe (Colorize.dll)

4) installer-script for NSIS now works with UAC and nsis-3.0b2. UAC allows Hydra to
be launched in user-mode instead of admin after install so that your settings get
stored to the right place and so that Windows 10 security doesn't freak-out.

5) fixes a bug that aborted servicing of plugin-functions for remaining plugins if
any single plugin did not implement a particular function (if it returned a NULL
pointer). This change is in ChildFrm.cpp

6) plugins now have access to the Query window ID instead of just the channel
window ID. this was to allow YahCoLoRiZe to receive /cx text commands from
a user in a query-session and to then send colorized text back to the proper
window.

---------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------

