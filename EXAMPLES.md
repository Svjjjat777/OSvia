# OSvia - Usage Examples

This document provides practical examples of how to use OSvia and its applications.

## Starting OSvia

```bash
$ ./osvia

╔════════════════════════════════════════╗
║    OSvia v0.1 - Main Menu              ║
╠════════════════════════════════════════╣
║ 1. Calculator       2. Browser          ║
║ 3. Weather         4. Flappy Bird      ║
║ 5. Snake           0. Shutdown         ║
╚════════════════════════════════════════╝

Select application (0-5): 
```

## Calculator Examples

### Basic Arithmetic

```
Select application (0-5): 1

╔════════════════════════════════╗
║        CALCULATOR              ║
╠════════════════════════════════╣
║  Display:        0             ║
╠════════════════════════════════╣
║ [7][8][9][/][C]                ║
║ [4][5][6][*][<-]               ║
║ [1][2][3][-]                   ║
║ [0][.][+][=]                   ║
║ Type 'exit' to quit             ║
╚════════════════════════════════╝

Input: 5
Input: +
Input: 3
Input: =
Display: 8
```

### Division

```
Input: 10
Input: /
Input: 2
Input: =
Display: 5
```

### Clear and Reset

```
Input: C
Display: 0
```

### Decimal Numbers

```
Input: 3
Input: .
Input: 14
Input: *
Input: 2
Input: =
Display: 6.28
```

## Browser Examples

### Navigate to Local Pages

```
Select application (0-5): 2

╔═════════════════════════════════════════╗
║     OSVIA BROWSER v0.1                  ║
╠═════════════════════════════════════════╣
║ URL: osvia://home
╠═════════════════════════════════════════╣
║ Title: OSvia Home
╠═════════════════════════════════════════╣
║ Welcome to OSvia Browser!
║
║ This is a simple browser engine.
║ You can navigate to basic pages.
╠═════════════════════════════════════════╣
║ Commands: navigate, back, forward, exit ║
╚═════════════════════════════════════════╝

Input: navigate osvia://about
```

### Browser Navigation History

```
Input: navigate osvia://home
Input: navigate osvia://about
Input: back           # Returns to osvia://home
Input: forward        # Goes back to osvia://about
```

### Reload Page

```
Input: reload
# Current page content refreshes
```

## Weather Examples

### Check Weather for Different Cities

```
Select application (0-5): 3

╔═════════════════════════════════════════╗
║    OSVIA WEATHER v0.1                   ║
╠═════════════════════════════════════════╣
║ City: Moscow                            ║
║ Temperature: -5.0°C                     ║
║ Condition: Snowy                        ║
║ Humidity: 75%                           ║
║ Wind Speed: 12.5 m/s                    ║
║ Updated: 2026-09-04 10:07:12            ║
╠═════════════════════════════════════════╣
║ Commands: city <name>, refresh, exit    ║
╚═════════════════════════════════════════╝

Input: city London
# Updates to London weather

Input: city Tokyo
# Updates to Tokyo weather
```

### Supported Cities

- Moscow (cold, snowy)
- London (rainy)
- Tokyo (cloudy)
- Dubai (sunny, hot)
- Any other city (default: clear, 20°C)

### Refresh Weather

```
Input: refresh
# Updates weather data for current city
```

## Flappy Bird Examples

### Starting the Game

```
Select application (0-5): 4

╔════════════════════════════════════╗
║                                    ║
║        @                           ║
║                                    ║
║               #                    ║
║               #                    ║
║               #                    ║
╚════════════════════════════════════╝

Score: 0 | Press SPACE to flap, 'exit' to quit
```

### Playing

```
Input: space        # Bird flaps and jumps
Input: space        # Flap again to dodge pipes
```

### Game Over and Restart

```
# After hitting a pipe or ground

Score: 5 | GAME OVER! Press 'r' to restart or 'exit' to quit

Input: r            # Restart game
Input: exit         # Return to menu
```

## Snake Examples

### Starting the Game

```
Select application (0-5): 5

╔════════════════════════════════════╗
║                                    ║
║               @                    ║
║                                    ║
║                 *                  ║  (* = food)
║                                    ║
╚════════════════════════════════════╝

Score: 0 | Length: 1
Instructions: WASD/Arrows to move, 'exit' to quit
```

### Playing

```
Input: d            # Move right
Input: w            # Move up
Input: d            # Move right
Input: s            # Move down
```

### Eating Food and Growing

```
# Head reaches food (*)
Score: 10 | Length: 2
# Snake body grows by 1
```

### Game Over

```
# After hitting yourself

Score: 50 | Length: 6 | GAME OVER! Press 'r' to restart or 'exit' to quit

Input: r            # Play again
Input: exit         # Return to menu
```

## Tips and Tricks

### Calculator
- Use `C` to clear the display
- You can chain operations: `5 + 3 + 2 = 10`
- Division by zero is handled gracefully

### Browser
- Use `osvia://` prefix for internal pages
- History is maintained automatically
- Try navigating to `osvia://home` and `osvia://about`

### Weather
- Cities are case-insensitive
- Try `city moscow`, `city london`, etc.
- Unknown cities default to "clear" weather

### Flappy Bird
- Timing is key - flap at the right moment
- Space bar must be pressed for each flap
- Pipes appear at random heights
- Score increases by 1 each time you pass a pipe

### Snake
- Can't move backwards into yourself
- Walls wrap around (exit left = enter right)
- Each food eaten adds 10 to score
- Snake grows by 1 segment per food

## Exiting Applications

All applications accept the `exit` command to return to the main menu:

```
Input: exit
Returning to main menu...
```

## System Shutdown

To shut down OSvia completely:

```
Select application (0-5): 0

Shutting down OSvia...
```

## Troubleshooting Common Issues

### Application Freezes
- Press `Ctrl+C` to force quit
- Restart from the main menu

### Input Not Responding
- Ensure you press Enter after typing input
- Check that caps lock is appropriate

### Incorrect Calculations
- Clear with `C` before new calculations
- Ensure proper number format

### Game Too Fast/Slow
- Adjust timing in `src/main.cpp` if recompiling
- Restart the game if performance issues occur

---

Enjoy using OSvia! 🎮
