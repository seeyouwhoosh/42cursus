# What is this crap?
So, this is supposedly working, ok? I think, I don't remember in which state I left it when I made the copy. The main problem here was that it was very, very slow.

Although there weren't any data races

Why?
* One of the problems was dealing with a lonely lonesome philosopher destined to die alone in this cruel house. So, I added an checker inside the grabbing forks thing to deal with it and let him die in a painless way
* It printed stuff even after someone died, so I moved the someone_died checker one line up when grabbing forks
* Another big problem was that the way I counted the meals they had was... probably not the best, I mean, it kind of makes sense, and I still think it's feasible, but I remember there being a problem with mutexes along the way
* Also, I added in the final version a eating variable, so the philosophers don't die while they are eating
* The main problem was the loops that it does when checking things, I think. Like I said, not sure, there are just too many a problem to pinpoint exactly which one of them was the main cause (probably all of them)

## Why do you leave this here?
Because it's an attempt, all my work shall be shown, as my suffering cannot be appreciated enough in the commits, I left a concrete proof of how crappy my code usually is; as a reminder, in case my future self gets too cocky (or hopefully not, so humiliated that I hope this piece of information can make her feel better somehow)
