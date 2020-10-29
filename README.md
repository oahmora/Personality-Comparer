 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\<"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# Truest Zodiac Sign
 > Your author list below should include links to all members GitHub and should begin with a "\<" (remove existing author).
 
 > Authors:
\<[Omar Hernandez](http//github.com/ohern017)\>
\<[Shamarri Coleman](https://github.com/sham-745)\>
\<[Yonas Adamu](https://github.com/Yonas-A)\>
 
 > You will be forming a group of **THREE** students and work on an interesting project that you will propose yourself (in this `README.md` document). You can pick any project that you'd like, but it needs ot implement three design patterns. Each of the members in a group is expected to work on at least one design pattern and its test cases. You can, of course, help each other, but it needs to be clear who will be responsible for which pattern and for which general project features.
 
 > ## Expectations
 > * Incorporate **three** distinct design patterns, *two* of the design patterns need to be taught in this course:
 >   * Composite, Strategy, Abstract Factory, Visitor
 > * All three design patterns need to be linked together (it can't be three distinct projects)
 > * Your project should be implemented in C/C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.

## Project Description

 > Your project description should summarize the project you are proposing. Be sure to include
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
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `Backlog` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 
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
 
