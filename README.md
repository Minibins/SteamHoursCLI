# SteamHoursCLI
Minimal Steam game idler written in C++.

Shows you as "in-game" for any Steam AppID without actually running the game.
Perfect for trading card farming or testing Steam API integration.

## Usage
```bash
./steam-idle <appid>
```

Example:
```bash
./steam-idle 730  # CS2/CS:GO
```

Press Ctrl+C to stop.

## Building

### Prerequisites
- g++ compiler
- Linux 64-bit

### Compile
```bash
g++ idle.cpp \
  -I. \
  -L. -lsteam_api \
  -Wl,-rpath,'$ORIGIN' \
  -o steam-idle
```

### Run
```bash
./steam-idle <appid>
```

## Requirements
- Steam client must be running
- You must be logged in
- The game does NOT need to be installed

## License

Free to use, modify, and distribute. Just give credit:
```
Based on steam-idle by [твой ник]
```

That's it!
