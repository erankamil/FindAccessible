The porpuse of the project is: In a given computers network that the computers connected between them in a way one connection (not all the computer are connected to each other),
We want to find the accesible group of computers that recieved the message that was send to a chosen comptuer in the computer newtork.
I solved this problem in two different ways (The two methodes in System.c file):
1) Recursively.
2) Iteratively with stack.

For example, in the following computer network we have five computers.

![network](https://user-images.githubusercontent.com/62330191/115355713-9971d180-a1c3-11eb-8fe8-2ba70bba4bbe.PNG)

The network implemented with array of N computer, each computer has the computers it is connected to represented in a linked list.

![networkStructure](https://user-images.githubusercontent.com/62330191/115355854-bf977180-a1c3-11eb-8503-9ed06eebde2c.PNG)
