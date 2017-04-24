
// What I did

I made a main driver with a menu, so that a user can select which color 
a robot will fight, and which fighting style it will use.  It then fights 
based on these given parameters.  I think this is useful because it keeps 
us from needing to continually download new code.  A nice side effect of 
this is that now, we can refactor a lot of code, and only have one main! 


// How it works

After the after the color/fighting style is chosen, the robot waits for the 
user to press A to start fighting so that there is time to position the robot 
appropriately.  Then, it enters a while loop; this loop can only be broken out 
of when the joust is over, or if the black button is pressed in case of 
"emergency".  Inside the loop, the joust function is called.  I moved the 
actual fighting into this function to make everything clean and nice.  Yay 
encapsulation!  This function returns an int indicating whether or not the 
fight is over.  That integer is captured in a variable, and by changing that 
variable from FALSE (0) to TRUE (1), the loop is broken out of, and the 
program ends.

The joust function is a way of keeping the same structure for every fighting 
style.  This does NOT make the styles all "the same" but rather is a happy way 
to eliminate code reuse.  For example, the border control functions, accept 
defeat function, and find shield functions really should never change, 
regardless of fighting style.  The remaining functions may, depending on how 
each style is implemented, which is how the diversity is allowed.  These are 
the functions that can be changed from style to style (in order of appearance 
in code):

	(1) locate shield
	(2) move lance
	(3) react to shield
	(4) normalize

Each of the styles has one of these functions.  The driver.h header file has all
of the function headers, but each group of four functions native to each style 
have their own .c files.  These are all header-guarded and included in main. Since
I do not know what hybrid_td will look like since I'm not writing it, I just made 
the content of the functions the same as the offensive ones for a "clean" slate 
to work with. 


// Locate shield

This function determines what behavior the robot will have if it does not detect 
the shield.  The default behavior is to move straight.  However, there doesn't 
seem to be any reason why this can't change from style to style, so I made one 
function for each style.  Right now, they are all the same, and if they stay that 
way, they can be refactored later.


// Move lance

This function determines how the lance moves.  I know that this is something that 
will definitely be different for each style.  


// React to shield

This function determines what behavior the robot will have when it does see the 
shield.  Funnily, this seems like it would be something that would vary from style 
to style, but since all of the styles (to my knowledge) use braitenberg, only the 
normalize functions need be different, and so for offensive, defensive, and 
hybrid_ve (for the moment), this function is uniform.  If they stay that way, they 
can be refactored later.


// Normalize

This function gives the "react to shield" function a normalized value to give to 
the motors in accordance to whatever braitenberg behavior is appropriate to the 
fighting style.  As alluded to above, this is obviously something that must vary 
for each style.


// What happens now

I haven't tested the driver yet because it's late and I have other homework to 
get to and I don't feel like testing it right now, but it should theoretically, 
optimistically, work perfectly.  When we all go in to change our fighting styles, 
only the functions in the offensive/defensive/hybrid_ve/hybrid_td files should 
change.  If function headers need changing (which is totally fine) then they 
should also obviously be changed in the driver.h as well.  This is how everything 
works.  If anyone has any questions for me, feel free to bring them up in the group. 
:)
