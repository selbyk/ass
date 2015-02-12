# osh
A simple UNIX shell with history feature

My solution to the first assignment in Operating System Concepts,
9e (Silberschatz, Galvin, and Gagne; 2009, 2011, or 2012)

### Goals
* Read user input
* Fork a child process using `fork()`
* Child process should invoke `execvp()`
* If command prepended with '&', parent should invoke `wait()`
* History

### Progress
* ~~Read user input~~
* ~~Fork a child process using `fork()`~~
* ~~Child process should invoke `execvp()`~~
* ~~If command prepended with '&', parent should invoke `wait()`~~
* History

## Building

```bash
git clone git@github.com:selbyk/ass.git
cd ass
make
```

## Running

### Interactive Interface

```bash
./osh
```

### CLI

```bash
./osh <command> <options>
```

## Usage
Basic commands to get around osh

### Built-in Commands

```
exit
quit
help - will show a menu
history - will show history
```
