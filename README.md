 
# Truest Zodiac Sign
 
 > Authors:
\<[Omar Hernandez](http//github.com/ohern017)\>
\<[Shamarri Coleman](https://github.com/sham-745)\>
\<[Yonas Adamu](https://github.com/Yonas-A)\>
 

## Project Description

 > * Why is it important or interesting to you?\
 >   * It is very easy for one to find their own zodiac sign. No surprises here; all it takes for one to know what their zodiac sign is to know their birthday and find zodiac sign that corresponds to it. However, how well does it define you? That's the question we want ask with this program. What this program will do is quiz the user on their personality and determine what zodiac sign they match the most according to their answers. The program will also contrast the user's zodiac sign with what they got in the quiz, perhaps to raise questions as to the veracity of the very concept itself.
 > * What languages/tools/technologies do you plan to use?
 >   * We plan to use C++ for this project.
 > * What will be the input/output of your project?
 >   * The inputs of the project will be the user’s birthday and their quiz responses. The output will be the zodiac sign they get according to the answers they’ve provided to the quiz and also what their zodiac sign is according to their birthday. A further development goal that can be pursued here is an analysis of the contrasts as an additional output.
> * What are the three design patterns you will be using?
 >   1)  **Composite**:
Each zodiac sign belongs to a group of elements which are Air, Water, Earth, and Fire. As an example, Aries is in the Fire sign group; such a sign would be designated as a Fire sign. The zodiac signs will inherit characteristics from their corresponding element. This creates a hierarchical structure that appears to be appropriate for the Composite pattern. In addition to that, since the ultimate goal of the program is to output zodiac signs, the elements will really only serve as useful abstract classes that the concrete classes, such as the zodiac signs, will inherit the bulk of their information
 >   2)  **Factory Method**:
The zodiac signs will be subclasses of the element classes (Fire, Air, Water, Earth). Each of the element classes will contain a number of characteristics that are common with the zodiac signs. After retrieving the characteristics from their superclasses, the zodiac sign class will include the information that sets the specific zodiac sign apart from those of the same element. For this reason, it is believed that the Factory Method design pattern will be a good fit.
 >   3)  **Mediator**:
Since the user will be matched with potentially two different zodiac signs, a comparison between the two signs should be considered. Furthermore, for a deeper analysis, there may need to be interaction between the classes to further emphasize points of deviation. For this reason, we want to promote loose coupling so that deeper comparisons/analysis can be done.

 > ## Phase II
 
## Class Diagram
 > ![zodiac final project](https://user-images.githubusercontent.com/72321122/99348285-17fdc800-284e-11eb-8ac4-8cbecc7dc3e9.png)
 >
 
 >Composite:
The inputs from the client into the Date class are taken into the ActualZodiac class, where a zodiac sign is determined according to the user's birthday. Afterwards, the birthday zodiac sign is compared to the quiz zodiac sign via the compareZodiac function to eventually illustrate the depth of the contrast to the user. The resulting zodiac signs will be output by the displayZodiac function.

 >Mediator: 
Client input into Question class will be stored within arrays in the Score class. The highest score is then determined by the calculateScore function. The Zodiac class will determine which element class has the highest score from getTotalScore function. The appropriate zodiac will be output by the displayZodiac function based on the total score. 

 >Factory:
The Water, Air, Fire and Earth element classes each correlate with the questions and score from the Zodiac class for each element. Signs within an element often share characteristics with one another. There are cases where an answer is more attributable to an element as opposed to a sign individually. In such cases, it is more appropriate to increment the group within an element accordingly, and therefore, the scores in each element class will increase by varying amounts.
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
