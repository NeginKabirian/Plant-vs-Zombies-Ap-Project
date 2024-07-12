# Plant-vs-Zombies-Ap-Project

This project is a version of the Plants vs. Zombies game developed using C++. Users register and log in to participate in two different rounds of combat. At the end, their information is saved to a file and displayed.
## Introduction

This project is a version of the Plants vs. Zombies game. Users register and log in to participate in two different rounds of combat. At the end, their information is saved to a file and displayed.

## Installation

To install and set up the project, follow these steps:

1. Clone the repository:

    ```bash
    git clone https://github.com/NeginKabirian/Plant-vs-Zombies-Ap-Project.git
    cd Plant-vs-Zombies-Ap-Project
    ```

2. Install the required dependencies:

    ```bash
    pip install -r requirements.txt
    ```

This project is written in C++. It utilizes fundamental concepts of Object-Oriented Programming (OOP), including inheritance and polymorphism.
We have a base class for plants and a base class for zombies, from which 6 plant characters and 6 zombie characters inherit.
A map data structure is used to store the characters
. The map's key is the number of each cell in the rectangle, and its value is a pair consisting of coordinates and a pointer to the base class.
Polymorphism is utilized in the plant functions, with dynamic casting to the required classes.
Additionally, maps are used to simulate the game rectangle as a matrix. The characters are designed to oscillate, making them more interesting.
A JSON file is used to store information, and try-catch blocks are implemented to prevent potential crashes.

The plant attack functions fully utilize the concept of polymorphism, and the base classes are pure virtual. Separate classes are used for the sun, brains, and the game map. The functions and movements of zombie characters are written within their own classes to enhance readability. Different UI screens are used for registration, login, game information, and more.

Client-Server Architecture
Clients send requests to the server. In the first round, the server randomly assigns roles. In the second round, the roles are switched. File handling and game timers are managed on the server side. Clients send messages to the server indicating which plant or zombie to add to the map, and the server forwards this information to the other client.

Contributing
To contribute to the project, follow these steps:

Fork the repository
Create a new branch (git checkout -b feature/AmazingFeature)
Commit your changes (git commit -m 'Add some AmazingFeature')
Push to the branch (git push origin feature/AmazingFeature)
Open a Pull Request

Authors
ghazalyounesi
NeginKabirian

Special thanks to everyone who has contributed to the development of this project
