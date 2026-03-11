## NFL Stat Tracker
A console-based C++ application for tracking player statistics across NFL and CFB positions.
  Built to practice C++ fundamentals, including pointer-to-member syntax, struct-based data modeling, and file persistence with ofstream/ifstream. Actively developed with a focus on clean, scalable design.

## Features
Add and remove players by position
Position-specific stat tracking (QB, RB, WR, TE, OL, DL, LB, DB)
Edit individual stats from an interactive menu
Data persists between sessions via file save/load

## Planned Features
Search and filter players
Sort players by stat
Sort Stats by Season
GUI interface

## How to Compile and Run
g++ -o stattrack stattrack.cpp
./stattrack

## Sample Output
```
NFL Stat Indicator v0.0.1

Menu:

1. Add Player
2. Remove Player
3. Player Stat Menu
4. Quit

Enter your choice:
1

Enter Name of Player:
patrick mahomes
Enter Position (QB, RB, WR, TE, OT, OG, C, DE, DT, OLB, ILB, CB, FS, SS):
qb

New Player added!

Menu:
...

3

Current Players:

Patrick Mahomes
Position: QB
Touchdowns: 0
Passing Yards: 0
Rushing Yards: 0
...

Please enter player # to edit (0 to cancel):
1. Patrick Mahomes

1

Please select a stat to edit for Patrick Mahomes
0. Cancel
1. Touchdowns: 0
2. Passing Yards: 0
...

2
5000

Stat updated!
```

## Positions Supported
QB, RB, WR, TE, OT, OG, C, DE, DT, OLB, ILB, CB, FS, SS

