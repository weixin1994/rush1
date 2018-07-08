CC	= g++

RM	= rm -f

CXXFLAGS	+= -Wextra -Wall -Werror
CXXFLAGS	+= -I.

LDFLAGS	=

NAME	= santa

SRCS	= Box.cpp \
		  ConveyorBeltPePeNoel.cpp \
		  ElfOfPePeNoel.cpp \
		  GiftPaper.cpp \
		  LittlePoney.cpp \
		  Object.cpp \
		  PaPaXML.cpp \
		  SexToy.cpp \
		  TablePePeNoel.cpp \
		  Teddy.cpp \
		  Toy.cpp \
		  Wrap.cpp \
		  test_unitaire.cpp

OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

