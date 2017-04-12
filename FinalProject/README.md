# Strategic Autonomous Jousting Robots
### We Demand Trial by Combat

### Programmers:

#### Team Razzle Frazzle           Team Velmer
Darin Beaudreau                Victoria Albanese
Tim Larocque                   Elmer Melendez

### Opportunity Statement
For our final project, we are implementing a robotic version of the medieval
sport of jousting. Our project is primarily for entertainment purposes. We
wanted to collaborate with a group to create Battle Bots, but saw this as the
less destructive way to approach the subject without possibly compromising the
CBC.

We want to work on this because we both find the idea of Battle Bots interesting.
The bots will not only utilize most of the sensors and concepts we learned to
use this semester, but will also give us the chance to customize our robot’s
design with more than just LEGO bricks.

### Mechanisms, Sensors, and Motors
For the mechanism of our jousting robots, we will have two main components that
apply to the actual jousting. We will have the lance, which will be a long object
(most likely wood) used to strike the opponent’s shield. The shield component
will be another small object (a circular piece of wood) that is painted a bright
color. The shield will be attached to the limit sensors that we were given in
class so that if the lance strikes it, it will trigger the limit sensor behind
it. The idea is that the first robot to have their shield struck will lose the
round.

For sensors, we will have to use the aforementioned limit sensors to detect when
the robot’s shield is struck, but several other sensors will be required. Among
them are the following.
- Servo Motor - we will need some way to rotate the lance so that it can track the
opponent’s shield and strike it. Without some way to move the lance, it will only
ever point forward. If the lance is always pointing straight forward, the only way
it could ever strike the opponent’s shield is if they are charging head-on.
- Infrared Sensor - similar to what we did in lab 2, where we had to follow a
line, the infrared sensor will be used to track the “tilt”, which is the barrier
separating the two jousters. It will also be used to make sure that the robot
does not go outside the “lists”, which are the barriers on the outside of the arena.
- USB camera - we will use the camera to detect blobs of color corresponding to
the color of the opponent’s shield and its position so that we can move toward
the opponent and position the lance to strike their shield.
- Limit Sensor - we need a method to detect when the robot’s shield has been struck. 
We will attach the shield to the limit sensor that when the opponent’s lance
strikes the shield, it will trigger the limit sensor. This will allow us to
determine when the round is over.
