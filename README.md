<h1 align="center" id="title">philosophers</h1>

<p align="center"><img src="https://socialify.git.ci/nkarapet42/philosophers/image?font=KoHo&logo=https%3A%2F%2Fgithub.com%2Fnkarapet42%2Fphilosophers%2Fassets%2F157054887%2F6fefa1a7-f6c9-451e-ae7d-61669aa780de&name=1&pattern=Brick%20Wall&theme=Light" alt="philosophers"/></p>

### Grade 125/100

<!DOCTYPE html>
<html lang="en">

<body>
    <div class="container">
        <h1>The Dining Philosophers Problem</h1>
        <p>
            The Dining Philosophers problem is a classic synchronization problem in computer science.
            It illustrates resource allocation and deadlock avoidance in a concurrent system.
        </p>
        <h2>Problem Description</h2>
        <ul>
            <li>Five philosophers sit around a round table.</li>
            <li>Each philosopher has their own plate, and there's a fork placed between each pair of adjacent philosophers.</li>
            <li>The dish served is spaghetti, which must be eaten with two forks.</li>
            <li>Philosophers alternate between thinking and eating.</li>
            <li>A philosopher can only eat when they have both a left and right fork available.</li>
            <li>After eating, a philosopher puts down both forks and starts sleeping.</li>
            <li>The goal is to design an algorithm so that no philosopher starves, ensuring they can forever alternate between eating and thinking.</li>
        </ul>
        <h2>Solutions</h2>
        <p>
            Various solutions exist, including Dijkstra's algorithm. These solutions involve mutexes, semaphores, and state tracking for each philosopher.
            Implementing them correctly ensures that philosophers can eat without starving.
        </p>
    </div>
</body>
</html>

#### Makefile Available Targets:  
`make` or `make all` - Makes _philo_ or _philoso_bonus_    
`make clean` - Deletes all the resulting object files  
`make fclean` - Deletes _philo_ or _philo_bonus_ and all the resulting object files  
`make re` - Deletes everything and rebuilds

### Basic Usage

Compile the files with `make` in folder philo and run the program:
```bash
./philo 4 310 200 100
```
Output should be:
```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
0 3 has taken a fork
0 3 has taken a fork
0 3 is eating
201 1 is sleeping
201 3 is sleeping
201 2 has taken a fork
201 2 has taken a fork
201 2 is eating
201 4 has taken a fork
201 4 has taken a fork
201 4 is eating
302 1 is thinking
302 3 is thinking
310 2 died
```
Compile the files with `make` in folder philo_bonus and run the program:
##### 1----------------------------------------------------------------------------------------------------------------------------
```bash
./philo_bonus 4 310 200 100
```
Output should be:
```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
0 2 has taken a fork
0 2 has taken a fork
0 2 is eating
201 3 has taken a fork
201 4 has taken a fork
201 2 is sleeping
201 1 is sleeping
201 3 has taken a fork
201 4 has taken a fork
201 3 is eating
201 4 is eating
302 1 is thinking
302 2 is thinking
310 4 died
```
##### 2----------------------------------------------------------------------------------------------------------------------------
```bash
./philo 200 800 200 200
```
Output should be:
```
...
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
0 13 has taken a fork
0 13 has taken a fork
0 13 is eating
0 3 has taken a fork
0 3 has taken a fork
0 11 has taken a fork
0 19 has taken a fork
0 21 has taken a fork
0 21 has taken a fork
0 21 is eating
0 23 has taken a fork
0 15 has taken a fork
0 15 has taken a fork
0 25 has taken a fork
0 25 has taken a fork
...
Infinity loop of eating
```
##### 3----------------------------------------------------------------------------------------------------------------------------
```bash
./philo "arguments" (if the amount of arguments is higher than 5 or less than 4)
```
Output should be same:
```
INVALID NUMBER OF ARGUMENTS -> 'args' : Need 4 or 5
```
# e
