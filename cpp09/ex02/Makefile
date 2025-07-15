NAME = PmergeMe
SRC =  main.cpp \
	   PmergeMe.cpp

OBJ = $(SRC:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address -g3
HEADERS = PmergeMe.hpp \

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