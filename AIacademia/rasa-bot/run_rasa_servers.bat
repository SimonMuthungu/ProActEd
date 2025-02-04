@echo off
echo Starting Rasa action server...
cd /d "%~dp0"
start "Rasa Action Server" cmd /k "rasa run actions --debug"

timeout /t 5 /nobreak > NUL

echo Starting Rasa server...
start "Rasa Server" cmd /k "rasa run --enable-api --cors * --debug"

echo Both servers are now running.
pause
