############################		Variables		############################
NAME = libdraw.a

LIBFT_DIR = ./libs/libft
LIBMLX_DIR = ./libs/libmlx

INC_DIR = ./includes
SRCS_DIR = ./srcs
OBJS_DIR = ./objs

C_INCLUDE_PATH += includes/
C_INCLUDE_PATH += $(LIBFT_DIR)/includes
C_INCLUDE_PATH += $(LIBMLX_DIR)/includes

#FLAGS = -Wall -Werror -Wextra
FLAGS += $(foreach path,$(C_INCLUDE_PATH),-I$(path))

SRCS_FILES = ft_create_window.c ft_draw_circle.c ft_draw_line.c ft_draw_rectangle.c

MLX_OBJS = $(LIBMLX_DIR)/*.o

# LIBFT_FUNCS =

SRCS =	$(foreach file,$(SRCS_FILES),$(SRCS_DIR)/$(file))

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS_FILES:%.c=%.o))
# OBJS += $(foreach func,$(LIBFT_FUNCS),$(OBJS_DIR)/libft/ft_$(func).o)

# FLAGS += $(foreach fun,$(LIBFT_FUNS),-Dft_$(fun)=ft_printf_libft_$(fun))

############################		  Rules 		############################

all: $(NAME)

$(OBJS): | $(OBJS_DIR)

$(OBJS_DIR):
	@mkdir -p $@
	# @mkdir -p $@/libft

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	gcc $(FLAGS) -c $< -o $@ 

# $(OBJS_DIR)/libft/%.o: $(LIBFT_DIR)/srcs/%.c
# 	@gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	echo "Building...\n"
	ar rc $@ $^
	ranlib $@
	echo "Build complete"

test: all
	gcc -I./includes -L. -ldraw -L$(LIBMLX_DIR) -lmlx -framework OpenGL -framework AppKit test.c

clean:
	@echo "Object files cleared"
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "Build cleared"

re: fclean all

.PHONY: all clean fclean re

#	by rschuppe