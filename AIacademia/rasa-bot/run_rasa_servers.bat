@echo off
echo Starting Rasa action server...
start "Rasa Action Server" cmd /k "cd C:\Users\user\Desktop\ProActEd\AIacademia\rasa-bot && rasa run actions --debug"

timeout /t 5 /nobreak > NUL

echo Starting Rasa server...
start "Rasa Server" cmd /k "cd C:\Users\user\Desktop\ProActEd\AIacademia\rasa-bot && rasa run --enable-api --cors "*" --debug"

echo Both servers are now running.
pause