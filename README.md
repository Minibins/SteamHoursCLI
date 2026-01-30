// minimal Steam "playing game" idle
// build: 
// g++ idle.cpp \
  -I. \
  -L. -lsteam_api \
  -Wl,-rpath,'$ORIGIN' \
  -o steam-idle
// run:   ./steam-idle 730