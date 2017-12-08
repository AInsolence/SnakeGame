This is a classic game Snake.

Language: C++

Graphic library: SFML 2.4.2 
https://www.sfml-dev.org/download.php

Background from: http://www.guoguiyan.com/data/out/144/69896840-papyrus-wallpapers.jpeg

To play it is needed to setup assets, link sfml library, and compile the sources.

SCRUM plan 08.11.2017

Sprints:

1. Create main block class - DONE
2. Create Level class - DONE
3. Create Snake class - DONE
4. Create KeyListener class - DONE
5. SetUp SFML - DONE
6. Find Assets - DONE
7. Create Food class - DONE
8. Create collision detection for the Snake head (collision with borders and food). Functor. - DONE
8.1 Check snake size change method. Changed. - DONE
9. Create point counter and HUD - DONE
10. Create GAME class and add win/lose conditions. - DONE
10.1 Make logic for the random food appearing in the game screen. - DONE
11. Add game music and sounds (for move, collision(game over), eating&grow) - AWAIT
12. Create Main Menu screen with animation - DONE
12.1 Create cursor and menu navigation - DONE
13. Create options screen - DONE
14. Rewrite KeyListener class with using SFML tools to handle user input - DONE
15. Add ability to change key controls in options - AWAIT
16. Create Record screen - DONE
16.1 Create 'Game over' screen - DONE
16.2 Add animated head, food - DONE
17. Add write/read records to/from file
18. ***more levels
19. ***add more lives for player
20. User game test)
21. ***Create installation pack

Debug:

1. Need new collision detection functor - DONE
2. Need fix food appearing - DONE
3. Prohibit reverse moving to the snake - DONE

Additional features after manual testing:
1. Create new graphics for the food & walls in the game - DONE
2. Create new graphics for the main menu - DONE
3. Create new graphics for the main menu points - DONE
4. Increasing speed depending on length of the snake