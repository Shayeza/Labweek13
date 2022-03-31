# Lab week 13

This C++ project is not yet versioned by Git! 
Perform the proper steps in order to get in under Git version control.

1. Create a `.gitignore` with suitable exclude patterns.
2. Initialise git `git init`
3. Run `git status` and verify that files/folders that should be excluded are not listed!
4. Check-in files `git add --all` (adds all changed files, in the eyes of git, in the project not excluded by `.gitignore`)
5. Make a commit `git commit -m "initial commit"` (comment can be anything)
6. Make a remote repository (can be private) on GitHub or similar (Do __not__ preload the remote repo with any files. This will lead to a conflict).
7. Add the remote `git remote add origin <preferably-ssh-link-to-remote-git-repo>` (replace <> and content within it)
8. Push the changes `git push -u origin main`. For further pushes to `main`, `git push` will suffice.

The above is not the only procedure to setup git versioning, but it is a good approach as it will work in all environments as it only relies on the command line. 
Furthermore, if you only need git for local versioning you can stop at step 5.

The project should now be version controlled and backed up in remote repo.
Still, there are improvements to be made.

### Add unit tests

Create some unit test in the `/tests` folder in order to improve the code quality. The project has been preloaded with [Catch2](https://github.com/catchorg/Catch2).
Test as much as possible. Especially core functionality and corner cases.

Notice the `enable_testing()` statement prior to `add_subdirectory(tests)` in the root `CMakeLists.txt`. 
This is required for `CTest` to work properly. `CTest` allows you to run all tests in a project and to easily run tests using the command line. 

### Add Continuous Integration (CI)

Improve the project by adding automated tests. This allows you to validate your code on a clean system each time you push upstream.
Furthermore, it allows you to test your code on a different type of OS than what you are developing on. 
This is crucial for cross-platform compatibility, if that is the goal. And it often is. 
Try adding runners for both Windows, Ubuntu and MacOS. The code may or may not work on all platforms, in which case you need to adjust the code.

There are several free providers of CI services. [GitHub Actions](https://github.com/features/actions) is recommended, but will not work outside of GitHub. 
Other providers like e.g, [Circle CI](https://circleci.com/signup/) works independently of the git hosting service.

For reference, you can examine the [Pathfinding project](https://github.com/AIS1002-OOP/Pathfinding).


### Other

Try removing the implementation of insert and or remove functions in `SinglyLinkedList` and re-implement them at your own discretion. 
Create and checkout a new branch `git branch -b testing` before doing so, in order to keep the existing code intact.
