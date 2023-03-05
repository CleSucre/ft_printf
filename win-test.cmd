@echo off
make
for %%f in (test\*) do gcc -Wall -Wextra -Werror %%f libftprintf.a
a.exe
