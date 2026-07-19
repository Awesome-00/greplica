# greplica

grep, but smaller. Built in C as a learning project. Finds lines matching a pattern in a file. Handles files up to 1024-byte lines.

## build & run

```bash
gcc greplica.c -o greplica
./greplica "hello" file.txt
```

## flags

`-c` — count matching lines instead of printing them

```bash
./greplica -c "hello" file.txt
```