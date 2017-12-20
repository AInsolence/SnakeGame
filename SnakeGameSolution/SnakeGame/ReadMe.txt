
This is a classic game Snake.

The game was written for self-study, and is not a holistic and complete product.
However, it is done to the stage when you can just play it.
Initially, I planned to write a console version, 
but since I already had experience in writing console games, 
I was decided to rewrite it with the SFML graphics library.
It was a very interesting experience, as I decided to write a game in the OOP style
and faced the challenges of building an application architecture,
which I have not always been able to solve and which I maybe would have done differently
if I wrote a new project.

To play it is needed to download SnakeDistr folder 
or compile project from the sources and link SFML2.4.2 library.

Additional Info:

Language: C++

Graphic library: SFML 2.4.2 
https://www.sfml-dev.org/download.php

Backgrounds downloaded from: http://www.guoguiyan.com/data/out/144/69896840-papyrus-wallpapers.jpeg

For Programming and Graphics I used VS2017 Community and GIMP.
Special THX for music & sound-effects to my brother Artem.

SCRUM plan 08.11.2017

Sprints:

1. Create main block class - DONE
2. Create Level class - DONE
3. Create Snake class - DONE
4. Create KeyListener class - DONE
5. SetUp SFML - DONE
6. Find Assets - DONE
7. Create Food class - DONE
8. Create collision detection for the Snake head (collision with borders and food). Functor - DONE
8.1 Check snake size change method - DONE
9. Create point counter and GameText class - DONE
10. Create GAME class and add win/lose conditions. - DONE
10.1 Make logic for the random food appearing in the game screen. - DONE
11. Add game music and sounds (for move, collision(game over), eating&grow) - AWAIT
12. Create Main Menu screen with animation - DONE
12.1 Create cursor and menu navigation - DONE
13. Create options screen - DONE
14. Rewrite KeyListener class with using SFML tools to handle user input - DONE
15. Add ability to change key controls in options - DECLINED for this game
16. Create Record screen - DONE
16.1 Create 'Game over' screen - DONE
16.2 Add animated head, food - DONE
17. Add write/read records to/from file - DONE
17.1 Add player name input form - DONE
17.2 Add ability to record players scores if it is higher than previous - DONE
17.3 Add info showing after the GAME OVER screen - DONE
17.4 Finish records screen - DONE
18. ***more levels - CHANGED game mechanic to gradual snake's speed increase - DONE
19. ***add more lives for player - CHANGED to one live survival - DONE
20. ***Create installation pack
21. User game test

Additional features after manual testing:

1. Create new graphics for the food & walls in the game - DONE
2. Create new graphics for the main menu - DONE
3. Create new graphics for the main menu points - DONE
4. Increasing speed depending on length of the snake - DONE

Debug:

1. Need new collision detection functor - FIXED
2. Need fix food appearing - FIXED
3. Prohibit reverse moving to the snake - FIXED
4. Bug in Level.cpp, another scale of the blocks does not work in a right way - FIXED
5. Bug in reading players scores in the cases when player's name contain numbers - FIXED
6. Does not work backspace in player's input name form - FIXED
7. Change all inatances initializations in the game.cpp to variant with shared_ptr - FIXED
After player test:
8. Bug with turn the snake into itself after double pressing the control keys - FIXED