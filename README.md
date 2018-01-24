# Next_Action
Next Action is a personal project manager, designed to be lightweight and unobtrusive. 

After the initial C++ version, I will port it to Java and C# to provide pretty GUIs.
The C++ version will probably remain a console app unless I really feel like messing with MFC.

Basic concept:
A todo list is an unordered binary tree of actions.
Each action can have siblings (actions that can be completed before or after it)
Each action can also have prerequisites (actions that MUST be completed BEFORE it)

Thus, any action with a nullptr prerequisite is an action that is available to be completed.
Any actions with a prerequisite cannot be completed.

e.g.
"Get a job" -- "Prepare code sample" -- "Debug" -- "Write functions" -- "Name functions" -- "Sketch data structures"
  |	              		|
"Brush teeth"   "Tailor resume"

"Get a job" has the prerequisites of "Prepare code sample" and "Tailor resume"
"Tailor resume" is part of "Get a job," but can be done before or after "Prepare code sample"
"Debug" requires that everything to its right be completed first.
"Brush teeth" has no prerequisites, thus can be done at any point.

Possible actions are: "Brush teeth", "Tailor resume", and "Sketch data structures"

All actions have 4 different energy costs: Creative, physical, emotional, and mental. These vary depending on what kind of energy the user will have to use to finish the task. There is no wrong answer here. You pick the numbers. If you think a 3 hour workout is 0 physical energy, go you. If you think getting out of bed is 1,000,000 emotional energy, do what you have to.

When each task has energy costs associated with it, you can search for the easiest actions for your current mood.
