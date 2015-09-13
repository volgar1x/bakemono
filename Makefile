include Makefile.project
include Makefile.user

NAME ?= $(shell basename `pwd`)
SRC = $(shell find $(SRCDIR) -name '*.cc')
OBJ = $(SRC:$(SRCDIR)/%.cc=$(BUILDDIR)/objects/%.o)
TARGET = $(BUILDDIR)/$(NAME)

CCOPT ?= 

ifdef HDIR
	CCOPT += -I $(HDIR)
endif

LDOPT ?=
LDOPT += $(CCOPT)

ifdef LIBDIR
LDOPT += -L $(LIBDIR)
endif

ifdef LIBS
LDOPT += $(addprefix -l,$(LIBS))
endif

.PHONY: default pre_build clean run

default: pre_build $(TARGET)

$(BUILDDIR)/objects/%.o: $(SRCDIR)/%.cc
	$(CC) $(CCOPT) -o $@ -c $<

$(TARGET): $(OBJ)
	$(CC) $(LDOPT) -o $@ $(OBJ)

pre_build:
	@mkdir -p $(BUILDDIR)/objects

clean:
	rm -rf $(BUILDDIR)

run: default
	@$(TARGET)

