@echo off

set name="..\testrom.nes"

set path=%path%;..\..\cc65\bin\

set CC65_HOME=..\..\cc65

cc65 -Oi game.c --add-source
ca65 crt0.s
ca65 game.s

ld65 -C nes.cfg -o %name% crt0.o game.o runtime.lib

del *.o
del game.s

D:\systems\Nes\fceux\fceux.exe %name%