## Instructions for Beginners    
  
_If you are completely new to GitHub, I recommend using GitHub Desktop, a visual interface that does not require command line and terminal. Please bear with these step by step instructions-- they are long!_  
  
1.  **Go to github.com and sign in**, or create a free account (if you do not have one already): https://github.com/join

2. **Create a new repository** on your GitHub account online. Title the repository PhysComp_FirstName (for example: PhysComp_Ian). Select "Public" for repository type. **Check the box to initialize the repository with a README**.  

3. **Send me your GitHub repo url on Discord.**  

4.  **Download GitHub for Desktop** at: https://desktop.github.com . Install and open the application. Sign in with your Github.com login.

5.  **Clone Your Respository**:  
    * Return to the "code" tab of your online repository.   
    * Select the green “Code” button, and then select “open in desktop”.    
    * You should see a prompt asking where you'd like to locally clone your repository. Keep the default path, or modify it to a different location, and select the "clone" button. You may receive an error that "Git can only clone to empty folders." In this case, modify the file path and create a new empty folder for the repo to clone to. Select the "clone" button.
    * You should now have your repo online at GitHub.com and cloned locally on your computer. Double check both locations. 

6.  **Go through all past assignments and re-label as needed**:  
     * All assignments should be labeled with the short study # and title (SS#_Title), making sure that each Arduino .ino file (and any related project files) is contained within a folder of the same name. For example, "SS1_patternLED.ino" should be contained within folder "SS1_patternLED". And so on.

7.  **Push your files to GitHub**:  
    * Place your SS1 folder into your **_local_** GitHub repository (stored on your computer).   
    * Go back to the GitHub Desktop app. You should see a notice of uncommitted changes, because your local repo just changed.   
    * Select the changes that you want to commit, and write a summary of the commit within the summary field (for example: “add SS1”).  
    * Select “commit to master”. You should now see no more uncommitted changes.   
    * **One more very critical step!** Currently, your commits are saved to your local repo, and we want to mirror these changes on the online repo. To do this, we "push" the commits. In the desktop app menu, go to Repository--> Push.   
    * Check your online repo. You should see your SS1 folder there now.    
    * Go through the same process for any remaining assignments, placing the .ino files into separate folders (if not already so), and pushing to your remote repo.

8.  **As you continue to work on assignments**:  
    * Any time you make a change to files within your local repo, you should see the uncommitted changes appear on the GitHub Desktop app.   
    * Commit and push your changes often (at the very least, at the end of each working session), detailing what each change is (for example: “add timer” or “fix count variable”). 
     * If you commit and push your changes often, this will take advantage of Git's version control. This will save you from losing work or "breaking your code". You can go back at any time and check the history of your files if you've been making commits along the way.    
    * If you want to create separate space for work in progress on your repo, feel free to add additional working folders for yourself. I will only be grading folders labeled specifically for our assignments (SS1, SS2, SS3, etc.) 
  
9. **If your local repository is "behind" your online repository in commits**:  
    * For example, if you are working on two separate computers, you may need to "pull" changes from the online repo to the local repo.
    * In the desktop app menu, go to Repository--> Pull. 

**Authenticating to GitHub**: You may receive an error during set up if you have not authenticated your GitHub account yet. Follow [instructions for authenticating to GitHub](https://docs.github.com/en/desktop/installing-and-configuring-github-desktop/installing-and-authenticating-to-github-desktop/authenticating-to-github).      

## More Newbie Help
  
This video is a pretty good overview of the basic process above:     
[Using the GitHub Desktop App](https://youtu.be/BKr8lbx3uFY)        

Here are some more videos for beginners:    
[Short history of Git and GitHub](https://youtu.be/1h9_cB9mPT8)      
[Common Workflows](https://youtu.be/_ALeswWzpBo)    

For more help:    
[Official GitHub for Desktop Documentation](https://help.github.com/desktop/)  
  
## Instructions For Experienced GitHub Users
  
_If you are familiar with command line and terminal, I encourage you to go that route. Here are some refreshers:_
* [setting up Git](https://docs.github.com/en/github/getting-started-with-github/set-up-git#setting-up-git)   
* [Git and GitHub basics](https://towardsdatascience.com/getting-started-with-git-and-github-6fcd0f2d4ac6)     
* ["Cheat sheet" of Git commands](https://education.github.com/git-cheat-sheet-education.pdf).    
* [Instructions for creating a personal access token](https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/creating-a-personal-access-token).    

_You are also welcome to use any GitHub GUI that you prefer, whatever gets the job done._
  
1. **Create a new repository**, locally and online, titled PhysComp_FirstName (for example: PhysComp_Ian). 

2. **Send me your GitHub repo url on Discord.**
  
3. **Go through all past assignments and re-label as needed**, with the short study # and title (SS#_Title), making sure that each Arduino .ino file is contained within a folder of the same name. For example, "SS1_LEDs.ino" should be contained within folder "SS1_LEDs". And so on. **Push all assignments to your repository**. Double check that your online and local repos are synchronized and up to date.
