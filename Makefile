CC 	= gcc

RM	= rm -f

LNAME	= lib/libmy.a

LSRC	= my/get_next_line.c \
        my/number.c \
        my/string.c \
        my/get_next_line.c \


LOBJ	= $(LSRC:.c=.o)

all	: $(LNAME)

$(LNAME)	: $(LOBJ)
	@ar rc $(LNAME) $(LOBJ)
	@cp lib/my/my.h include/
	@echo -e "\033[32m<####################\033[36mCompilation lib\033[32m####################>\033[0m"

clean	:
	@$(RM) $(LOBJ)
	@echo -e "\033[32m<####################\033[36mmake clean\033[32m####################>\033[0m"

fclean	: clean
	@$(RM) $(LNAME)
	@echo -e "\033[32m<####################\033[36mmake fclean\033[32m####################>\033[0m"

re	: fclean all
	@echo -e "\033[32m<####################\033[36mmake re\033[32m####################>\033[0m"


