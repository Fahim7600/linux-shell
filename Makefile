# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Source files
SRCS = src/main.c src/parser.c src/executor.c src/history.c src/signal_handler.c src/builtins.c

# Object files
OBJS = $(SRCS:.c=.o)

# Output binary
TARGET = shell

# Build rules
all: $(TARGET)

$(TARGET): $(OBJS)
    $(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJS) $(TARGET)