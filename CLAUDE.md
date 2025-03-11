# MiniRT Reference Guide

## Build Commands
- `make` - Build and run with testing.rt
- `make re` - Clean and rebuild
- `make clean` - Remove object files
- `make fclean` - Remove object files and executable

## Testing
- `make unity` - Run Unity test suite
- `make valgrind` - Check for memory leaks

## Code Style
- Follow 42 School Norm (enforced by Norminette)
- File organization: BASE/ (core types), CORE/ (initialization), OBJECTS/ (3D primitives), PHYSICS/ (lighting)
- Function limit: 25 lines max per function
- Variable naming: snake_case
- Struct format: t_name
- Error handling: Return NULL or -1 on failure with appropriate cleanup
- Memory management: Always free allocated memory

## Project Structure
- INC/ - Header files
- SRC/ - Source files organized by component
- MAP/ - Scene description files (.rt)
- TESTS/ - Unit tests
- LIB/ - Libraries (libft, muk_lib)