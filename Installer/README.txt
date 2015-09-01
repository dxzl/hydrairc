========================================================================
get the NSIS (nullsoft scriptable installer):

http://nsis.sourceforge.net/Download

you also need UAC.zip from http://nsis.sourceforge.net/UAC_plug-in

Install NSIS (I'm using 3.0b2 on Windows 10 Pro). Put the x86 DLL in
"Program Files (x86)\NSIS\Plugins\x86-ansi" and put UAC.nsh in
"Program Files (x86)\NSIS\Include"

To build HydraIRC just right-click "HydraIRC Installer.nsi" and select
"Compile NSIS Script". The output-file, HydraIRC-v0.3.165-Release.exe,
will be in the Distribution folder.

- dxzl
========================================================================
