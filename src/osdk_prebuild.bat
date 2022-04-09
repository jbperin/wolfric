@ECHO OFF


SET STARTADDR=$9800
SET INPUTFN=charset_std_s
SET OUTTAP=charset_std.tap
SET AUTOFLAG=0
%osdk%\bin\xa.exe %INPUTFN%.s -o BUILD\final.out -e xaerr.txt -l %INPUTFN%.txt
%osdk%\bin\header.exe -a%AUTOFLAG% BUILD\final.out BUILD\%OUTTAP% %STARTADDR%


SET STARTADDR=$9C00
SET INPUTFN=..\data\altchar.bin
SET OUTTAP=charset_alt.tap
SET AUTOFLAG=0
%osdk%\bin\header.exe -a%AUTOFLAG% %INPUTFN% BUILD\%OUTTAP% %STARTADDR%

SET STARTADDR=$BF40
SET INPUTFN=..\data\botpan.bin
SET OUTTAP=bottom_panel.tap
SET AUTOFLAG=0
%osdk%\bin\header.exe -a%AUTOFLAG% %INPUTFN% BUILD\%OUTTAP% %STARTADDR%


SET SPLASH_IMG=..\art\splash.png
%osdk%\bin\PictConv.exe -m0 -f6 -o4image %SPLASH_IMG% image_s.s

SET STARTADDR=$a000
SET INPUTFN=image_s
SET OUTTAP=splash.tap
SET AUTOFLAG=0
%osdk%\bin\xa.exe %INPUTFN%.s -o BUILD\final.out -e xaerr.txt -l %INPUTFN%.txt
%osdk%\bin\header.exe -a%AUTOFLAG% BUILD\final.out BUILD\%OUTTAP% %STARTADDR%

SET INPUTFN=loader
SET OUTTAP=loader.tap
%osdk%\bin\bas2tap.exe -b2t1 %INPUTFN%.bas BUILD\%OUTTAP% 


