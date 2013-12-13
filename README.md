RobotMaze
=========
Library to implement a Left Wall following robot to navigate the maze. Achieves A Functionality and Bonus Functionality.

## Notes

This library uses the RobotMotion and RobotSensors libraries to make movements. All function calls are in main.c in which calls to these libraries are made in order to implement funcitonality.

## Documentation
C2C Michael Bentley informed me that I should increase my delay after `rightTurn()` since my right wheel was not moving backwards at all. This advice solved my problem and allowed the robot to turn on a dime.
