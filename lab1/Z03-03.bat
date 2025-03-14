Echo off
cls

if not exist TXT (
    mkdir TXT
)

set "EXT=%~1"	


move "*.%EXT%" "TXT\"

echo hello
pause



