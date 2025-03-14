Echo off
cls

if not exist TXT (
    mkdir TXT
)

move "*.txt" "TXT\"

echo hello
pause



