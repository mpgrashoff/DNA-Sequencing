DNA Sequencing Project Blog

Marijn Grashoff

Day 1:

Today is mostly about understanding the concept. I'm going to go into a YouTube rabbit hole: https://www.youtube.com/watch?v=b6xBvl0yPAY&t=499s. This video is a decent explanation of the concept: https://www.youtube.com/watch?v=FIxYGV7WPA8&t=270s. After watching this video, I know what I want to do. Just implementing the algorithm is not enough, in my opinion, as it would be a "dumb" algorithm. It works but has no application or uses. Instead, I want to use the PAM120 matrix as shown in the video to make a biologically significant matching algorithm. This way, the work I do is actually useful.

Day 2:

Okay, today I'm coding the basic framework. I'm thinking of a standard class that implements a grid with some private variables and functions to help it along. The algorithm part is surprisingly easy; you just have to fill in the grid, then trace your way back through it, and checking that is pretty easy.

I'm done implementing the grid. I used standard vectors as that seemed easiest. Furthermore, I think I might need a second or maybe more grids to represent the PAM tables. I think it would be cool if you could switch the operating mode of the code so that you can use different substitution tables.

Day 3:

After reading the last two entries, I feel I did a poor job of explaining the PAM tables. When a protein, for example, in a DNA string mutates, the chance of it mutating into one or another protein is not equal. As you can guess, the protein not changing is most likely, so in the matrix, this has the highest score. But if it does change, the odds are vastly different depending on what it changes into. This is relevant because if you want to determine the likelihood that two strings of, for example, DNA came from the same species, then knowing the chance that it ended up the way it looks now is very important. Thus, if there are fewer mutations, the match will be greater or if there are mutations some are way more likely than others. Based on this information and this algorithm, you could calculate the likelihood that one DNA string is genetically related to another.

If I have time left over, I might implement this calculation.

Day 4:

Today, I implemented the init algorithm to fill the table. For now, I'm just using the gap and mismatch penalties and not yet using the substitution matrix. I also made a function that prints the matrix in a nice way so that I can read the output and see if it makes sense. This is nice for debugging.

Day 5:

Today, I made the traceback function that finds the route that you took, thus showing the alignment of the two strings. I did not have a lot of time today, so it's not yet tested.

Day 6:

While testing the function, I encountered a bug. This traceback only works if string A > string B. This is due to a mistake in the filling of the matrix. I fixed it by finding the right lengths.

Day 7:

I have a fully working algorithm now, and this took a few weeks, so I don't have a lot of time left. I might need to tone down the scope, as per usual with my projects. I always start out with big plans and get all excited, but then reality kicks in. But that's okay! 😄 I am still implementing at least one PAM matrix and two operation modes.

Day 8:

I did A LOT of work today. I added the PAM matrix, which I had to do manually as I could not find an Excel sheet with the matrix in it. I tried to use Google Lens and ChatGPT to auto-parse it from a table picture I had, but this did not work. So, I resorted to manually inserting the values. It was not that bad. After this, I updated the INIT function to also initialize the PAM matrix. I added an ENUM class for the matrix types and added support for it to the rest of the algorithm. I foresaw that I wanted to make this change, so I coded it in a way that my traceback function would not have to change, and this was very nice.

Day 9:

When testing, I noticed that my results were not the same as the guy in the second video. Upon further inspection, I figured out he is using an OLDER PAM120 matrix, so our results would not be the same. To make sure my implementation works, I ran it against this site: https://bioboot.github.io/bimm143_W20/class-material/nw/. Then, I do end up getting the same answers, so my algorithm does work. I could not find another implementation using the PAM matrices, so I did not test that, but I see no reason why it would not work.

Day 10:

I rewrote some minor parts, but I think I'm done, especially as my time is up, and I have to make the presentation. This was a cool project, and I'm glad I did it. It was a lot less work than my assembly but still challenging, which is exactly what I was looking for. Even though I did not get to implementing everything, I am very happy with the end result. If I had more time, I would implement more PAM matrices and a genetic match calculator.