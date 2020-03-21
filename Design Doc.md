# Design Doc

This project is based on the [Pong Challenge](https://gamedev.net/challenges/2-pong/) on gamedev.net.

## Game Requirements

The game must have:
- Start screen
- Key to return to the start screen
- Score system
- AI Player
- Graphics at least for the UI and players
- Sound effects for ball and paddle and when a player scores
- A unique gameplay element that makes your Pong game stand out from others
- The actual gameplay must happen on a single screen (no camera translation)

## Art Requirements

- The game must be 2D
- The art must be your own

## Game Components
#### Start Screen
The screen shown when the game starts. Contains:
- Game title
- Game credits
- Start button
- Quit button
- Instructions

#### Game screen
The screen shown when playing the game. Contains:
- Ball
- Player paddle
- Computer paddle
- Background image
- Scoreboard
- Prompt to launch ball
- Prompt for winning

#### Keybindings
The keys that will be used and their function:
- w/W: Move paddle up
- s/S: Move paddle down
- Esc: Return to start screen from game
- Space: Launch ball/Pause game

## Game Mechanics
#### Paddles
Located at the left and right edges of the screen. Left is controlled by the player; Right is controlled by the AI. Paddles can move along the x-axis and reflect the ball.

#### Ball
Starts stationary in the center of the screen.  Once launched, bounces off the top and bottom boundaries as well as the paddles.  Bounces are physics based incorporating spin and paddle momentum.  

#### Winning
When the ball leaves the left or right side of the screen, a point is awarded to the player who hit it passed their opponent.  First player to 5 points wins.  

#### Unique Gameplay Element: Power-ups
Power-ups:
- Spawn randomly along the center of the play area
- Appear as rotating boxes with a letter corresponding to it's contents
- Power-ups are awarded to the player who hits it with the ball
- Power-ups include:
    - Ball Speed
    - Ball Size
    - Backboard (make it harder for opponent to score)
    - Ball direction
- [ ] Finalize mechanics


## Assets
#### Font
The font will be used for start screen elements and scoring.
For development, will use FreeSansBold.ttf from [GNU Free Fonts](https://github.com/opensourcedesign/fonts/tree/master/gnu-freefont_freesans). May use FontForge to create custom font down the road.
- [ ] Update with custom font

#### Art
- Background: Custom image
- [ ] Update with background image file

#### Audio
- Sound for ball bounce
- Sound for start screen buttons
- Sound for scoring
- Sound for winning
- [ ] Update with sound files
