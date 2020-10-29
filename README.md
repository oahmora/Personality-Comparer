## \Truest  Zodiac Sign\

##\Group Members\
<Omar Hernandez> (https://github.com/ohern017)
<Shamarri Coleman> (https://github.com/sham-745)
<Yonas Adamu> (https://github.com/Yonas-A)


##Project description:
> **Why is it important or interesting to you?**
Do you know what your zodiac sign is? You most likely do because it is so easy to find. However, how well does it define you? That’s the question we want to address with this program. What this program will do is quiz the user on their personality and determine what zodiac sign they match the most according to their answers. The program will also contrast the user's zodiac sign with what they got in the quiz, perhaps to raise questions as to the veracity of the very concept itself.

> **What languages/tools/technologies do you plan to use?**
We plan to use C++ for this project.

> **What will be the input/output of your project?**
The inputs of the project will be the user’s birthday and their quiz responses. The output will be the zodiac sign they get according to the answers they’ve provided to the quiz and also what their zodiac sign is according to their birthday. A further development goal that can be pursued here is an analysis of the contrasts as an additional output.

> **What are the three design patterns you will be using? For each design pattern, you must: Explain in 3-5 sentences why you picked this pattern and what feature you will implement with it.**
> 1) *Composite*:
Each zodiac sign belongs to a group of elements which are Air, Water, Earth, and Fire. As an example, Aries is in the Fire sign group; such a sign would be designated as a Fire sign. The zodiac signs will inherit characteristics from their corresponding element. This creates a hierarchical structure that appears to be appropriate for the Composite pattern. In addition to that, since the ultimate goal of the program is to output zodiac signs, the elements will really only serve as useful abstract classes that the concrete classes, such as the zodiac signs, will inherit the bulk of their information
> 2) *Factory Method*:
The zodiac signs will be subclasses of the element classes (Fire, Air, Water, Earth). Each of the element classes will contain a number of characteristics that are common with the zodiac signs. After retrieving the characteristics from their superclasses, the zodiac sign class will include the information that sets the specific zodiac sign apart from those of the same element. For this reason, it is believed that the Factory Method design pattern will be a good fit.
> 3) *Mediator*:
Since the user will be matched with potentially two different zodiac signs, a comparison between the two signs should be considered. Furthermore, for a deeper analysis, there may need to be interaction between the classes to further emphasize points of deviation. For this reason, we want to promote loose coupling so that deeper comparisons/analysis can be done.
