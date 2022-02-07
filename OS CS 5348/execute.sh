#/bin/bash
set -e
make
cat cal.exe | fgrep -c "quadratic" shellop