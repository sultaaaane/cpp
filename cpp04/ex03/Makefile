NAME = Animal
SRC =  main.cpp \
		AMateria.cpp \
		Character.cpp \
		Cure.cpp \
		Ice.cpp \
		MateriaSource.cpp \
		ICharacter.cpp \
		IMateriaSource.cpp \
		free.cpp
		

OBJ = $(SRC:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g3 -fsanitize=address

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(SRC) $(CXXFLAGS) -o $(NAME)
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY : all clean fclean re
.SECONDARY : $(OBJ)