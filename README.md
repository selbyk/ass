# ass
a simple shell

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
./ass
```

### CLI

```bash
./ass <command> <options>
```
