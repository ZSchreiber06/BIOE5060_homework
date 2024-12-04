# A MATLAB Pong Game
The updatepong() function updates the location of the pong ball. When the ball hits the top or bottom of the screen its  velocity in the y direction is reflected. When the ball hits either the red or blue bat the velocity in the x direction is reflected. When the ball hits the right or left side of the wall without hitting a bat a point is added to the opposite team's score and the ball is set back to the center. 
The WindowKeyPressFcn() function assigns keys to the movement of the red and blue bats. 
In this code, the red bat is moved up by the q key and down by the z key. While the blue bat is moved up by the p key and down by the m key.
The sbSpeed_Callback() function adjusted the speed of the pong ball using the slide (called speed) in the GUI interface.
The btClose_Callback(), closes the GUI when the close button is hit. It uses closereq() to do this. 
