@ECHO OFF
if not exist "BUILD" mkdir BUILD
::
:: Initial check.
:: Verify if the SDK is correctly configurated
::
IF "%OSDK%"=="" GOTO ErCfg


::
:: Set the build paremeters
::
CALL osdk_config.bat

CALL osdk_prebuild.bat

::
:: Launch the compilation of files
::
CALL %OSDK%\bin\make.bat %OSDKFILE%

MOVE BUILD\%OSDKNAME%.tap BUILD\main.tap
COPY /B BUILD\loader.tap+BUILD\splash.tap+BUILD\charset_std.tap+build\charset_alt.tap+BUILD\bottom_panel.tap+build\main.tap BUILD\%OSDKNAME%.tap
REM COPY /B BUILD\loader.tap+build\charset_alt.tap+build\main.tap BUILD\%OSDKNAME%.tap


GOTO End


::
:: Outputs an error message
::
:ErCfg
ECHO == ERROR ==
ECHO The Oric SDK was not configured properly
ECHO You should have a OSDK environment variable setted to the location of the SDK
IF "%OSDKBRIEF%"=="" PAUSE
GOTO End


:End
pause
