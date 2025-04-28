NAME = template
SRC =  main.cpp \
	   span.cpp

OBJ = $(SRC:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address
HEADERS = span.hpp \

all : $(NAME)

$(NAME) : $(OBJ) $(HEADERS)
	$(CXX) $(SRC) $(CXXFLAGS) -o $(NAME)
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY : all clean fclean re
.SECONDARY : $(OBJ)