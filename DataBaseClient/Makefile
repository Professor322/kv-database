COMPILER = g++
CHECK_FLAGS = -Wall -Wextra
#COMPILE_FLAGS = -std=17
NAME = client
ADD_SRC = ../CommonFiles/
RESOURCES = http_request_parser.cpp http_response_parser.cpp
SRC_S = $(addprefix $(ADD_SRC), $(RESOURCES)) main.cpp
OBJ = $(SRC_S:.c=.o)
ADD_INC = ../CommonFiles/ ../boost_system/include/ ../jsoncpplib/include/
BOOST_SYSTEM = ../boost_system/libboost_system.a
JSON_CPP_LIB = ../jsoncpplib/libjsoncpp.a

all: $(NAME)

$(NAME):  $(OBJ)
	$(COMPILER) -o $(NAME) $(CHECK_FLAGS) $(COMPILE_FLAGS) -I $(ADD_INC) $(OBJ) $(BOOST_SYSTEM) $(JSON_CPP_LIB)
	echo ======[Done]======
%.o : %.c
	echo "$(NAME) >>> Add/Update $<"
	$(COMPILER) -c -o $@ -I $(ADD_INC) $(CHECK_FLAGS) $<
clean:
	@rm -f $(ADD_SRC)*.o
fclean: clean
	@rm -f ./$(NAME)
re: fclean all