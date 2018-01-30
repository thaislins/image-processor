# DIRS
INCDIR = include
BINDIR = bin
SRCDIR = src
BUILDDIR = build
LIBDIR = lib
# TARGET
TARGET_IMGPROC = $(BINDIR)/ppmprocessor
# EXTENSIONS
SRCEXT = cpp
HEADEREXT = hpp
# COMPILER
CC = g++
# FOR CLEANING
RM = /bin/rm
# WARNING FLAG
WARN = -Wall
# PEDANTIC FLAG
PEDANTIC = -pedantic -ansi
# DEBUG FLAGS
DEBUG = -g
COMPRESS = -O3
# LINKING FLAGS
INCFLAG = -I $(INCDIR)
LFLAGS = $(DEBUG) $(WARN) $(PEDANTIC) $(INCFLAG) -lpthread
# COMPILATION FLAGS
CFLAGS = $(DEBUG) -c $(WARN) -std=c++11
# OBJS
OBJS = $(BUILDDIR)/main.o $(BUILDDIR)/ppmreader.o $(BUILDDIR)/ppmwriter.o $(BUILDDIR)/image.o $(BUILDDIR)/pixel.o


# ----------------------
# ENTRIES
# ----------------------

all: $(TARGET_IMGPROC) 

$(TARGET_IMGPROC): $(OBJS)
	$(CC) $^ -o $(TARGET_IMGPROC) $(LFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INCFLAG) -o $@ $<"
	$(CC) $(CFLAGS) $(INCFLAG) -o $@ $<

# DUMMY ENTRIES
clean:
	@echo "Cleaning..."
	@echo " $(RM) $(OBJS) $(TARGET_IMGPROC)"
	$(RM) $(OBJS) $(TARGET_IMGPROC)

.PHONY: clean

