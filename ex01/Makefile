NAME = PhoneBook
SRC = 	PhoneBook.cpp \
		Contact.cpp   \
		main.cpp
OBJ = $(SRC:.cpp=.o)
FLAGS = -Wall -Werror -Wextra -std=c++98
GCC = c++

all : $(NAME)

$(NAME) : $(OBJ)
	$(GCC) $(SRC) $(FLAGS) -o $(NAME)
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY : all clean fclean re
.SECONDARY : $(OBJ)